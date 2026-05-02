# Function Rename Progress — app_update_1.63.bin

## Status
- **Binary**: `/even_1.63/app_update_1.63.bin` (ARM LE 32-bit, 2805 functions)
- **Named functions**: 2322 / 2805 (82.7%)
- **Unnamed FUN_* count**: 483 (+ 0 $_FUN_*) = 483 total unnamed
  - SDK region (<0x80000): 326 unnamed
  - App region (>=0x80000): 157 unnamed (application code, do not rename)
- **Source tree**: `/media/files/ncs/v2.5.1`
- **Naming convention**: `#_$_<source_function_name>`
- **Last updated**: 2026-04-04 (continuation 8 — function discovery workflow: 202 functions renamed, 1453 prototypes updated)

## Workflow Summary
See `RENAME_WORKFLOW.md` for full methodology.

Short version:
1. Find FUN_* callers of `$__ASSERT` (embedded source file path strings identify the originating .c file)
2. Get xrefs to each WEST_TOPDIR .c string → find which FUN_* functions reference them
3. Decompile function → search source in v2.5.1 → compare + confirm via callers/callees
4. Rename via `POST /rename_function` → `#_$_<name>`

### API — use `ghidraMCP` bash function:
```bash
# ghidraMCP is: curl -s "http://127.0.0.1:8089/${@:1}"
# Must be called from interactive shell: bash -i -c '...'

# GET requests:
bash -i -c 'ghidraMCP "decompile_function?address=0x00051734&program=/even_1.63/app_update_1.63.bin"'
bash -i -c 'ghidraMCP "get_function_callees?name=FUN_00051734&program=/even_1.63/app_update_1.63.bin"'
bash -i -c 'ghidraMCP "get_function_callers?name=FUN_00051734&program=/even_1.63/app_update_1.63.bin"'
bash -i -c 'ghidraMCP "read_memory?address=0x000f0577&length=128&program=/even_1.63/app_update_1.63.bin"'
bash -i -c 'ghidraMCP "get_function_by_address?address=0x00054f14&program=/even_1.63/app_update_1.63.bin"'

# POST rename — use rename_function_by_address with JSON body:
curl -s -X POST "http://127.0.0.1:8089/rename_function_by_address" \
  -H "Content-Type: application/json" \
  -d '{"function_address":"0xXXXXXXXX","new_name":"#_$_<name>"}'
# NOTE: rename_function uses {"oldName":"...","newName":"..."} (camelCase) but requires knowing old name
# rename_function_by_address uses {"function_address":"0x...","new_name":"..."} — preferred

# Read LE32 pointer at a data address:
bash -i -c 'ghidraMCP "read_memory?address=0x00054f04&length=4&program=/even_1.63/app_update_1.63.bin"' \
  | python3 -c "import sys,json; d=json.loads(sys.stdin.read()); b=d['data']; ptr=b[0]|b[1]<<8|b[2]<<16|b[3]<<24; print(hex(ptr))"

# Read string at pointer:
bash -i -c 'ghidraMCP "read_memory?address=0x000f0577&length=128&program=/even_1.63/app_update_1.63.bin"' \
  | python3 -c "import sys,json; d=json.loads(sys.stdin.read()); bs=bytes(d['data']); print(bs.split(b'\x00')[0].decode('ascii','replace'))"
```

**Key gotchas:**
- `decompile_function` requires `address=0x...` (not `name=`)
- `get_function_callees` / `get_function_callers` require `name=` (not `address=`)
- `rename_function` POST body uses `oldName` / `newName` (camelCase)
- `get_function_callers?name=` needs the `$_` prefix in the name for already-named functions — escape if needed, or use curl directly
- Assert file:line points to the INLINE FUNCTION, not the calling function. A cold path (out-of-line assert block) may be listed as a separate FUN_* if it's the target of a CALL instruction.
- I should not rename application level functions. They should remain as "FUN_XXXXXX". The "#_$_" prefix is reserved for zephyr and nrf sdk functions.
- If I find a function that is named incorrectly or is application code, I should bookmark it with a note of what I think it should be.
  - I should never rename function that is already named unless it starts with "$_FUN_".
- Any functions that exist within the current code base are considered SDK functions, I can rename those functions.

---

## FUN_* Callers of $__ASSERT (all 8 completed)

