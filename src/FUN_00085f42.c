/*
 * Function: FUN_00085f42
 * Entry:    00085f42
 * Prototype: undefined __stdcall FUN_00085f42(int param_1)
 */


void FUN_00085f42(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = net_buf_add((net_buf *)(param_1 + 0xc),1);
  *puVar1 = 0;
  return;
}


