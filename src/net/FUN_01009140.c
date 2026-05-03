/*
 * Function: FUN_01009140
 * Entry:    01009140
 * Prototype: undefined8 __stdcall FUN_01009140(uint param_1, uint param_2, uint param_3, uint param_4)
 */


undefined8 FUN_01009140(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint unaff_r4;
  uint unaff_r5;
  uint unaff_r6;
  uint unaff_r7;
  uint unaff_r8;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint unaff_r9;
  uint uVar11;
  uint uVar12;
  uint unaff_r10;
  uint uVar13;
  uint uVar14;
  uint unaff_r11;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  bool bVar18;
  
  uVar8 = unaff_r8 + unaff_r4;
  bVar17 = CARRY4(unaff_r9,unaff_r5) || CARRY4(unaff_r9 + unaff_r5,(uint)CARRY4(unaff_r8,unaff_r4));
  uVar11 = unaff_r9 + unaff_r5 + CARRY4(unaff_r8,unaff_r4);
  bVar18 = CARRY4(unaff_r10,unaff_r6) || CARRY4(unaff_r10 + unaff_r6,(uint)bVar17);
  uVar13 = unaff_r10 + unaff_r6 + bVar17;
  uVar15 = unaff_r11 + unaff_r7 + bVar18;
  uVar3 = (uint)(CARRY4(unaff_r11,unaff_r7) || CARRY4(unaff_r11 + unaff_r7,(uint)bVar18));
  uVar9 = uVar8 + unaff_r5;
  bVar17 = CARRY4(uVar11,unaff_r6) || CARRY4(uVar11 + unaff_r6,(uint)CARRY4(uVar8,unaff_r5));
  uVar11 = uVar11 + unaff_r6 + CARRY4(uVar8,unaff_r5);
  bVar18 = CARRY4(uVar13,unaff_r7) || CARRY4(uVar13 + unaff_r7,(uint)bVar17);
  uVar13 = uVar13 + unaff_r7 + bVar17;
  bVar17 = CARRY4(uVar15,unaff_r7) || CARRY4(uVar15 + unaff_r7,(uint)bVar18);
  uVar15 = uVar15 + unaff_r7 + bVar18;
  bVar18 = CARRY4(param_1,uVar3) || CARRY4(param_1 + uVar3,(uint)bVar17);
  uVar3 = param_1 + uVar3 + bVar17;
  bVar17 = CARRY4(param_2,(uint)bVar18);
  uVar4 = param_2 + bVar18;
  bVar18 = CARRY4(param_3,(uint)bVar17);
  uVar5 = param_3 + bVar17;
  uVar6 = param_4 + unaff_r4 + (uint)bVar18;
  uVar10 = uVar9 - unaff_r7;
  bVar17 = uVar11 < (unaff_r7 <= uVar9);
  uVar12 = uVar11 - (unaff_r7 > uVar9);
  bVar1 = uVar13 < (uVar11 != 0 || bVar17);
  uVar14 = uVar13 - (uVar11 == 0 && !bVar17);
  bVar17 = uVar15 - unaff_r4 < (uint)(uVar13 != 0 || bVar1);
  uVar16 = (uVar15 - unaff_r4) - (uint)(uVar13 == 0 && !bVar1);
  bVar1 = uVar3 - unaff_r5 < (uint)(unaff_r4 < uVar15 || bVar17);
  uVar8 = (uVar3 - unaff_r5) - (uint)(unaff_r4 >= uVar15 && !bVar17);
  bVar17 = uVar4 - unaff_r6 < (uint)(unaff_r5 < uVar3 || bVar1);
  uVar3 = (uVar4 - unaff_r6) - (uint)(unaff_r5 >= uVar3 && !bVar1);
  bVar1 = uVar5 - unaff_r4 < (uint)(unaff_r6 < uVar4 || bVar17);
  uVar11 = (uVar5 - unaff_r4) - (uint)(unaff_r6 >= uVar4 && !bVar17);
  uVar15 = (uVar6 - unaff_r6) - (uint)(unaff_r4 >= uVar5 && !bVar1);
  bVar17 = uVar8 - unaff_r6 < (uint)(unaff_r5 <= uVar16);
  uVar4 = (uVar8 - unaff_r6) - (uint)(unaff_r5 > uVar16);
  bVar2 = uVar3 - unaff_r7 < (uint)(unaff_r6 < uVar8 || bVar17);
  uVar9 = (uVar3 - unaff_r7) - (uint)(unaff_r6 >= uVar8 && !bVar17);
  bVar17 = uVar11 - unaff_r5 < (uint)(unaff_r7 < uVar3 || bVar2);
  uVar13 = (uVar11 - unaff_r5) - (uint)(unaff_r7 >= uVar3 && !bVar2);
  uVar7 = (uVar15 - unaff_r7) - (uint)(unaff_r5 >= uVar11 && !bVar17);
  uVar11 = ((uint)(CARRY4(param_4,unaff_r4) || CARRY4(param_4 + unaff_r4,(uint)bVar18)) -
           (uint)(uVar6 <= unaff_r6 && (uint)(unaff_r4 < uVar5 || bVar1) <= uVar6 - unaff_r6)) -
           (uint)(uVar15 <= unaff_r7 && (uint)(unaff_r5 < uVar11 || bVar17) <= uVar15 - unaff_r7);
  uVar5 = uVar11 | 1;
  uVar3 = (int)uVar11 >> 1;
  uVar8 = (int)(uVar11 ^ 2) >> 1;
  uVar8 = (uVar11 - uVar3) -
          (uint)(!CARRY4(uVar7,uVar3) &&
                !CARRY4(uVar7 + uVar3,
                        (uint)(uVar8 < uVar13 ||
                              uVar13 - uVar8 <
                              (uint)(uVar3 < uVar9 ||
                                    uVar9 - uVar3 <
                                    (uint)(uVar3 < uVar4 ||
                                          uVar4 - uVar3 <
                                          (uint)(uVar3 < uVar16 - unaff_r5 ||
                                                (uVar16 - unaff_r5) - uVar3 <
                                                (uint)(CARRY4(uVar14,uVar3) ||
                                                      CARRY4(uVar14 + uVar3,
                                                             (uint)(CARRY4(uVar12,uVar3) ||
                                                                   CARRY4(uVar12 + uVar3,
                                                                          (uint)CARRY4(uVar10,uVar5)
                                                                         ))))))))));
  return CONCAT44(uVar12 + uVar3 + CARRY4(uVar10,uVar5) + uVar8 + CARRY4(uVar10 + uVar5,uVar8),
                  uVar10 + uVar5 + uVar8);
}