| Address  | Current Name                              | Source / Notes                              | Status |
|----------|-------------------------------------------|---------------------------------------------|--------|
| 0004ef2c | #_$_mpsc_pbuf_alloc                       | zephyr/lib/os/mpsc_pbuf.c                   | DONE   |
| 00051734 | #_$_settings_register                     | settings/src/settings.c                     | DONE   |
| 00054ee4 | #_$_img_mgmt_get_opposite_slot_assert     | Compiler cold path (img_mgmt_priv.h:113)    | DONE   |
| 00054f14 | #_$_img_mgmt_slot_to_image_assert         | Compiler cold path (img_mgmt_priv.h:98)     | DONE   |
| 0007418c | #_$_virtqueue_free                        | virtio/virtqueue.c                          | DONE   |
| 00076054 | #_$_work_timeout                          | kernel/work.c                               | DONE   |
| 000775f4 | #_$_z_sched_wake_thread                   | kernel/sched.c                              | DONE   |
| 000776b4 | #_$_z_unpend1_no_timeout                  | kernel/sched.c                              | DONE   |

### Note on FUN_00054ee4 and FUN_00054f14

These are **compiler-generated out-of-line assert cold paths** — not standalone source functions.

Background: `img_mgmt_priv.h` defines two inline functions:
- `img_mgmt_slot_to_image(slot)` — asserts `slot < 4` at line 98
- `img_mgmt_get_opposite_slot(slot)` — asserts `slot < 4` at line 113

When a function inlines these helpers and the compiler predicts the assert rarely fires, it moves the assert block out-of-line to a separate address and emits a CALL to it on the rare bad-slot path.

- **#_$_img_mgmt_get_opposite_slot_assert** (00054ee4) — called by `$_img_mgmt_state_read` and `#_$_img_mgmt_get_next_boot_slot` when slot >= 4
- **#_$_img_mgmt_slot_to_image_assert** (00054f14) — called by `#_$_img_mgmt_slot_in_use` and `#_$_img_mgmt_set_next_boot_slot` when slot >= 4

### Note on #_$_mpsc_pbuf_alloc (0004ef2c)

Called by `$_FUN_000507fc` (K_NO_WAIT wrapper) which is called by `$_z_impl_z_log_msg_static_create`.

`struct mpsc_pbuf_buffer` layout (confirmed from `zephyr/include/zephyr/sys/mpsc_pbuf.h`):
- +0x00: `tmp_wr_idx`
- +0x04: `wr_idx`
- +0x08: `tmp_rd_idx`
- +0x0c: `rd_idx`
- +0x10: `flags`
- +0x14: `lock` (k_spinlock)
- +0x18: `notify_drop` (callback)
- +0x1c: `get_wlen` (callback)
- +0x20: `buf` (uint32_t*)
- +0x24: `size` → word index 9 → matches `param_1[9] < param_2` (wlen > size early return)
- +0x28: `max_usage`
- +0x2c: `sem` (k_sem)

---

## Type Creation Progress (Complete)

Ran the full type creation workflow from `rename_workflow.md`. All 8 steps complete.

### Artifacts generated:

| File | Contents |
|------|----------|
| `prototype_targets.txt` | 1,743 `$_`/`#_` functions with source signatures appended |
| `types.txt` | 191 deduplicated non-primitive types extracted from signatures |
| `type_definitions.txt` | Source file locations for all 191 types |
| `parsed_types.json` | Machine-readable extracted type definitions |

### Signature lookup stats
1,302 found (first pass) + 228 (second pass) = **1,530 matched**, 134 not found (compiler builtins/uncertain names), 79 skipped (unnamed/builtins).

### Step 8: Types submitted to Ghidra

| Run | Created | Existed | Errors |
|-----|---------|---------|--------|
| Initial (typedefs, enums, structs, unions) | 64 | 32 | 105 |
| Retry #1 (fixed type name mappings) | 68 | 0 | 28 |
| Retry #2 (force unknown deps to dword/pointer) | 28 | 0 | 0 |
| **Total** | **160** | **32** | **0** |

**192 types now in Ghidra** (160 newly created + 32 pre-existing from prior sessions).

Breakdown: 76 typedefs, 16 enums, 106 structs, 3 unions.

Verified: `struct bt_conn` resolves to 216 bytes (matches known layout from session 5).

