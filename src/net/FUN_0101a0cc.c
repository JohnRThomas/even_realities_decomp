/*
 * Function: FUN_0101a0cc
 * Entry:    0101a0cc
 * Prototype: uint __stdcall FUN_0101a0cc(int param_1, uint param_2, byte param_3, undefined1 param_4, undefined1 param_5)
 */


uint FUN_0101a0cc(int param_1,uint param_2,byte param_3,undefined1 param_4,undefined1 param_5)

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
  undefined4 uVar7;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 *puVar8;
  undefined4 extraout_r3_01;
  undefined4 uVar9;
  ushort uStack_36;
  int aiStack_34 [2];
  undefined4 uStack_2c;
  ushort uStack_26;
  int local_24 [2];
  
  puVar2 = (ushort *)FUN_0100ada0();
  uVar3 = FUN_0102753e((short *)puVar2);
  if (uVar3 == 1) {
    return 1;
  }
  FUN_0102794a(puVar2,local_24,&uStack_26);
  puVar4 = (undefined4 *)FUN_010278d2(local_24[0]);
  *(undefined4 *)((int)puVar4 + 0x12) = 0;
  *(undefined4 *)((int)puVar4 + 0x16) = 0;
  *(undefined4 *)((int)puVar4 + 0x1a) = 0;
  *(undefined4 *)((int)puVar4 + 0x1e) = 0;
  *(undefined4 *)((int)puVar4 + 0x22) = 0;
  *(undefined4 *)((int)puVar4 + 0x26) = 0;
  *(undefined4 *)((int)puVar4 + 0x2a) = 0;
  *(undefined1 *)((int)puVar4 + 0x12) = 1;
  if (param_2 == 0xff) {
    *(undefined1 *)((int)puVar4 + 0x13) = *(undefined1 *)(param_1 + 0x11);
    puVar8 = *(undefined4 **)(param_1 + 4);
    puVar4[5] = *puVar8;
    *(undefined2 *)(puVar4 + 6) = *(undefined2 *)(puVar8 + 1);
  }
  else {
    iVar5 = FUN_0100d298(param_2,(undefined1 *)((int)puVar4 + 0x13),puVar4 + 5);
    uVar7 = extraout_r2;
    uVar9 = extraout_r3;
    if (iVar5 == 0) goto LAB_0101a1be;
    *(byte *)((int)puVar4 + 0x13) = *(byte *)((int)puVar4 + 0x13) | 2;
  }
  *(undefined1 *)((int)puVar4 + 0x2d) = param_4;
  *(undefined1 *)((int)puVar4 + 0x1b) = param_5;
  *(undefined1 *)(puVar4 + 8) = 0xff;
  *(undefined1 *)((int)puVar4 + 0x25) = 0xff;
  *(byte *)(puVar4 + 7) = param_3 & 0x1b | 0x1a | *(byte *)(puVar4 + 7) & 0xe4;
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
  FUN_01009500(0x33,0x361,extraout_r2_00,extraout_r3_00);
  uVar7 = extraout_r2_01;
  uVar9 = extraout_r3_01;
LAB_0101a1be:
  FUN_01009500(0x33,0xe6,uVar7,uVar9);
  uStack_2c = 0x101a1c7;
  puVar2 = (ushort *)FUN_0100ada0();
  FUN_0102794a(puVar2,aiStack_34,&uStack_36);
  iVar5 = FUN_010278d2(aiStack_34[0]);
  return (uint)(*(char *)(iVar5 + 0x13) != -1);
}


