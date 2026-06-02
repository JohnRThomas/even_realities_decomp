#!/usr/bin/env python3
"""
Step 8: Final verification pass.
Fetch every function's current Ghidra signature and compare against the true source.
Write mismatches to remaining_mismatches.txt.
"""

import re
import subprocess

TARGETS_FILE = "/media/files/ncs/prototype_targets.txt"
MISSING_TYPES_FILE = "/media/files/ncs/missing_types.txt"
OUTPUT_FILE = "/media/files/ncs/remaining_mismatches.txt"
PROGRAM = "/even_1.63/app_update_1.63.bin"

C_KEYWORDS = {'static', 'const', 'volatile', 'inline', 'extern', 'struct', 'union',
              'enum', 'ALWAYS_INLINE', '__syscall', 'FUNC_NO_STACK_PROTECTOR',
              'FUNC_NORETURN', '__must_check', 'ZRESTRICT', 'restrict',
              'NRFX_STATIC_INLINE', 'NRFY_STATIC_INLINE', 'NRF_STATIC_INLINE', 'LC3_HOT',
              '__STATIC_FORCEINLINE', '__weak', '_ELIDABLE_INLINE', 'register',
              '__restrict'}

# Equivalent type groups — any type in the same group matches any other
_EQUIV_GROUPS = [
    {'ulong', 'unsigned long', 'uint32_t'},
    {'uint', 'unsigned int', 'uint32_t', 'unsigned'},
    {'ushort', 'unsigned short', 'uint16_t'},
    {'uchar', 'unsigned char', 'uint8_t'},
    {'longlong', 'long long', 'int64_t'},
    {'int', 'int32_t', 'signed int'},
    {'short', 'int16_t', 'signed short'},
    {'char', 'signed char', 'int8_t'},
    {'byte', 'uint8_t', 'uchar', 'unsigned char'},
    {'size_t', 'uint', 'uint32_t', 'unsigned int', 'uint_fast32_t'},
    {'ssize_t', 'int', 'int32_t'},
]

# Build lookup: type -> canonical representative (first element of group)
_TYPE_CANONICAL = {}
for group in _EQUIV_GROUPS:
    canon = sorted(group)[0]  # deterministic pick
    for t in group:
        # If already mapped, merge groups by using the existing canonical
        if t in _TYPE_CANONICAL:
            existing_canon = _TYPE_CANONICAL[t]
            if existing_canon != canon:
                # Remap everything pointing to the old canon
                for k, v in list(_TYPE_CANONICAL.items()):
                    if v == canon:
                        _TYPE_CANONICAL[k] = existing_canon
                canon = existing_canon
        _TYPE_CANONICAL[t] = canon


def canonicalize_type(t):
    """Map a type to its canonical form for equivalence comparison."""
    t = t.strip()
    return _TYPE_CANONICAL.get(t, t)


def normalize_pointers(s):
    """Normalize all pointer styles to 'type *name' form."""
    # Ensure space before * and no space after *
    # "uint32_t* pData" -> "uint32_t *pData"
    # "uint32_t * pData" -> "uint32_t *pData"
    # "uint32_t *pData" -> "uint32_t *pData" (already ok)
    # "int**c" -> "int **c"
    s = re.sub(r'\s*\*\s*', ' *', s)  # put space before each *, remove space after
    s = re.sub(r'\s+', ' ', s).strip()
    return s


def strip_for_compare(sig):
    """Strip C keywords, calling conventions, and normalize for comparison."""
    result = sig.strip().rstrip(';').strip()
    for kw in C_KEYWORDS:
        result = re.sub(rf'\b{re.escape(kw)}\b', '', result)
    result = re.sub(r'\b(__stdcall|__cdecl|__fastcall|__thiscall)\b', '', result)
    # Normalize array params to pointers for comparison
    result = re.sub(r'(\w+)\s*\[[^\]]*\]', r' *\1', result)
    # Collapse whitespace
    result = re.sub(r'\s+', ' ', result).strip()
    # Normalize pointer spacing
    result = normalize_pointers(result)
    return result


