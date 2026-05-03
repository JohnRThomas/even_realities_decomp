/*
 * Function: FUN_01029b8e
 * Entry:    01029b8e
 * Prototype: int __stdcall FUN_01029b8e(ushort * param_1, ushort * param_2)
 */


int FUN_01029b8e(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  int extraout_r3;
  ushort *puStack_10;
  ushort *puStack_c;
  
  uVar1 = *param_1;
  *param_2 = uVar1;
  puStack_10 = param_1;
  puStack_c = param_2;
  iVar2 = FUN_0100d7c0(uVar1,(undefined1 *)&puStack_10);
  if (iVar2 == 0) {
    iVar2 = FUN_01028aa6((int)&puStack_10);
    *(undefined1 *)(param_2 + 1) = *(undefined1 *)(iVar2 + 0x19);
    iVar2 = extraout_r3;
  }
  return iVar2;
}


