/*
 * Function: $_?_FUN_00085f54
 * Entry:    00085f54
 * Prototype: undefined4 __stdcall $_?_FUN_00085f54(int param_1)
 */


undefined4 ____FUN_00085f54(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = net_buf_add((net_buf *)(param_1 + 0xc),1);
  *puVar1 = 1;
  return 0;
}


