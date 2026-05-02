#!/usr/bin/env python3
"""
Step 7: Update function signatures in Ghidra.
For each function in prototype_targets.txt:
  7a. Validate all types exist in Ghidra
  7b. Validate the prototype string
  7c. Set the prototype
  7d. Verify the result
"""

import re
import subprocess
import json
import urllib.parse
import time

INPUT_FILE = "/media/files/ncs/prototype_targets.txt"
MISSING_TYPES_FILE = "/media/files/ncs/missing_types.txt"
PROGRAM = "/even_1.63/app_update_1.63.bin"
BASE_URL = "http://127.0.0.1:8089"

# C keywords to strip from signatures before sending to Ghidra
C_KEYWORDS = {'static', 'const', 'volatile', 'inline', 'extern', 'struct', 'union',
              'enum', 'ALWAYS_INLINE', '__syscall', 'FUNC_NO_STACK_PROTECTOR',
              'FUNC_NORETURN', '__must_check', 'ZRESTRICT', 'restrict',
              'NRFX_STATIC_INLINE', 'NRFY_STATIC_INLINE', 'NRF_STATIC_INLINE',
              'LC3_HOT'}

# Primitives that don't need validation
PRIMITIVE_TYPES = {'void', 'int', 'char', 'bool', 'float', 'double', 'short', 'long',
                   'unsigned', 'signed', 'uint8_t', 'uint16_t', 'uint32_t', 'uint64_t',
                   'int8_t', 'int16_t', 'int32_t', 'int64_t', 'size_t', 'ssize_t',
                   'uintptr_t', 'intptr_t', 'ptrdiff_t', 'off_t', 'wchar_t',
                   'uint', 'ushort', 'ulong', 'ulonglong', 'longlong',
                   'undefined', 'undefined1', 'undefined2', 'undefined4', 'undefined8',
                   'byte', 'word', 'dword', 'qword', 'pointer'}

# Cache for type validation results
_type_cache = {}


def strip_c_keywords(sig):
    """Strip C keywords from a signature for Ghidra."""
    # Tokenize carefully - don't break apart multi-word identifiers
    result = sig
    for kw in C_KEYWORDS:
        # Word-boundary replacement
        result = re.sub(rf'\b{re.escape(kw)}\b', '', result)
    # Collapse whitespace
    result = re.sub(r'\s+', ' ', result).strip()
    # Clean up artifacts like "* *" -> "**"
    result = re.sub(r'\*\s+\*', '**', result)
    return result


def extract_base_types(sig):
    """Extract base type names from a signature (after stripping keywords)."""
    sig = sig.strip().rstrip(';').strip()

    types = set()

    # Remove the function name and parens structure to get type tokens
    # First strip C keywords
    clean = strip_c_keywords(sig)

    # Find everything before the function name (return type area)
    # and inside the parens (parameter types)
    m = re.match(r'^(.*?)\b(\w+)\s*\((.*)\)$', clean)
    if not m:
        return types

    ret_part = m.group(1).strip()
    params_str = m.group(3).strip()

    # Extract return type
    ret_tokens = ret_part.split()
    for t in ret_tokens:
        clean_t = t.strip('*& ')
        if clean_t and re.match(r'^[a-zA-Z_]\w*$', clean_t):
            types.add(clean_t)

    # Extract param types
    if params_str and params_str != 'void':
        # Split by comma, respecting nested parens
        depth = 0
        current = ''
        params = []
        for ch in params_str:
            if ch == '(': depth += 1; current += ch
            elif ch == ')': depth -= 1; current += ch
            elif ch == ',' and depth == 0:
                params.append(current.strip())
                current = ''
            else: current += ch
        if current.strip():
            params.append(current.strip())

        for p in params:
            if p == '...':
                continue
            tokens = p.split()
            # All tokens except the last (param name) are type tokens
            # But the last could also be a type if there's no name
            for t in tokens[:-1]:
                clean_t = t.strip('*& ')
                if clean_t and re.match(r'^[a-zA-Z_]\w*$', clean_t):
                    types.add(clean_t)
            # If only one token, it's a type
            if len(tokens) == 1:
                clean_t = tokens[0].strip('*& ')
                if clean_t and re.match(r'^[a-zA-Z_]\w*$', clean_t):
                    types.add(clean_t)

    # Remove primitives
    types -= PRIMITIVE_TYPES

    return types


def validate_type_exists(type_name):
    """Check if a type exists in Ghidra using get_type_size. Caches results."""
    if type_name in _type_cache:
        return _type_cache[type_name]

    try:
        encoded = urllib.parse.quote(type_name)
        r = subprocess.run(
            ['bash', '-i', '-c',
             f'ghidraMCP "get_type_size?type_name={encoded}&program={PROGRAM}"'],
            capture_output=True, text=True, timeout=10
        )
        output = r.stdout.strip()
        # get_type_size returns "Type: X\nSize: N bytes\n..." if found
        # or "Data type not found: X" if not found
        exists = 'not found' not in output.lower() and 'Size:' in output
        _type_cache[type_name] = (exists, output)
    except Exception as e:
        _type_cache[type_name] = (False, str(e))

    return _type_cache[type_name]


