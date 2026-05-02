# Function Rename Workflow Plan

## Context

We have 615 unnamed `FUN_*` functions (+ 79 `$_FUN_*`) in the Ghidra project for `even_1.63/app_update_1.63.bin` (ARM LE 32-bit, nRF5340, Zephyr/NCS v2.5.1). About 1,700 functions are already renamed with `$_` or `#_$_` prefixes. The goal is to identify and rename as many remaining `FUN_*` functions as possible using the true source at `./v2.5.1`.

**Constraints:**
- Application-level functions (Even Realities G1 app code) stay as `FUN_*` — do NOT rename
- Only SDK/library functions found in the v2.5.1 source tree get renamed
- Naming convention: `#_$_<source_function_name>`
- Never rename already-named functions (unless `$_FUN_*`)
- API: `POST /rename_function_by_address` with `{"function_address":"0x...","new_name":"#_$_<name>"}`
- All function names MUST be sourced from the true source.

## Approach — 5 Phases, executed in order

### Phase 0: Enumerate and Index

1. **List all functions** via `list_functions_enhanced`, partition into:
   - `rename_targets.txt` — `FUN_*` and `$_FUN_*` (694 functions)
   - Already-named (skip)

2. **Build analysis index** — For each target, call `analyze_function_complete?name=FUN_XXXX` and store:
   - address, callers, callees, string refs, param count
   - Output: `fun_analysis_index.json`

3. **Address range classification** 
   — Flag functions in 0x80000+ region as likely application code
   — Check RENAME_PROGRESS.md for any matching taged regions

**Files:** `rename_targets.txt`, `fun_analysis_index.json`

### Phase 1: WEST_TOPDIR String Cross-References (highest confidence, ~50-100 functions)

88 `WEST_TOPDIR` strings in the binary directly identify source files. Any `FUN_*` referencing one is provably from that file.

1. `search_strings?query=WEST_TOPDIR` → get all 88 string addresses
2. For each string, `get_xrefs_to?address=0x...` → find `FUN_*` functions referencing it
3. Strip `WEST_TOPDIR/` prefix → resolve to path under `./v2.5.1/`
4. For each (`source_file`, `FUN_*` list) pair:
   - Read the source file, extract all function definitions
   - Decompile the `FUN_*` and compare: param count, callees, string constants, control flow
   - Rank candidates by match quality
5. **Verify:** decompiled structure matches, callee names match, no better candidate
6. **Rename** confirmed matches

**Note:** Compiler cold paths (outlined assert blocks) reference WEST_TOPDIR strings but aren't standalone functions. Name as `#_$_<parent>_assert` or skip.

### Phase 2: Named-Neighbor Call Graph Walking (medium-high confidence, ~100-200 functions)

With ~1,700 named functions, many `FUN_*` are one hop away from a known function.

1. From `fun_analysis_index.json`, find `FUN_*` with at least one named caller or callee (the "frontier")
2. Sort by named-neighbor count descending
3. For each frontier function:
   - Look up source files of named callees/callers
   - Search those files for functions matching the decompiled structure
   - Cross-check: param count, callees, string constants
4. **Iterative:** After renaming a batch, re-run — newly named functions create new frontier nodes
5. Run 2-3 rounds until no more progress

### Phase 3: String Constant Matching (medium confidence, ~30-80 functions)

Many SDK functions embed unique strings (log messages, `__func__` names, error strings).

1. From `fun_analysis_index.json`, collect string refs for each unidentified `FUN_*`
2. **`__func__` strings:** Zephyr LOG macros embed function names. Search binary strings for known SDK function names, get xrefs back to `FUN_*`
3. **Unique error/debug strings:** Grep the string in `./v2.5.1/` to pinpoint the source function
4. **Verify:** decompiled code structure matches the identified source function

### Phase 4: Driver API / Function Pointer Tables (high confidence, ~20-40 functions)

Zephyr device drivers use API structs with function pointers (`gpio_driver_api`, `flash_driver_api`, `uart_driver_api`, `sensor_driver_api`, etc.).

1. For each known API struct type, find an already-named implementation function
2. Use `get_xrefs_to` on that function → find the data address holding the API struct
3. Read adjacent memory to extract all function pointers from the struct
4. Map each pointer to its field position (from the source struct definition)
5. Rename any `FUN_*` found at known field positions

### Phase 5: Residual Classification

After Phases 1-4, categorize what's left:
- **Application code** (0x80000+ region, calls app globals) → leave as `FUN_*`
- **Unidentifiable** (heavy optimization, proprietary blobs) → leave as `FUN_*`, document why

## Verification

After each phase:
1. Re-fetch `list_functions`, confirm `FUN_*` count decreased by expected amount
2. For each rename, `get_function_by_address` → confirm name matches
3. Update `RENAME_PROGRESS.md` with counts and methods used

## Tracking

Master log: `RENAME_PROGRESS.md`
```
address | old_name | new_name | source_file | method | confidence | notes
```

## Safety Rules (from RENAME_PROGRESS.md)

1. Never rename already-named functions (unless `$_FUN_*`)
2. Never rename application-level functions — stay as `FUN_*`
3. Always verify before renaming (no blind batch renames)
4. Use `#_$_` prefix for all SDK/library renames
5. Log everything — every rename, skip, and failure
6. **All names MUST come from the true source code.** Never invent descriptive names like `*_helper`, `*_sub_XXXX`, `*_wrapper`, `sdk_func_*`, or `*_internal`. If the true source name cannot be found, leave the function as `FUN_*`.

## Verification Rules (mandatory before every rename)

Every rename MUST pass ALL of the following checks. No exceptions.

1. **Decompile the function** in Ghidra and read the actual code.
2. **Find the candidate source function** in `./v2.5.1` and read its actual code.
3. **Compare the two side-by-side:**
   - Parameter count must match (accounting for compiler optimizations that may merge/split params)
   - Return type must be compatible
   - The operations performed must match (not just "calls similar functions" — the actual logic must correspond)
   - Constants, struct field offsets, and control flow must be consistent
4. **Never name a function based solely on its caller or callee.** "Called by X" or "calls Y" is a hint for where to search, NOT evidence of identity. Many unrelated functions call the same SDK APIs.
5. **Never name a function based on a pattern match against unrelated source files.** A function in `gatt.c` that calls `memcpy` is not the same as a function in `l2cap.c` that also calls `memcpy`.
6. **If the source function is `static`, verify it lives in the same compilation unit** as the caller/callee context suggests. Static functions from wrong files are false positives.
7. **If uncertain, leave as `FUN_*`.** A wrong name is worse than no name — it actively misleads analysis.

## Key Files

- `/media/files/ncs/RENAME_PROGRESS.md` — existing progress, API patterns, insights
- `/media/files/ncs/FUNCTION_RENAME_WORKFLOW.md` — existing methodology
- `/media/files/ncs/v2.5.1/` — true source tree
- `/media/files/ncs/configs` — active Kconfig macros for disambiguation
- `/media/files/ncs/lookup_functions.py` — reusable `find_function_in_source()` utility
