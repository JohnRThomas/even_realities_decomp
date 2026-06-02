#!/usr/bin/env python3
"""
Step 2-3: Look up each function from prototype_targets.txt in the true source code (./v2.5.1).
Appends the true source file, function name, and signature to each line.
Marks functions not found with '*'.
"""

import re
import subprocess
import os

SOURCE_DIR = "/media/files/ncs/v2.5.1"
INPUT_FILE = "/media/files/ncs/prototype_targets.txt"
OUTPUT_FILE = "/media/files/ncs/prototype_targets_updated.txt"

# C type keywords that can appear before a function name
C_RETURN_TYPES = r'(?:(?:static|inline|const|volatile|extern|unsigned|signed|short|long|void|int|char|bool|float|double|uint\d+_t|int\d+_t|size_t|ssize_t|off_t|enum|struct|union|__attribute__\s*\([^)]*\))\s+)*'

def strip_ghidra_prefix(name):
    """Strip #_, $_, ?_ prefixes in any combination to get the true C name."""
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


def find_function_in_source(func_name):
    """
    Grep for func_name in source, then identify actual C function signatures.
    Returns list of (filepath, line_number, signature) tuples.
    """
    # Use ripgrep to find all lines containing the function name in .c and .h files
    try:
        result = subprocess.run(
            ['rg', '-n', '--no-heading', '-t', 'c', '-t', 'h',
             rf'\b{re.escape(func_name)}\b', SOURCE_DIR],
            capture_output=True, text=True, timeout=30
        )
    except subprocess.TimeoutExpired:
        return []

    if not result.stdout.strip():
        return []

    candidates = []
    lines_by_file = {}

    # Group results by file
    for line in result.stdout.strip().split('\n'):
        # Format: /path/to/file:linenum:content
        match = re.match(r'^(.+?):(\d+):(.+)$', line)
        if not match:
            continue
        filepath, linenum, content = match.group(1), int(match.group(2)), match.group(3)
        if filepath not in lines_by_file:
            lines_by_file[filepath] = []
        lines_by_file[filepath].append((linenum, content))

    for filepath, file_lines in lines_by_file.items():
        for linenum, content in file_lines:
            # Check if this line looks like a function signature/definition
            # Pattern: optional qualifiers, return type, function_name, opening paren
            sig = try_extract_signature(filepath, linenum, content, func_name)
            if sig:
                candidates.append((filepath, linenum, sig))

    # Sort: prefer .h over .c, then by path length (shorter = more canonical)
    def sort_key(c):
        is_header = 1 if c[0].endswith('.h') else 2
        return (is_header, len(c[0]))

    candidates.sort(key=sort_key)
    return candidates


def try_extract_signature(filepath, linenum, content, func_name):
    """
    Try to extract a full C function signature from the given line.
    Handles multi-line signatures by reading subsequent lines if needed.
    """
    content = content.strip()

    # Skip if this is inside a comment, #define, or string
    if content.startswith('//') or content.startswith('/*') or content.startswith('*'):
        return None
    if content.startswith('#'):
        return None

    # Check if func_name appears as part of an actual function signature pattern
    # Look for: [qualifiers] return_type func_name(
    # The func_name should be followed by ( possibly with spaces
    pattern = rf'\b{re.escape(func_name)}\s*\('
    if not re.search(pattern, content):
        return None

    # Skip if it's a function CALL (no return type before the name)
    # A function definition/declaration has a type before the name
    before_name = content[:content.index(func_name)].strip()

    # If nothing before the name or it's just whitespace, check if the return type
    # is on the previous line (multi-line signature)
    if not before_name:
        # Could be multi-line with return type on previous line
        prev_content = read_line(filepath, linenum - 1) if linenum > 1 else None
        if prev_content:
            prev_stripped = prev_content.strip()
            # Check if previous line ends with a type-like token
            if prev_stripped and not prev_stripped.startswith('#') and not prev_stripped.startswith('//'):
                # Combine and retry
                combined = prev_stripped + ' ' + content
                return try_extract_from_combined(combined, func_name)
        return None

    # Verify there's a return type before the function name
    # Simple heuristic: should contain at least one word that looks like a type
    type_words = re.findall(r'\b\w+\b', before_name)
    if not type_words:
        return None

    # Known non-type words that indicate this is NOT a signature
    non_type_indicators = {'if', 'while', 'for', 'switch', 'return', 'case', 'sizeof', 'typeof', '=', 'goto'}
    if any(w in non_type_indicators for w in type_words):
        return None

    # Now extract the full signature including parameters
    return extract_full_sig(filepath, linenum, content, func_name)


