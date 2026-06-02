#!/usr/bin/env python3
"""
Fix pass for prototype_targets_updated.txt:
1. Resolve macro-wrapped signatures (CJSON_PUBLIC, FUNC_NORETURN, __STATIC_FORCEINLINE)
2. Re-search functions that got false matches (if-statements, comments, etc.)
3. For common libc functions (strcmp, strlen, memcpy, etc.), use canonical signatures.
"""

import re
import subprocess
import os

SOURCE_DIR = "/media/files/ncs/v2.5.1"
INPUT_FILE = "/media/files/ncs/prototype_targets_updated.txt"
OUTPUT_FILE = "/media/files/ncs/prototype_targets_fixed.txt"

# Known canonical signatures for common libc/compiler functions
# that are hard to grep for because they appear everywhere
CANONICAL_SIGS = {
    'strcmp': 'int strcmp(const char *s1, const char *s2);',
    'strlen': 'size_t strlen(const char *s);',
    'memcpy': 'void *memcpy(void *dst, const void *src, size_t n);',
    'memset': 'void *memset(void *s, int c, size_t n);',
    'strncpy': 'char *strncpy(char *dst, const char *src, size_t n);',
    'snprintk': 'int snprintk(char *str, size_t size, const char *fmt, ...);',
    'printk': 'void printk(const char *fmt, ...);',
    'abort': 'void abort(void);',
}

# Macro expansions for known wrapper macros
MACRO_EXPANSIONS = {
    'CJSON_PUBLIC': lambda inner: inner,  # CJSON_PUBLIC(type) -> type
    'FUNC_NORETURN': lambda sig: sig.replace('FUNC_NORETURN ', ''),
    '__STATIC_FORCEINLINE': lambda sig: sig.replace('__STATIC_FORCEINLINE ', 'static inline '),
}


def resolve_cjson_public(sig):
    """Resolve CJSON_PUBLIC(return_type) func(...) -> return_type func(...)"""
    m = re.match(r'CJSON_PUBLIC\(([^)]+)\)\s*(.*)', sig)
    if m:
        return_type = m.group(1).strip()
        rest = m.group(2).strip()
        return f"{return_type} {rest}"
    return sig


def resolve_macros(sig):
    """Resolve known macros in a signature."""
    if 'CJSON_PUBLIC' in sig:
        sig = resolve_cjson_public(sig)
    if 'FUNC_NORETURN' in sig:
        sig = sig.replace('FUNC_NORETURN ', '')
    if '__STATIC_FORCEINLINE' in sig:
        sig = sig.replace('__STATIC_FORCEINLINE ', 'static inline ')
    return sig


def is_valid_c_signature(sig):
    """Check if a string looks like a valid C function signature."""
    if not sig or sig == '*':
        return False
    # Must have balanced parens
    if sig.count('(') != sig.count(')'):
        return False
    # Must not start with control flow keywords
    if re.match(r'^\s*(if|while|for|switch|return|do|case)\b', sig):
        return False
    # Must not contain common non-signature patterns
    if '==' in sig or '>>' in sig or '<<' in sig or '||' in sig or '&&' in sig:
        return False
    # Must have the pattern: type name(...)
    if not re.search(r'\w+\s*\(.*\)', sig):
        return False
    return True


def find_function_declaration(func_name):
    """
    More targeted search: look specifically for function declarations/definitions.
    Uses a tighter regex that requires a return type before the function name.
    """
    # Search for pattern: word(s) func_name( in .h and .c files
    # Exclude comments, #defines, and string literals
    try:
        result = subprocess.run(
            ['rg', '-n', '--no-heading', '-t', 'c', '-t', 'h',
             rf'^\s*(?:static\s+|inline\s+|extern\s+|const\s+|volatile\s+)*\w[\w\s\*]*\b{re.escape(func_name)}\s*\(',
             SOURCE_DIR],
            capture_output=True, text=True, timeout=30
        )
    except subprocess.TimeoutExpired:
        return None

    if not result.stdout.strip():
        return None

    best = None
    for line in result.stdout.strip().split('\n'):
        match = re.match(r'^(.+?):(\d+):(.+)$', line)
        if not match:
            continue
        filepath, linenum, content = match.group(1), int(match.group(2)), match.group(3).strip()

        # Skip comments and preprocessor
        if content.startswith('//') or content.startswith('/*') or content.startswith('*') or content.startswith('#'):
            continue

        # Try to extract a complete signature
        sig = extract_complete_sig(filepath, linenum, content, func_name)
        if sig and is_valid_c_signature(sig):
            rel_path = filepath
            if filepath.startswith('/media/files/ncs/'):
                rel_path = filepath[len('/media/files/ncs/'):]
            # Prefer .h over .c
            score = 0 if filepath.endswith('.h') else 1
            if best is None or score < best[0]:
                best = (score, rel_path, linenum, sig)

    if best:
        return (best[1], best[2], best[3])
    return None


_line_cache = {}

def read_line(filepath, linenum):
    """Read a specific line from a file (1-indexed)."""
    if filepath not in _line_cache:
        try:
            with open(filepath, 'r', errors='replace') as f:
                _line_cache[filepath] = f.readlines()
        except:
            return None
    lines = _line_cache[filepath]
    if 1 <= linenum <= len(lines):
        return lines[linenum - 1]
    return None


