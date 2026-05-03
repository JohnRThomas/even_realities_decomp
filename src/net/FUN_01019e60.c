/*
 * Function: FUN_01019e60
 * Entry:    01019e60
 * Prototype: undefined __stdcall FUN_01019e60(void)
 */


void FUN_01019e60(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  ushort *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar8;
  undefined4 extraout_r2_02;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 uVar9;
  undefined4 extraout_r3_02;
  undefined4 *unaff_r5;
  ushort uStack_36;
  int aiStack_34 [2];
  ushort *puStack_2c;
  undefined4 *puStack_28;
  uint uStack_24;
  ushort uStack_16;
  int local_14;
  
  puVar4 = (ushort *)FUN_0100ada0();
  FUN_0102794a(puVar4,&local_14,&uStack_16);
  puVar5 = (undefined4 *)FUN_010278d2(local_14);
  bVar1 = *(byte *)((int)puVar5 + 0x1f);
  if (bVar1 == 0) {
    uVar6 = FUN_0102753e((short *)puVar4);
    if (uVar6 == 1) {
      return;
    }
    bVar3 = FUN_0100adb4();
    iVar7 = FUN_01027732((short *)puVar4,(ushort)bVar3,'\x01');
    uVar8 = extraout_r2;
    uVar9 = extraout_r3;
    if (iVar7 == 0) goto LAB_01019ece;
    uVar6 = FUN_0102753e((short *)puVar4);
    uVar8 = extraout_r2_00;
    uVar9 = extraout_r3_00;
    if (uVar6 != 0) {
      *(byte *)(puVar5 + 2) = bVar1;
      FUN_0100f788(puVar5,0x1019a9d,6);
      DAT_2100109c = 0;
      return;
    }
  }
  else {
    uVar6 = FUN_0102753e((short *)puVar4);
    uVar8 = extraout_r2_01;
    uVar9 = extraout_r3_01;
    puVar5 = unaff_r5;
    if (uVar6 != 0) {
      DAT_2100109c = 0;
      return;
    }
  }
  FUN_01009500(0x33,0x2be,uVar8,uVar9);
  uVar8 = extraout_r2_02;
  uVar9 = extraout_r3_02;
LAB_01019ece:
  FUN_01009500(0x33,0x2ba,uVar8,uVar9);
  puStack_2c = puVar4;
  puStack_28 = puVar5;
  uStack_24 = (uint)bVar1;
  puVar4 = (ushort *)FUN_0100ada0();
  FUN_0102794a(puVar4,aiStack_34,&uStack_36);
  iVar7 = FUN_010278d2(aiStack_34[0]);
  cVar2 = DAT_2100109e;
  puVar5 = DAT_21001098;
  if (*(char *)(iVar7 + 0x1f) != '\0') {
    if (DAT_21001098 != (undefined4 *)0x0) {
      *(byte *)(DAT_21001098 + 7) = *(byte *)(DAT_21001098 + 7) & 0x9f | 0x40;
      *(undefined1 *)(puVar5 + 2) = 0;
      FUN_0100f788(puVar5,0x1019a9d,6);
      if (cVar2 != '\0') {
        *(undefined1 *)((int)puVar5 + 0x11) = 0;
        FUN_0100f788((undefined4 *)((int)puVar5 + 9),0x1019a9d,6);
      }
      DAT_21001098 = (undefined4 *)0x0;
      DAT_2100109e = '\0';
    }
    FUN_01019e60();
    return;
  }
  return;
}


