/*
 * Function: FUN_0101f0a0
 * Entry:    0101f0a0
 * Prototype: int __stdcall FUN_0101f0a0(ushort * param_1, undefined4 param_2, undefined4 param_3, ushort * param_4)
 */


int FUN_0101f0a0(ushort *param_1,undefined4 param_2,undefined4 param_3,ushort *param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_r2;
  undefined4 uVar5;
  undefined4 extraout_r2_00;
  undefined *puVar6;
  undefined4 extraout_r3;
  undefined4 uVar7;
  undefined4 extraout_r3_00;
  bool bVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined4 local_18;
  ushort *local_14;
  
  local_18 = param_3;
  local_14 = param_4;
  uVar9 = FUN_010200cc();
  uVar1 = DAT_21000eb0;
  if ((uVar9 & 0x20) == 0) {
    uVar1 = 0x1b;
    param_1[0x2b] = 0x1b;
  }
  else {
    param_1[0x2b] = DAT_21000eac._2_2_;
  }
  param_1[0x2c] = uVar1;
  uVar10 = FUN_010200cc();
  if ((int)((ulonglong)uVar10 >> 0x20) << 0x1e < 0) {
    local_18 = CONCAT31(local_18._1_3_,1);
    local_14 = param_1;
    FUN_0101ea74((int)&local_18);
  }
  bVar8 = (char)DAT_2100120c != '\0';
  *(bool *)((int)param_1 + 0x73) = bVar8;
  uVar7 = DAT_2100121c;
  uVar5 = DAT_21001218;
  uVar4 = DAT_21001214;
  *(undefined4 *)(param_1 + 0x3e) = DAT_21001210;
  *(undefined4 *)(param_1 + 0x40) = uVar4;
  *(undefined4 *)(param_1 + 0x42) = uVar5;
  *(undefined4 *)(param_1 + 0x44) = uVar7;
  *(undefined4 *)(param_1 + 0x18) = DAT_21000eb4;
  puVar6 = &DAT_00001d4c;
  if (bVar8) {
    puVar6 = (undefined *)0x3e8;
  }
  *(undefined **)(param_1 + 10) = puVar6;
  iVar2 = FUN_0101ee60((int)param_1,uVar4,uVar5);
  uVar1 = *param_1;
  if (iVar2 == 0) goto LAB_0101f124;
  iVar3 = FUN_0100a564(uVar1,1);
  if (iVar3 == 0) {
    iVar2 = 9;
  }
  else {
    uVar4 = 0x57d;
    uVar5 = extraout_r2;
    uVar7 = extraout_r3;
    while( true ) {
      uVar1 = FUN_01009500(0x39,uVar4,uVar5,uVar7);
LAB_0101f124:
      iVar3 = FUN_0100a758(uVar1,DAT_21000eac._2_2_,DAT_21000eb0,(uint)(byte)DAT_21000eac,
                           (ushort)DAT_21000eac._1_1_);
      if (iVar3 == 0) break;
      uVar4 = 0x588;
      uVar5 = extraout_r2_00;
      uVar7 = extraout_r3_00;
    }
  }
  return iVar2;
}


