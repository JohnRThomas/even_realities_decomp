/*
 * Function: tc_cmac_erase
 * Entry:    000838e6
 * Prototype: int __stdcall tc_cmac_erase(TCCmacState_t s)
 */


/* exclude_from_export */

int tc_cmac_erase(TCCmacState_t s)

{
  if (s != (TCCmacState_t)0x0) {
    memset(s,0,0x58);
  }
  return (uint)(s != (TCCmacState_t)0x0);
}