### Post-creation audit (14 types corrected)
Compared Ghidra struct sizes against known-correct sizes from decompilation and source analysis. Fixed:

| Type | Was | Now | Root cause |
|------|-----|-----|------------|
| `_wait_q_t` | 4B | 8B | Was `dword`, should be `sys_dlist_t` (2 pointers) |
| `sys_dlist_t` | 4B | 8B | Was `dword`, should be `struct _dnode` (head+tail) |
| `sys_slist_t` | 4B | 8B | Same as above |
| `k_timeout_t` | 4B | 8B | Was `int`, should be `longlong` (CONFIG_TIMEOUT_64BIT=true) |
| `smp_hdr` | 13B | 8B | Bitfield parsing created duplicate fields |
| `cJSON` | 36B | 40B | `valueint` was `int`(4B), should be `longlong`(8B) |
| `k_mutex` | 16B | 20B | `_wait_q_t` was 4B, now 8B |
| `k_condvar` | 4B | 8B | Same `_wait_q_t` fix |
| `k_timer` | 28B | 56B | `_timeout`(24B) and `k_timeout_t`(8B) were both too small |
| `bt_le_adv_param` | 19B | 20B | Missing alignment padding |
| `k_mem_slab` | 32B | 36B | `_wait_q_t` fix cascaded |
| `flash_area` | 19B | 20B | Alignment padding |
| `bt_l2cap_server` | 11B | 12B | Alignment padding |
| `mpsc_pbuf_buffer` | 48B | 68B | `k_sem`(24B) was `dword`(4B) |

All 34 key types now pass size verification against expected values.

### Key issues encountered during step 8:
- Ghidra doesn't recognize `long` as a type name — use `int` (32-bit ARM) or `longlong` (64-bit)
- Ghidra doesn't recognize `int64_t`, `int8_t`, `int16_t` — use `longlong`, `byte`, `short`
- `dword` works for `uint32_t`; `uint` works; `unsigned int` does not
- Struct fields referencing types not yet created fail — must submit in dependency order
- Complex fields (inline unions, `ATOMIC_DEFINE` macros, variable-length arrays) need manual conversion to `dword`/`pointer`
- Server must be running — `curl -s` suppresses connection errors, making failures look like successes

**Helper scripts created:**
- `find_signatures.sh` — initial grep-based signature search (superseded by python)
- `fast_lookup.py` — first-pass signature index builder + matcher
- `fix_notfound.py` — second-pass broad index lookup for remaining functions
- `extract_types.py` — parameter type extraction from signatures
- `clean_types.py` — deduplication and noise filtering
- `find_type_defs.py` — locates type definitions in source tree
- `extract_and_submit_types.py` — parses full C definitions into JSON for ghidraMCP

---

## Function Prototype Workflow (Complete — Session 8)

Updated function signatures in Ghidra to match true Zephyr/NCS source code. See `function_workflow.md` for full methodology.

### Results

| Metric | Count |
|--------|-------|
| Total `$_`/`#_` functions | 1,453 (with source match) |
| Prototypes verified correct | 1,453 / 1,453 (100%) |
| Types created for this workflow | 180 new + 4 standard (ssize_t, off_t, int16_t, int64_t) |
| Skipped (no source match) | 173 |

### Key findings
- `set_function_prototype` returns success but can silently fail if called too rapidly — need per-function verification
- C keywords (`static`, `const`, `struct`, `volatile`, `inline`) must be stripped before sending to Ghidra
- Array params (`uint8_t key[16]`) → convert to pointers (`uint8_t *key`)
- Function pointer params (`void (*func)(...)`) → convert to `void *func`
- `k_work_handler_t` (function pointer typedef) can't be used directly — substitute `void *`
- `unsigned` alone = `uint` in Ghidra

### Output files
- `prototype_targets.txt` — 1,453 functions with true source signatures
- `remaining_mismatches.txt` — 0 mismatches (all resolved)
- `skipped_functions.txt` — 173 functions with no source match

---

## Function Discovery Workflow (In Progress — Session 8)

Renaming FUN_* functions using call graph analysis, WEST_TOPDIR string xrefs, and decompilation comparison. See `function_discovery_workflow.md` for methodology.

### Results so far

