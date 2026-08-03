/*
 * Function: correlate_ltpf
 * Entry:    0006c7f4
 * Prototype: undefined __stdcall correlate_ltpf(int param_1, short * param_2, int param_3, undefined4 * param_4, int param_5)
 */


/* exclude_from_export */

void correlate_ltpf(int param_1,short *param_2,int param_3,undefined4 *param_4,int param_5)

{
  short *psVar1;
  short *psVar2;
  short *psVar3;
  short *psVar4;
  short *psVar5;
  short *psVar6;
  short *psVar7;
  short *psVar8;
  short *psVar9;
  short *psVar10;
  short *psVar11;
  short *psVar12;
  short *psVar13;
  short *psVar14;
  short *psVar15;
  short sVar16;
  short sVar17;
  short sVar18;
  short sVar19;
  short sVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  longlong lVar23;
  longlong lVar24;
  uint uVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  short *psVar30;
  undefined4 *puVar31;
  undefined4 *puVar32;
  short *psVar33;
  undefined4 *puVar34;
  uint in_fpscr;
  undefined4 uVar35;
  undefined4 uVar36;
  
  iVar29 = param_3 >> 4;
  psVar30 = param_2;
  puVar34 = param_4;
  if (((uint)param_2 & 3) != 0) {
    lVar24 = 0;
    psVar30 = param_2 + -1;
    puVar34 = param_4 + 1;
    iVar28 = param_1 + 0x20;
    do {
      iVar26 = iVar28 + 0x20;
      lVar24 = (longlong)((int)*(short *)(iVar28 + -2) * (int)param_2[0xf]) +
               (longlong)((int)*(short *)(iVar28 + -4) * (int)param_2[0xe]) +
               (longlong)((int)*(short *)(iVar28 + -6) * (int)param_2[0xd]) +
               (longlong)((int)*(short *)(iVar28 + -8) * (int)param_2[0xc]) +
               (longlong)((int)*(short *)(iVar28 + -10) * (int)param_2[0xb]) +
               (longlong)((int)*(short *)(iVar28 + -0xc) * (int)param_2[10]) +
               (longlong)((int)*(short *)(iVar28 + -0xe) * (int)param_2[9]) +
               (longlong)((int)*(short *)(iVar28 + -0x10) * (int)param_2[8]) +
               (longlong)((int)*(short *)(iVar28 + -0x12) * (int)param_2[7]) +
               (longlong)((int)*(short *)(iVar28 + -0x14) * (int)param_2[6]) +
               (longlong)((int)*(short *)(iVar28 + -0x16) * (int)param_2[5]) +
               (longlong)((int)*(short *)(iVar28 + -0x18) * (int)param_2[4]) +
               (longlong)((int)*(short *)(iVar28 + -0x1a) * (int)param_2[3]) +
               (longlong)((int)*(short *)(iVar28 + -0x1c) * (int)param_2[2]) +
               (longlong)((int)*(short *)(iVar28 + -0x1e) * (int)param_2[1]) +
               (int)*(short *)(iVar28 + -0x20) * (int)*param_2 + lVar24;
      iVar28 = iVar26;
      param_2 = param_2 + 0x10;
    } while (param_1 + 0x20 + iVar29 * 0x20 != iVar26);
    uVar35 = VectorSignedToFloat((uint)(lVar24 + 0x20) >> 6 |
                                 (int)((ulonglong)(lVar24 + 0x20) >> 0x20) * 0x4000000,
                                 (byte)(in_fpscr >> 0x16) & 3);
    *param_4 = uVar35;
    param_5 = param_5 + -1;
  }
  if (1 < param_5) {
    uVar25 = param_5 - 2U >> 1;
    puVar31 = puVar34 + 2;
    psVar33 = psVar30;
    do {
      lVar23 = 0;
      iVar26 = (int)psVar33[-1] << 0x10;
      lVar24 = 0;
      iVar28 = param_1 + 0x20;
      psVar1 = psVar33;
      do {
        sVar17 = (short)((uint)*(undefined4 *)psVar1 >> 0x10);
        sVar16 = (short)*(undefined4 *)psVar1;
        sVar18 = (short)*(undefined4 *)(iVar28 + -0x20);
        sVar19 = (short)((uint)*(undefined4 *)(iVar28 + -0x20) >> 0x10);
        uVar21 = (longlong)((int)sVar18 * (int)sVar16) + (longlong)((int)sVar19 * (int)sVar17) +
                 lVar24;
        uVar22 = (longlong)((int)sVar18 * (int)(short)((uint)iVar26 >> 0x10)) +
                 (longlong)((int)sVar19 * (int)sVar16) + lVar23;
        iVar27 = iVar28 + 0x20;
        sVar16 = (short)*(undefined4 *)(psVar1 + 2);
        sVar18 = (short)*(undefined4 *)(iVar28 + -0x1c);
        sVar19 = (short)((uint)*(undefined4 *)(iVar28 + -0x1c) >> 0x10);
        uVar22 = (longlong)((int)sVar18 * (int)sVar17) + (longlong)((int)sVar19 * (int)sVar16) +
                 ((longlong)(int)(uVar22 >> 0x20) << 0x20 | uVar22 & 0xffffffff);
        sVar17 = (short)((uint)*(undefined4 *)(psVar1 + 2) >> 0x10);
        uVar21 = (longlong)((int)sVar18 * (int)sVar16) + (longlong)((int)sVar19 * (int)sVar17) +
                 ((longlong)(int)(uVar21 >> 0x20) << 0x20 | uVar21 & 0xffffffff);
        sVar18 = (short)((uint)*(undefined4 *)(psVar1 + 4) >> 0x10);
        sVar16 = (short)*(undefined4 *)(psVar1 + 4);
        sVar19 = (short)*(undefined4 *)(iVar28 + -0x18);
        sVar20 = (short)((uint)*(undefined4 *)(iVar28 + -0x18) >> 0x10);
        uVar21 = (longlong)((int)sVar19 * (int)sVar16) + (longlong)((int)sVar20 * (int)sVar18) +
                 ((longlong)(int)(uVar21 >> 0x20) << 0x20 | uVar21 & 0xffffffff);
        uVar22 = (longlong)((int)sVar19 * (int)sVar17) + (longlong)((int)sVar20 * (int)sVar16) +
                 ((longlong)(int)(uVar22 >> 0x20) << 0x20 | uVar22 & 0xffffffff);
        sVar16 = (short)*(undefined4 *)(psVar1 + 6);
        sVar19 = (short)*(undefined4 *)(iVar28 + -0x14);
        sVar20 = (short)((uint)*(undefined4 *)(iVar28 + -0x14) >> 0x10);
        uVar22 = (longlong)((int)sVar19 * (int)sVar18) + (longlong)((int)sVar20 * (int)sVar16) +
                 ((longlong)(int)(uVar22 >> 0x20) << 0x20 | uVar22 & 0xffffffff);
        sVar17 = (short)((uint)*(undefined4 *)(psVar1 + 6) >> 0x10);
        uVar21 = (longlong)((int)sVar19 * (int)sVar16) + (longlong)((int)sVar20 * (int)sVar17) +
                 ((longlong)(int)(uVar21 >> 0x20) << 0x20 | uVar21 & 0xffffffff);
        sVar18 = (short)((uint)*(undefined4 *)(psVar1 + 8) >> 0x10);
        sVar16 = (short)*(undefined4 *)(psVar1 + 8);
        sVar19 = (short)*(undefined4 *)(iVar28 + -0x10);
        sVar20 = (short)((uint)*(undefined4 *)(iVar28 + -0x10) >> 0x10);
        uVar21 = (longlong)((int)sVar19 * (int)sVar16) + (longlong)((int)sVar20 * (int)sVar18) +
                 ((longlong)(int)(uVar21 >> 0x20) << 0x20 | uVar21 & 0xffffffff);
        uVar22 = (longlong)((int)sVar19 * (int)sVar17) + (longlong)((int)sVar20 * (int)sVar16) +
                 ((longlong)(int)(uVar22 >> 0x20) << 0x20 | uVar22 & 0xffffffff);
        sVar16 = (short)*(undefined4 *)(psVar1 + 10);
        sVar19 = (short)*(undefined4 *)(iVar28 + -0xc);
        sVar20 = (short)((uint)*(undefined4 *)(iVar28 + -0xc) >> 0x10);
        uVar22 = (longlong)((int)sVar19 * (int)sVar18) + (longlong)((int)sVar20 * (int)sVar16) +
                 ((longlong)(int)(uVar22 >> 0x20) << 0x20 | uVar22 & 0xffffffff);
        sVar17 = (short)((uint)*(undefined4 *)(psVar1 + 10) >> 0x10);
        uVar21 = (longlong)((int)sVar19 * (int)sVar16) + (longlong)((int)sVar20 * (int)sVar17) +
                 ((longlong)(int)(uVar21 >> 0x20) << 0x20 | uVar21 & 0xffffffff);
        sVar18 = (short)((uint)*(undefined4 *)(psVar1 + 0xc) >> 0x10);
        sVar16 = (short)*(undefined4 *)(psVar1 + 0xc);
        sVar19 = (short)*(undefined4 *)(iVar28 + -8);
        sVar20 = (short)((uint)*(undefined4 *)(iVar28 + -8) >> 0x10);
        uVar21 = (longlong)((int)sVar19 * (int)sVar16) + (longlong)((int)sVar20 * (int)sVar18) +
                 ((longlong)(int)(uVar21 >> 0x20) << 0x20 | uVar21 & 0xffffffff);
        uVar22 = (longlong)((int)sVar19 * (int)sVar17) + (longlong)((int)sVar20 * (int)sVar16) +
                 ((longlong)(int)(uVar22 >> 0x20) << 0x20 | uVar22 & 0xffffffff);
        iVar26 = *(int *)(psVar1 + 0xe);
        sVar16 = (short)*(undefined4 *)(iVar28 + -4);
        sVar17 = (short)((uint)*(undefined4 *)(iVar28 + -4) >> 0x10);
        lVar24 = (longlong)((int)sVar16 * (int)(short)iVar26) +
                 (longlong)((int)sVar17 * (int)(short)((uint)iVar26 >> 0x10)) +
                 ((longlong)(int)(uVar21 >> 0x20) << 0x20 | uVar21 & 0xffffffff);
        lVar23 = (longlong)((int)sVar16 * (int)sVar18) +
                 (longlong)((int)sVar17 * (int)(short)iVar26) +
                 ((longlong)(int)(uVar22 >> 0x20) << 0x20 | uVar22 & 0xffffffff);
        iVar28 = iVar27;
        psVar1 = psVar1 + 0x10;
      } while (param_1 + 0x20 + iVar29 * 0x20 != iVar27);
      uVar35 = VectorSignedToFloat((uint)(lVar24 + 0x20) >> 6 |
                                   (int)((ulonglong)(lVar24 + 0x20) >> 0x20) * 0x4000000,
                                   (byte)(in_fpscr >> 0x16) & 3);
      uVar36 = VectorSignedToFloat((uint)(lVar23 + 0x20) >> 6 |
                                   (int)((ulonglong)(lVar23 + 0x20) >> 0x20) * 0x4000000,
                                   (byte)(in_fpscr >> 0x16) & 3);
      puVar32 = puVar31 + 2;
      puVar31[-2] = uVar35;
      puVar31[-1] = uVar36;
      puVar31 = puVar32;
      psVar33 = psVar33 + -2;
    } while (puVar34 + uVar25 * 2 + 4 != puVar32);
    puVar34 = puVar34 + (uVar25 + 1) * 2;
    param_5 = (param_5 - 2U) + uVar25 * -2;
    psVar30 = psVar30 + (uVar25 + 1) * -2;
  }
  if (param_5 != 1) {
    return;
  }
  lVar24 = 0;
  iVar28 = param_1 + 0x20;
  iVar29 = iVar28 + iVar29 * 0x20;
  do {
    psVar33 = (short *)(iVar28 + -0x20);
    psVar1 = (short *)(iVar28 + -0x1e);
    psVar2 = (short *)(iVar28 + -0x1c);
    psVar3 = (short *)(iVar28 + -0x1a);
    psVar4 = (short *)(iVar28 + -0x18);
    psVar5 = (short *)(iVar28 + -0x16);
    psVar6 = (short *)(iVar28 + -0x14);
    psVar7 = (short *)(iVar28 + -0x12);
    psVar8 = (short *)(iVar28 + -0x10);
    psVar9 = (short *)(iVar28 + -0xe);
    psVar10 = (short *)(iVar28 + -0xc);
    psVar11 = (short *)(iVar28 + -10);
    psVar12 = (short *)(iVar28 + -8);
    psVar13 = (short *)(iVar28 + -6);
    psVar14 = (short *)(iVar28 + -4);
    psVar15 = (short *)(iVar28 + -2);
    iVar28 = iVar28 + 0x20;
    lVar24 = (longlong)((int)*psVar15 * (int)psVar30[0xf]) +
             (longlong)((int)*psVar14 * (int)psVar30[0xe]) +
             (longlong)((int)*psVar13 * (int)psVar30[0xd]) +
             (longlong)((int)*psVar12 * (int)psVar30[0xc]) +
             (longlong)((int)*psVar11 * (int)psVar30[0xb]) +
             (longlong)((int)*psVar10 * (int)psVar30[10]) +
             (longlong)((int)*psVar9 * (int)psVar30[9]) +
             (longlong)((int)*psVar8 * (int)psVar30[8]) +
             (longlong)((int)*psVar7 * (int)psVar30[7]) +
             (longlong)((int)*psVar6 * (int)psVar30[6]) +
             (longlong)((int)*psVar5 * (int)psVar30[5]) +
             (longlong)((int)*psVar4 * (int)psVar30[4]) +
             (longlong)((int)*psVar3 * (int)psVar30[3]) +
             (longlong)((int)*psVar2 * (int)psVar30[2]) +
             (longlong)((int)*psVar1 * (int)psVar30[1]) + (int)*psVar33 * (int)*psVar30 + lVar24;
    psVar30 = psVar30 + 0x10;
  } while (iVar29 != iVar28);
  uVar35 = VectorSignedToFloat((uint)(lVar24 + 0x20) >> 6 |
                               (int)((ulonglong)(lVar24 + 0x20) >> 0x20) * 0x4000000,
                               (byte)(in_fpscr >> 0x16) & 3);
  *puVar34 = uVar35;
  return;
}


