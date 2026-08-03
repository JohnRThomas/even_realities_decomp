/*
 * Function: tc_cmac_init
 * Entry:    000838f6
 * Prototype: int __stdcall tc_cmac_init(TCCmacState_t s)
 */


/* exclude_from_export_ai */

int tc_cmac_init(TCCmacState_t s)

{
  if (s != (TCCmacState_t)0x0) {
    memset(s,0,0x10);
    memset(s + 0x30,0,0x10);
    *(undefined4 *)(s + 0x44) = 0;
    *(undefined4 *)(s + 0x50) = 0;
    *(undefined4 *)(s + 0x54) = 0x10000;
  }
  return (uint)(s != (TCCmacState_t)0x0);
}


