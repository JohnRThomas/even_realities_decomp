/*
 * Function: FUN_01008bdc
 * Entry:    01008bdc
 * Prototype: undefined8 __stdcall FUN_01008bdc(undefined4 param_1, uint * param_2, uint * param_3)
 */


undefined8 FUN_01008bdc(undefined4 param_1,uint *param_2,uint *param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  bool bVar36;
  bool bVar37;
  bool bVar38;
  
  uVar11 = *param_3;
  uVar12 = param_3[1];
  uVar13 = param_3[2];
  uVar14 = param_3[3];
  uVar16 = param_3[4];
  uVar19 = param_3[5];
  uVar21 = param_3[6];
  uVar24 = param_3[7];
  uVar17 = *param_2;
  uVar20 = param_2[1];
  uVar22 = param_2[2];
  uVar25 = param_2[3];
  uVar34 = param_2[4];
  uVar35 = param_2[5];
  uVar10 = (uint)((ulonglong)uVar17 * (ulonglong)uVar11 >> 0x20);
  uVar8 = (uint)((ulonglong)uVar20 * (ulonglong)uVar11);
  uVar27 = (uint)((ulonglong)uVar20 * (ulonglong)uVar11 >> 0x20);
  uVar9 = (uint)((ulonglong)uVar17 * (ulonglong)uVar12 + (ulonglong)(uVar10 + uVar8) >> 0x20);
  lVar1 = (ulonglong)uVar22 * (ulonglong)uVar11 +
          (ulonglong)
          CONCAT14(CARRY4(uVar27,uVar9) || CARRY4(uVar27 + uVar9,(uint)CARRY4(uVar10,uVar8)),
                   uVar27 + uVar9 + CARRY4(uVar10,uVar8));
  uVar28 = (uint)lVar1;
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar10 = (uint)((ulonglong)uVar20 * (ulonglong)uVar12);
  uVar9 = (uint)((ulonglong)uVar20 * (ulonglong)uVar12 >> 0x20);
  lVar1 = (ulonglong)uVar25 * (ulonglong)uVar11 +
          (ulonglong)CONCAT14(CARRY4(uVar8,uVar9),uVar8 + uVar9);
  uVar8 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar27 = (uint)((ulonglong)uVar17 * (ulonglong)uVar13 + (ulonglong)(uVar28 + uVar10) >> 0x20);
  bVar36 = CARRY4(uVar8,uVar27) || CARRY4(uVar8 + uVar27,(uint)CARRY4(uVar28,uVar10));
  lVar1 = (ulonglong)uVar17 * (ulonglong)uVar14 +
          (ulonglong)(uVar8 + uVar27 + (uint)CARRY4(uVar28,uVar10));
  uVar8 = (uint)lVar1;
  uVar10 = (uint)((ulonglong)lVar1 >> 0x20);
  lVar1 = (ulonglong)uVar20 * (ulonglong)uVar14 +
          (ulonglong)
          CONCAT14(CARRY4(uVar9,uVar10) || CARRY4(uVar9 + uVar10,(uint)bVar36),
                   uVar9 + uVar10 + (uint)bVar36);
  uVar9 = (uint)lVar1;
  uVar27 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar29 = (uint)((ulonglong)uVar22 * (ulonglong)uVar12);
  uVar28 = (uint)((ulonglong)uVar22 * (ulonglong)uVar12 >> 0x20);
  lVar1 = (ulonglong)uVar25 * (ulonglong)uVar12 + (ulonglong)(uVar9 + uVar28);
  uVar10 = (uint)lVar1;
  uVar15 = (uint)((ulonglong)lVar1 >> 0x20);
  lVar1 = (ulonglong)uVar34 * (ulonglong)uVar12 +
          (ulonglong)
          CONCAT14(CARRY4(uVar27,uVar15) || CARRY4(uVar27 + uVar15,(uint)CARRY4(uVar9,uVar28)),
                   uVar27 + uVar15 + (uint)CARRY4(uVar9,uVar28));
  uVar9 = (uint)lVar1;
  uVar27 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar28 = (uint)((ulonglong)uVar20 * (ulonglong)uVar13 + (ulonglong)(uVar8 + uVar29) >> 0x20);
  bVar36 = CARRY4(uVar10,uVar28) || CARRY4(uVar10 + uVar28,(uint)CARRY4(uVar8,uVar29));
  lVar1 = (ulonglong)uVar22 * (ulonglong)uVar13 +
          (ulonglong)(uVar10 + uVar28 + CARRY4(uVar8,uVar29));
  uVar10 = (uint)lVar1;
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar37 = CARRY4(uVar9,uVar8) || CARRY4(uVar9 + uVar8,(uint)bVar36);
  lVar1 = (ulonglong)uVar25 * (ulonglong)uVar13 + (ulonglong)(uVar9 + uVar8 + bVar36);
  uVar28 = (uint)lVar1;
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  lVar1 = (ulonglong)uVar34 * (ulonglong)uVar13 +
          (ulonglong)
          CONCAT14(CARRY4(uVar27,uVar8) || CARRY4(uVar27 + uVar8,(uint)bVar37),
                   uVar27 + uVar8 + bVar37);
  uVar29 = (uint)lVar1;
  uVar30 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar27 = (uint)((ulonglong)uVar34 * (ulonglong)uVar11);
  uVar8 = (uint)((ulonglong)uVar34 * (ulonglong)uVar11 >> 0x20);
  lVar1 = (ulonglong)uVar35 * (ulonglong)uVar11 + (ulonglong)(uVar28 + uVar8);
  uVar15 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar36 = CARRY4(uVar29,uVar9) || CARRY4(uVar29 + uVar9,(uint)CARRY4(uVar28,uVar8));
  lVar1 = (ulonglong)uVar22 * (ulonglong)uVar16 +
          (ulonglong)(uVar29 + uVar9 + (uint)CARRY4(uVar28,uVar8));
  uVar28 = (uint)lVar1;
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  lVar1 = (ulonglong)uVar25 * (ulonglong)uVar16 +
          (ulonglong)
          CONCAT14(CARRY4(uVar30,uVar8) || CARRY4(uVar30 + uVar8,(uint)bVar36),
                   uVar30 + uVar8 + bVar36);
  uVar29 = (uint)lVar1;
  uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar9 = (uint)((ulonglong)uVar17 * (ulonglong)uVar16 + (ulonglong)(uVar27 + uVar10) >> 0x20);
  bVar36 = CARRY4(uVar15,uVar9) || CARRY4(uVar15 + uVar9,(uint)CARRY4(uVar27,uVar10));
  lVar1 = (ulonglong)uVar20 * (ulonglong)uVar16 +
          (ulonglong)(uVar15 + uVar9 + (uint)CARRY4(uVar27,uVar10));
  uVar15 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar37 = CARRY4(uVar28,uVar9) || CARRY4(uVar28 + uVar9,(uint)bVar36);
  lVar1 = (ulonglong)uVar20 * (ulonglong)uVar19 + (ulonglong)(uVar28 + uVar9 + (uint)bVar36);
  uVar28 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  bVar36 = CARRY4(uVar29,uVar9) || CARRY4(uVar29 + uVar9,(uint)bVar37);
  lVar1 = (ulonglong)uVar22 * (ulonglong)uVar19 + (ulonglong)(uVar29 + uVar9 + bVar37);
  uVar30 = (uint)lVar1;
  uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
  lVar1 = (ulonglong)uVar25 * (ulonglong)uVar19 +
          (ulonglong)
          CONCAT14(CARRY4(uVar8,uVar9) || CARRY4(uVar8 + uVar9,(uint)bVar36),
                   uVar8 + uVar9 + (uint)bVar36);
  uVar8 = (uint)lVar1;
  uVar27 = (uint)((ulonglong)uVar17 * (ulonglong)uVar19);
  uVar9 = (uint)((ulonglong)uVar17 * (ulonglong)uVar19 >> 0x20);
  lVar2 = (ulonglong)uVar17 * (ulonglong)uVar21 + (ulonglong)(uVar28 + uVar9);
  uVar29 = (uint)lVar2;
  uVar10 = (uint)((ulonglong)lVar2 >> 0x20);
  bVar36 = CARRY4(uVar30,uVar10) || CARRY4(uVar30 + uVar10,(uint)CARRY4(uVar28,uVar9));
  lVar2 = (ulonglong)uVar20 * (ulonglong)uVar21 +
          (ulonglong)(uVar30 + uVar10 + CARRY4(uVar28,uVar9));
  uVar31 = (uint)lVar2;
  uVar28 = (uint)((ulonglong)lVar2 >> 0x20);
  lVar2 = (ulonglong)uVar22 * (ulonglong)uVar21 + (ulonglong)(uVar8 + uVar28 + (uint)bVar36);
  uVar9 = (uint)lVar2;
  uVar10 = (uint)((ulonglong)uVar22 * (ulonglong)uVar14 + (ulonglong)(uVar15 + uVar27) >> 0x20);
  bVar37 = CARRY4(uVar29,uVar10) || CARRY4(uVar29 + uVar10,(uint)CARRY4(uVar15,uVar27));
  lVar3 = (ulonglong)uVar25 * (ulonglong)uVar14 +
          (ulonglong)(uVar29 + uVar10 + (uint)CARRY4(uVar15,uVar27));
  uVar30 = (uint)lVar3;
  uVar10 = (uint)((ulonglong)lVar3 >> 0x20);
  bVar38 = CARRY4(uVar31,uVar10) || CARRY4(uVar31 + uVar10,(uint)bVar37);
  lVar3 = (ulonglong)uVar17 * (ulonglong)uVar24 + (ulonglong)(uVar31 + uVar10 + bVar37);
  uVar32 = (uint)lVar3;
  uVar15 = (uint)((ulonglong)lVar3 >> 0x20);
  lVar3 = (ulonglong)uVar20 * (ulonglong)uVar24 + (ulonglong)(uVar9 + uVar15 + (uint)bVar38);
  uVar10 = (uint)lVar3;
  uVar23 = param_2[6];
  uVar26 = param_2[7];
  uVar27 = (uint)((ulonglong)uVar23 * (ulonglong)uVar11);
  uVar29 = (uint)((ulonglong)uVar23 * (ulonglong)uVar11 >> 0x20);
  lVar4 = (ulonglong)uVar26 * (ulonglong)uVar11 + (ulonglong)(uVar32 + uVar29);
  uVar31 = (uint)lVar4;
  uVar17 = (uint)((ulonglong)lVar4 >> 0x20);
  lVar4 = (ulonglong)uVar34 * (ulonglong)uVar16 +
          (ulonglong)(uVar10 + uVar17 + (uint)CARRY4(uVar32,uVar29));
  uVar11 = (uint)lVar4;
  uVar20 = (uint)((ulonglong)uVar35 * (ulonglong)uVar12 + (ulonglong)(uVar30 + uVar27) >> 0x20);
  bVar37 = CARRY4(uVar31,uVar20) || CARRY4(uVar31 + uVar20,(uint)CARRY4(uVar30,uVar27));
  lVar5 = (ulonglong)uVar23 * (ulonglong)uVar12 +
          (ulonglong)(uVar31 + uVar20 + CARRY4(uVar30,uVar27));
  uVar33 = (uint)lVar5;
  uVar20 = (uint)((ulonglong)lVar5 >> 0x20);
  lVar5 = (ulonglong)uVar26 * (ulonglong)uVar12 + (ulonglong)(uVar11 + uVar20 + (uint)bVar37);
  uVar12 = (uint)lVar5;
  uVar31 = (uint)((ulonglong)uVar35 * (ulonglong)uVar13);
  uVar30 = (uint)((ulonglong)uVar35 * (ulonglong)uVar13 >> 0x20);
  lVar6 = (ulonglong)uVar23 * (ulonglong)uVar13 + (ulonglong)(uVar12 + uVar30);
  uVar27 = (uint)lVar6;
  uVar18 = (uint)((ulonglong)uVar34 * (ulonglong)uVar14 + (ulonglong)(uVar33 + uVar31) >> 0x20);
  lVar7 = (ulonglong)uVar35 * (ulonglong)uVar14 +
          (ulonglong)(uVar27 + uVar18 + (uint)CARRY4(uVar33,uVar31));
  return CONCAT44(uVar23 * uVar14 +
                  uVar26 * uVar13 +
                  uVar34 * uVar19 +
                  uVar35 * uVar16 +
                  uVar22 * uVar24 +
                  uVar25 * uVar21 +
                  (int)((ulonglong)lVar1 >> 0x20) + (int)((ulonglong)lVar2 >> 0x20) +
                  (uint)(CARRY4(uVar8,uVar28) || CARRY4(uVar8 + uVar28,(uint)bVar36)) +
                  (int)((ulonglong)lVar3 >> 0x20) +
                  (uint)(CARRY4(uVar9,uVar15) || CARRY4(uVar9 + uVar15,(uint)bVar38)) +
                  (int)((ulonglong)lVar4 >> 0x20) +
                  (uint)(CARRY4(uVar10,uVar17) ||
                        CARRY4(uVar10 + uVar17,(uint)CARRY4(uVar32,uVar29))) +
                  (int)((ulonglong)lVar5 >> 0x20) +
                  (uint)(CARRY4(uVar11,uVar20) || CARRY4(uVar11 + uVar20,(uint)bVar37)) +
                  (int)((ulonglong)lVar6 >> 0x20) + (uint)CARRY4(uVar12,uVar30) +
                  (int)((ulonglong)lVar7 >> 0x20) +
                  (uint)(CARRY4(uVar27,uVar18) ||
                        CARRY4(uVar27 + uVar18,(uint)CARRY4(uVar33,uVar31))),(int)lVar7);
}


