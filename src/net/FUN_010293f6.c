/*
 * Function: FUN_010293f6
 * Entry:    010293f6
 * Prototype: undefined __stdcall FUN_010293f6(ushort * param_1, ushort * param_2, undefined4 param_3)
 */


void FUN_010293f6(ushort *param_1,ushort *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r2;
  undefined4 uVar4;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  ushort *puStack_20;
  ushort *puStack_1c;
  undefined4 uStack_18;
  
  puStack_20 = param_1;
  puStack_1c = param_2;
  uStack_18 = param_3;
  iVar1 = FUN_0100d7c0(*param_1,(undefined1 *)&puStack_20);
  if (iVar1 == 0) {
    iVar1 = FUN_01028aa2((int)&puStack_20);
    uVar3 = extraout_r1;
    uVar4 = extraout_r2;
    do {
      *(undefined1 *)(iVar1 + 0x70) = 0;
      iVar2 = FUN_01028c64((uint)*(byte *)(iVar1 + 0x6e),uVar3,uVar4);
      *(char *)(param_2 + 1) = (char)iVar2;
      iVar2 = FUN_01028c64((uint)*(byte *)(iVar1 + 0x6f),extraout_r1_00,extraout_r2_00);
      *(char *)((int)param_2 + 3) = (char)iVar2;
      uVar3 = extraout_r1_01;
      uVar4 = extraout_r2_01;
    } while (*(char *)(iVar1 + 0x70) != '\0');
    *param_2 = *param_1;
  }
  return;
}