def extract_complete_sig(filepath, linenum, content, func_name):
    """Extract a complete function signature, handling multi-line."""
    full_text = content.strip()

    # Count parens
    paren_depth = 0
    found_open = False
    for ch in full_text:
        if ch == '(':
            paren_depth += 1
            found_open = True
        elif ch == ')':
            paren_depth -= 1

    # Read more lines if parens aren't balanced
    if paren_depth > 0:
        for i in range(1, 20):
            next_line = read_line(filepath, linenum + i)
            if next_line is None:
                break
            next_stripped = next_line.strip()
            # Stop if we hit a line that's clearly not part of the signature
            if next_stripped.startswith('#') or next_stripped.startswith('//'):
                break
            full_text += ' ' + next_stripped
            for ch in next_stripped:
                if ch == '(':
                    paren_depth += 1
                elif ch == ')':
                    paren_depth -= 1
            if paren_depth <= 0:
                break

    if paren_depth != 0:
        return None

    # Extract up to closing paren of the function signature
    sig_match = re.search(rf'^(.*?\b{re.escape(func_name)}\s*\()', full_text)
    if not sig_match:
        return None

    open_pos = sig_match.end() - 1
    depth = 1
    pos = open_pos + 1
    while pos < len(full_text) and depth > 0:
        if full_text[pos] == '(':
            depth += 1
        elif full_text[pos] == ')':
            depth -= 1
        pos += 1

    if depth != 0:
        return None

    sig = full_text[:pos].strip()
    sig = re.sub(r'\s*\{.*$', '', sig)
    sig = re.sub(r'\s+', ' ', sig).strip()

    if not sig.endswith(';'):
        sig += ';'

    return sig


def strip_ghidra_prefix(name):
    """Strip #_, $_, ?_ prefixes."""
    while True:
        if name.startswith('#_'):
            name = name[2:]
        elif name.startswith('$_'):
            name = name[2:]
        elif name.startswith('?_'):
            name = name[2:]
        else:
            break
    return name


def main():
    with open(INPUT_FILE, 'r') as f:
        lines = f.readlines()

    fixed = 0
    still_bad = 0
    output_lines = []

    for line in lines:
        line = line.strip()
        if not line:
            continue

        parts = [p.strip() for p in line.split('|')]
        if len(parts) < 6:
            output_lines.append(line)
            continue

        addr, ghidra_name, ghidra_sig = parts[0], parts[1], parts[2]
        source_loc, true_name, true_sig = parts[3], parts[4], parts[5]

        # Skip already-missing entries
        if source_loc == '*' and true_sig == '*':
            output_lines.append(line)
            continue

        needs_fix = False

        # Check if signature has known macros
        if any(m in true_sig for m in ['CJSON_PUBLIC', 'FUNC_NORETURN', '__STATIC_FORCEINLINE']):
            true_sig = resolve_macros(true_sig)
            needs_fix = True

        # Check if signature is invalid
        if not is_valid_c_signature(true_sig):
            needs_fix = True
            true_sig = None  # force re-lookup

        if needs_fix:
            if true_sig and is_valid_c_signature(true_sig):
                # Macro resolution was enough
                output_lines.append(f"{addr} | {ghidra_name} | {ghidra_sig} | {source_loc} | {true_name} | {true_sig}")
                fixed += 1
            else:
                # Check canonical signatures first
                clean_name = strip_ghidra_prefix(ghidra_name)
                if clean_name in CANONICAL_SIGS:
                    canon_sig = CANONICAL_SIGS[clean_name]
                    output_lines.append(f"{addr} | {ghidra_name} | {ghidra_sig} | canonical | {clean_name} | {canon_sig}")
                    fixed += 1
                else:
                    # Re-search with tighter regex
                    result = find_function_declaration(clean_name)
                    if result:
                        rel_path, linenum, sig = result
                        resolved_sig = resolve_macros(sig)
                        if is_valid_c_signature(resolved_sig):
                            output_lines.append(f"{addr} | {ghidra_name} | {ghidra_sig} | {rel_path}:{linenum} | {clean_name} | {resolved_sig}")
                            fixed += 1
                        else:
                            # Still bad, mark as missing
                            output_lines.append(f"{addr} | {ghidra_name} | {ghidra_sig} | * | {clean_name} | *")
                            still_bad += 1
                    else:
                        output_lines.append(f"{addr} | {ghidra_name} | {ghidra_sig} | * | {clean_name} | *")
                        still_bad += 1
        else:
            output_lines.append(line)

    with open(OUTPUT_FILE, 'w') as f:
        for ol in output_lines:
            f.write(ol + '\n')

    print(f"Fixed: {fixed}, Still bad: {still_bad}")
    print(f"Output: {OUTPUT_FILE}")

    # Final count
    total = len(output_lines)
    found = sum(1 for l in output_lines if '| * |' not in l)
    missing = total - found
    print(f"Total: {total}, Found: {found}, Missing: {missing}")


if __name__ == '__main__':
    main()
