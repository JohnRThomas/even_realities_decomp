#!/usr/bin/env python3
"""Build + RSA-2048-PSS-sign the EPHEMERAL-SLOT patch (handler_payload.S).

Produces a standalone signed CPUAPP image (to be flashed LATER, overwrite-only,
after review -- this script does NOT flash). It reuses the exact hook site
(0x0001a710) + reply path (context+0x0c) of the proven memread/QSPI exporters,
but its appended handler adds three BLE commands -- STAGE (0x30), VERIFY (0x31),
RUN (0x3f) -- that stage a candidate image into a QSPI scratch region and enter
it live, so the next reset always returns to the untouched primary image.

CRITICAL: signs with RSA-2048 **PSS** (TLV 0x20 = RSA2048_PSS, salt_len=32),
NOT PKCS#1 v1.5 (the glasses' MCUboot rejects pkcs1.5). The MCUboot KEYHASH TLV
(0x01) is SHA-256 of the PKCS#1 RSAPublicKey DER, NOT SubjectPublicKeyInfo.

Usage:
  python3 fw_patching/patch.py
"""
from __future__ import annotations

import argparse
import hashlib
import json
import shutil
import struct
import subprocess
from pathlib import Path

from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import padding, utils

HERE = Path(__file__).resolve().parent
ORIGINAL = Path.home() / "Projects/G1disasm2/app_update.bin"
ORIGINAL_SHA256 = "e0614feb3609fc2f251a00c16ca66f01c9fb8153de81ca1818cab5f79b42fd3b"
REFERENCE_PSS = Path("/Users/freedomcoder/Projects/ARMemul/fw/ota/app_update_qspi_exporter.pss.bin")
KEY = Path.home() / "ncs251/bootloader/mcuboot/root-rsa-2048.pem"
TOOLCHAIN = Path.home() / "zephyr-sdk-0.16.5-1/arm-zephyr-eabi/bin"
AS = TOOLCHAIN / "arm-zephyr-eabi-as"
LD = TOOLCHAIN / "arm-zephyr-eabi-ld"
OBJCOPY = TOOLCHAIN / "arm-zephyr-eabi-objcopy"
OBJDUMP = TOOLCHAIN / "arm-zephyr-eabi-objdump"

MCUBOOT_MAGIC = 0x96F3B83D
TLV_MAGIC = 0x6907
HEADER_SIZE = 0x200
SLOT_END_FILE_OFFSET = 0xF0000
IMAGE_LOAD_VA = 0xC000
HOOK_VA = 0x0001A710
HOOK_FILE_OFFSET = HOOK_VA - IMAGE_LOAD_VA
HOOK_EXPECTED = bytes.fromhex("0d 4b 1b 68")
HANDLER_VA = 0x000FAA40                      # same slot as the memread/QSPI exporters
HANDLER_FILE_OFFSET = HANDLER_VA - IMAGE_LOAD_VA
HANDLER_SRC = HERE / "handler_payload.S"
ENTRY_SYMBOL = "qspi_ble_payload"
KEYHASH_EXPECTED = bytes.fromhex(
    "fc5701dc6135e1323847bdc40f04d2e5"
    "bee5833b23c29f93593d00018cfa9994"
)
# b.w HANDLER_VA encoded for the 4 bytes at HOOK_VA (matches the exporter builds).
HOOK_REPLACEMENT = bytes.fromhex("e0 f0 96 b9")


def run(*args, capture=False):
    return subprocess.run([str(a) for a in args], check=True, text=True,
                          capture_output=capture)