def build_ghidra_prototype(ghidra_name, true_sig):
    """
    Build the Ghidra prototype string:
    - Strip C keywords (static, const, struct, etc.)
    - Replace the true function name with the Ghidra-prefixed name
    """
    sig = true_sig.strip().rstrip(';').strip()
    sig = strip_c_keywords(sig)

    # Find and replace the function name with the Ghidra name
    # The function name is the last identifier before the opening paren
    m = re.match(r'^(.*?)\b(\w+)\s*(\(.*\))$', sig)
    if not m:
        return None

    ret_type = m.group(1).strip()
    params = m.group(3).strip()

    prototype = f"{ret_type} {ghidra_name}{params}"
    # Clean up double spaces
    prototype = re.sub(r'\s+', ' ', prototype).strip()

    return prototype


def get_calling_convention(ghidra_sig):
    """Extract calling convention from existing Ghidra signature."""
    m = re.search(r'\b(__stdcall|__cdecl|__fastcall|__thiscall)\b', ghidra_sig)
    if m:
        return m.group(1)
    return None


def set_prototype(addr, prototype, calling_convention=None):
    """Set function prototype in Ghidra via POST."""
    data = {
        "function_address": f"0x{addr}",
        "prototype": prototype,
    }
    if calling_convention:
        data["calling_convention"] = calling_convention

    try:
        json_data = json.dumps(data)
        r = subprocess.run(
            ['curl', '-s', '-X', 'POST',
             f'{BASE_URL}/set_function_prototype?program={PROGRAM}',
             '-H', 'Content-Type: application/json',
             '-d', json_data],
            capture_output=True, text=True, timeout=15
        )
        return r.stdout.strip()
    except Exception as e:
        return f"ERROR: {e}"


def verify_prototype(addr, expected_name):
    """Fetch the function back from Ghidra and return its signature."""
    try:
        r = subprocess.run(
            ['bash', '-i', '-c',
             f'ghidraMCP "get_function_by_address?address=0x{addr}&program={PROGRAM}"'],
            capture_output=True, text=True, timeout=10
        )
        output = r.stdout.strip()
        sig_match = re.search(r'Signature:\s*(.+)', output)
        name_match = re.search(r'Function:\s*(.+?)\s+at\s+', output)
        if sig_match and name_match:
            return name_match.group(1).strip(), sig_match.group(1).strip()
    except:
        pass
    return None, None


def main():
    with open(INPUT_FILE) as f:
        lines = f.readlines()

    total = len([l for l in lines if l.strip()])
    print(f"Processing {total} functions...")

    # First pass: validate all types to build the cache and identify missing types early
    print("\n--- Phase 1: Validating types ---")
    missing_types_log = []
    ready_functions = []
    skipped_missing_types = 0

    for i, line in enumerate(lines):
        line = line.strip()
        if not line:
            continue

        parts = [p.strip() for p in line.split('|')]
        if len(parts) < 6:
            continue

        addr, ghidra_name, ghidra_sig = parts[0], parts[1], parts[2]
        true_sig = parts[5]

        # Extract types to validate
        types_needed = extract_base_types(true_sig)

        missing = []
        for t in types_needed:
            exists, response = validate_type_exists(t)
            if not exists:
                missing.append(t)

        if missing:
            missing_types_log.append(f"{ghidra_name} at {addr} | missing: {', '.join(missing)} | true_sig: {true_sig}")
            skipped_missing_types += 1
        else:
            ready_functions.append((addr, ghidra_name, ghidra_sig, true_sig, parts))

        if (i + 1) % 200 == 0:
            print(f"  Type validation progress: {i+1}/{total}")

    # Write missing types log
    with open(MISSING_TYPES_FILE, 'w') as f:
        for entry in missing_types_log:
            f.write(entry + '\n')

    print(f"\nType validation complete:")
    print(f"  Ready to update: {len(ready_functions)}")
    print(f"  Skipped (missing types): {skipped_missing_types}")
    print(f"  Missing types log: {MISSING_TYPES_FILE}")

    # Phase 2: Set prototypes
    print(f"\n--- Phase 2: Setting {len(ready_functions)} prototypes ---")
    success = 0
    failed = []

    for i, (addr, ghidra_name, ghidra_sig, true_sig, parts) in enumerate(ready_functions):
        # Build the Ghidra-ready prototype
        prototype = build_ghidra_prototype(ghidra_name, true_sig)
        if not prototype:
            failed.append(f"{ghidra_name} at {addr} | could not build prototype from: {true_sig}")
            continue

        # Get existing calling convention
        calling_conv = get_calling_convention(ghidra_sig)

        # Set the prototype
        result = set_prototype(addr, prototype, calling_conv)

        if 'error' in result.lower() or 'fail' in result.lower():
            failed.append(f"{ghidra_name} at {addr} | set_prototype failed: {result[:100]} | attempted: {prototype}")
            continue

        # Verify
        verified_name, verified_sig = verify_prototype(addr, ghidra_name)
        if verified_name != ghidra_name:
            failed.append(f"{ghidra_name} at {addr} | verification name mismatch: got {verified_name}")
            continue

        success += 1

        if (i + 1) % 100 == 0:
            print(f"  Progress: {i+1}/{len(ready_functions)} (success: {success}, failed: {len(failed)})")

    print(f"\n--- Results ---")
    print(f"  Successfully updated: {success}")
    print(f"  Failed: {len(failed)}")
    print(f"  Skipped (missing types): {skipped_missing_types}")

    if failed:
        with open('/media/files/ncs/failed_updates.txt', 'w') as f:
            for entry in failed:
                f.write(entry + '\n')
        print(f"  Failed log: /media/files/ncs/failed_updates.txt")
        print("\n  Sample failures:")
        for f_entry in failed[:10]:
            print(f"    {f_entry[:150]}")


if __name__ == '__main__':
    main()