def strip_ghidra_prefix(name):
    while True:
        if name.startswith('#_'): name = name[2:]
        elif name.startswith('$_'): name = name[2:]
        elif name.startswith('?_'): name = name[2:]
        else: break
    return name


def extract_ret_and_params(sig):
    """Extract return type and param list for comparison."""
    sig = sig.strip().rstrip(';').strip()
    m = re.match(r'^(.*?)\b(\w+)\s*\((.*)\)$', sig)
    if not m:
        return None, None, None
    return m.group(1).strip(), m.group(2), m.group(3).strip()


def normalize_params(params_str):
    """Normalize parameter string for comparison."""
    if not params_str or params_str == 'void':
        return 'void'
    # Split params, normalize each
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

    normalized = []
    for p in params:
        # Normalize spaces around *
        p = re.sub(r'\s*\*\s*', ' *', p).strip()
        p = re.sub(r'\s+', ' ', p)
        normalized.append(p)

    return ', '.join(normalized)


def split_params(params_str):
    """Split parameter string into individual params."""
    if not params_str or params_str == 'void':
        return []
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
    return params


def extract_param_type(param):
    """Extract just the type from a parameter (strip the name)."""
    param = param.strip()
    if param == '...':
        return '...'
    tokens = param.split()
    if len(tokens) <= 1:
        return param.rstrip(' *').strip()
    # Last token is the name (possibly with leading *)
    name_tok = tokens[-1]
    type_toks = tokens[:-1]
    # If name starts with *, the * is part of the type
    stars = ''
    while name_tok.startswith('*'):
        stars += '*'
        name_tok = name_tok[1:]
    type_str = ' '.join(type_toks)
    if stars:
        type_str += ' ' + stars
    return re.sub(r'\s+', ' ', type_str).strip()


def params_equivalent(cp, tp):
    """Check if two parameter strings are equivalent (type match, name ignored)."""
    ct = normalize_pointers(extract_param_type(cp))
    tt = normalize_pointers(extract_param_type(tp))

    if ct == tt:
        return True

    # Check with type canonicalization
    ct_stars = ct.count('*')
    tt_stars = tt.count('*')
    ct_base = ct.replace('*', '').strip()
    tt_base = tt.replace('*', '').strip()

    if ct_stars == tt_stars and canonicalize_type(ct_base) == canonicalize_type(tt_base):
        return True

    # Function pointer params in true sig get simplified to void* in Ghidra.
    # After normalize_pointers, "(*func)" becomes "( *func)", so check both patterns
    # Function pointer or pointer-to-array params in true sig get simplified in Ghidra.
    # "void (*func)(...)" -> "void *func", "int (*c)[16]" -> "int **c"
    has_complex_ptr_in_true = '(*' in tp or '( *' in tp
    if has_complex_ptr_in_true and ct_stars >= 1:
        return True

    # Function pointer typedefs (ending in _t, _cb, _handler) -> void* is acceptable
    if ct.strip() == 'void *' and re.search(r'_t$|_cb$|_handler$|_func$', tt_base):
        return True

    # int (*x)[N] in true sig -> int **x in Ghidra (array-of-pointer simplification)
    # After fix_sig, true has "int **x" and Ghidra has "int * *x" - pointer count matches
    if ct.replace(' ', '') == tt.replace(' ', ''):
        return True

    return False


