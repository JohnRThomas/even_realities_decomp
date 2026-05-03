/*
 * Function: FUN_01029b1a
 * Entry:    01029b1a
 * Prototype: int __stdcall FUN_01029b1a(ushort * param_1, ushort * param_2, undefined4 param_3)
 */


int FUN_01029b1a(ushort *param_1,ushort *param_2,undefined4 param_3)

{
  int iVar1;
  int extraout_r3;
  ushort *puStack_18;
  ushort *puStack_14;
  undefined4 uStack_10;
  
  puStack_18 = param_1;
  puStack_14 = param_2;
  uStack_10 = param_3;
  iVar1 = FUN_0100d7c0(*param_1,(undefined1 *)&puStack_18);
  if (iVar1 == 0) {
    iVar1 = FUN_01028aa6((int)&puStack_18);
    *param_2 = *param_1;
    param_2[1] = *(ushort *)(iVar1 + 0x48);
    iVar1 = extraout_r3;
  }
  return iVar1;
}


