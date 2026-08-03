/*
 * Function: boot_magic_compatible_check
 * Entry:    00088520
 * Prototype: int __stdcall boot_magic_compatible_check(uint8_t tbl_val, uint8_t val)
 */


/* exclude_from_export */

int boot_magic_compatible_check(uint8_t tbl_val,uint8_t val)

{
  if (tbl_val == '\x04') {
    return 1;
  }
  if (tbl_val == '\x05') {
    return (uint)(val != '\x01');
  }
  return (uint)(tbl_val == val);
}