def sha256(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()


def assemble(out: Path) -> bytes:
    obj, elf, binary = out / "patch.o", out / "patch.elf", out / "handler_payload.bin"
    run(AS, "-mcpu=cortex-m33", "-mthumb", "-o", obj, HANDLER_SRC)
    run(LD, f"-Ttext=0x{HANDLER_VA:x}", "-e", ENTRY_SYMBOL, "-o", elf, obj)
    run(OBJCOPY, "-O", "binary", elf, binary)
    (out / "handler_payload.disasm.txt").write_text(
        run(OBJDUMP, "-d", elf, capture=True).stdout)
    return binary.read_bytes()


def parse_original(image: bytes):
    names = ("magic", "load_addr", "hdr_size", "protected_tlv_size", "img_size",
             "flags", "major", "minor", "revision", "build")
    header = dict(zip(names, struct.unpack_from("<IIHHIIBBHI", image, 0)))
    if header["magic"] != MCUBOOT_MAGIC:
        raise ValueError("unexpected MCUboot magic")
    if header["hdr_size"] != HEADER_SIZE:
        raise ValueError("unexpected header size")
    if header["protected_tlv_size"] != 0 or header["flags"] != 0:
        raise ValueError("unexpected protected TLVs / flags")
    body_end = header["hdr_size"] + header["img_size"]
    if image[body_end:body_end + 2] != struct.pack("<H", TLV_MAGIC):
        raise ValueError("regular TLV header not found")
    return bytearray(image[:body_end]), header


def pss_sign(body: bytes):
    """Return (tlv_block, digest, keyhash, signature) using RSA-2048 PSS."""
    key = serialization.load_pem_private_key(KEY.read_bytes(), password=None)
    pub = key.public_key()
    pub_der = pub.public_bytes(
        serialization.Encoding.DER,
        serialization.PublicFormat.PKCS1)  # RSAPublicKey DER (mcuboot keyhash)
    keyhash = hashlib.sha256(pub_der).digest()
    if keyhash != KEYHASH_EXPECTED:
        raise ValueError("signing key does not match the device key hash")
    digest = hashlib.sha256(body).digest()
    signature = key.sign(
        digest,
        padding.PSS(mgf=padding.MGF1(hashes.SHA256()), salt_length=32),
        utils.Prehashed(hashes.SHA256()))
    if len(signature) != 256:
        raise ValueError(f"expected 256-byte signature, got {len(signature)}")
    pub.verify(signature, digest,
               padding.PSS(mgf=padding.MGF1(hashes.SHA256()), salt_length=32),
               utils.Prehashed(hashes.SHA256()))
    records = b"".join((
        struct.pack("<BBH", 0x10, 0, len(digest)) + digest,        # IMAGE_HASH
        struct.pack("<BBH", 0x01, 0, len(keyhash)) + keyhash,      # KEYHASH
        struct.pack("<BBH", 0x20, 0, len(signature)) + signature,  # RSA2048_PSS
    ))
    tlv = struct.pack("<HH", TLV_MAGIC, 4 + len(records)) + records
    return tlv, digest, keyhash, signature


def tlv_layout(img: bytes):
    m, _, h, _, isz = struct.unpack_from("<IIHHI", img, 0)
    be = h + isz
    tm, tl = struct.unpack_from("<HH", img, be)
    p, end, items = be + 4, be + tl, []
    while p < end:
        t, _, l = struct.unpack_from("<BBH", img, p)
        items.append((t, l))
        p += 4 + l
    return (m, h, tm, items)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", type=Path, default=None)
    args = ap.parse_args()
    out = (args.out or (HERE / "build_payload")).resolve()
    if out.exists():
        shutil.rmtree(out)
    out.mkdir(parents=True)

    original = ORIGINAL.read_bytes()
    if sha256(original) != ORIGINAL_SHA256:
        raise ValueError("source image hash mismatch; refusing to patch")
    body, old_header = parse_original(original)
    if body[HOOK_FILE_OFFSET:HOOK_FILE_OFFSET + 4] != HOOK_EXPECTED:
        raise ValueError("hook preimage mismatch; refusing to patch")

    handler = assemble(out)
    if len(body) > HANDLER_FILE_OFFSET:
        raise ValueError("handler would overlap the signed payload")
    if HANDLER_FILE_OFFSET + len(handler) >= SLOT_END_FILE_OFFSET:
        raise ValueError("appended handler does not fit the primary slot")
    body.extend(b"\0" * (HANDLER_FILE_OFFSET - len(body)))
    body.extend(handler)
    body[HOOK_FILE_OFFSET:HOOK_FILE_OFFSET + 4] = HOOK_REPLACEMENT

    new_img_size = len(body) - HEADER_SIZE
    if len(body) >= SLOT_END_FILE_OFFSET:
        raise ValueError("patched payload does not fit the primary slot")
    struct.pack_into("<I", body, 12, new_img_size)

    tlv, digest, keyhash, signature = pss_sign(bytes(body))
    signed = bytes(body) + tlv
    if len(signed) >= SLOT_END_FILE_OFFSET:
        raise ValueError("signed image does not fit the primary slot")
    out_image = out / "app_update_payload.pss.bin"
    out_image.write_bytes(signed)

    ref_ok = None
    mine = tlv_layout(signed)
    if REFERENCE_PSS.exists():
        ref = tlv_layout(REFERENCE_PSS.read_bytes())
        ref_ok = (mine[0] == ref[0] and mine[1] == ref[1]
                  and mine[2] == ref[2] and mine[3] == ref[3])

    hook_disasm = run(
        OBJDUMP, "-D", "-b", "binary", "-marm", "-Mforce-thumb",
        f"--adjust-vma=0x{IMAGE_LOAD_VA:x}", f"--start-address=0x{HOOK_VA:x}",
        f"--stop-address=0x{HOOK_VA + 8:x}", out_image, capture=True).stdout
    (out / "hook.disasm.txt").write_text(hook_disasm)

    manifest = {
        "schema": 1,
        "variant": "ephemeral-slot (STAGE 0x30 / VERIFY 0x31 / RUN 0x3f)",
        "source_image": str(ORIGINAL),
        "source_sha256": sha256(original),
        "output_image": str(out_image),
        "output_sha256": sha256(signed),
        "signature_scheme": "RSA-2048 PSS (MGF1-SHA256, salt_len=32), Prehashed SHA256",
        "signature_self_verify": "OK",
        "signing_key": str(KEY),
        "public_key_sha256": keyhash.hex(),
        "body_digest_sha256": digest.hex(),
        "old_img_size": old_header["img_size"],
        "new_img_size": new_img_size,
        "reference_pss_tlv_layout_match": ref_ok,
        "tlv_layout": [(hex(t), l) for t, l in mine[3]],
        "handler": {"address": f"0x{HANDLER_VA:08x}",
                    "file_offset": f"0x{HANDLER_FILE_OFFSET:x}",
                    "size": len(handler), "sha256": sha256(handler),
                    "bytes": handler.hex(" ")},
        "in_place_patch": {"address": f"0x{HOOK_VA:08x}",
                           "file_offset": f"0x{HOOK_FILE_OFFSET:x}",
                           "before": HOOK_EXPECTED.hex(" "),
                           "after": HOOK_REPLACEMENT.hex(" "),
                           "meaning": f"b.w 0x{HANDLER_VA:08x}"},
        "firmware_calls": {
            "flash_settings_read": "0x000225b4",
            "qspi_nor_write": "0x00060f20",
            "qspi_nor_erase": "0x00060dd0",
            "qspi_device": "0x00087bf0",
        },
        "qspi_scratch": {"base": "0x00000000", "limit": "0x000c0000",
                         "note": "NOT proven free; best static candidate above the "
                                 "highest mapped burned-asset region (ends 0x00dbedcf). "
                                 "Validate against a live partition map before trust."},
        "ram_load_window": {"base": "0x20002000", "limit": "0x20070000",
                            "excluded": "pcd_sram [0x20000000,0x20002000) SPU-locked; "
                                        "net-core IPC [0x20070000,0x20080000)"},
        "protocol": {
            "STAGE": {"command": "0x30",
                      "request": "[4]=flags(bit0 erase-sector), [5:9]=qspi_addr LE "
                                 "(4-byte aligned, in scratch), [9]=count(4..176 mult4), "
                                 "[10:10+count]=data",
                      "reply": "[0]=0x30,[1]=0xc9/0xca,[2]=status(0 ok/1 invalid/2 io),"
                               "[3]=count,[4:8]=qspi_addr"},
            "VERIFY": {"command": "0x31",
                       "request": "[5:9]=base LE, [9:13]=length LE",
                       "reply": "[0]=0x31,[1]=0xc9/0xca,[2]=status,[3]=0,[4:8]=CRC32 LE",
                       "hash": "CRC-32 IEEE poly 0xEDB88320 (NOT cryptographic)"},
            "RUN": {"command": "0x3f",
                    "request": "[5:9]=qspi_src LE, [9:13]=length LE, "
                               "[13:17]=expected_crc32 LE, [17:21]=load_addr LE",
                    "reply": "accepted [0]=0x3f,[1]=0xc9,[2]=0,[3]=0,[4:8]=load_addr "
                             "(sent BEFORE entry); refuse [1]=0xca,[2]=1 bounds/3 crc"},
        },
        "no_persistent_arming": "true -- trigger is the live RUN command only; "
                                "staged bytes are inert; disarms on reboot structurally",
        "slot_end_file_offset": f"0x{SLOT_END_FILE_OFFSET:x}",
        "remaining_slot_bytes_after_signed_image": SLOT_END_FILE_OFFSET - len(signed),
        "flash_note": "DO NOT FLASH from this script. Overwrite-only swap is a reviewed, "
                      "separate step. RUN enters an image WITHOUT MCUboot signature check.",
    }
    (out / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")
    print(json.dumps(manifest, indent=2))


if __name__ == "__main__":
    main()
