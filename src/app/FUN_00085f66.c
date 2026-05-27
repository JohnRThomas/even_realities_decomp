/*
 * Function: $_?_FUN_00085f66
 * Entry:    00085f66
 * Prototype: undefined4 __stdcall $_?_FUN_00085f66(int param_1, undefined4 param_2, int param_3)
 */


undefined4 ____FUN_00085f66(int param_1,undefined4 param_2,int param_3)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  
  puVar1 = net_buf_add((net_buf *)(param_1 + 0xc),4);
  *puVar1 = *(undefined2 *)(param_3 + 8);
  puVar1[1] = *(undefined2 *)(param_3 + 0xe);
  if (*(char *)(param_3 + 0x10) == '\0') {
    uVar2 = 0x2800;
  }
  else {
    uVar2 = 0x2801;
  }
  ____FUN_00086f1e((net_buf *)(param_1 + 0xc),uVar2);
  return 0;
}


