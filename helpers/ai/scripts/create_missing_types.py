#!/usr/bin/env python3
"""
Type Creation Workflow: Find and create 180 missing types in Ghidra.
Following type_creation_workflow.md:
1. Find type definitions in true source
2. Categorize (typedef, enum, struct, union, function pointer, opaque)
3. Create in dependency order (leaf-first)
"""

import re
import subprocess
import json
import urllib.parse
import os

SOURCE_DIR = "/media/files/ncs/v2.5.1"
PROGRAM = "/even_1.63/app_update_1.63.bin"
BASE_URL = "http://127.0.0.1:8089"

MISSING_TYPES = [
    "CCBool_t", "CCError_t", "CCRndState_t", "CCUtilError_t", "CC_PalTrngParams_t",
    "NRF_QSPI_Type", "NRF_TWIM_Type", "_PRINTF_FLOAT_TYPE", "_bt_gatt_ccc",
    "_timeout_func_t", "adc_gain", "adc_sequence", "adv_name_type", "arm_mpu_region",
    "attr_read_cb", "boot_swap_state", "bt_ancs_app_attr_id_val", "bt_ancs_attr_response",
    "bt_ancs_ds_notif_cb", "bt_ancs_notif_attr_id_val", "bt_ancs_ns_notif_cb",
    "bt_ancs_write_cb", "bt_att_chan_opt", "bt_att_encode_t", "bt_att_func_t",
    "bt_bond_info", "bt_buf_type", "bt_conn_tx_cb_t", "bt_data",
    "bt_gatt_attr_func_t", "bt_gatt_ccc_cfg", "bt_gatt_chrc",
    "bt_gatt_complete_func_t", "bt_gatt_dm_attr", "bt_gatt_dm_cb",
    "bt_gatt_notify_params", "bt_gatt_service_val", "bt_gatt_subscribe_params",
    "bt_gattp", "bt_gattp_indicate_cb", "bt_hci_cmd_state_set",
    "bt_l2cap_chan_destroy_t", "bt_l2cap_chan_state_t", "cbprintf_convert_cb",
    "chunk_fields", "clock_control_subsys_t", "delayed_store_flags",
    "dmic_cfg", "dmic_trigger", "drvError_t", "dtls_alert_level_t",
    "dtls_context_t", "flash_page_cb", "flash_sector", "gpio_int_mode",
    "gpio_int_trig", "i2c_msg", "i2s_nrfx_drv_data", "img_mgmt_upload_action",
    "img_mgmt_upload_req", "internal_hooks", "ipc_ept_cfg", "ipc_rpmsg_ept",
    "ipc_rpmsg_instance", "json_append_bytes_t", "k_timer_expiry_t",
    "k_timer_stop_t", "k_work_queue_config", "k_work_sync",
    "lc3_attdet_analysis_t", "lc3_bandwidth", "lc3_bits_mode", "lc3_complex",
    "lc3_dt", "lc3_encoder", "lc3_encoder_t", "lc3_ltpf_analysis_t",
    "lc3_ltpf_data_t", "lc3_pcm_format", "lc3_sns_data_t", "lc3_spec_analysis_t",
    "lc3_spec_side_t", "lc3_tns_data_t", "lc3_srate",
    "log_backend_evt", "log_backend_evt_arg", "log_output_func_t", "log_timestamp_t",
    "lsm6dso_emb_fsm_enable_t", "lsm6dso_fifo_mode_t", "lsm6dso_fs_g_t",
    "lsm6dso_fs_xl_t", "lsm6dso_fsm_odr_t", "lsm6dso_g_hm_mode_t",
    "lsm6dso_i3c_disable_t", "lsm6dso_odr_g_t", "lsm6dso_odr_xl_t",
    "lsm6dso_reg_access_t", "lsm6dso_xl_hm_mode_t",
    "lv_obj_t", "lv_res_t",
    "mbedtls_ctr_drbg_context", "mbox_msg", "metal_log_level", "metal_phys_addr_t",
    "mpsc_pbuf_buffer_config", "net_buf_allocator_cb",
    "nrf_cc3xx_platform_ctr_drbg_context_t", "nrf_cc3xx_platform_mutex_apis_t",
    "nrf_cc3xx_platform_mutexes_t",
    "nrf_gpio_pin_dir_t", "nrf_gpio_pin_drive_t", "nrf_gpio_pin_input_t",
    "nrf_gpio_pin_pull_t", "nrf_gpio_pin_sense_t", "nrf_gpiote_event_t",
    "nrf_qspi_cinstr_conf_t", "nrf_qspi_cinstr_len_t", "nrf_qspi_erase_len_t",
    "nrf_qspi_pins_t", "nrf_spim_event_t", "nrf_twim_event_t",
    "nrfx_gpiote_handler_config_t", "nrfx_gpiote_input_config_t",
    "nrfx_gpiote_interrupt_handler_t", "nrfx_gpiote_output_config_t",
    "nrfx_gpiote_task_config_t", "nrfx_gpiote_trigger_config_t",
    "nrfx_pdm_event_handler_t", "nrfx_qspi_handler_t", "nrfx_qspi_state_t",
    "nrfx_spim_config_t", "nrfx_spim_evt_handler_t", "nrfx_spim_xfer_desc_t",
    "nrfx_twim_config_t", "nrfx_twim_evt_handler_t", "nrfx_twim_xfer_desc_t",
    "nrfx_wdt_config_t", "nrfy_spim_xfer_desc_t", "nrfy_twim_xfer_desc_t",
    "onoff_client", "onoff_transitions", "parse_buffer",
    "pinctrl_dev_config", "pinctrl_soc_pin_t", "pinctrl_state",
    "pm_device_action", "pm_device_state", "printbuffer", "q31_t",
    "rpmsg_ept_cb", "rpmsg_ns_bind_cb", "rpmsg_ns_unbind_cb",
    "rpmsg_virtio_config", "rpmsg_virtio_device", "rpmsg_virtio_shm_pool",
    "sensor_attribute", "sensor_channel", "sensor_value", "session_t",
    "settings_handler_static", "settings_load_arg", "settings_load_direct_cb",
    "settings_read_cb", "settings_store", "str_context", "stream_flash_callback_t",
    "sys_notify_generic_callback", "uart_config", "va_list",
    "virtio_device", "virtqueue_buf", "vq_callback", "vring", "vring_alloc_info",
    "z_arm_mpu_partition", "z_nrf_rtc_timer_compare_handler_t", "z_poller",
    "zcbor_decoder_t", "zcbor_major_type_t", "zcbor_map_decode_key_val",
]

