# Function Prototype Workflow

## Function Signature updates in Ghidra Library

### Goal
Update all function signatures in `even_1.63/app_update_1.63.bin` to match the true Zephyr/NCS source code found in `./v2.5.1/*`.
Example: `z_device_is_ready` which is defined in Ghidra as `int $_z_device_is_ready(int *dev)`.
- True source signature: `bool z_device_is_ready(const struct device *dev)`
- Ghidra prototype after keyword stripping: `bool $_z_device_is_ready(device *dev)`

Note: The true source is the reference for correctness, but C keywords (`const`, `struct`, etc.) are stripped before sending the prototype to Ghidra.

### Steps

1. **List prototype target functions** 
   Build `prototype_targets.txt` in two phases:
   
   **1a.** List all functions using `list_functions_enhanced` (paginate with offset/limit). Filter for functions starting with `$_`, `#_$_`, `#_?_`, or `#_$_?_`. Skip functions that start with only `?_` (no `$_`/`#_` outer prefix).
   ```bash
   bash -i -c 'ghidraMCP "list_functions_enhanced?offset=0&limit=10000&program=/even_1.63/app_update_1.63.bin"'
   ```
   Note: This endpoint returns JSON with `address` and `name` only (no signature).

   **1b.** For each filtered function, fetch its signature using `get_function_by_address`:
   ```bash
   bash -i -c 'ghidraMCP "get_function_by_address?address=0xXXXXXXXX&program=/even_1.63/app_update_1.63.bin"'
   ```
   - Line format should be "Ghidra Address | Ghidra Function Name | Ghidra function signature"

2. **Look up each function in true source**
   For each function in the file, grep for its stripped name in the true source code (`./v2.5.1`), then narrow results to actual C function signatures (declarations or definitions).
   - Some functions like `divide`, `strlen`, `isnanf` match multiple files. Prefer `.h` files over `.c` for declarations.
   - Some function signatures span multiple lines. Check for multi-line signatures when a single-line match looks incomplete (e.g. return type on one line, name+params on the next).
   - If there is ambiguity due to `#ifdef` / `#if defined(...)` macros, cross-reference `project_firmware_configs.md` to determine which macro branch is active for this build.

3. **Append the function signature**
   Append the function signature to its entry in `prototype_targets.txt`.
   - Line format should now be "Ghidra Address | Ghidra Function Name | Ghidra function signature | <path/to/true_source_file>.h:<line_number> | true function name | true function signature"
   - Example: 00053a80 | $_fault_handle | uint __stdcall $_fault_handle(int * esf, int fault, int * recoverable) | /media/files/ncs/v2.5.1/zephyr/arch/arm/core/aarch32/cortex_m/fault.c:842 | fault_handle | static uint32_t fault_handle(z_arch_esf_t *esf, int fault, bool *recoverable);
   - **3a.** If you can't find the function in the true source, mark it with an `*`.

4. **Verify Function Definition**
   - Verify that each "true function signature" in 'prototype_targets.txt' is a C function signature.
   - Repeat Steps 2 and 3 until this step passes.

5. **Filter**
   - **5a.** Move all `*`-marked entries (no source match) to `skipped_functions.txt`.
   - **5b.** Mark functions where the Ghidra signature already matches the true source with `@` and move them to `skipped_functions.txt`.

6. **Verify and re-fetch signatures from Ghidra**
   For each function in `prototype_targets.txt`, re-fetch its current Ghidra-defined signature using ghidraMCP as a pre-modification safety check.
   Use address-based lookup for reliability, but verify the returned function name matches the expected Ghidra name before proceeding:
   ```bash
   bash -i -c 'ghidraMCP "get_function_by_address?address=0xXXXXXXXX&program=/even_1.63/app_update_1.63.bin"'
   ```
   Verify two things before proceeding:
   - The returned function name exactly matches the expected Ghidra name from `prototype_targets.txt`.
   - The stripped name (e.g. `#_$_img_mgmt_state_read` → `img_mgmt_state_read`) perfectly matches the true source function name.
   If either check fails, flag the entry and move it to `skipped_functions.txt` with the reason.

