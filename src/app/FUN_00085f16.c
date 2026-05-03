/*
 * Function: FUN_00085f16
 * Entry:    00085f16
 * Prototype: undefined4 __stdcall FUN_00085f16(int param_1, undefined4 param_2, int param_3)
 */


undefined4 FUN_00085f16(int param_1,undefined4 param_2,int param_3)

{
  undefined2 *puVar1;
  
  puVar1 = net_buf_add((net_buf *)(param_1 + 0xc),2);
  *puVar1 = *(undefined2 *)(param_3 + 10);
  return 0;
}