_file_cache = {}
def read_file(filepath):
    if filepath not in _file_cache:
        try:
            with open(filepath, 'r', errors='replace') as f:
                _file_cache[filepath] = f.readlines()
        except:
            _file_cache[filepath] = []
    return _file_cache[filepath]


def type_exists_in_ghidra(type_name):
    """Check if type already exists."""
    try:
        r = subprocess.run(
            ['bash', '-i', '-c',
             f'ghidraMCP "get_type_size?type_name={urllib.parse.quote(type_name)}&program={PROGRAM}"'],
            capture_output=True, text=True, timeout=10)
        return 'not found' not in r.stdout.lower() and 'Size:' in r.stdout
    except:
        return False


def find_type_definition(type_name):
    """
    Find the definition of a type in the source code.
    Returns (category, definition_info) where category is one of:
    'typedef_simple', 'typedef_funcptr', 'enum', 'struct', 'union', 'opaque', 'not_found'
    """
    # Search for typedef
    try:
        r = subprocess.run(
            ['rg', '-n', '--no-heading', '-t', 'c', '-t', 'h',
             rf'\btypedef\b.*\b{re.escape(type_name)}\b', SOURCE_DIR],
            capture_output=True, text=True, timeout=30)
        typedef_lines = r.stdout.strip().split('\n') if r.stdout.strip() else []
    except:
        typedef_lines = []

    # Search for enum
    try:
        r = subprocess.run(
            ['rg', '-n', '--no-heading', '-t', 'c', '-t', 'h',
             rf'\benum\s+{re.escape(type_name)}\b', SOURCE_DIR],
            capture_output=True, text=True, timeout=30)
        enum_lines = r.stdout.strip().split('\n') if r.stdout.strip() else []
    except:
        enum_lines = []

    # Search for struct
    try:
        r = subprocess.run(
            ['rg', '-n', '--no-heading', '-t', 'c', '-t', 'h',
             rf'\bstruct\s+{re.escape(type_name)}\b', SOURCE_DIR],
            capture_output=True, text=True, timeout=30)
        struct_lines = r.stdout.strip().split('\n') if r.stdout.strip() else []
    except:
        struct_lines = []

    # Search for } type_name; pattern (typedef struct {...} type_name;)
    try:
        r = subprocess.run(
            ['rg', '-n', '--no-heading', '-t', 'c', '-t', 'h',
             rf'\}}\s*{re.escape(type_name)}\s*;', SOURCE_DIR],
            capture_output=True, text=True, timeout=30)
        closing_lines = r.stdout.strip().split('\n') if r.stdout.strip() else []
    except:
        closing_lines = []

    # Search for #define (macro-defined type)
    try:
        r = subprocess.run(
            ['rg', '-n', '--no-heading', '-t', 'c', '-t', 'h',
             rf'#define\s+{re.escape(type_name)}\b', SOURCE_DIR],
            capture_output=True, text=True, timeout=30)
        define_lines = r.stdout.strip().split('\n') if r.stdout.strip() else []
    except:
        define_lines = []

    # Analyze results

    # 1. Check for simple typedef: typedef base_type type_name;
    for line in typedef_lines:
        m = re.match(r'^(.+?):(\d+):(.+)$', line)
        if not m: continue
        filepath, linenum, content = m.group(1), int(m.group(2)), m.group(3).strip()

        # Simple typedef: typedef uint32_t type_name;
        simple_m = re.match(rf'typedef\s+(\w[\w\s\*]*?)\s+{re.escape(type_name)}\s*;', content)
        if simple_m:
            base = simple_m.group(1).strip()
            return ('typedef_simple', {'base_type': base, 'file': filepath, 'line': linenum})

        # Function pointer typedef: typedef ret (*type_name)(params);
        fptr_m = re.match(rf'typedef\s+(.+?)\s*\(\s*\*\s*{re.escape(type_name)}\s*\)\s*\((.*?)\)\s*;', content)
        if fptr_m:
            return ('typedef_funcptr', {
                'ret_type': fptr_m.group(1).strip(),
                'params': fptr_m.group(2).strip(),
                'file': filepath, 'line': linenum
            })

        # Multi-line function pointer - check if this line has the beginning
        if f'*{type_name}' in content or f'* {type_name}' in content:
            # Read more lines to complete
            file_lines = read_file(filepath)
            full = content
            for i in range(1, 10):
                if linenum + i - 1 < len(file_lines):
                    full += ' ' + file_lines[linenum + i - 1].strip()
                    if ';' in file_lines[linenum + i - 1]:
                        break

            fptr_m2 = re.search(rf'typedef\s+(.+?)\s*\(\s*\*\s*{re.escape(type_name)}\s*\)\s*\((.*?)\)\s*;', full)
            if fptr_m2:
                return ('typedef_funcptr', {
                    'ret_type': fptr_m2.group(1).strip(),
                    'params': fptr_m2.group(2).strip(),
                    'file': filepath, 'line': linenum
                })

    # 2. Check for typedef enum/struct/union {...} type_name;
    for line in closing_lines:
        m = re.match(r'^(.+?):(\d+):(.+)$', line)
        if not m: continue
        filepath, linenum, content = m.group(1), int(m.group(2)), m.group(3).strip()

        # Find the opening of this block by searching backwards
        file_lines = read_file(filepath)
        # Search backwards for typedef enum/struct/union
        for back in range(linenum - 1, max(0, linenum - 200), -1):
            back_line = file_lines[back].strip() if back < len(file_lines) else ''
            if re.match(r'typedef\s+enum\b', back_line):
                # Extract enum values
                enum_body = extract_enum_values(file_lines, back, linenum - 1)
                if enum_body is not None:
                    return ('enum', {'values': enum_body, 'file': filepath, 'line': back + 1})
                break
            elif re.match(r'typedef\s+struct\b', back_line):
                return ('struct_opaque', {'file': filepath, 'line': back + 1, 'end_line': linenum})
                break
            elif re.match(r'typedef\s+union\b', back_line):
                return ('union_opaque', {'file': filepath, 'line': back + 1, 'end_line': linenum})
                break

    # 3. Check for enum type_name { ... };
    for line in enum_lines:
        m = re.match(r'^(.+?):(\d+):(.+)$', line)
        if not m: continue
        filepath, linenum, content = m.group(1), int(m.group(2)), m.group(3).strip()
        if '{' in content or (linenum < len(read_file(filepath)) and '{' in read_file(filepath)[linenum].strip() if linenum < len(read_file(filepath)) else False):
            file_lines = read_file(filepath)
            # Find the closing brace
            end_line = linenum - 1
            depth = 0
            for i in range(linenum - 1, min(linenum + 100, len(file_lines))):
                for ch in file_lines[i]:
                    if ch == '{': depth += 1
                    elif ch == '}': depth -= 1
                if depth == 0 and i > linenum - 1:
                    end_line = i
                    break
            enum_body = extract_enum_values(file_lines, linenum - 1, end_line)
            if enum_body is not None:
                return ('enum', {'values': enum_body, 'file': filepath, 'line': linenum})

    # 4. Check for #define
    for line in define_lines:
        m = re.match(r'^(.+?):(\d+):(.+)$', line)
        if not m: continue
        content = m.group(3).strip()
        define_m = re.match(rf'#define\s+{re.escape(type_name)}\s+(\S+)', content)
        if define_m:
            base = define_m.group(1).strip()
            return ('typedef_simple', {'base_type': base, 'file': m.group(1), 'line': int(m.group(2))})

    return ('not_found', {})


