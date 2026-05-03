/*
 * Function: FUN_0100f804
 * Entry:    0100f804
 * Prototype: undefined2 __stdcall FUN_0100f804(int param_1, undefined1 * param_2)
 */


undefined2 FUN_0100f804(int param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined8 uVar9;
  undefined2 uStack_3c;
  undefined1 auStack_28 [2];
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  ushort local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  uVar4 = FUN_0100f134();
  if (uVar4 == 0) {
    uVar8 = *(undefined4 *)(param_1 + 9);
    uVar5 = *(undefined4 *)(param_1 + 0xd);
    *param_2 = 0x2f;
    uVar3 = *(undefined2 *)(param_1 + 0x11);
    *(undefined4 *)(param_2 + 3) = uVar8;
    *(undefined4 *)(param_2 + 7) = uVar5;
    *(undefined2 *)(param_2 + 0xb) = uVar3;
    return 4;
  }
  *(undefined1 *)(param_1 + 8) = 0;
  uVar2 = *(ushort *)(param_1 + -0x1e2);
  iVar6 = FUN_0102937c((uint)uVar2,auStack_28,0);
  if (iVar6 == 0) {
    local_1a = local_22;
    local_18 = local_20;
    local_16 = local_26;
    local_14 = local_24;
    local_1c = uVar2;
    iVar6 = FUN_01028e56(&local_1c);
    uVar5 = extraout_r2_00;
    uVar8 = extraout_r3_00;
    if (iVar6 == 0) {
      return 0;
    }
  }
  else {
    FUN_01009500(0x2c,0xfc,extraout_r2,extraout_r3);
    uVar5 = extraout_r2_01;
    uVar8 = extraout_r3_01;
  }
  uVar9 = FUN_01009500(0x2c,0x105,uVar5,uVar8);
  puVar7 = (undefined1 *)((ulonglong)uVar9 >> 0x20);
  iVar6 = (int)uVar9;
  uVar4 = FUN_0100f148(*(byte *)(iVar6 + 0x13) & 1);
  if (uVar4 == 0) {
    uVar8 = *(undefined4 *)(iVar6 + 9);
    uVar5 = *(undefined4 *)(iVar6 + 0xd);
    *puVar7 = 0x14;
    *(undefined4 *)(puVar7 + 2) = uVar8;
    uVar1 = *(undefined1 *)(iVar6 + 0x13);
    *(undefined2 *)(puVar7 + 10) = *(undefined2 *)(iVar6 + 0x11);
    *(undefined4 *)(puVar7 + 6) = uVar5;
    puVar7[0xc] = uVar1;
    uStack_3c = 4;
  }
  else {
    uStack_3c = 0;
  }
  return uStack_3c;
}