def extract_full_sig(filepath, linenum, content, func_name):
    """Extract the complete function signature, handling multi-line params."""
    # Find the opening paren
    full_text = content.strip()

    # Count parens to find the closing one
    paren_depth = 0
    found_open = False
    for ch in full_text:
        if ch == '(':
            paren_depth += 1
            found_open = True
        elif ch == ')':
            paren_depth -= 1
            if found_open and paren_depth == 0:
                break

    # If parens aren't balanced, read more lines
    if paren_depth > 0:
        max_extra_lines = 15
        for i in range(1, max_extra_lines + 1):
            next_line = read_line(filepath, linenum + i)
            if next_line is None:
                break
            full_text += ' ' + next_line.strip()
            for ch in next_line:
                if ch == '(':
                    paren_depth += 1
                elif ch == ')':
                    paren_depth -= 1
                    if paren_depth == 0:
                        break
            if paren_depth == 0:
                break

    if paren_depth != 0:
        return None

    # Extract up to and including the closing paren
    # Find the position of the function name and its matching close paren
    sig_match = re.search(
        rf'^(.*?\b{re.escape(func_name)}\s*\()',
        full_text
    )
    if not sig_match:
        return None

    start = 0  # start of signature (include return type)
    # Find the closing paren after the opening one
    open_pos = sig_match.end() - 1  # position of (
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

    sig = full_text[start:pos].strip()

    # Clean up: remove { and anything after, add ; if it's a declaration
    sig = re.sub(r'\s*\{.*$', '', sig)
    # Collapse whitespace
    sig = re.sub(r'\s+', ' ', sig).strip()

    # Final validation: should look like "type name(params)"
    if not re.search(rf'\b{re.escape(func_name)}\s*\(.*\)', sig):
        return None

    return sig + ';'


def try_extract_from_combined(combined, func_name):
    """Try to extract signature from combined (multi-line) text."""
    combined = re.sub(r'\s+', ' ', combined).strip()
    pattern = rf'\b{re.escape(func_name)}\s*\('
    if not re.search(pattern, combined):
        return None

    before_name = combined[:combined.index(func_name)].strip()
    type_words = re.findall(r'\b\w+\b', before_name)
    if not type_words:
        return None

    # Extract sig from combined
    sig_match = re.search(rf'^(.*?\b{re.escape(func_name)}\s*\(.*?\))', combined)
    if sig_match:
        sig = sig_match.group(1).strip()
        sig = re.sub(r'\s*\{.*$', '', sig)
        sig = re.sub(r'\s+', ' ', sig).strip()
        return sig + ';'
    return None


_line_cache = {}

def read_line(filepath, linenum):
    """Read a specific line from a file (1-indexed). Caches files."""
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


def main():
    with open(INPUT_FILE, 'r') as f:
        lines = f.readlines()

    total = len(lines)
    found = 0
    not_found = 0
    output_lines = []

    for i, line in enumerate(lines):
        line = line.strip()
        if not line:
            continue

        parts = [p.strip() for p in line.split('|')]
        if len(parts) < 3:
            output_lines.append(line + ' | * | * | *')
            not_found += 1
            continue

        addr, ghidra_name, ghidra_sig = parts[0], parts[1], parts[2]
        true_name = strip_ghidra_prefix(ghidra_name)

        candidates = find_function_in_source(true_name)

        if candidates:
            filepath, linenum, sig = candidates[0]
            # Make path relative for readability
            rel_path = filepath
            if filepath.startswith('/media/files/ncs/'):
                rel_path = filepath[len('/media/files/ncs/'):]
            output_lines.append(f"{addr} | {ghidra_name} | {ghidra_sig} | {rel_path}:{linenum} | {true_name} | {sig}")
            found += 1
        else:
            output_lines.append(f"{addr} | {ghidra_name} | {ghidra_sig} | * | {true_name} | *")
            not_found += 1

        if (i + 1) % 200 == 0:
            print(f"  Progress: {i+1}/{total} (found: {found}, missing: {not_found})")

    with open(OUTPUT_FILE, 'w') as f:
        for ol in output_lines:
            f.write(ol + '\n')

    print(f"\nDone. Total: {total}, Found: {found}, Missing: {not_found}")
    print(f"Output written to {OUTPUT_FILE}")


if __name__ == '__main__':
    main()
