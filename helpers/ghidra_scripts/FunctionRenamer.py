#@runtime Jython
#@author
#@category EvenG1Helpers
#@keybinding
#@menupath
#@toolbar

# Rename functions based on debug prints of the form:
#   printk("%s(): ...", "function_name")

import re

# Check if we're running in Ghidra
try:
    from ghidra.program.model.symbol import SourceType
    from ghidra.program.model.address import Address
    from ghidra.program.model.listing import Function
    from ghidra.util.exception import DuplicateNameException
    GHIDRA_AVAILABLE = True
except ImportError:
    GHIDRA_AVAILABLE = False
    print("Ghidra environment not available. This script must be run from within Ghidra.")
    print("Please use one of these methods:")
    print("1. Window -> Script Manager -> Add Script -> Browse to this file -> Run")
    print("2. Analysis -> One Shot -> Run Script -> Browse to this file -> Run")

# PATTERN_BYTES = b"%s():"
# PATTERN_BYTES = b"[%s-%d]"
# PATTERN_BYTES = b"%s para"
# PATTERN_BYTES = b" para is "
PATTERN_BYTES = b"message queue send"

OTHER_STR_MAX_WINDOW_INSNS = 16          # scan  instructions around the reference
ALLOW_RENAME_IF_USER_DEFINED = False     # set True to force-rename even user-defined names

def is_default_like(name):
    # Heuristics for default/auto names across archs/loaders
    lower = name.lower()
    return (lower.startswith("fun_") or lower.startswith("sub_") or
            lower.startswith("lab_") or lower.startswith("thunk_") or
            lower.startswith("entry") or lower.startswith("undefined") or
            lower.startswith("nullsub_"))

def sanitize_to_symbol(s):
    # keep alnum and underscore; replace others with '_'
    s = s.strip()
    if not s:
        return None
    s = re.sub(r"[^0-9a-zA-Z_]", "_", s)
    # symbols can't start with a digit
    if re.match(r"^\d", s):
        s = "_" + s
    # squeeze multiple underscores
    s = re.sub(r"_+", "_", s)
    return s

def find_all(sub_bytes, mem, start_addr, monitor):
    """Yield every Address where sub_bytes occurs in memory (forward)."""
    addr = start_addr
    while not monitor.isCancelled():
        hit = mem.findBytes(addr, sub_bytes, None, True, monitor)
        if hit is None:
            break
        yield hit
        # advance 1 byte to look for next match
        try:
            addr = hit.add(1)
        except:
            break

def is_string_data(data):
    if data is None:
        return False
    try:
        dtname = (data.getDataType().getName() or "").lower()
        if "string" in dtname or "unicode" in dtname:
            return True
        # Fallback: many string data types still produce a Java String value
        val = data.getValue()
        return isinstance(val, basestring) if 'basestring' in globals() else isinstance(val, str)
    except:
        return False

def data_as_python_string(data):
    try:
        val = data.getValue()
        if val is None:
            # Fallback to default rendering
            val = data.getDefaultValueRepresentation()
        # Convert Java String to Python str
        return str(val)
    except:
        return None

def iter_window_instructions(listing, func_body, center_addr, back=8, forward=8):
    """Iterate instructions around center_addr within the same function body."""
    inst_at = listing.getInstructionAt(center_addr)
    if inst_at is None:
        inst_at = listing.getInstructionAfter(center_addr)
    if inst_at is None:
        inst_at = listing.getInstructionBefore(center_addr)
    if inst_at is None:
        return

    # Collect backward
    back_list = []
    cur = inst_at
    for _ in range(back):
        cur = listing.getInstructionBefore(cur.getAddress())
        if cur is None or not func_body.contains(cur.getAddress()):
            break
        back_list.append(cur)
    back_list.reverse()

    # Center + forward
    forward_list = [inst_at]
    cur = inst_at
    for _ in range(forward):
        cur = listing.getInstructionAfter(cur.getAddress())
        if cur is None or not func_body.contains(cur.getAddress()):
            break
        forward_list.append(cur)

    for ins in back_list + forward_list:
        yield ins

