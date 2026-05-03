/*
 * Function: FUN_010090e8
 * Entry:    010090e8
 * Prototype: undefined __stdcall FUN_010090e8(int * param_1, uint * param_2, uint * param_3)
 */


void FUN_010090e8(int *param_1,uint *param_2,uint *param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
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
  uint uVar16;
  uint uVar17;
  uint uVar18;
  bool bVar19;
  bool bVar20;
  
  uVar6 = *param_2;
  uVar8 = param_2[1];
  uVar10 = param_2[2];
  uVar11 = param_2[3];
  uVar12 = param_2[4];
  uVar13 = param_2[5];
  uVar14 = param_2[6];
  uVar15 = param_2[7];
  uVar5 = *param_3;
  uVar16 = param_3[1];
  uVar7 = uVar6 - uVar5;
  bVar2 = uVar8 - uVar16 < (uint)(uVar5 <= uVar6);
  uVar9 = (uVar8 - uVar16) - (uint)(uVar5 > uVar6);
  uVar5 = param_3[2];
  uVar6 = param_3[3];
  bVar3 = uVar10 - uVar5 < (uint)(uVar16 < uVar8 || bVar2);
  uVar16 = (uVar10 - uVar5) - (uint)(uVar16 >= uVar8 && !bVar2);
  bVar2 = uVar11 - uVar6 < (uint)(uVar5 < uVar10 || bVar3);
  uVar10 = (uVar11 - uVar6) - (uint)(uVar5 >= uVar10 && !bVar3);
  uVar5 = param_3[4];
  uVar17 = param_3[5];
  bVar3 = uVar12 - uVar5 < (uint)(uVar6 < uVar11 || bVar2);
  uVar11 = (uVar12 - uVar5) - (uint)(uVar6 >= uVar11 && !bVar2);
  bVar2 = uVar13 - uVar17 < (uint)(uVar5 < uVar12 || bVar3);
  uVar12 = (uVar13 - uVar17) - (uint)(uVar5 >= uVar12 && !bVar3);
  uVar8 = param_3[6];
  uVar18 = param_3[7];
  bVar4 = uVar14 - uVar8 < (uint)(uVar17 < uVar13 || bVar2);
  uVar13 = (uVar14 - uVar8) - (uint)(uVar17 >= uVar13 && !bVar2);
  uVar6 = -(uint)(uVar15 <= uVar18 && (uint)(uVar8 < uVar14 || bVar4) <= uVar15 - uVar18);
  bVar19 = CARRY4(uVar9,uVar6) || CARRY4(uVar9 + uVar6,(uint)CARRY4(uVar7,uVar6));
  bVar20 = CARRY4(uVar16,uVar6) || CARRY4(uVar16 + uVar6,(uint)bVar19);
  bVar2 = CARRY4(uVar10,(uint)bVar20);
  bVar3 = CARRY4(uVar11,(uint)bVar2);
  bVar1 = CARRY4(uVar12,(uint)bVar3);
  uVar5 = -((int)uVar6 >> 0x1f);
  *param_1 = uVar7 + uVar6;
  param_1[1] = uVar9 + uVar6 + (uint)CARRY4(uVar7,uVar6);
  param_1[2] = uVar16 + uVar6 + (uint)bVar19;
  param_1[3] = uVar10 + bVar20;
  param_1[4] = uVar11 + bVar2;
  param_1[5] = uVar12 + bVar3;
  param_1[6] = uVar13 + uVar5 + bVar1;
  param_1[7] = ((uVar15 - uVar18) - (uint)(uVar8 >= uVar14 && !bVar4)) +
               uVar6 + (CARRY4(uVar13,uVar5) || CARRY4(uVar13 + uVar5,(uint)bVar1));
  return;
}