| Method | Functions Renamed |
|--------|-------------------|
| WEST_TOPDIR string xrefs (Phase 1) | 3 |
| Call graph walking — round 1 | 14 |
| Call graph walking — round 2 (expanded) | 27 |
| Call graph walking — round 3 (re-expanded) | 15 |
| Call graph walking — round 4 | 11 |
| Call graph walking — round 5 | 16 |
| Call graph walking — round 6 | 5 |
| Call graph walking — round 7 | 14 |
| Call graph walking — round 8 | 14 |
| Call graph walking — rounds 9-15 (automated) | 33 |
| Driver API table analysis (Phase 4) | 14 |
| App-region SDK matches (Phase 2 on app) | 5 |
| $_FUN_* full pass (all 31 resolved) | 31 |
| **Total this session** | **202** |

### Functions renamed (session 8)

| Address | Old Name | New Name | Method |
|---------|----------|----------|--------|
| 0004f378 | $_FUN_0004f378 | #_$_nrf_gpio_pin_present_check | WEST_TOPDIR |
| 0006b230 | $_FUN_0006b230 | #_$_nrf_gpio_pin_port_decode | WEST_TOPDIR |
| 00064854 | $_FUN_00064854 | #_$_gpio_fire_callbacks | WEST_TOPDIR |
| 0006de28 | FUN_0006de28 | #_$_lc3_analyze | call graph |
| 0007d560 | FUN_0007d560 | #_$_CC_PalWaitInterrupt | call graph |
| 0000e274 | FUN_0000e274 | #_$___aeabi_d2ulz | call graph |
| 00078d74 | FUN_00078d74 | #_$_fmod | call graph |
| 0006fa20 | FUN_0006fa20 | #_$_lc3_sns_analyze | call graph |
| 000124d8 | FUN_000124d8 | #_$_lsm6dso_accel_convert | call graph |
| 00012518 | FUN_00012518 | #_$_lsm6dso_gyro_convert | call graph |
| 0007e1d0 | FUN_0007e1d0 | #_$_mbedtls_sha256 | call graph |
| 0007d17c | FUN_0007d17c | #_$_mbedtls_sha256_update_wrap | call graph |
| 0007d1f8 | FUN_0007d1f8 | #_$_mbedtls_sha256_free_wrap | call graph |
| 0007de90 | FUN_0007de90 | #_$_mbedtls_platform_zeroize | call graph |
| 0007dc70 | FUN_0007dc70 | #_$_cc3xx_entropy_get_trng | call graph |
| 00012bd8 | FUN_00012bd8 | #_$___ieee754_logf | call graph |
| 00013db8 | FUN_00013db8 | #_$_nano-newlib__multiply_and_add | call graph |
| 0007d304 | FUN_0007d304 | #_$_hmac_sha256_calculate | call graph |
| 00052fb0 | FUN_00052fb0 | #_$_net_buf_destroy | call graph |
| 00012d08 | FUN_00012d08 | #_$___ieee754_log | call graph |
| 00079a70 | FUN_00079a70 | #_$_fmod_remainder | call graph |
| 0007fbe2 | FUN_0007fbe2 | #_$_st25dv_i2c_delay | call graph |
| 0007fece | FUN_0007fece | #_$_k_thread_create | call graph |
| 0004f430 | FUN_0004f430 | #_$_nrfx_gppi_channel_setup | call graph |
| 0000dad4 | FUN_0000dad4 | #_$___muldf3_helper | call graph |
| 0000dcba | FUN_0000dcba | #_$___divdf3_helper | call graph |
| 00012c78 | FUN_00012c78 | #_$_lsm6dso_channel_get_dispatch | call graph |
| 00013da8 | FUN_00013da8 | #_$_nano-newlib__strtod_helper | call graph |
| 00054320 | FUN_00054320 | #_$_nano-newlib__sbrk | call graph |
| 0007c7f4 | FUN_0007c7f4 | #_$_nrf_cc3xx_platform_init | call graph |
| 0007d56c | FUN_0007d56c | #_$_CC_HalWaitInterrupt | call graph |
| 0007f2ac | FUN_0007f2ac | #_$_ClearDataBuffersInfo | call graph |
| 00055c8c | FUN_00055c8c | #_$_smp_bt_disconnected_log | call graph |
| 0004e460 | FUN_0004e460 | #_$_uart_console_hook_install | call graph |
| 000542e4 | FUN_000542e4 | #_$_uart_console_rx_hook_install | call graph |
| 0007b838 | FUN_0007b838 | #_$_nano-newlib__printf_getbuf | call graph |
| 00079f94 | FUN_00079f94 | #_$_cJSON_CreateHooks | call graph |
| 00018ba8 | FUN_00018ba8 | #_$_bt_ancs_disconnect_cleanup | call graph |
| 00012760 | FUN_00012760 | #_$_nrf_rtc_event_clear_and_read | call graph |
| 0000d588 | $_FUN_0000d588 | #_$___aeabi_dadd_helper | call graph expanded |
| 0000dddc | $_FUN_0000dddc | #_$___gedf2 | call graph expanded |
| 0000de04 | $_FUN_0000de04 | #_$___ledf2_internal | call graph expanded |
| 0000de18 | $_FUN_0000de18 | #_$___ltdf2 | call graph expanded |
| 0000de58 | $_FUN_0000de58 | #_$___eqdf2_internal | call graph expanded |
| 00013350 | FUN_00013350 | #_$_fmod_loop | call graph expanded |
| 0006f01c | FUN_0006f01c | #_$_lc3_sns_compute_scale_factors | call graph expanded |
| 0006f270 | FUN_0006f270 | #_$_lc3_sns_spectral_shaping | call graph expanded |
| 0007de9c | FUN_0007de9c | #_$_mbedtls_sha256_starts | call graph expanded |
| 0007d64c | FUN_0007d64c | #_$_CC_HalWaitOnIrq | call graph expanded |
| 0007d610 | FUN_0007d610 | #_$_CC_HalReadIrq | call graph expanded |
| 0007d67c | $_FUN_0007d67c | #_$_CC_HalWriteRegister | call graph expanded |
| 0007c8b0 | $_FUN_0007c8b0 | #_$_CC_LibInit_sub | call graph expanded |
| 0007d534 | $_FUN_0007d534 | #_$_CC_HalInit | call graph expanded |
| 0007d578 | $_FUN_0007d578 | #_$_CC_PalInit | call graph expanded |
| 0007b818 | FUN_0007b818 | #_$_cJSON_InitHooks | call graph expanded |
| 0007ac64 | FUN_0007ac64 | #_$_cjson_print_string_ptr | call graph expanded |
| 0005d188 | FUN_0005d188 | #_$_gatt_ccc_set | call graph expanded |
| 00075ca4 | $_FUN_00075ca4 | #_$_smp_bt_tx_rsp | call graph expanded |
| 00069d88 | FUN_00069d88 | #_$_qspi_device_deinit_helper | call graph expanded |
| 0005339c | $_FUN_0005339c | #_$_nrfx_clock_enable_sub | call graph expanded |
| 00066b04 | $_FUN_00066b04 | #_$_sync_rtc_channel_setup | call graph expanded |
| 0004ee04 | $_FUN_0004ee04 | #_$_cbvprintf_format_handler | call graph expanded |
| 0004ee30 | $_FUN_0004ee30 | #_$_cbvprintf_output_handler | call graph expanded |
| 0004e2bc | FUN_0004e2bc | #_$_console_write | call graph expanded |
| 0007cc94 | $_FUN_0007cc94 | #_$_mbedtls_ctr_drbg_update | call graph expanded |
| 0007ce08 | $_FUN_0007ce08 | #_$_mbedtls_aes_crypt_ecb_wrap | call graph expanded |
| 000780b4 | $_FUN_000780b4 | #_$_z_reschedule | call graph round 4 |
| 000782ac | $_FUN_000782ac | #_$_z_pend_curr | call graph round 4 |
| 0007cef8 | $_FUN_0007cef8 | #_$_CC_AesSelfTest | call graph round 4 |
| 00079e74 | $_FUN_00079e74 | #_$_nano-newlib__sfp_lock | call graph round 4 |
| 00079ee4 | $_FUN_00079ee4 | #_$_nano-newlib__sinit | call graph round 4 |
| 0007b118 | $_FUN_0007b118 | #_$_cjson_ensure_buffer | call graph round 4 |
| 00064fb8 | $_FUN_00064fb8 | #_$_gpio_nrfx_init | call graph round 4 |
| 0004f76c | $_FUN_0004f76c | #_$_z_arm_reset_handler | call graph round 4 |
| 00053dec | $_FUN_00053dec | #_$_z_arm_prep_c | call graph round 4 |
| 00066c7c | $_FUN_00066c7c | #_$_gpio_nrfx_manage_callback | call graph round 4 |
| 00065148 | $_FUN_00065148 | #_$_gpio_nrfx_port_get_direction | call graph round 4 |
| 00053dc8 | $_FUN_00053dc8 | #_$_z_data_copy | call graph round 5 |
| 00067f64 | $_FUN_00067f64 | #_$_z_arm_platform_init | call graph round 5 |
| 00066784 | $_FUN_00066784 | #_$_z_timer_expiry_handler | call graph round 5 |
| 0007cecc | $_FUN_0007cecc | #_$_CC_RndInit | call graph round 5 |
| 0007d280 | $_FUN_0007d280 | #_$_CC_HmacInit | call graph round 5 |
| 0007d608 | FUN_0007d608 | #_$_CC_PalDmaInit | call graph round 5 |
| 0007d684 | FUN_0007d684 | #_$_CC_PalMutexCreate | call graph round 5 |
| 0007d6d0 | FUN_0007d6d0 | #_$_CC_PalInterruptInit | call graph round 5 |
| 0007df60 | FUN_0007df60 | #_$_CC_HashInit | call graph round 5 |
| 0004e328 | FUN_0004e328 | #_$_console_write_locked | call graph round 5 |
| 0004e3d0 | FUN_0004e3d0 | #_$_console_read_locked | call graph round 5 |
| 0004e41c | FUN_0004e41c | #_$_console_putchar | call graph round 5 |
| 00079d78 | $_FUN_00079d78 | #_$_nano-newlib__fflush | call graph round 5 |
| 00079df0 | $_FUN_00079df0 | #_$_nano-newlib__sfp_init | call graph round 5 |
| 0007ab7c | FUN_0007ab7c | #_$_cjson_print_to_buffer | call graph round 5 |
| 0007affc | $_FUN_0007affc | #_$_nano-newlib__fclose | call graph round 5 |
| 0004b058 | FUN_0004b058 | #_$_cjson_print_buffered | call graph round 6 |
| 0004e2e8 | FUN_0004e2e8 | #_$_console_read | call graph round 6 |
| 0007b840 | FUN_0007b840 | #_$_nano-newlib__sputc | call graph round 6 |
| 0007c7d0 | FUN_0007c7d0 | #_$_nano-newlib__write | call graph round 6 |
| 0007e43c | FUN_0007e43c | #_$_CC_HashSetup | call graph round 6 |
| 00068e44 | $_FUN_00068e44 | #_$_nrfx_gpiote_trigger_enable | call graph round 7 |
| 0007c230 | FUN_0007c230 | #_$_cjson_print_string_escape | call graph round 7 |
| 0007c5d4 | FUN_0007c5d4 | #_$_cjson_parse_string | call graph round 7 |
| 0004b0cc | FUN_0004b0cc | #_$_cjson_print_debug | call graph round 7 |
| 0005a658 | FUN_0005a658 | #_$_bt_conn_tx_free | call graph round 7 |
| 0004f3e4 | $_FUN_0004f3e4 | #_$_nrfx_oscillators_init | call graph round 7 |
| 00055ab6 | $_FUN_00055ab6 | #_$_bt_conn_le_param_update_cb | call graph round 7 |
| 0006876c | $_FUN_0006876c | #_$_nrfx_gpiote_pin_uninit | call graph round 7 |
| 000688c8 | $_FUN_000688c8 | #_$_nrfx_gpiote_in_event_addr_get | call graph round 7 |
| 00012fe8 | FUN_00012fe8 | #_$_nano-newlib__strtod_compute | call graph round 7 |
| 00031bf4 | FUN_00031bf4 | #_$_dynamic_buffer_alloc | call graph round 7 |
| 000317e0 | FUN_000317e0 | #_$_dynamic_buffer_copy | call graph round 7 |
| 0007fa08 | FUN_0007fa08 | #_$_eeprom_data_read | call graph round 7 |
| 0007fd06 | FUN_0007fd06 | #_$_eeprom_data_write | call graph round 7 |
| 0007f770 | FUN_0007f770 | #_$_st25dv_i2c_read_byte | call graph round 8 |
| 0007f784 | FUN_0007f784 | #_$_st25dv_i2c_read_block | call graph round 8 |
| 0007f922 | FUN_0007f922 | #_$_st25dv_i2c_write_byte | call graph round 8 |
| 0007f9d8 | FUN_0007f9d8 | #_$_st25dv_i2c_write_block | call graph round 8 |
| 0007fae6 | FUN_0007fae6 | #_$_st25dv_i2c_transfer | call graph round 8 |
| 00026ee4 | FUN_00026ee4 | #_$_st25dv_eeprom_write_page | call graph round 8 |
| 0007c520 | FUN_0007c520 | #_$_cjson_print_string_value | call graph round 8 |
| 0004b160 | FUN_0004b160 | #_$_cjson_format_string | call graph round 8 |
| 0003160c | FUN_0003160c | #_$_cjson_hooks_deallocate | call graph round 8 |
| 00031618 | FUN_00031618 | #_$_cjson_hooks_allocate | call graph round 8 |
| 0003176c | FUN_0003176c | #_$_cjson_hooks_get_size | call graph round 8 |
| 00031798 | FUN_00031798 | #_$_cjson_hooks_resize | call graph round 8 |
| 00031fdc | FUN_00031fdc | #_$_cjson_print_value_internal | call graph round 8 |
| 00055a9c | $_FUN_00055a9c | #_$_bt_conn_le_param_req_cb | call graph round 8 |

