/*
 * Function: FUN_0100f15c
 * Entry:    0100f15c
 * Prototype: int __stdcall FUN_0100f15c(undefined4 * param_1)
 */


int FUN_0100f15c(undefined4 *param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  ushort *puVar5;
  byte bVar6;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 uVar7;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 uVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  byte *local_38;
  byte *local_34;
  char local_30 [4];
  undefined4 *local_2c;
  char local_28 [4];
  undefined4 *local_24;
  
  if (*(char *)(param_1 + 2) == '\0') {
    uVar1 = *(ushort *)(param_1 + 1);
    uVar2 = *(ushort *)((int)param_1 + 6);
    uVar10 = (uint)uVar2;
    puVar11 = (undefined4 *)*param_1;
    iVar3 = FUN_0100d7c0(uVar1,local_30);
    if (iVar3 != 0) {
      return 1;
    }
    puVar9 = local_2c + 0x2a;
    if (uVar10 == 0) goto LAB_0100f182;
    puVar4 = (ushort *)FUN_0100a97c(uVar1,extraout_r1_00,extraout_r2_00);
    uVar7 = extraout_r2_01;
    uVar8 = extraout_r3;
    if (puVar4 == (ushort *)0x0) goto LAB_0100f2ce;
    puVar5 = FUN_010271ce(puVar4,uVar2);
    if ((puVar5 == (ushort *)0x0) || (DAT_21000eac._2_2_ < uVar10)) goto LAB_0100f1d4;
    FUN_0102789e((int)puVar4,puVar5,(int *)&local_38);
    local_38[0] = 0;
    local_38[1] = 0;
    local_38[2] = 0;
    FUN_0100eddc(local_38,2);
    FUN_01026198((undefined4 *)(local_38 + 3),puVar11,uVar10);
    iVar3 = FUN_010272cc(puVar4,uVar2);
    uVar7 = extraout_r2_04;
    uVar8 = extraout_r3_02;
    if (iVar3 == 0) goto LAB_0100f2d6;
    if (local_30[0] == '\0') goto LAB_0100f24a;
    local_24 = local_2c;
    if (*(char *)((int)local_2c + 0x2ea) != '\0') {
      *(undefined1 *)((int)local_2c + 0x2ea) = 0;
      FUN_010145a8(local_2c);
      local_24 = local_2c;
    }
  }
  else {
    if (*(char *)(param_1 + 2) != '\x01') {
      MasterStackPointer = 0x3d;
      return 0;
    }
    uVar1 = *(ushort *)(param_1 + 1);
    uVar2 = *(ushort *)((int)param_1 + 6);
    uVar10 = (uint)uVar2;
    puVar12 = (undefined4 *)*param_1;
    iVar3 = FUN_0100d7c0(uVar1,local_28);
    puVar11 = local_24;
    if (iVar3 != 0) {
      return 1;
    }
    puVar9 = local_24 + 0x2a;
    if (uVar10 == 0) {
LAB_0100f182:
      *(undefined1 *)(puVar9 + 9) = 1;
                    /* WARNING: Read-only address (ram,0x00000000) is written */
      return 1;
    }
    puVar4 = (ushort *)FUN_0100a97c(uVar1,extraout_r1,extraout_r2);
    uVar7 = extraout_r2_02;
    uVar8 = extraout_r3_00;
    if (puVar4 == (ushort *)0x0) {
LAB_0100f2ce:
      FUN_01009500(0x2b,0x67,uVar7,uVar8);
      uVar7 = extraout_r2_05;
      uVar8 = extraout_r3_03;
LAB_0100f2d6:
      iVar3 = FUN_01009500(0x2b,0x7c,uVar7,uVar8);
                    /* WARNING: Read-only address (ram,0x00000000) is written */
      MasterStackPointer = 2;
      LAB_00000002 = 1;
      return iVar3;
    }
    puVar5 = FUN_010271ce(puVar4,uVar2);
    if ((puVar5 == (ushort *)0x0) || (DAT_21000eac._2_2_ < uVar10)) {
LAB_0100f1d4:
      FUN_0100f440();
      return 1;
    }
    FUN_0102789e((int)puVar4,puVar5,(int *)&local_34);
    local_34[0] = 0;
    local_34[1] = 0;
    local_34[2] = 0;
    if (*(char *)(puVar11 + 0x33) == '\0') {
      bVar6 = 1;
    }
    else {
      bVar6 = 2;
    }
    FUN_0100eddc(local_34,bVar6);
    FUN_01026198((undefined4 *)(local_34 + 3),puVar12,uVar10);
    iVar3 = FUN_010272cc(puVar4,uVar2);
    uVar7 = extraout_r2_03;
    uVar8 = extraout_r3_01;
    if (iVar3 == 0) goto LAB_0100f2d6;
    if (local_28[0] == '\0') goto LAB_0100f24a;
    if (*(char *)((int)local_24 + 0x2ea) != '\0') {
      *(undefined1 *)((int)local_24 + 0x2ea) = 0;
      FUN_010145a8(local_24);
    }
  }
  *(undefined2 *)((int)local_24 + 0x2e2) = 0;
LAB_0100f24a:
  *(undefined1 *)(puVar9 + 9) = 0;
  return iVar3;
}


