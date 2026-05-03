/*
 * Function: FUN_0101b650
 * Entry:    0101b650
 * Prototype: uint __stdcall FUN_0101b650(void)
 */


/* WARNING: Removing unreachable block (ram,0x0101b91a) */
/* WARNING: Removing unreachable block (ram,0x0101b7a6) */
/* WARNING: Removing unreachable block (ram,0x0101b87a) */
/* WARNING: Removing unreachable block (ram,0x0101b884) */
/* WARNING: Removing unreachable block (ram,0x0101b892) */
/* WARNING: Removing unreachable block (ram,0x0101b8a0) */
/* WARNING: Removing unreachable block (ram,0x0101b8c8) */
/* WARNING: Removing unreachable block (ram,0x0101b8de) */
/* WARNING: Removing unreachable block (ram,0x0101b8f0) */
/* WARNING: Removing unreachable block (ram,0x0101b8fe) */
/* WARNING: Removing unreachable block (ram,0x0101b908) */
/* WARNING: Removing unreachable block (ram,0x0101b924) */
/* WARNING: Removing unreachable block (ram,0x0101b92e) */
/* WARNING: Removing unreachable block (ram,0x0101b938) */
/* WARNING: Removing unreachable block (ram,0x0101b994) */
/* WARNING: Removing unreachable block (ram,0x0101b9a2) */
/* WARNING: Removing unreachable block (ram,0x0101b9a4) */
/* WARNING: Removing unreachable block (ram,0x0101b9a6) */
/* WARNING: Removing unreachable block (ram,0x0101b9a8) */
/* WARNING: Removing unreachable block (ram,0x0101b9b0) */
/* WARNING: Removing unreachable block (ram,0x0101b9ba) */
/* WARNING: Removing unreachable block (ram,0x0101b9bc) */
/* WARNING: Removing unreachable block (ram,0x0101b9be) */
/* WARNING: Removing unreachable block (ram,0x0101b982) */
/* WARNING: Removing unreachable block (ram,0x0101b910) */
/* WARNING: Removing unreachable block (ram,0x0101b7b4) */
/* WARNING: Removing unreachable block (ram,0x0101b846) */
/* WARNING: Removing unreachable block (ram,0x0101b7c6) */
/* WARNING: Removing unreachable block (ram,0x0101b7d8) */
/* WARNING: Removing unreachable block (ram,0x0101b85e) */
/* WARNING: Removing unreachable block (ram,0x0101b864) */
/* WARNING: Removing unreachable block (ram,0x0101b7ec) */
/* WARNING: Removing unreachable block (ram,0x0101b94a) */
/* WARNING: Removing unreachable block (ram,0x0101b6c8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0101b650(void)

{
  byte bVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  int iVar7;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 uVar8;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined1 extraout_r3;
  undefined4 extraout_r3_00;
  uint uVar9;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 uVar10;
  undefined4 extraout_r3_05;
  uint extraout_r3_06;
  uint uVar11;
  byte abStack_48 [4];
  int aiStack_44 [5];
  undefined1 *puStack_30;
  
  if (DAT_210010a0 != 0) {
    FUN_0101b538();
  }
  DAT_21001114 = 0;
  if (DAT_210010a0 == 0) {
    DAT_210010cf = DAT_210010a0;
    DAT_210010a4 = &DAT_00002710;
    DAT_21001100 = &DAT_00002710;
    DAT_21001104 = 0x271;
    iVar2 = FUN_0101a930();
    DAT_210010a8 = (int)&DAT_00002710 - iVar2;
    return 0;
  }
  FUN_01009500(0x21,800,0,(uint)DAT_210010a0);
  FUN_01026284((undefined4 *)&DAT_210010a0,0,0x78);
  puVar3 = FUN_01019a04();
  DAT_21001118 = 0;
  *puVar3 = 0x20;
  uVar4 = FUN_0101b650();
  if (uVar4 == 0) {
    return 0;
  }
  FUN_01009500(0x21,0x235,extraout_r2,extraout_r3_00);
  puStack_30 = &DAT_210010a0;
  if (DAT_210010a0 != 0) {
    return 0xc;
  }
  pbVar5 = FUN_01019a04();
  bVar1 = DAT_08400728;
  uVar9 = (uint)DAT_08400728;
  DAT_210010c8 = 0x8400428;
  uVar8 = extraout_r2_00;
  uVar4 = uVar9;
  if (uVar9 == 0) {
    DAT_210010a1 = DAT_08400728;
    DAT_210010ce = DAT_08400728;
    DAT_210010a0 = 5;
    DAT_21001114 = (ushort)DAT_08400728;
    DAT_210010cc = DAT_08400728;
    iVar2 = FUN_0101a930();
    DAT_210010f8 = 0;
    uVar4 = 0;
    uVar11 = 0;
    do {
      iVar7 = uVar4 + 2;
      uVar11 = uVar11 + 1;
      uVar4 = uVar11 & 0xff;
      DAT_210010f8 = DAT_210010f8 + iVar2 + *(int *)(&DAT_210010a0 + iVar7 * 4);
    } while (uVar4 <= DAT_210010cf);
    uVar4 = FUN_01023634(0x101b321,0);
    *pbVar5 = (byte)uVar4;
    uVar8 = extraout_r2_01;
    uVar10 = extraout_r3_01;
    if (uVar4 != 0x20) {
      pbVar6 = FUN_0101ab8c(abStack_48,1,(uint *)0x0,(uint *)0x0);
      uVar8 = extraout_r2_02;
      uVar10 = extraout_r3_02;
      if (pbVar6 != (byte *)0x0) {
        uVar4 = FUN_010239c8((uint)*pbVar5,abStack_48);
        if (uVar4 != 0) {
          return 0;
        }
        FUN_01009500(0x21,0x312,extraout_r2_03,extraout_r3_03);
        uVar8 = extraout_r2_04;
        uVar10 = extraout_r3_04;
      }
      FUN_01009500(0x21,0x311,uVar8,uVar10);
      uVar8 = extraout_r2_05;
      uVar10 = extraout_r3_05;
    }
    FUN_01009500(0x21,0x30e,uVar8,uVar10);
    uVar8 = extraout_r2_06;
    uVar4 = extraout_r3_06;
  }
  FUN_01009500(0x21,0x300,uVar8,uVar4);
                    /* WARNING: Read-only address (ram,0x0000002f) is written */
  _Reset = 0;
                    /* WARNING: Read-only address (ram,0x00000060) is written */
  _UNK_00000060 = 0;
                    /* WARNING: Read-only address (ram,0x00000064) is written */
  _DAT_00000064 = 0x271;
  UNK_0000002f = extraout_r3;
  iVar2 = FUN_0101a930();
  uVar4 = uVar9 & 1;
  if ((bVar1 & 1) != 0) {
    _NMI = aiStack_44[0] - iVar2;
                    /* WARNING: Read-only address (ram,0x00000008) is written */
  }
  uVar11 = uVar4;
  if ((int)(uVar9 << 0x1e) < 0) {
    uVar11 = uVar4 + 1;
    *(int *)((uVar4 + 2) * 4) = aiStack_44[uVar4] - iVar2;
  }
  if ((int)(uVar9 << 0x1c) < 0) {
    *(int *)((uVar11 + 2) * 4) = aiStack_44[uVar11] - iVar2;
  }
  return 0;
}