---

## Next Steps

The 8 original `$__ASSERT` callers are fully resolved. Next approach to continue reducing unnamed FUN_* count:

### Method: WEST_TOPDIR string xrefs

Find the data address of WEST_TOPDIR `.c` file path strings embedded in the binary, then use `get_xrefs_to` to find all FUN_* functions that reference each string. This anchors functions to source files without needing assert callers.

```bash
# Example: find functions referencing a known source file string
# 1. Search for file path string in binary data
bash -i -c 'ghidraMCP "search_memory?value=kernel/work.c&program=/even_1.63/app_update_1.63.bin"'

# 2. Get xrefs to the string address to find referencing functions
bash -i -c 'ghidraMCP "get_xrefs_to?address=0xXXXXXXXX&program=/even_1.63/app_update_1.63.bin"'
```

### Method: Named function callers/callees

Pick any already-named function and explore its call graph:
- `get_function_callers` → unnamed callers may be identifiable from context
- `get_function_callees` → unnamed callees may be identifiable

---

## Pending Investigations

### FUN_00059538 — bt_pub_key_get candidate
- Has only one caller `hci_num_completed_packets` which is suspicious for bt_pub_key_get
- Needs further investigation

### Application-level functions (0x80000+ region) — DO NOT RENAME
- FUN_000800ca, FUN_00080224, etc. are Even Realities G1 application code
- These use GlassesState type and ___get_dashboard_state()
- Per policy: application-level functions remain as FUN_XXXXXX