7. **Update function signatures in Ghidra**
   Process each function individually. **NEVER modify the name of a function during this workflow.**

   **7a. Validate types first.**
   Before setting a prototype, check that every type in the true source signature exists in Ghidra (return type + all parameter types).
   Strip qualifiers and indirection to get the base type name for validation (e.g. `const struct smp_streamer *` → validate `smp_streamer`):
   ```bash
   bash -i -c 'ghidraMCP "validate_data_type_exists?type_name=smp_streamer&program=/even_1.63/app_update_1.63.bin"'
   ```
   - If ANY type in the signature is missing from Ghidra, log the missing type(s) and function to `missing_types.txt` and **skip the entire function**. Do not perform partial updates — either the full signature can be set or the function is skipped.

   **7b. Validate the prototype.**
   Before applying, validate the full prototype string:
   ```bash
   bash -i -c 'ghidraMCP "validate_function_prototype?function_address=0xXXXXXXXX&prototype=PROTOTYPE_STRING&program=/even_1.63/app_update_1.63.bin"'
   ```

   **7c. Set the prototype.**
   Using ghidraMCP, update the function signature to match the true source:
   ```bash
   curl -s -X POST "http://127.0.0.1:8089/set_function_prototype?program=/even_1.63/app_update_1.63.bin" \
     -H "Content-Type: application/json" \
     -d '{"function_address":"0xXXXXXXXX","prototype":"PROTOTYPE_STRING"}'
   ```
   The updated prototype must use the existing Ghidra-prefixed function name (e.g. `int #_$_img_mgmt_state_read(smp_streamer *ctxt)`).
   Update both parameter types AND parameter names to match the true source.
   Strip C keywords (`static`, `const`, `struct`, `volatile`, `inline`, etc.) from the prototype before sending to Ghidra — Ghidra does not use these qualifiers.
   Preserve the existing Ghidra calling convention (e.g. `__stdcall`) when setting the prototype.

   **7d. Verify.**
   After setting, fetch the signature back from Ghidra using `get_function_by_address` and confirm it matches.

8. **Final verification pass**
   After all updates in step 7 are complete, make a full pass over all functions:
   - Fetch each function's current Ghidra signature.
   - Compare against the true source signature (where available).
   - Write all functions that still do not match to `remaining_mismatches.txt` with the format:
     ```
     ghidra_name at addr | true_signature | ghidra_current_signature | reason
     ```
   - Reasons may include: missing type, partial update, Ghidra did not accept the prototype, etc.

### Insights

#### Name cleaning for Ghidra function prefixes
Ghidra names use layered prefixes: `$_`, `#_`, `#_$_`, and sometimes `?` for uncertain names. To get the true C function name:
1. Strip leading `#_` and `$_` in any combination (may repeat, e.g. `#_$_` or `$_`)
2. Strip leading `?_` (uncertain name marker)
3. Names like `nano-newlib_` are part of nano-newlib — skip these
4. Names like `$_FUN_0000XXXX` are renamed-but-unidentified stubs — skip these

#### Matching criteria for step 5b
A Ghidra signature "matches" the true source when:
- Return type is the same
- Parameter count is the same
- All parameter types are the same
- Parameter names are the same
`const`, `static`, `struct`, and other C qualifiers/keywords are ignored when comparing. Functions that already match are marked `@` and moved to `skipped_functions.txt`.

#### C keyword stripping for Ghidra prototypes
Before sending a prototype to Ghidra, strip these C keywords from all types:
- `static`, `const`, `volatile`, `inline`, `extern`, `struct`, `union`, `enum`
Example: `static uint32_t fault_handle(const struct z_arch_esf_t *esf, int fault, bool *recoverable)` becomes `uint32_t $_fault_handle(z_arch_esf_t *esf, int fault, bool *recoverable)` for Ghidra.

#### Safety rules
- **NEVER rename a function** during this workflow. Only modify the signature (return type, parameter types, parameter names).
- Use address-based lookup and verify the name matches before modifying.
- No partial updates — if any type in the signature is missing, skip the entire function.
- The stripped Ghidra name must perfectly match the true source function name before any modification.
