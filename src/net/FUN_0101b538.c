/*
 * Function: FUN_0101b538
 * Entry:    0101b538
 * Prototype: uint __stdcall FUN_0101b538(void)
 */


/* WARNING: Possible PIC construction at 0x0101b6c0: Changing call to branch */
/* WARNING (jumptable): Removing unreachable block (ram,0x0101b6c4) */
/* WARNING (jumptable): Removing unreachable block (ram,0x0101b6c6) */
/* WARNING: Removing unreachable block (ram,0x0101b6c4) */
/* WARNING: Removing unreachable block (ram,0x0101b6c6) */
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
/* WARNING: Removing unreachable block (ram,0x0101b76e) */
/* WARNING: Removing unreachable block (ram,0x0101b6ee) */
/* WARNING: Removing unreachable block (ram,0x0101b706) */
/* WARNING: Removing unreachable block (ram,0x0101b726) */
/* WARNING: Removing unreachable block (ram,0x0101b73e) */
/* WARNING: Removing unreachable block (ram,0x0101b74e) */
/* WARNING: Removing unreachable block (ram,0x0101b75c) */
/* WARNING: Removing unreachable block (ram,0x0101b766) */
/* WARNING: Removing unreachable block (ram,0x0101b778) */
/* WARNING: Removing unreachable block (ram,0x0101b782) */
/* WARNING: Removing unreachable block (ram,0x0101b78c) */
/* WARNING: Removing unreachable block (ram,0x0101b796) */
/* WARNING: Removing unreachable block (ram,0x0101b80a) */
/* WARNING: Removing unreachable block (ram,0x0101b810) */
/* WARNING: Removing unreachable block (ram,0x0101b814) */
/* WARNING: Removing unreachable block (ram,0x0101b82a) */
/* WARNING: Removing unreachable block (ram,0x0101b82e) */
/* WARNING: Removing unreachable block (ram,0x0101b840) */

uint FUN_0101b538(void)

{
  bool bVar1;
  char cVar2;
  byte *pbVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  uint uVar6;
  uint extraout_r2;
  undefined4 extraout_r2_00;
  uint extraout_r2_01;
  uint extraout_r2_02;
  uint extraout_r2_03;
  uint extraout_r2_04;
  undefined4 extraout_r3;
  uint uVar7;
  int extraout_r3_00;
  uint extraout_r3_01;
  byte *pbVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  ulonglong uVar12;
  
  puVar10 = (undefined4 *)&stack0xfffffff0;
  pbVar8 = &DAT_210010a0;
  pbVar3 = FUN_01019a04();
  if ((DAT_210010a0 != 4) && (DAT_210010a0 != 5)) {
    return 0xc;
  }
  uVar6 = 1;
  DAT_210010a1 = 1;
  if (DAT_210010b4 == '\0') {
    FUN_01023fb0((uint)*pbVar3);
    uVar6 = (uint)pbVar3[3];
    uVar9 = 0;
    iVar4 = 0;
    uVar11 = extraout_r1_00;
    if (uVar6 != 0 || (pbVar3[4] & 0x1f) != 0) {
      FUN_01019a0c(3,0,uVar6);
      uVar11 = extraout_r1_01;
      uVar6 = extraout_r2_01;
      iVar4 = extraout_r3_00;
    }
  }
  else {
    uVar9 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar9 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    uVar11 = extraout_r1;
    cVar2 = DAT_210010b4;
    if (((DAT_210010b4 != '\0') && (DAT_210010b5 != '\0')) &&
       (FUN_010198d0(), uVar11 = extraout_r1_02, uVar6 = extraout_r2_02, cVar2 = '\0',
       DAT_210010b4 != '\0')) {
      FUN_01020e34();
      FUN_01023284();
      DAT_210010b4 = '\0';
      DAT_210010b5 = '\0';
      uVar11 = extraout_r1_03;
      uVar6 = extraout_r2_03;
      cVar2 = DAT_210010b4;
    }
    DAT_210010b4 = cVar2;
    iVar4 = 0;
    if (uVar9 == 0) {
      iVar4 = 0;
      enableIRQinterrupts();
    }
  }
  uVar12 = FUN_0102491c((uint)*pbVar3,uVar11,uVar6,iVar4);
  if (DAT_210010cc == '\0') {
    if ((DAT_210010a0 == 5) && (DAT_21001110 == 0)) {
      FUN_0101e50c(DAT_210010c8 + 0x2d8);
    }
LAB_0101b582:
    FUN_0101e50c(0x210010f0);
  }
  else {
    uVar7 = (uint)DAT_210010a0;
    uVar6 = extraout_r2;
    if (uVar7 != 5) goto LAB_0101b63e;
    if (DAT_21001110 == 0) goto LAB_0101b582;
    FUN_0101e660(0x210010f0,(int)(uVar12 >> 0x20),extraout_r2);
  }
  pbVar3 = (byte *)0x0;
  DAT_210010a1 = 0;
  if (DAT_210010cc == '\0') {
    uVar9 = 0;
  }
  else {
    uVar9 = 0xc;
  }
  FUN_01019a54();
  DAT_210010cc = '\0';
  DAT_210010a2 = 0;
  DAT_210010c8 = 0;
  if (DAT_210010a0 == 4) {
    FUN_01019ee0();
  }
  DAT_210010a0 = 0;
  pbVar8 = FUN_01019a04();
  cVar2 = FUN_010236bc((uint)*pbVar8);
  if (cVar2 != '\0') {
    *pbVar8 = 0x20;
    return uVar9;
  }
  FUN_01009500(0x21,0x396,extraout_r2_00,extraout_r3);
  uVar6 = extraout_r2_04;
  uVar7 = extraout_r3_01;
LAB_0101b63e:
  uVar11 = 0x101b649;
  FUN_01009500(0x21,0x25b,uVar6,uVar7);
  while( true ) {
    puVar10[-1] = uVar11;
    puVar10[-2] = uVar9;
    puVar10[-3] = pbVar3;
    puVar10[-4] = pbVar8;
    if (DAT_210010a0 != 0) {
      FUN_0101b538();
    }
    uVar9 = (uint)DAT_210010a0;
    DAT_21001114 = 0;
    if (uVar9 == 0) break;
    FUN_01009500(0x21,800,0,uVar9);
    puVar10[-5] = 0x101b699;
    puVar10 = puVar10 + -6;
    *puVar10 = &DAT_210010a0;
    pbVar8 = &DAT_210010a0;
    FUN_01026284((undefined4 *)&DAT_210010a0,0,0x78);
    puVar5 = FUN_01019a04();
    DAT_21001118 = 0;
    *puVar5 = 0x20;
    uVar11 = 0x101b6c5;
  }
  DAT_210010cf = DAT_210010a0;
  DAT_210010a4 = &DAT_00002710;
  DAT_21001100 = &DAT_00002710;
  DAT_21001104 = 0x271;
  iVar4 = FUN_0101a930();
  DAT_210010a8 = (int)&DAT_00002710 - iVar4;
  return 0;
}


