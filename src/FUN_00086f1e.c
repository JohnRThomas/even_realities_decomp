/*
 * Function: FUN_00086f1e
 * Entry:    00086f1e
 * Prototype: undefined __stdcall FUN_00086f1e(net_buf * param_1, undefined4 param_2)
 */


void FUN_00086f1e(net_buf *param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = net_buf_add(param_1,2);
  *puVar1 = (char)param_2;
  puVar1[1] = (char)((uint)param_2 >> 8);
  return;
}


