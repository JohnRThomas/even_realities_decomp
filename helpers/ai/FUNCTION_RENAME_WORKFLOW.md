# Function Rename Workflow — app_update_1.63.bin

## Goal
Rename `FUN_*` and `$_FUN_*` functions in `even_1.63/app_update_1.63.bin` using the true Zephyr/NCS source code in `./v2.5.1`.

## Method: String → ASSERT → Source Cross-Reference

### Key Insight
- `$__ASSERT()` calls embed file path strings like:
  ```
  "WEST_TOPDIR/zephyr/subsys/logging/log_output.c"
  ```
  These strings are passed into `$__ASSERT()` and uniquely identify the source file the containing function originated from. Combined with other string arguments (format strings, variable names), we can pinpoint the exact source function.

### Naming Convention
All renamed functions use the prefix: `#_$_<function_name>`
- Example: `FUN_0000e340` → `#_$_log_output_flush`

### Step-by-Step Process

1. **List strings** in the binary (`/list_strings`)
2. **Filter** for assert file-path strings (`.c` paths containing `WEST_TOPDIR` or Zephyr subsystem paths)
3. **For each string**, get all referencing functions (`/get_cross_references` or xref tools)
   - Ignore functions that do NOT start with `FUN_` or `$_FUN_`
4. **Search the true source** in `./v2.5.1` for the string to identify the source file
5. **Identify candidate function names** from the source file around where the string appears
6. **Decompile the function** (`/decompile_function`) and compare to source
7. **Confirm** by checking callers/callees match the call graph in source code
8. **Rename** the function: `POST /rename_function` → `#_$_<source_function_name>`
  - DO NOT RENAME APPLICATION LEVEL functions. They should remain as "FUN_XXXXXX".

### Notes on Compiler Transformations
- Functions may be **inlined**: the assert string appears inside a larger caller — check if the full function body matches a larger source function
- Functions may be **outlined**: compiler extracted a chunk into a new function — name it descriptively (e.g., `#_$_log_output_flush_outlined_0`)
- Multiple functions may reference the same string if the assert is in an inlined helper

### Ghidra HTTP Endpoints Used
- `GET /list_strings` — enumerate binary strings
- `POST /get_cross_references` — find functions referencing a string address
- `POST /decompile_function` — get pseudocode for analysis
- `POST /rename_function` — apply confirmed name
- `POST /get_function_callers` / `get_function_callees` — verify call graph

### Source Tree
- Root: `/media/files/ncs/v2.5.1`
- Key subsystems: `zephyr/subsys/logging/`, `zephyr/kernel/`, `zephyr/lib/`, etc.

## Progress Log
Track renamed functions here as work proceeds.

| Address | Old Name | New Name | Source File |
|---------|----------|----------|-------------|
| (TBD)   |          |          |             |
