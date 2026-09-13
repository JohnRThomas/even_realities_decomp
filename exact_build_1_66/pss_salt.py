#!/usr/bin/env python3
"""Recover / pin the RSA-PSS salt of an MCUboot image signature.

imgtool signs with RSA-2048 PSS (SHA-256, MGF1-SHA-256, 32-byte random salt),
so two signings of the same image differ.  The salt is recoverable from a
signature with the public key alone (EM = s^e mod n; DB = maskedDB ^ MGF1(H)),
and re-signing with that salt and the same private key reproduces the
signature bit for bit whenever the signed bytes are identical.

Usage (needs the `cryptography` package, e.g. the NCS toolchain python):
  pss_salt.py recover KEY.pem IMAGE.bin        print the salt (hex) and check H
  pss_salt.py resign  KEY.pem IN.bin OUT.bin SALT_HEX
                                              rewrite the RSA2048_PSS TLV of IN
                                              signed with SALT, write OUT
KEY.pem may be the private key (root-rsa-2048.pem) for both commands.
"""
import hashlib
import struct
import sys

from cryptography.hazmat.primitives import serialization

IMAGE_MAGIC = 0x96F3B83D
TLV_INFO_MAGIC = 0x6907
TLV_RSA2048_PSS = 0x20
HLEN = 32
SLEN = 32


def mgf1(seed, length):
    out = b""
    counter = 0
    while len(out) < length:
        out += hashlib.sha256(seed + struct.pack(">I", counter)).digest()
        counter += 1
    return out[:length]


def load_key(path):
    data = open(path, "rb").read()
    try:
        priv = serialization.load_pem_private_key(data, password=None)
        return priv.public_key().public_numbers(), priv.private_numbers()
    except ValueError:
        return serialization.load_pem_public_key(data).public_numbers(), None


def image_parts(data):
    magic, _, hdr_size, prot_size, img_size, _ = struct.unpack_from("<IIHHII", data, 0)
    assert magic == IMAGE_MAGIC
    signed_end = hdr_size + img_size + prot_size
    off = signed_end
    tmagic, tlen = struct.unpack_from("<HH", data, off)
    assert tmagic == TLV_INFO_MAGIC, "unprotected TLV area not found"
    p = off + 4
    while p < off + tlen:
        ttype, length = struct.unpack_from("<HH", data, p)
        if ttype == TLV_RSA2048_PSS:
            return data[:signed_end], p + 4, length
        p += 4 + length
    raise SystemExit("no RSA2048_PSS TLV")


def em_bits(pub):
    return pub.n.bit_length() - 1


def recover(pub, signed, sig):
    embits = em_bits(pub)
    emlen = (embits + 7) // 8
    em = pow(int.from_bytes(sig, "big"), pub.e, pub.n).to_bytes(emlen, "big")
    assert em[-1] == 0xBC, "not a PSS encoding for this key"
    masked, h = em[:emlen - HLEN - 1], em[emlen - HLEN - 1:-1]
    db = bytearray(a ^ b for a, b in zip(masked, mgf1(h, len(masked))))
    db[0] &= 0xFF >> (8 * emlen - embits)
    salt = bytes(db[-SLEN:])
    assert db[-SLEN - 1] == 1 and not any(db[:-SLEN - 1]), "bad DB padding"
    mhash = hashlib.sha256(signed).digest()
    ok = hashlib.sha256(b"\0" * 8 + mhash + salt).digest() == h
    return salt, ok


def sign(pub, priv, signed, salt):
    embits = em_bits(pub)
    emlen = (embits + 7) // 8
    mhash = hashlib.sha256(signed).digest()
    h = hashlib.sha256(b"\0" * 8 + mhash + salt).digest()
    db = b"\0" * (emlen - SLEN - HLEN - 2) + b"\x01" + salt
    masked = bytearray(a ^ b for a, b in zip(db, mgf1(h, len(db))))
    masked[0] &= 0xFF >> (8 * emlen - embits)
    em = bytes(masked) + h + b"\xbc"
    klen = (pub.n.bit_length() + 7) // 8
    return pow(int.from_bytes(em, "big"), priv.d, pub.n).to_bytes(klen, "big")


def main():
    if len(sys.argv) < 4:
        raise SystemExit(__doc__)
    cmd, keypath, inpath = sys.argv[1:4]
    pub, priv = load_key(keypath)
    data = bytearray(open(inpath, "rb").read())
    signed, sig_off, sig_len = image_parts(bytes(data))
    if cmd == "recover":
        salt, ok = recover(pub, signed, bytes(data[sig_off:sig_off + sig_len]))
        print(salt.hex())
        if not ok:
            raise SystemExit("signature does not verify against this image with this key")
    elif cmd == "resign":
        if priv is None:
            raise SystemExit("resign needs the private key")
        outpath, salt = sys.argv[4], bytes.fromhex(sys.argv[5])
        sig = sign(pub, priv, signed, salt)
        assert len(sig) == sig_len
        data[sig_off:sig_off + sig_len] = sig
        open(outpath, "wb").write(bytes(data))
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main()
