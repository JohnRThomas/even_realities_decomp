/*
 * Function: api_stop
 * Entry:    00087044
 * Prototype: undefined __stdcall api_stop(int param_1, byte param_2)
 */


/* exclude_from_export */

void api_stop(int param_1,byte param_2)

{
  stop(param_1,param_2,0x80);
  return;
}