def extract_enum_values(file_lines, start_line, end_line):
    """Extract enum values from source lines."""
    values = {}
    auto_val = 0
    text = ' '.join(file_lines[start_line:end_line + 1])

    # Find content between { and }
    brace_m = re.search(r'\{(.*)\}', text)
    if not brace_m:
        return None

    body = brace_m.group(1)
    # Remove comments
    body = re.sub(r'/\*.*?\*/', '', body)
    body = re.sub(r'//[^\n]*', '', body)

    for item in body.split(','):
        item = item.strip()
        if not item:
            continue
        if '=' in item:
            parts = item.split('=', 1)
            name = parts[0].strip()
            val_str = parts[1].strip()
            # Try to evaluate simple expressions
            try:
                val = int(val_str, 0)
                auto_val = val + 1
            except:
                # Could be an expression like (1 << 3) or BIT(3)
                val = auto_val
                auto_val += 1
            if re.match(r'^[A-Za-z_]\w*$', name):
                values[name] = val
        else:
            name = item.strip()
            if re.match(r'^[A-Za-z_]\w*$', name):
                values[name] = auto_val
                auto_val += 1

    return values if values else None


def create_typedef(name, base_type):
    """Create a typedef in Ghidra."""
    # Strip C keywords from base_type
    clean_base = base_type
    for kw in ['const', 'struct', 'enum', 'union', 'volatile']:
        clean_base = re.sub(rf'\b{kw}\b', '', clean_base)
    clean_base = re.sub(r'\s+', ' ', clean_base).strip()

    data = {"name": name, "base_type": clean_base}
    try:
        r = subprocess.run(
            ['curl', '-s', '-X', 'POST',
             f'{BASE_URL}/create_typedef?program={PROGRAM}',
             '-H', 'Content-Type: application/json',
             '-d', json.dumps(data)],
            capture_output=True, text=True, timeout=15)
        return r.stdout.strip()
    except Exception as e:
        return f"ERROR: {e}"


