/*
 * Function: FUN_01008ab0
 * Entry:    01008ab0
 * Prototype: bool __stdcall FUN_01008ab0(int * param_1, uint * param_2, uint * param_3)
 */


bool FUN_01008ab0(int *param_1,uint *param_2,uint *param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
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
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  
  uVar11 = *param_2;
  uVar12 = param_2[1];
  uVar13 = param_2[2];
  uVar14 = param_2[3];
  uVar15 = param_2[4];
  uVar16 = param_2[5];
  uVar17 = param_2[6];
  uVar18 = param_2[7];
  uVar7 = *param_3;
  uVar19 = param_3[1];
  bVar1 = uVar12 - uVar19 < (uint)(uVar7 <= uVar11);
  uVar8 = param_3[2];
  uVar20 = param_3[3];
  bVar2 = uVar13 - uVar8 < (uint)(uVar19 < uVar12 || bVar1);
  bVar3 = uVar14 - uVar20 < (uint)(uVar8 < uVar13 || bVar2);
  uVar9 = param_3[4];
  uVar21 = param_3[5];
  bVar4 = uVar15 - uVar9 < (uint)(uVar20 < uVar14 || bVar3);
  bVar5 = uVar16 - uVar21 < (uint)(uVar9 < uVar15 || bVar4);
  uVar10 = param_3[6];
  uVar22 = param_3[7];
  bVar6 = uVar17 - uVar10 < (uint)(uVar21 < uVar16 || bVar5);
  *param_1 = uVar11 - uVar7;
  param_1[1] = (uVar12 - uVar19) - (uint)(uVar7 > uVar11);
  param_1[2] = (uVar13 - uVar8) - (uint)(uVar19 >= uVar12 && !bVar1);
  param_1[3] = (uVar14 - uVar20) - (uint)(uVar8 >= uVar13 && !bVar2);
  param_1[4] = (uVar15 - uVar9) - (uint)(uVar20 >= uVar14 && !bVar3);
  param_1[5] = (uVar16 - uVar21) - (uint)(uVar9 >= uVar15 && !bVar4);
  param_1[6] = (uVar17 - uVar10) - (uint)(uVar21 >= uVar16 && !bVar5);
  param_1[7] = (uVar18 - uVar22) - (uint)(uVar10 >= uVar17 && !bVar6);
  return uVar18 <= uVar22 && (uint)(uVar10 < uVar17 || bVar6) <= uVar18 - uVar22;
}


