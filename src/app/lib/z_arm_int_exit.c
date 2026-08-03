/*
 * Function: z_arm_int_exit
 * Entry:    00053668
 * Prototype: undefined __stdcall z_arm_int_exit(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

void z_arm_int_exit(void)

{
  if (_current.poller != _current.base) {
    _DAT_e000ed04 = 0x10000000;
  }
  return;
}


