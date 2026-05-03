/*
 * Function: FUN_01027d4c
 * Entry:    01027d4c
 * Prototype: undefined __stdcall FUN_01027d4c(byte param_1)
 */


void FUN_01027d4c(byte param_1)

{
  int iVar1;
  undefined4 extraout_r2;
  int iStack_14;
  ushort local_10;
  int local_c;
  
  FUN_01027bf8(&iStack_14,param_1);
  while (iVar1 = FUN_0100a5d8(&iStack_14), iVar1 == 0) {
    local_c = FUN_0100a564(local_10,param_1);
    if (local_c != 0) {
      FUN_01009500(0x17,0x2d7,extraout_r2,local_c);
    }
  }
  return;
}


