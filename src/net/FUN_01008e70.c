/*
 * Function: FUN_01008e70
 * Entry:    01008e70
 * Prototype: undefined8 __stdcall FUN_01008e70(undefined4 param_1, uint * param_2)
 */


undefined8 FUN_01008e70(undefined4 param_1,uint *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int unaff_r7;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  bool bVar24;
  bool bVar25;
  bool bVar26;
  
  uVar7 = *param_2;
  uVar8 = param_2[1];
  uVar15 = param_2[2];
  uVar16 = param_2[3];
  uVar17 = param_2[4];
  uVar18 = param_2[5];
  uVar22 = param_2[6];
  uVar23 = param_2[7];
  uVar9 = (uint)((ulonglong)uVar7 * (ulonglong)uVar8);
  uVar1 = (ulonglong)uVar7 * (ulonglong)uVar15 + ((ulonglong)uVar7 * (ulonglong)uVar8 >> 0x20);
  uVar12 = (uint)uVar1;
  uVar13 = uVar12 * 2 + (uint)CARRY4(uVar9,uVar9);
  uVar1 = (ulonglong)uVar7 * (ulonglong)uVar16 + (uVar1 >> 0x20);
  uVar6 = (uint)(uVar1 >> 0x20);
  uVar10 = (uint)((ulonglong)uVar8 * (ulonglong)uVar8);
  uVar19 = (uint)((ulonglong)uVar8 * (ulonglong)uVar8 >> 0x20);
  bVar24 = CARRY4(uVar13,uVar10) ||
           CARRY4(uVar13 + uVar10,
                  (uint)CARRY4(uVar9 * 2,(uint)((ulonglong)uVar7 * (ulonglong)uVar7 >> 0x20)));
  lVar2 = (ulonglong)uVar8 * (ulonglong)uVar15 + (uVar1 & 0xffffffff);
  uVar10 = (uint)lVar2;
  uVar11 = (uint)((ulonglong)lVar2 >> 0x20);
  uVar13 = uVar10 * 2 + (uint)bVar24;
  uVar10 = (uint)(CARRY4(uVar10,uVar10) || CARRY4(uVar10 * 2,(uint)bVar24));
  uVar1 = (ulonglong)uVar7 * (ulonglong)uVar17 +
          (ulonglong)CONCAT14(CARRY4(uVar6,uVar11),uVar6 + uVar11);
  bVar25 = CARRY4(uVar13,uVar19) ||
           CARRY4(uVar13 + uVar19,
                  (uint)(((unaff_r7 * 2 +
                          (uint)(CARRY4(uVar12,uVar12) ||
                                CARRY4(uVar12 * 2,(uint)CARRY4(uVar9,uVar9)))) * 2 + uVar10 & 2) !=
                        0));
  lVar2 = (ulonglong)uVar7 * (ulonglong)uVar18 + (uVar1 >> 0x20);
  uVar6 = (uint)lVar2;
  uVar12 = (uint)((ulonglong)lVar2 >> 0x20);
  lVar2 = (ulonglong)uVar8 * (ulonglong)uVar16 + (uVar1 & 0xffffffff);
  uVar11 = (uint)lVar2;
  uVar19 = (uint)((ulonglong)lVar2 >> 0x20);
  uVar9 = uVar11 * 2 + (uint)bVar25;
  uVar13 = uVar10 * -0x80000000 >> 1;
  uVar1 = (ulonglong)uVar8 * (ulonglong)uVar17 + (ulonglong)(uVar6 + uVar19);
  uVar10 = (uint)(uVar1 >> 0x20);
  uVar3 = (ulonglong)uVar7 * (ulonglong)uVar22 +
          (ulonglong)
          CONCAT14(CARRY4(uVar12,uVar10) || CARRY4(uVar12 + uVar10,(uint)CARRY4(uVar6,uVar19)),
                   uVar12 + uVar10 + CARRY4(uVar6,uVar19));
  uVar14 = (uint)uVar3;
  lVar2 = (ulonglong)uVar7 * (ulonglong)uVar23 + (uVar3 >> 0x20);
  uVar20 = (uint)lVar2;
  uVar6 = (uint)((ulonglong)lVar2 >> 0x20);
  bVar24 = CARRY4(uVar9,(uint)(uVar13 != 0));
  uVar12 = (uint)((ulonglong)uVar15 * (ulonglong)uVar15 + (ulonglong)(uVar9 + (uVar13 != 0)) >> 0x20
                 );
  lVar2 = (ulonglong)uVar15 * (ulonglong)uVar16 + (uVar1 & 0xffffffff);
  uVar10 = (uint)lVar2;
  uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
  uVar19 = uVar10 * 2 + (uint)bVar24;
  uVar10 = (uint)(CARRY4(uVar10,uVar10) || CARRY4(uVar10 * 2,(uint)bVar24));
  uVar1 = (ulonglong)uVar8 * (ulonglong)uVar18 + (ulonglong)(uVar14 + uVar9);
  uVar7 = (uint)(uVar1 >> 0x20);
  bVar24 = CARRY4(uVar20,uVar7) || CARRY4(uVar20 + uVar7,(uint)CARRY4(uVar14,uVar9));
  lVar2 = (ulonglong)uVar8 * (ulonglong)uVar22 + (ulonglong)(uVar20 + uVar7 + CARRY4(uVar14,uVar9));
  uVar21 = (uint)lVar2;
  uVar9 = (uint)((ulonglong)lVar2 >> 0x20);
  lVar2 = (ulonglong)uVar8 * (ulonglong)uVar23 +
          (ulonglong)
          CONCAT14(CARRY4(uVar6,uVar9) || CARRY4(uVar6 + uVar9,(uint)bVar24),
                   uVar6 + uVar9 + (uint)bVar24);
  uVar6 = (uint)lVar2;
  lVar4 = (ulonglong)uVar15 * (ulonglong)uVar17 + (uVar1 & 0xffffffff);
  uVar14 = (uint)lVar4;
  uVar7 = (uint)((ulonglong)lVar4 >> 0x20);
  uVar1 = (ulonglong)uVar15 * (ulonglong)uVar18 + (ulonglong)(uVar21 + uVar7);
  uVar8 = (uint)(uVar1 >> 0x20);
  lVar4 = (ulonglong)uVar15 * (ulonglong)uVar22 +
          (ulonglong)(uVar6 + uVar8 + (uint)CARRY4(uVar21,uVar7));
  uVar9 = (uint)lVar4;
  uVar20 = uVar10 * -0x80000000;
  bVar24 = CARRY4(uVar19,uVar12) ||
           CARRY4(uVar19 + uVar12,
                  (uint)((((int)((uint)(CARRY4(uVar11,uVar11) || CARRY4(uVar11 * 2,(uint)bVar25)) <<
                                 0x1f | uVar13) >> 0x1f) * -2 + uVar10 & 2) != 0));
  uVar13 = uVar14 * 2 + (uint)bVar24;
  uVar10 = (uint)((ulonglong)uVar16 * (ulonglong)uVar16);
  uVar12 = (uint)((ulonglong)uVar16 * (ulonglong)uVar16 >> 0x20);
  bVar25 = CARRY4(uVar13,uVar10) || CARRY4(uVar13 + uVar10,(uint)CARRY4(uVar20,uVar20));
  lVar5 = (ulonglong)uVar16 * (ulonglong)uVar17 + (uVar1 & 0xffffffff);
  uVar10 = (uint)lVar5;
  uVar11 = (uint)((ulonglong)lVar5 >> 0x20);
  bVar26 = CARRY4(uVar10,uVar10) || CARRY4(uVar10 * 2,(uint)bVar25);
  uVar10 = uVar10 * 2 + (uint)bVar25;
  lVar5 = (ulonglong)uVar16 * (ulonglong)uVar18 + (ulonglong)(uVar9 + uVar11);
  uVar13 = (uint)lVar5;
  bVar24 = CARRY4(uVar10,uVar12) ||
           CARRY4(uVar10 + uVar12,
                  (uint)(((CARRY4(uVar14,uVar14) || CARRY4(uVar14 * 2,(uint)bVar24)) * '\x02' +
                          bVar26 & 2U) != 0));
  uVar10 = uVar13 * 2 + (uint)bVar24;
  uVar12 = (uint)((ulonglong)uVar17 * (ulonglong)uVar17);
  return CONCAT44((uVar17 * uVar18 +
                  uVar16 * uVar22 +
                  uVar15 * uVar23 +
                  (int)((ulonglong)lVar2 >> 0x20) + (int)((ulonglong)lVar4 >> 0x20) +
                  (uint)(CARRY4(uVar6,uVar8) || CARRY4(uVar6 + uVar8,(uint)CARRY4(uVar21,uVar7))) +
                  (int)((ulonglong)lVar5 >> 0x20) + (uint)CARRY4(uVar9,uVar11)) * 2 +
                  (uint)(CARRY4(uVar13,uVar13) || CARRY4(uVar13 * 2,(uint)bVar24)) +
                  (int)((ulonglong)uVar17 * (ulonglong)uVar17 >> 0x20) +
                  (uint)(CARRY4(uVar10,uVar12) || CARRY4(uVar10 + uVar12,(uint)bVar26)),
                  uVar10 + uVar12 + (uint)bVar26);
}