**Note**: Non-canonical ZCBOR (no CONFIG_ZCBOR_CANONICAL): map/list start writes 0xBF/0x9F, end writes 0xFF (break).
**Note**: zcbor_int_decode / zcbor_int32_decode were initially misidentified; corrected after realizing 000899b8 is value_encode_len (encode, not decode).


**Note**: `atan2f` (000793fc) was initially misnamed `#_$_powf` based on its two-float signature. Corrected after recognizing: (a) atan2(y,1)=atan(y) path calls atanf; (b) quadrant index `(int)param_2>>0x1e & 2U | (uint)param_1>>0x1f` is characteristic of atan2f sign-based dispatch.


**Key insight**: atomic functions in this binary take BIT MASKS not indices.
- `atomic_set_bit(ptr, SC_LOAD)` where SC_LOAD=2 → compiles to `__atomic_set_bit(ptr, BIT(2))` = `__atomic_set_bit(ptr, 4)`
- `atomic_set_bit(ptr, DB_HASH_LOAD)` where DB_HASH_LOAD=4 → compiles to `__atomic_set_bit(ptr, 0x10)` (BIT(4)=16)
- `MVN.W r1, #2` = bytes `6F F0 02 01` = r1 = ~2 = 0xFFFFFFFD = bitmask for clearing bit 1 (SC_INDICATE_PENDING)
- gatt_sc.flags at 0x20006628 (offset 0x50 from gatt_sc base at 0x200065D8)