def other_string_nearby(listing, fmt_ref_from_addr, fmt_str_addr, func):
    """
    Look +/-N instructions around the instruction that referenced the "%s():" string.
    Return the contents of another string literal used nearby (not the same address).
    """
    body = func.getBody()
    for ins in iter_window_instructions(listing, body, fmt_ref_from_addr,
                                        back=OTHER_STR_MAX_WINDOW_INSNS,
                                        forward=OTHER_STR_MAX_WINDOW_INSNS):
        # Look at references FROM this instruction; any to strings?
        refs = ins.getReferencesFrom()
        for r in refs:
            to = r.getToAddress()
            if to is None or to == fmt_str_addr:
                continue
            data = listing.getDataContaining(to)
            if not is_string_data(data):
                continue
            s = data_as_python_string(data)
            if not s:
                continue
            # Ignore format-like strings and the "%s():" one
            if "%" in s or "#" in s or "@" in s:
                continue
            # Prefer short, identifier-ish strings
            return s
    return None

# Main execution - flat script style
if GHIDRA_AVAILABLE:
    # Get the current program and monitor from Ghidra environment
    program = currentProgram
    monitor = getMonitor()

    if program is None:
        printerr("No program open. Run this from CodeBrowser.")
        printerr("Debug info:")
        printerr("  - currentProgram is None")
        printerr("  - Make sure you have a binary loaded in Ghidra")
        printerr("  - Try running from Script Manager instead")
    else:
        println("Script execution started")
        println("Program loaded successfully: " + str(program.getName()))

        listing = program.getListing()
        mem = program.getMemory()

        scope = currentSelection if currentSelection else program.getMemory().getAllInitializedAddressSet()
        start_addr = scope.getMinAddress()

        tx = program.startTransaction("Rename from printk prints")
        renamed, skipped, errors = 0, 0, 0
        seen_funcs = set()

        try:
            for hit in find_all(PATTERN_BYTES, mem, start_addr, monitor):
                if not scope.contains(hit):
                    continue

                str_data = listing.getDataContaining(hit)
                if not is_string_data(str_data):
                    # Not a defined string; skip (we could define it, but keep script safe)
                    continue

                # Find where this string is referenced from (push/ldr etc.)
                refs_to = program.getReferenceManager().getReferencesTo(str_data.getMinAddress())
                for ref in refs_to:
                    if monitor.isCancelled():
                        break

                    from_addr = ref.getFromAddress()
                    func = listing.getFunctionContaining(from_addr)
                    if func is None:
                        continue

                    fid = (func.getEntryPoint(), func.getName())
                    if fid in seen_funcs:
                        continue


                    # print(str_data)
                    # name_candidate = data_as_python_string(str_data).split(' ')[0]
                    name_candidate = other_string_nearby(listing, from_addr, str_data.getMinAddress(), func)
                    if not name_candidate:
                        skipped += 1
                        continue

                    # if "%s" in name_candidate:
                    #     skipped += 1
                    #     continue

                    new_name = sanitize_to_symbol(name_candidate)
                    if not new_name:
                        skipped += 1
                        continue

                    # Respect user-defined names unless override enabled
                    cur_name = func.getName()
                    src = func.getSymbol().getSource()
                    if (src == SourceType.USER_DEFINED and not ALLOW_RENAME_IF_USER_DEFINED) and not is_default_like(cur_name):
                        if new_name != cur_name:
                          println("Skipped: {} already has name {}".format(new_name, cur_name))
                        skipped += 1
                        seen_funcs.add(fid)
                        continue

                    # Avoid collisions by suffixing
                    final_name = new_name
                    i = 1
                    while True:
                        try:
                            # func.setName(final_name, SourceType.USER_DEFINED)
                            println("Renamed {} @ {} -> {}".format(cur_name, func.getEntryPoint(), final_name))
                            renamed += 1
                            break
                        except DuplicateNameException:
                            i += 1
                            final_name = "{}_{}".format(new_name, i)
                        except Exception as e:
                            printerr("Failed to rename {} @ {}: {}".format(cur_name, func.getEntryPoint(), e))
                            errors += 1
                            break

                    seen_funcs.add((func.getEntryPoint(), func.getName()))
        finally:
            program.endTransaction(tx, True)

        println("Done. Renamed: {}, Skipped: {}, Errors: {}".format(renamed, skipped, errors))
else:
    print("Script cannot run outside of Ghidra environment.")
