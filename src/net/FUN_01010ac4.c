/*
 * Function: FUN_01010ac4
 * Entry:    01010ac4
 * Prototype: byte * __stdcall FUN_01010ac4(byte * param_1, int param_2)
 */


byte * FUN_01010ac4(byte *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  int extraout_r2;
  int extraout_r2_00;
  int extraout_r2_01;
  int extraout_r2_02;
  undefined4 extraout_r2_03;
  int extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 uVar9;
  undefined4 extraout_r3;
  uint extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  undefined8 uVar15;
  
  iVar14 = *(int *)(param_1 + 4);
  bVar1 = *param_1;
  uVar12 = (uint)bVar1;
  iVar11 = iVar14 + 0xa8;
  if (uVar12 == 0) {
    uVar5 = FUN_0100dbc0(iVar11,8,(uint)*(byte *)(iVar14 + 0xc5),0);
    iVar13 = extraout_r2;
    if ((uVar5 == 0) &&
       (uVar5 = FUN_0100dbc0(iVar11,0,(uint)*(byte *)(iVar14 + 0xc6),0), iVar13 = extraout_r2_01,
       uVar5 == 0)) {
      return &DAT_00000001;
    }
LAB_01010ae4:
    bVar2 = *(byte *)(iVar14 + 0x107);
  }
  else {
    uVar5 = FUN_0100dbc0(iVar11,8,(uint)*(byte *)(iVar14 + 0xc5),uVar12);
    iVar13 = extraout_r2_00;
    if (uVar5 != 0) goto LAB_01010ae4;
    if (*(int *)(iVar14 + 0xb4) << 0x1e < 0) {
      return &DAT_00000001;
    }
    bVar2 = *(byte *)(iVar14 + 0x107);
  }
  uVar5 = (uint)bVar2;
  if (-1 < (int)(uVar5 << 0x1e)) {
    uVar4 = FUN_0100efac(param_2);
    *(undefined1 *)(iVar14 + 0x111) = uVar4;
    *(undefined2 *)(iVar14 + 0x112) = *(undefined2 *)(param_2 + 5);
    bVar2 = *(byte *)(iVar14 + 0x107) | 2;
    *(undefined2 *)(iVar14 + 0x114) = *(undefined2 *)(param_2 + 7);
    iVar13 = (uint)*(byte *)(iVar14 + 0x107) << 0x1f;
    *(byte *)(iVar14 + 0x107) = bVar2;
    if (iVar13 < 0) {
      FUN_0100f7c8((undefined4 *)(iVar14 + 0x108),0x1010aa1,2);
      uVar5 = (uint)*(byte *)(iVar14 + 0x107);
      iVar13 = extraout_r2_02;
    }
    else {
      uVar5 = (uint)bVar2;
    }
  }
  if ((int)(uVar5 << 0x1f) < 0) {
LAB_01010b10:
    if (*(char *)(iVar14 + 0xc5) != '\x01') {
      return (byte *)0x0;
    }
    *(undefined1 *)(iVar14 + 0xc5) = 0;
    *(undefined1 *)(iVar14 + 0x100) = 0;
    return (byte *)0x0;
  }
  if (uVar12 == 0) {
    uVar12 = FUN_0100dbc0(iVar11,0,(uint)*(byte *)(iVar14 + 0xc6),0);
    if (uVar12 != 0) {
      *(ushort *)(iVar14 + 0x102) = (ushort)bVar1;
      *(undefined1 *)(iVar14 + 0xc6) = 1;
      *(undefined1 *)(iVar14 + 0x104) = 1;
      goto LAB_01010b10;
    }
    FUN_01009500(0x40,0x49,extraout_r2_03,extraout_r3);
    iVar13 = extraout_r2_04;
    uVar12 = extraout_r3_00;
  }
  else {
    uVar12 = *(uint *)(iVar14 + 0xb4);
    if ((uVar12 & 2) == 0) {
      *(undefined2 *)(iVar14 + 0x102) = 0;
      *(uint *)(iVar14 + 0xb4) = uVar12 | 2;
      *(char *)(iVar14 + 0x104) = *(char *)(iVar14 + 0x104) + '\x01';
      goto LAB_01010b10;
    }
  }
  pbVar6 = (byte *)FUN_01009500(0x40,0x50,iVar13,uVar12);
  bVar1 = *pbVar6;
  if (bVar1 == 0) {
    iVar13 = *(int *)(pbVar6 + 4);
    iVar11 = iVar13 + 0xa8;
    iVar14 = iVar13 + 0x160;
    if ((int)((uint)*(byte *)(iVar13 + 0x107) << 0x1e) < 0) {
      pbVar7 = (byte *)FUN_0100dbc0(iVar11,0,(uint)*(byte *)(iVar13 + 0xc6),0);
      pbVar6 = (byte *)0x0;
      if (pbVar7 != (byte *)0x0) {
        *(byte *)(iVar13 + 0x104) = bVar1;
        *(undefined1 *)(iVar13 + 0x172) = 0;
        return pbVar7;
      }
      goto LAB_01010c28;
    }
  }
  else {
    iVar11 = *(int *)(pbVar6 + 4);
    iVar14 = iVar11 + 0x160;
    if ((int)((uint)*(byte *)(iVar11 + 0x107) << 0x1e) < 0) {
      uVar12 = *(uint *)(iVar11 + 0xb4);
      if (-1 < (int)(uVar12 << 0x1e)) {
LAB_01010c28:
        *(undefined1 *)(iVar14 + 0x12) = 0;
        return pbVar6;
      }
      cVar3 = *(char *)(iVar11 + 0x104) + -1;
      *(char *)(iVar11 + 0x104) = cVar3;
      if (-1 < cVar3) {
        *(uint *)(iVar11 + 0xb4) = uVar12 & 0xfffffffd;
        goto LAB_01010c28;
      }
      FUN_01009500(0x40,0x81,(int)cVar3,uVar12);
      uVar9 = extraout_r2_06;
      uVar10 = extraout_r3_02;
      goto LAB_01010c56;
    }
    iVar11 = iVar11 + 0xa8;
  }
  pbVar6 = (byte *)FUN_0100dbc0(iVar11,0,(uint)*(byte *)(iVar11 + 0x1d),(uint)bVar1);
  uVar9 = extraout_r2_05;
  uVar10 = extraout_r3_01;
  if (pbVar6 != (byte *)0x0) {
    *(undefined1 *)(iVar11 + 0x1d) = 1;
    *(undefined1 *)(iVar11 + 0x58) = 1;
    *(undefined2 *)(iVar11 + 0x54) = 0;
    return pbVar6;
  }
LAB_01010c56:
  uVar15 = FUN_01009500(0x40,0x6f,uVar9,uVar10);
  puVar8 = (undefined1 *)((ulonglong)uVar15 >> 0x20);
  do {
    *puVar8 = 0x2e;
    *(undefined4 *)(puVar8 + 3) = *(undefined4 *)((int)uVar15 + 9);
  } while( true );
}


