/*
 * Function: FUN_0100ee5c
 * Entry:    0100ee5c
 * Prototype: uint __stdcall FUN_0100ee5c(int param_1, undefined4 * param_2, uint param_3, undefined4 param_4)
 */


uint FUN_0100ee5c(int param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  
  if (param_3 < 0x1c) {
    *(char *)(param_1 + 1) = (char)param_3;
    uVar1 = FUN_01026198((undefined4 *)(param_1 + 3),param_2,param_3);
    return uVar1;
  }
  iVar2 = FUN_01009500(0x2a,0x47e,param_3,param_4);
  return (uint)*(ushort *)(iVar2 + 7);
}


