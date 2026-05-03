/*
 * Function: FUN_010100a2
 * Entry:    010100a2
 * Prototype: int __stdcall FUN_010100a2(int param_1, undefined1 * param_2, undefined4 param_3, undefined4 * param_4)
 */


int FUN_010100a2(int param_1,undefined1 *param_2,undefined4 param_3,undefined4 *param_4)

{
  ushort uVar1;
  bool bVar2;
  undefined1 uVar3;
  int iVar4;
  undefined1 *extraout_r1;
  undefined1 *extraout_r1_00;
  undefined1 *puVar5;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r3;
  uint uVar6;
  
  uVar1 = *(ushort *)(param_1 + -0xdc);
  uVar6 = (uint)uVar1;
  puVar5 = param_2;
  if ((code *)*param_4 != (code *)0x0) {
    (*(code *)*param_4)(param_1 + -0x34);
    puVar5 = extraout_r1;
    param_3 = extraout_r2;
  }
  if (DAT_21000068 != (code *)0x0) {
    (*DAT_21000068)(uVar6);
    puVar5 = extraout_r1_00;
    param_3 = extraout_r2_00;
  }
  *(ushort *)(param_2 + 3) = uVar1;
  *param_2 = 10;
  param_2[2] = 0;
  param_2[5] = *(undefined1 *)(param_1 + 9);
  iVar4 = FUN_0100a918(uVar1,puVar5,param_3);
  bVar2 = FUN_01027516(iVar4);
  if (bVar2) {
    FUN_0100b0dc(uVar6);
    FUN_0100a564(uVar1,0);
    iVar4 = FUN_0100a564(uVar1,1);
    if ((iVar4 == 0) && (DAT_21000064 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x010100fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar4 = (*DAT_21000064)();
      return iVar4;
    }
    return iVar4;
  }
  FUN_01009500(99,0x72,extraout_r2_01,extraout_r3);
  iVar4 = *(int *)((byte *)(uVar6 * 2) + 4);
  uVar6 = FUN_0100dbc0(iVar4 + 0xa8,1,(uint)*(byte *)(iVar4 + 199),(uint)*(byte *)(uVar6 * 2));
  if (uVar6 == 0) {
    uVar3 = FUN_0100ef28(0);
    *(undefined1 *)(iVar4 + 200) = uVar3;
    *(undefined1 *)(iVar4 + 199) = 7;
  }
  return 0;
}


