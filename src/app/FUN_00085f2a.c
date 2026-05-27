/*
 * Function: $_?_FUN_00085f2a
 * Entry:    00085f2a
 * Prototype: undefined4 __stdcall $_?_FUN_00085f2a(int param_1, undefined4 param_2, int param_3)
 */


undefined4 ____FUN_00085f2a(int param_1,undefined4 param_2,int param_3)

{
  undefined2 *puVar1;
  
  puVar1 = net_buf_add((net_buf *)(param_1 + 0xc),4);
  *puVar1 = *(undefined2 *)(param_3 + 8);
  puVar1[1] = *(undefined2 *)(param_3 + 0xe);
  return 0;
}