def create_enum(name, values, size=4):
    """Create an enum in Ghidra."""
    data = {"name": name, "values": values, "size": size}
    try:
        r = subprocess.run(
            ['curl', '-s', '-X', 'POST',
             f'{BASE_URL}/create_enum?program={PROGRAM}',
             '-H', 'Content-Type: application/json',
             '-d', json.dumps(data)],
            capture_output=True, text=True, timeout=15)
        return r.stdout.strip()
    except Exception as e:
        return f"ERROR: {e}"


def create_struct_opaque(name, size=4):
    """Create an opaque struct (just a sized placeholder)."""
    data = {"name": name, "fields": [{"name": "opaque", "type": f"byte[{size}]", "offset": 0}]}
    try:
        r = subprocess.run(
            ['curl', '-s', '-X', 'POST',
             f'{BASE_URL}/create_struct?program={PROGRAM}',
             '-H', 'Content-Type: application/json',
             '-d', json.dumps(data)],
            capture_output=True, text=True, timeout=15)
        return r.stdout.strip()
    except Exception as e:
        return f"ERROR: {e}"


def main():
    print(f"Processing {len(MISSING_TYPES)} missing types...")
    print()

    # Step 1: Find definitions
    found = {}
    not_found = []

    for i, type_name in enumerate(MISSING_TYPES):
        # Skip if already in Ghidra
        if type_exists_in_ghidra(type_name):
            print(f"  SKIP (exists): {type_name}")
            continue

        category, info = find_type_definition(type_name)
        found[type_name] = (category, info)

        if category == 'not_found':
            not_found.append(type_name)

        if (i + 1) % 30 == 0:
            print(f"  Searched: {i+1}/{len(MISSING_TYPES)}")

    print(f"\nDefinition search results:")
    from collections import Counter
    cats = Counter(cat for cat, _ in found.values())
    for cat, count in cats.most_common():
        print(f"  {cat}: {count}")
    print()

    # Step 2: Create types in order
    # Order: simple typedefs -> enums -> function pointer typedefs -> structs -> opaque
    order = ['typedef_simple', 'enum', 'typedef_funcptr', 'struct_opaque', 'union_opaque', 'not_found']

    created = 0
    failed = []

    for category in order:
        types_in_cat = [(name, info) for name, (cat, info) in found.items() if cat == category]
        if not types_in_cat:
            continue

        print(f"\n--- Creating {category} types ({len(types_in_cat)}) ---")

        for type_name, info in types_in_cat:
            if category == 'typedef_simple':
                base = info['base_type']
                result = create_typedef(type_name, base)
                if 'error' in result.lower() or 'fail' in result.lower():
                    # Try with simpler base type
                    # Common: the base type itself might not exist, use int as fallback
                    result2 = create_typedef(type_name, 'int')
                    if 'error' in result2.lower():
                        failed.append(f"{type_name} | {category} | base={base} | {result}")
                        print(f"  FAIL: {type_name} (base={base}): {result[:80]}")
                    else:
                        created += 1
                        print(f"  OK (fallback int): {type_name}")
                else:
                    created += 1
                    print(f"  OK: {type_name} -> {base}")

            elif category == 'enum':
                values = info.get('values', {})
                if not values:
                    # Create as simple int typedef
                    result = create_typedef(type_name, 'int')
                    if 'error' not in result.lower():
                        created += 1
                        print(f"  OK (as typedef int): {type_name}")
                    else:
                        failed.append(f"{type_name} | {category} | no values | {result}")
                        print(f"  FAIL: {type_name}")
                else:
                    result = create_enum(type_name, values)
                    if 'error' in result.lower() or 'fail' in result.lower():
                        # Fallback: create as typedef int
                        result2 = create_typedef(type_name, 'int')
                        if 'error' not in result2.lower():
                            created += 1
                            print(f"  OK (enum fallback as int): {type_name}")
                        else:
                            failed.append(f"{type_name} | {category} | {result}")
                            print(f"  FAIL: {type_name}: {result[:80]}")
                    else:
                        created += 1
                        print(f"  OK: {type_name} ({len(values)} values)")

            elif category == 'typedef_funcptr':
                # Create as void* typedef (function pointers are just pointers in Ghidra)
                result = create_typedef(type_name, 'pointer')
                if 'error' in result.lower():
                    result = create_typedef(type_name, 'void *')
                    if 'error' in result.lower():
                        failed.append(f"{type_name} | {category} | {result}")
                        print(f"  FAIL: {type_name}: {result[:80]}")
                    else:
                        created += 1
                        print(f"  OK: {type_name} -> void*")
                else:
                    created += 1
                    print(f"  OK: {type_name} -> pointer")

            elif category in ('struct_opaque', 'union_opaque'):
                # Create as opaque 4-byte struct (pointer-sized placeholder)
                result = create_struct_opaque(type_name)
                if 'error' in result.lower() or 'fail' in result.lower():
                    # Try as typedef
                    result2 = create_typedef(type_name, 'int')
                    if 'error' not in result2.lower():
                        created += 1
                        print(f"  OK (as typedef int): {type_name}")
                    else:
                        failed.append(f"{type_name} | {category} | {result}")
                        print(f"  FAIL: {type_name}: {result[:80]}")
                else:
                    created += 1
                    print(f"  OK (opaque struct): {type_name}")

            elif category == 'not_found':
                # Create as opaque typedef to int (placeholder)
                result = create_typedef(type_name, 'int')
                if 'error' in result.lower():
                    failed.append(f"{type_name} | not_found | {result}")
                    print(f"  FAIL: {type_name}: {result[:80]}")
                else:
                    created += 1
                    print(f"  OK (placeholder int): {type_name}")

    print(f"\n--- Summary ---")
    print(f"Created: {created}")
    print(f"Failed: {len(failed)}")
    print(f"Not found in source (created as placeholders): {len(not_found)}")

    if failed:
        print("\nFailed types:")
        for f_entry in failed:
            print(f"  {f_entry}")

    # Write results
    with open('/media/files/ncs/type_creation_results.txt', 'w') as f:
        f.write(f"Created: {created}\n")
        f.write(f"Failed: {len(failed)}\n\n")
        for entry in failed:
            f.write(f"FAILED: {entry}\n")


if __name__ == '__main__':
    main()
