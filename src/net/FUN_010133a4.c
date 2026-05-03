/*
 * Function: FUN_010133a4
 * Entry:    010133a4
 * Prototype: uint __stdcall FUN_010133a4(int param_1, int param_2, undefined4 param_3)
 */


uint FUN_010133a4(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  uint uVar5;
  uint extraout_r3;
  undefined4 unaff_r4;
  uint uVar6;
  undefined4 unaff_r7;
  undefined8 uVar7;
  char cStack_22;
  char cStack_21;
  
  uVar5 = param_1 - 1U & 0xff;
  if ((uVar5 < 2) || (param_2 == 0x1d)) {
    switch(param_2) {
    case 0x10:
      return (uint)*(ushort *)(&DAT_0103c1ac + uVar5 * 2);
    default:
      FUN_01009500(0x2f,0x102,param_3,uVar5);
      param_3 = extraout_r2;
      uVar5 = extraout_r3;
      break;
    case 0x12:
    case 0x13:
      return (uint)*(ushort *)(&DAT_0103c1b4 + uVar5 * 2);
    case 0x15:
      return (uint)*(ushort *)(&DAT_0103c1b0 + uVar5 * 2);
    case 0x1d:
      return param_1 * 0x35a;
    }
  }
  uVar7 = FUN_01009500(0x2f,0xee,param_3,uVar5);
  puVar4 = (undefined4 *)((ulonglong)uVar7 >> 0x20);
  *puVar4 = extraout_r2_00;
  puVar4[1] = unaff_r4;
  puVar4[2] = unaff_r7;
  iVar3 = FUN_01009500(6,0x35b,extraout_r2_00,(int)uVar7 << 4);
  uVar5 = FUN_01012ee8(iVar3);
  if (uVar5 == 0) {
    uVar5 = 0x8b;
  }
  else {
    uVar2 = FUN_01012eb0(iVar3);
    if ((uVar2 == 0) && (uVar5 = FUN_01012eb8(iVar3), uVar5 == 0)) {
      uVar6 = 0x7f;
      uVar5 = 0x75;
    }
    else {
      uVar6 = 0x89;
      uVar5 = 0x7f;
    }
    FUN_01022108();
    FUN_01022114();
    if (cStack_22 != '\0' || cStack_21 != '\0') {
      uVar5 = uVar6;
    }
    bVar1 = FUN_01026528();
    if (bVar1) {
      return uVar5 + 0x18;
    }
    bVar1 = FUN_010263e0();
    if (bVar1) {
      uVar5 = uVar5 + 0xf;
    }
  }
  return uVar5;
}


