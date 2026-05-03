/*
 * Function: FUN_01019f50
 * Entry:    01019f50
 * Prototype: uint __stdcall FUN_01019f50(int param_1, short * param_2, undefined4 * param_3, int param_4, byte param_5, undefined1 param_6, undefined1 param_7)
 */


uint FUN_01019f50(int param_1,short *param_2,undefined4 *param_3,int param_4,byte param_5,
                 undefined1 param_6,undefined1 param_7)

{
  byte bVar1;
  ushort *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  short *psVar6;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 uVar7;
  undefined1 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 extraout_r3_05;
  undefined4 *puVar8;
  undefined4 extraout_r3_06;
  undefined4 uVar9;
  uint uVar10;
  byte in_stack_00000244;
  ushort uStack_66;
  int aiStack_64 [2];
  undefined4 uStack_5c;
  ushort uStack_56;
  int aiStack_54 [2];
  undefined4 *puStack_4c;
  short *psStack_48;
  int iStack_44;
  int iStack_40;
  undefined4 *puStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  undefined1 uStack_30;
  ushort uStack_2e;
  int local_2c [2];
  
  uVar10 = (uint)param_5;
  puVar2 = (ushort *)FUN_0100ada0();
  uVar3 = FUN_0102753e((short *)puVar2);
  if (uVar3 == 1) {
    return 1;
  }
  FUN_0102794a(puVar2,local_2c,&uStack_2e);
  puVar4 = (undefined4 *)FUN_010278d2(local_2c[0]);
  *(undefined4 *)((int)puVar4 + 0x12) = 0;
  *(undefined4 *)((int)puVar4 + 0x16) = 0;
  *(undefined4 *)((int)puVar4 + 0x1a) = 0;
  *(undefined4 *)((int)puVar4 + 0x1e) = 0;
  *(undefined4 *)((int)puVar4 + 0x22) = 0;
  *(undefined4 *)((int)puVar4 + 0x26) = 0;
  *(undefined4 *)((int)puVar4 + 0x2a) = 0;
  *(undefined1 *)((int)puVar4 + 0x12) = 1;
  switch(param_2) {
  case (short *)0x0:
    *(byte *)(puVar4 + 7) = *(byte *)(puVar4 + 7) & 0xec | 0x13;
    break;
  case (short *)0x1:
    *(byte *)(puVar4 + 7) = *(byte *)(puVar4 + 7) & 0xea | 0x15;
    break;
  case (short *)0x2:
    *(byte *)(puVar4 + 7) = *(byte *)(puVar4 + 7) | 0x10;
    break;
  default:
    FUN_01009500(0x33,0x314,extraout_r2,1);
    uVar7 = extraout_r2_02;
    uVar9 = extraout_r3_02;
    goto LAB_0101a0b6;
  case (short *)0x6:
    *(byte *)(puVar4 + 7) = *(byte *)(puVar4 + 7) & 0xed | 0x12;
  }
  if (uVar10 == 0xff) {
    *(undefined1 *)((int)puVar4 + 0x13) = *(undefined1 *)(param_1 + 0x11);
    puVar8 = *(undefined4 **)(param_1 + 4);
    puVar4[5] = *puVar8;
    *(undefined2 *)(puVar4 + 6) = *(undefined2 *)(puVar8 + 1);
LAB_01019ff0:
    *(undefined1 *)((int)puVar4 + 0x1b) = param_7;
    *(undefined2 *)((int)puVar4 + 0x1e) = 1;
    *(undefined1 *)(puVar4 + 8) = 0xff;
    if ((int)((uint)*(byte *)(puVar4 + 7) << 0x1d) < 0) {
      if (param_4 - 2U < 2) {
        *(undefined4 *)((int)puVar4 + 0x26) = *param_3;
        *(undefined2 *)((int)puVar4 + 0x2a) = *(undefined2 *)(param_3 + 1);
      }
      else {
        puVar8 = *(undefined4 **)(param_1 + 8);
        *(undefined4 *)((int)puVar4 + 0x26) = *puVar8;
        *(undefined2 *)((int)puVar4 + 0x2a) = *(undefined2 *)(puVar8 + 1);
      }
      *(char *)((int)puVar4 + 0x25) = (char)param_4;
    }
    else {
      *(undefined1 *)((int)puVar4 + 0x25) = 0xff;
    }
    *(undefined1 *)((int)puVar4 + 0x2d) = param_6;
    *(undefined1 *)(puVar4 + 0xb) = 0x7f;
    param_2 = (short *)FUN_0100ada0();
    bVar1 = FUN_0100adb4();
    iVar5 = FUN_01027732(param_2,(ushort)bVar1,'\x01');
    uVar7 = extraout_r2_01;
    uVar9 = extraout_r3_01;
    if (iVar5 != 0) {
      *(undefined1 *)(puVar4 + 2) = 0;
      uVar3 = FUN_0100f788(puVar4,0x1019a9d,6);
      return uVar3;
    }
LAB_0101a0b6:
    FUN_01009500(0x33,0x334,uVar7,uVar9);
    uVar7 = extraout_r2_03;
    uVar9 = extraout_r3_03;
  }
  else {
    iVar5 = FUN_0100d298(uVar10,(undefined1 *)((int)puVar4 + 0x13),puVar4 + 5);
    uVar7 = extraout_r2_00;
    uVar9 = extraout_r3_00;
    if (iVar5 != 0) {
      *(byte *)((int)puVar4 + 0x13) = *(byte *)((int)puVar4 + 0x13) | 2;
      goto LAB_01019ff0;
    }
  }
  iVar5 = FUN_01009500(0x33,0xe6,uVar7,uVar9);
  uStack_34 = 0x101a0c9;
  puStack_4c = puVar4;
  psStack_48 = param_2;
  iStack_44 = param_1;
  iStack_40 = param_4;
  puStack_3c = param_3;
  uStack_38 = uVar10;
  puVar2 = (ushort *)FUN_0100ada0();
  uVar3 = FUN_0102753e((short *)puVar2);
  if (uVar3 == 1) {
    return 1;
  }
  FUN_0102794a(puVar2,aiStack_54,&uStack_56);
  puVar4 = (undefined4 *)FUN_010278d2(aiStack_54[0]);
  *(undefined4 *)((int)puVar4 + 0x12) = 0;
  *(undefined4 *)((int)puVar4 + 0x16) = 0;
  *(undefined4 *)((int)puVar4 + 0x1a) = 0;
  *(undefined4 *)((int)puVar4 + 0x1e) = 0;
  *(undefined4 *)((int)puVar4 + 0x22) = 0;
  *(undefined4 *)((int)puVar4 + 0x26) = 0;
  *(undefined4 *)((int)puVar4 + 0x2a) = 0;
  *(undefined1 *)((int)puVar4 + 0x12) = 1;
  if (iVar5 * 0x10 == 0xff) {
    *(undefined1 *)((int)puVar4 + 0x13) = *(undefined1 *)(iVar5 + 0x11);
    puVar8 = *(undefined4 **)(iVar5 + 4);
    puVar4[5] = *puVar8;
    *(undefined2 *)(puVar4 + 6) = *(undefined2 *)(puVar8 + 1);
  }
  else {
    iVar5 = FUN_0100d298(iVar5 * 0x10,(undefined1 *)((int)puVar4 + 0x13),puVar4 + 5);
    uVar7 = extraout_r2_04;
    uVar9 = extraout_r3_04;
    if (iVar5 == 0) goto LAB_0101a1be;
    *(byte *)((int)puVar4 + 0x13) = *(byte *)((int)puVar4 + 0x13) | 2;
  }
  *(undefined1 *)((int)puVar4 + 0x2d) = extraout_r3;
  *(undefined1 *)((int)puVar4 + 0x1b) = uStack_30;
  *(undefined1 *)(puVar4 + 8) = 0xff;
  *(undefined1 *)((int)puVar4 + 0x25) = 0xff;
  *(byte *)(puVar4 + 7) = in_stack_00000244 & 0x1b | 0x1a | *(byte *)(puVar4 + 7) & 0xe4;
  *(undefined1 *)(puVar4 + 0xb) = 0x7f;
  *(undefined2 *)((int)puVar4 + 0x1e) = 1;
  psVar6 = (short *)FUN_0100ada0();
  bVar1 = FUN_0100adb4();
  iVar5 = FUN_01027732(psVar6,(ushort)bVar1,'\x01');
  if (iVar5 != 0) {
    *(undefined1 *)(puVar4 + 2) = 0;
    uVar3 = FUN_0100f788(puVar4,0x1019a9d,6);
    return uVar3;
  }
  FUN_01009500(0x33,0x361,extraout_r2_05,extraout_r3_05);
  uVar7 = extraout_r2_06;
  uVar9 = extraout_r3_06;
LAB_0101a1be:
  FUN_01009500(0x33,0xe6,uVar7,uVar9);
  uStack_5c = 0x101a1c7;
  puVar2 = (ushort *)FUN_0100ada0();
  FUN_0102794a(puVar2,aiStack_64,&uStack_66);
  iVar5 = FUN_010278d2(aiStack_64[0]);
  return (uint)(*(char *)(iVar5 + 0x13) != -1);
}


