/*
 * Function: FUN_0101eeac
 * Entry:    0101eeac
 * Prototype: undefined4 __stdcall FUN_0101eeac(ushort * param_1, ushort param_2, int param_3, int param_4)
 */


undefined4 FUN_0101eeac(ushort *param_1,ushort param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar6;
  uint uVar7;
  ushort uVar8;
  undefined4 extraout_r3;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined1 local_20 [4];
  ushort *local_1c;
  
  FUN_0100d94c((undefined4 *)param_1,0);
  *param_1 = param_2;
  *(undefined1 **)(param_1 + 0x188) = &DAT_21001225;
  uVar9 = FUN_010200cc();
  uVar8 = DAT_21000eb0;
  if ((uVar9 & 0x20) == 0) {
    uVar8 = 0x1b;
    param_1[0x2b] = 0x1b;
  }
  else {
    param_1[0x2b] = DAT_21000eac._2_2_;
  }
  param_1[0x2c] = uVar8;
  uVar10 = FUN_010200cc();
  if ((int)((ulonglong)uVar10 >> 0x20) << 0x1e < 0) {
    local_20[0] = 0;
    local_1c = param_1;
    FUN_0101ea74((int)local_20);
  }
  *(bool *)((int)param_1 + 0x73) = (char)DAT_2100120c != '\0';
  uVar1 = DAT_2100121c;
  uVar6 = DAT_21001218;
  uVar5 = DAT_21001214;
  *(undefined4 *)(param_1 + 0x3e) = DAT_21001210;
  *(undefined4 *)(param_1 + 0x40) = uVar5;
  *(undefined4 *)(param_1 + 0x42) = uVar6;
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  iVar2 = FUN_0100a758(*param_1,DAT_21000eac._2_2_,DAT_21000eb0,(uint)(byte)DAT_21000eac,
                       (ushort)DAT_21000eac._1_1_);
  if (iVar2 != 0) {
    FUN_01009500(0x39,0xffb,extraout_r2,extraout_r3);
  }
  uVar3 = FUN_01028a56();
  *(uint *)(param_1 + 0xc) = uVar3;
  if (param_4 != 0) {
    uVar3 = FUN_0100fe6c();
    *(uint *)(param_1 + 0x10) = uVar3 & 0xffffff;
  }
  uVar3 = FUN_0100de00((uint)*(ushort *)(param_3 + (uint)*(byte *)(param_3 + 0x4d) * 2 + 0x24));
  pcVar4 = (char *)FUN_0100de00((uint)*(ushort *)
                                       (param_3 + (uint)*(byte *)(param_3 + 0x4d) * 2 + 0x2a));
  if (pcVar4 < &DAT_00001d4c) {
    uVar8 = 1000;
  }
  else {
    pcVar4 = FUN_0101e6d0(uVar3,pcVar4,0x4e2);
    uVar8 = 0x4e2;
  }
  *(char **)(param_1 + 10) = pcVar4;
  *(char **)(param_1 + 0x174) = pcVar4;
  param_1[0x176] = uVar8;
  uVar5 = DAT_21000eb4;
  iVar2 = param_3 + (uint)*(byte *)(param_3 + 0x4d) * 2;
  param_1[0xe] = *(ushort *)(iVar2 + 0x30);
  uVar8 = *(ushort *)(iVar2 + 0x36);
  *(undefined4 *)(param_1 + 0x18) = uVar5;
  param_1[0xf] = uVar8;
  FUN_0101c3c0((int)param_1,uVar5);
  param_1[0x67] = 0xffff;
  param_1[0x68] = 0xffff;
  *(undefined1 *)(param_1 + 0x69) = 0x1f;
  *(undefined1 *)(param_1 + 0x18a) = 0xff;
  uVar5 = extraout_r1;
  uVar6 = extraout_r2_00;
  if (DAT_2100122c != (code *)0x0) {
    (*DAT_2100122c)(param_1,param_1 + 0xb1,1);
    uVar5 = extraout_r1_00;
    uVar6 = extraout_r2_01;
  }
  uVar5 = FUN_0101ee60((int)param_1,uVar5,uVar6);
  uVar3 = FUN_0100fe6c();
  uVar7 = uVar3 % 0xc + 5;
  if (uVar7 < 9) {
    *(char *)((int)param_1 + 0xd9) = (char)(uVar3 % 0xc) + '\r';
  }
  else {
    *(char *)((int)param_1 + 0xd9) = (char)uVar7;
  }
  FUN_0100d94c((undefined4 *)param_1,1);
  return uVar5;
}


