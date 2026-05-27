/*
 * Function: $_?_FUN_00085f96
 * Entry:    00085f96
 * Prototype: undefined4 __stdcall $_?_FUN_00085f96(int param_1, undefined4 param_2, int * param_3)
 */


undefined4 ____FUN_00085f96(int param_1,undefined4 param_2,int *param_3)

{
  undefined2 *puVar1;
  uint uVar2;
  
  puVar1 = net_buf_add((net_buf *)(param_1 + 0xc),4);
  *puVar1 = (short)param_3[2];
  puVar1[1] = *(undefined2 *)((int)param_3 + 0xe);
  if ((char)param_3[4] == '\x02') {
    uVar2 = 0x2802;
  }
  else if ((char)param_3[4] == '\x03') {
    uVar2 = 0x2803;
  }
  else {
    uVar2 = (uint)*(ushort *)(*param_3 + 2);
  }
  ____FUN_00086f1e((net_buf *)(param_1 + 0xc),uVar2);
  return 0;
}