def main():
    # Load all entries from prototype_targets.txt (the ones we tried to update)
    entries = []
    with open(TARGETS_FILE) as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            parts = [p.strip() for p in line.split('|')]
            if len(parts) >= 6:
                entries.append(parts)

    # Also load missing_types entries
    missing_entries = []
    with open(MISSING_TYPES_FILE) as f:
        for line in f:
            line = line.strip()
            if line:
                missing_entries.append(line)

    total = len(entries)
    print(f"Verifying {total} functions from prototype_targets.txt...")

    matched = 0
    mismatched = []

    for i, parts in enumerate(entries):
        addr, ghidra_name = parts[0], parts[1]
        true_name = parts[4]
        true_sig = parts[5]

        # Fetch current Ghidra signature
        try:
            r = subprocess.run(
                ['bash', '-i', '-c',
                 f'ghidraMCP "get_function_by_address?address=0x{addr}&program={PROGRAM}"'],
                capture_output=True, text=True, timeout=10
            )
            output = r.stdout.strip()
            sig_match = re.search(r'Signature:\s*(.+)', output)
            if not sig_match:
                mismatched.append(f"{ghidra_name} at {addr} | {true_sig} | NO_RESPONSE | fetch failed")
                continue
            current_sig = sig_match.group(1).strip()
        except:
            mismatched.append(f"{ghidra_name} at {addr} | {true_sig} | TIMEOUT | fetch timeout")
            continue

        # Compare: strip keywords and normalize both
        norm_current = strip_for_compare(current_sig)
        norm_true = strip_for_compare(true_sig)

        # Replace ghidra name with true name in current for comparison
        stripped_name = strip_ghidra_prefix(ghidra_name)
        norm_current_compare = norm_current.replace(ghidra_name, stripped_name)

        # Extract and compare components
        curr_ret, curr_func, curr_params = extract_ret_and_params(norm_current_compare)
        true_ret, true_func, true_params = extract_ret_and_params(norm_true)

        if curr_ret is None or true_ret is None:
            mismatched.append(f"{ghidra_name} at {addr} | {true_sig} | {current_sig} | parse error")
            continue

        # Normalize params
        norm_curr_params = normalize_params(curr_params)
        norm_true_params = normalize_params(true_params)

        # Compare return type (with equivalence)
        if canonicalize_type(curr_ret) != canonicalize_type(true_ret):
            curr_ret_base = curr_ret.rstrip(' *').strip()
            true_ret_base = true_ret.rstrip(' *').strip()
            curr_is_ptr = '*' in curr_ret
            true_is_ptr = '*' in true_ret
            # Pointer equivalence: same base type
            if curr_is_ptr and true_is_ptr and canonicalize_type(curr_ret_base) == canonicalize_type(true_ret_base):
                pass  # equivalent
            # Ghidra inferred a more specific pointer for a void* return — acceptable
            elif true_ret.strip() == 'void *' and curr_is_ptr:
                pass  # Ghidra refined void* to a specific type
            else:
                mismatched.append(f"{ghidra_name} at {addr} | {true_sig} | {current_sig} | return type mismatch: '{curr_ret}' vs '{true_ret}'")
                continue

        # Compare params with equivalence
        curr_param_list = split_params(curr_params)
        true_param_list = split_params(true_params)

        if len(curr_param_list) != len(true_param_list):
            mismatched.append(f"{ghidra_name} at {addr} | {true_sig} | {current_sig} | param count mismatch: {len(curr_param_list)} vs {len(true_param_list)}")
            continue

        params_match = True
        for cp, tp in zip(curr_param_list, true_param_list):
            if not params_equivalent(cp, tp):
                params_match = False
                break

        if not params_match:
            mismatched.append(f"{ghidra_name} at {addr} | {true_sig} | {current_sig} | params mismatch")
            continue

        matched += 1

        if (i + 1) % 200 == 0:
            print(f"  Progress: {i+1}/{total} (matched: {matched}, mismatched: {len(mismatched)})")

    print(f"\n--- Final Verification Results ---")
    print(f"Total verified: {total}")
    print(f"Matched: {matched}")
    print(f"Mismatched: {len(mismatched)}")
    print(f"Missing types (not attempted): {len(missing_entries)}")

    # Write mismatches
    with open(OUTPUT_FILE, 'w') as f:
        f.write(f"# Remaining mismatches after prototype update workflow\n")
        f.write(f"# Format: ghidra_name at addr | true_signature | ghidra_current_signature | reason\n\n")

        if mismatched:
            f.write("## Mismatched after update attempt\n")
            for m in mismatched:
                f.write(m + '\n')

        f.write(f"\n## Skipped - missing types ({len(missing_entries)} functions, see missing_types.txt)\n")
        for m in missing_entries:
            f.write(m + '\n')

    print(f"\nWrote {OUTPUT_FILE}")

    if mismatched:
        print("\nSample mismatches:")
        for m in mismatched[:10]:
            print(f"  {m[:150]}")


if __name__ == '__main__':
    main()