---

## Global Variable Labels (RAM → named variables + types in Ghidra)

### Newly discovered configs (not in `/configs` file, inferred from binary layout)
- `CONFIG_BT_GAP_AUTO_UPDATE_CONN_PARAMS = true` — conn_param_retry_countdown present in bt_conn_le (writes 3 at conn+0xB4)
- `CONFIG_BT_REMOTE_VERSION = true` — rv struct at end of bt_conn (fills gap to ref at 0xD0)
- `CONFIG_TIMEOUT_64BIT = true` — `int64_t dticks` in `struct _timeout` (k_work_delayable = 48 bytes)
- `CONFIG_POLL = true` — sys_dlist_t poll_events in k_queue (makes k_queue = 28 bytes)
- `CONFIG_BT_MAX_PAIRED = 2` — inferred from find_sc_cfg (SC_CFG_MAX=3), key_pool (2 entries), gatt_delayed_store (3 peers)
- `CONFIG_BT_KEYS_OVERWRITE_OLDEST = true` — `aging_counter` field at bt_keys+0x58 makes sizeof=0x5C


### Key structs created in Ghidra (sizes confirmed from decompiles)
- `k_work` = 16 bytes (node+handler+queue*+flags)
- `k_work_delayable` = 48 bytes (k_work:16 + _timeout:24 + queue*:4 + align_pad:4)
- `k_timeout_t` = 8 bytes (int64_t ticks, CONFIG_TIMEOUT_64BIT=true) — fixed/recreated session 5
- `_timeout` = 24 bytes (sys_dnode_t:8 + fn:4 + [pad4] + int64_t dticks:8, CONFIG_TIMEOUT_64BIT=true)
- `k_queue` = 28 bytes (sflist:8 + spinlock:4 + wait_q:8 + poll_events:8, CONFIG_POLL=true)
- `k_fifo` = 28 bytes (k_queue wrapper)
- `k_spinlock` = 4 bytes (uintptr_t thread_cpu, CONFIG_SPIN_VALIDATE=true, SMP=false)
- `k_poll_signal` = 16 bytes (sys_dlist_t:8 + signaled:4 + result:4)
- `k_sem` = 24 bytes (wait_q:8 + count:4 + limit:4 + poll_events:8)
- `bt_conn` = 216 bytes (0xD8), `bt_conn_le` = 56 bytes (0x38)
- `gatt_sc` = 88 bytes (params:24 + start:2 + end:2 + pad:4 + work:48 + flags:4 + trail_pad:4)
- `db_hash` = 108 bytes (hash:16 + work:48 + sync:40+4)
- `bt_keys` = 92 bytes (0x5C), stride confirmed from bt_keys_get_addr_impl
- `gatt_sc_cfg` = 12 bytes, `ds_peer` = 12 bytes, `gatt_delayed_store` = 88 bytes
- `device_state` = 2 bytes (init_res:u8, initialized_bits:u8), CONFIG_PM_DEVICE=true
- `pm_device` = 12 bytes (flags:4+state:4+action_cb:4), no RUNTIME/POWER_DOMAIN
- `device` = 24 bytes (name+config+api+state+data+pm all pointers), CONFIG_PM_DEVICE=true → pm field added (was 20B)
- `gpio_dt_spec` = 8 bytes (port*:4+pin:1+_pad:1+dt_flags:2)
- `gpio_callback` = 12 bytes (node:4+handler:4+pin_mask:4)
- `gpio_driver_config` = 4 bytes (port_pin_mask:u32)
- `gpio_driver_data` = 4 bytes (invert:u32)

### Function renames and parameter type updates (session 5)
- `FUN_00052770` → `#_$_nus_ccc_cfg_changed` (NUS CCCD changed handler, calls send_enabled cb at nus_cb+8)
- `FUN_00052784` → `#_$_nus_on_receive` (NUS RX write handler, calls received cb at nus_cb+0)
- `nus_cb` at 0x2000ac98 = static `struct bt_nus_cb` (12B: received/sent/send_enabled func ptrs)
- `FUN_0005a5a8` already named `#_$_bt_conn_auth_cb_register` (confirmed)
- `FUN_0005a658`: application code only (clears 16B + k_queue_append), not renamed
- `FUN_00052fa4`, `FUN_00052fb0`, `FUN_0007c8a0`: no callers, unidentified; leave as FUN_*

