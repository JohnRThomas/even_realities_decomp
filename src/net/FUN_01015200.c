/*
 * Function: FUN_01015200
 * Entry:    01015200
 * Prototype: undefined4 * __stdcall FUN_01015200(int param_1)
 */


undefined4 * FUN_01015200(int param_1)

{
  undefined2 *puVar1;
  bool bVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 extraout_r2;
  int extraout_r2_00;
  uint uVar9;
  undefined4 extraout_r3;
  uint extraout_r3_00;
  int iVar10;
  int iVar11;
  undefined8 uVar12;
  
  iVar8 = *(int *)(param_1 + 4);
  uVar9 = *(uint *)(iVar8 + 0xb4);
  if ((int)(uVar9 << 0x1b) < 0) {
    if (-1 < (int)(uVar9 << 0x1a)) {
      *(uint *)(iVar8 + 0xb4) = uVar9 & 0xffffffef;
      FUN_0100ffb0(param_1);
      puVar7 = FUN_01014698(*(undefined4 **)(param_1 + 4),5,extraout_r2,extraout_r3);
      return puVar7;
    }
  }
  else {
    FUN_01009500(0x31,0x50c,iVar8,uVar9);
    iVar8 = extraout_r2_00;
    uVar9 = extraout_r3_00;
  }
  uVar12 = FUN_01009500(0x31,0x50d,iVar8,uVar9);
  iVar10 = (int)((ulonglong)uVar12 >> 0x20);
  iVar8 = (int)uVar12;
  if ((*(uint *)(*(int *)(iVar8 + 4) + 0xb4) & 0x30) != 0) {
    return (undefined4 *)&DAT_00000001;
  }
  bVar2 = FUN_0100efe0(iVar10);
  if (!bVar2) {
    puVar7 = (undefined4 *)FUN_01010034(iVar8,iVar10);
    return puVar7;
  }
  iVar11 = *(int *)(iVar8 + 4);
  uVar3 = FUN_0100efd8(iVar10);
  uVar4 = FUN_0100efd0(iVar10);
  uVar5 = FUN_0100efdc(iVar10);
  uVar6 = FUN_0100efd4(iVar10);
  FUN_0100f998(iVar11 + 0x30,uVar3,uVar4,uVar5,uVar6);
  puVar1 = DAT_21000f6c;
  if (((int)((uint)DAT_21000f74 << 0x1e) < 0) && (*(char *)(DAT_21000f78 + 3) == '\x14')) {
    iVar10 = *(int *)(iVar8 + 4);
LAB_010152a8:
    *(undefined1 *)(iVar10 + 100) = 1;
  }
  else {
    iVar10 = *(int *)(iVar8 + 4);
    if (*(char *)(iVar10 + 0xc5) == '\x1e') goto LAB_010152a8;
    if (((*(char *)(iVar10 + 100) != '\x01') && (*(char *)(iVar10 + 0x163) == '\0')) &&
       (*(char *)(iVar10 + 0x162) == '\0')) {
      puVar7 = (undefined4 *)(DAT_21000f6c + 0xf1);
      *(uint *)(iVar10 + 0xb4) = *(uint *)(iVar10 + 0xb4) | 0x20;
      FUN_0100fad0(*puVar1,(int)(puVar1 + 0x18),puVar7);
      goto LAB_010152ba;
    }
  }
  *(uint *)(iVar10 + 0xb4) = *(uint *)(iVar10 + 0xb4) | 0x10;
LAB_010152ba:
  FUN_0100ff98(iVar8);
  return (undefined4 *)0x0;
}


