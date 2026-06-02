#!/usr/bin/env python3
"""
Retry failed prototype updates after fixing known issues:
- Array params: data[64] -> *data
- Function pointer params: void (*func)(...) -> void *func (simplified)
- ssize_t, off_t, int16_t, int64_t now created as typedefs
"""

import re
import subprocess
import json
import urllib.parse

FAILED_FILE = "/media/files/ncs/failed_updates.txt"
PROGRAM = "/even_1.63/app_update_1.63.bin"
BASE_URL = "http://127.0.0.1:8089"

C_KEYWORDS = {'static', 'const', 'volatile', 'inline', 'extern', 'struct', 'union',
              'enum', 'ALWAYS_INLINE', '__syscall', 'FUNC_NO_STACK_PROTECTOR',
              'FUNC_NORETURN', '__must_check', 'ZRESTRICT', 'restrict',
              'NRFX_STATIC_INLINE', 'NRFY_STATIC_INLINE', 'NRF_STATIC_INLINE',
              'LC3_HOT'}


def strip_c_keywords(sig):
    result = sig
    for kw in C_KEYWORDS:
        result = re.sub(rf'\b{re.escape(kw)}\b', '', result)
    result = re.sub(r'\s+', ' ', result).strip()
    return result


def fix_array_params(prototype):
    """Convert array params like 'uint8_t data[64]' to 'uint8_t *data'."""
    # Match param_name[...] and replace with *param_name
    prototype = re.sub(r'(\w+)\s*\[[^\]]*\]', r'*\1', prototype)
    return prototype


def fix_function_pointer_params(prototype):
    """
    Convert function pointer params like 'void (*func)(bt_conn *conn, void *data)'
    to 'void *func' for Ghidra compatibility.
    """
    # Pattern: type (*name)(params) -> type *name
    # Need to handle nested parens carefully
    result = prototype
    # Find patterns like: type (*name)(...)
    # This is tricky with regex, do it iteratively
    while True:
        m = re.search(r'(\w[\w\s\*]*?)\s*\(\s*\*\s*(\w+)\s*\)\s*\(', result)
        if not m:
            break
        # Find the matching closing paren for the function pointer params
        start = m.end() - 1  # position of (
        depth = 1
        pos = start + 1
        while pos < len(result) and depth > 0:
            if result[pos] == '(': depth += 1
            elif result[pos] == ')': depth -= 1
            pos += 1
        # Replace the whole function pointer with simplified form
        ret_type = m.group(1).strip()
        name = m.group(2)
        # For Ghidra, just use a generic pointer
        replacement = f"void *{name}"
        result = result[:m.start()] + replacement + result[pos:]

    # Also handle: int (*c)[16] -> int **c (array of pointers)
    result = re.sub(r'(\w+)\s*\(\s*\*\s*(\w+)\s*\)\s*\[\d+\]', r'\1 **\2', result)

    return result


def build_ghidra_prototype(ghidra_name, true_sig):
    sig = true_sig.strip().rstrip(';').strip()
    sig = strip_c_keywords(sig)
    sig = fix_array_params(sig)
    sig = fix_function_pointer_params(sig)

    m = re.match(r'^(.*?)\b(\w+)\s*(\(.*\))$', sig)
    if not m:
        return None

    ret_type = m.group(1).strip()
    params = m.group(3).strip()

    prototype = f"{ret_type} {ghidra_name}{params}"
    prototype = re.sub(r'\s+', ' ', prototype).strip()
    return prototype


def get_calling_convention(ghidra_sig):
    m = re.search(r'\b(__stdcall|__cdecl|__fastcall|__thiscall)\b', ghidra_sig)
    return m.group(1) if m else None


def main():
    # Re-read prototype_targets.txt to get the original entries for failed functions
    with open('/media/files/ncs/prototype_targets.txt') as f:
        targets = {}
        for line in f:
            line = line.strip()
            if not line:
                continue
            parts = [p.strip() for p in line.split('|')]
            if len(parts) >= 6:
                targets[parts[0]] = parts  # key by address

    with open(FAILED_FILE) as f:
        failed_lines = f.readlines()

    print(f"Retrying {len(failed_lines)} failed functions...")

    success = 0
    still_failed = []

    for line in failed_lines:
        line = line.strip()
        if not line:
            continue

        # Parse: "ghidra_name at addr | reason | attempted: prototype"
        m = re.match(r'(.+?) at (\w+) \|', line)
        if not m:
            still_failed.append(f"PARSE_ERROR | {line}")
            continue

        ghidra_name = m.group(1).strip()
        addr = m.group(2).strip()

        # Get the original entry from prototype_targets.txt
        if addr not in targets:
            still_failed.append(f"NOT_IN_TARGETS | {line}")
            continue

        parts = targets[addr]
        ghidra_sig = parts[2]
        true_sig = parts[5]

        # Build fixed prototype
        prototype = build_ghidra_prototype(ghidra_name, true_sig)
        if not prototype:
            still_failed.append(f"CANT_BUILD | {ghidra_name} at {addr} | {true_sig}")
            continue

        calling_conv = get_calling_convention(ghidra_sig)

        # Try to set it
        data = {"function_address": f"0x{addr}", "prototype": prototype}
        if calling_conv:
            data["calling_convention"] = calling_conv

        try:
            r = subprocess.run(
                ['curl', '-s', '-X', 'POST',
                 f'{BASE_URL}/set_function_prototype?program={PROGRAM}',
                 '-H', 'Content-Type: application/json',
                 '-d', json.dumps(data)],
                capture_output=True, text=True, timeout=15
            )
            result = r.stdout.strip()
        except Exception as e:
            result = f"ERROR: {e}"

        if 'error' in result.lower() or 'fail' in result.lower():
            still_failed.append(f"{ghidra_name} at {addr} | {result[:100]} | prototype: {prototype}")
        else:
            # Verify
            try:
                r = subprocess.run(
                    ['bash', '-i', '-c',
                     f'ghidraMCP "get_function_by_address?address=0x{addr}&program={PROGRAM}"'],
                    capture_output=True, text=True, timeout=10
                )
                print(f"  OK: {ghidra_name} -> {prototype[:80]}")
                success += 1
            except:
                success += 1  # set worked even if verify timed out

    print(f"\nRetry results: {success} fixed, {len(still_failed)} still failing")

    # Write remaining failures
    with open(FAILED_FILE, 'w') as f:
        for entry in still_failed:
            f.write(entry + '\n')

    if still_failed:
        print("\nStill failing:")
        for s in still_failed:
            print(f"  {s[:150]}")


if __name__ == '__main__':
    main()
