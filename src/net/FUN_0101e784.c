/*
 * Function: FUN_0101e784
 * Entry:    0101e784
 * Prototype: undefined __stdcall FUN_0101e784(char * param_1, int param_2)
 */


void FUN_0101e784(char *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 uVar3;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 uVar4;
  undefined4 extraout_r3_04;
  undefined4 extraout_r3_05;
  
  if ((*(char *)(param_2 + 0x1cb) != '\0') && (*(char *)(param_2 + 0x1d5) != '\0')) {
    return;
  }
  if (param_1 != (char *)0x0) {
    if (*param_1 == '\0') {
      if (((*(char *)(param_2 + 0x1c2) == '\0') &&
          (iVar1 = FUN_0100a518(*(ushort *)(param_2 + 0x17c),1), iVar1 != 0)) &&
         (puVar2 = FUN_010280e4((int *)(iVar1 + 0x158),param_2 + 0x1e5), uVar3 = extraout_r2,
         uVar4 = extraout_r3, puVar2 == (undefined4 *)0x0)) goto LAB_0101e850;
      iVar1 = FUN_0100a564(*(ushort *)(param_2 + 0x180),8);
      uVar3 = extraout_r2_00;
      uVar4 = extraout_r3_00;
      if (iVar1 != 0) goto LAB_0101e86e;
      if (*(int *)(param_1 + 0x74) != 0) {
        return;
      }
      iVar1 = FUN_0100a564(*(ushort *)(param_2 + 0x17e),7);
      if (iVar1 == 0) {
        return;
      }
      FUN_01009500(0x1a,0x60,extraout_r2_01,extraout_r3_01);
    }
    else if (*(char *)(param_2 + 0x1c0) != '\0') goto LAB_0101e7a4;
    if (((*(char *)(param_2 + 0x1c2) == '\0') &&
        (iVar1 = FUN_0100a518(*(ushort *)(param_2 + 0x17c),0), iVar1 != 0)) &&
       (puVar2 = FUN_010280e4((int *)(iVar1 + 0x158),param_2 + 0x1e5), puVar2 == (undefined4 *)0x0))
    {
      FUN_01009500(0x1a,0x2b,extraout_r2_02,extraout_r3_02);
    }
    *(undefined2 *)(param_2 + 0x17c) = 0xffff;
LAB_0101e7a4:
    *(undefined4 *)(param_2 + 0x178) = 0;
    *(undefined4 *)(param_2 + 0x170) = 0;
    *(undefined4 *)(param_2 + 0x174) = 0;
    return;
  }
  if (((*(char *)(param_2 + 0x1c2) == '\0') &&
      (iVar1 = FUN_0100a518(*(ushort *)(param_2 + 0x17c),1), iVar1 != 0)) &&
     (puVar2 = FUN_010280e4((int *)(iVar1 + 0x158),param_2 + 0x1e5), uVar3 = extraout_r2_03,
     uVar4 = extraout_r3_03, puVar2 == (undefined4 *)0x0)) {
LAB_0101e850:
    FUN_01009500(0x1a,0x23,uVar3,uVar4);
  }
  iVar1 = FUN_0100a564(*(ushort *)(param_2 + 0x180),8);
  if (iVar1 == 0) {
    return;
  }
  FUN_01009500(0x1a,0x4e,extraout_r2_04,extraout_r3_04);
  uVar3 = extraout_r2_05;
  uVar4 = extraout_r3_05;
LAB_0101e86e:
  FUN_01009500(0x1a,0x53,uVar3,uVar4);
  FUN_0102a47c(extraout_r1 + 0x88);
  FUN_0102a3fa(extraout_r1);
  return;
}


