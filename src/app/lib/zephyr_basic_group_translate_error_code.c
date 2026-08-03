/*
 * Function: zephyr_basic_group_translate_error_code
 * Entry:    00084258
 * Prototype: int __stdcall zephyr_basic_group_translate_error_code(zephyr_basic_group_err_code_t ret)
 */


/* exclude_from_export */

int zephyr_basic_group_translate_error_code(zephyr_basic_group_err_code_t ret)

{
  if (ret == 2) {
    return 5;
  }
  return (uint)(1 < ret - 3);
}


