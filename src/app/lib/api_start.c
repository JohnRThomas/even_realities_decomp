/*
 * Function: api_start
 * Entry:    00087000
 * Prototype: undefined __stdcall api_start(int param_1, byte param_2, undefined4 param_3, undefined4 param_4)
 */


/* exclude_from_export */

void api_start(int param_1,byte param_2,undefined4 param_3,undefined4 param_4)

{
  async_start(param_1,param_2,param_3,param_4,0x80);
  return;
}


