/*
 * Function: FUN_01008b4c
 * Entry:    01008b4c
 * Prototype: undefined8 __stdcall FUN_01008b4c(uint * param_1, uint * param_2, int param_3)
 */


undefined8 FUN_01008b4c(uint *param_1,uint *param_2,int param_3)

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
  
  uVar14 = -param_3;
  uVar5 = *param_1;
  uVar6 = param_1[1];
  uVar7 = param_1[2];
  uVar8 = param_1[3];
  uVar9 = *param_2 & uVar14;
  uVar10 = param_2[1] & uVar14;
  bVar1 = uVar6 - uVar10 < (uint)(uVar9 <= uVar5);
  uVar11 = param_2[2] & uVar14;
  bVar2 = uVar7 - uVar11 < (uint)(uVar10 < uVar6 || bVar1);
  uVar13 = param_2[3] & uVar14;
  bVar3 = uVar8 - uVar13 < (uint)(uVar11 < uVar7 || bVar2);
  *param_1 = uVar5 - uVar9;
  param_1[1] = (uVar6 - uVar10) - (uint)(uVar9 > uVar5);
  param_1[2] = (uVar7 - uVar11) - (uint)(uVar10 >= uVar6 && !bVar1);
  param_1[3] = (uVar8 - uVar13) - (uint)(uVar11 >= uVar7 && !bVar2);
  uVar5 = param_1[4];
  uVar6 = param_1[5];
  uVar7 = param_1[6];
  uVar9 = param_1[7];
  uVar10 = param_2[4] & uVar14;
  bVar1 = uVar5 - uVar10 < (uint)(uVar13 < uVar8 || bVar3);
  uVar11 = param_2[5] & uVar14;
  bVar2 = uVar6 - uVar11 < (uint)(uVar10 < uVar5 || bVar1);
  uVar12 = param_2[6] & uVar14;
  bVar4 = uVar7 - uVar12 < (uint)(uVar11 < uVar6 || bVar2);
  uVar14 = param_2[7] & uVar14;
  param_1[4] = (uVar5 - uVar10) - (uint)(uVar13 >= uVar8 && !bVar3);
  param_1[5] = (uVar6 - uVar11) - (uint)(uVar10 >= uVar5 && !bVar1);
  param_1[6] = (uVar7 - uVar12) - (uint)(uVar11 >= uVar6 && !bVar2);
  param_1[7] = (uVar9 - uVar14) - (uint)(uVar12 >= uVar7 && !bVar4);
  return CONCAT44(param_2 + 8,
                  (uint)(uVar9 <= uVar14 && (uint)(uVar12 < uVar7 || bVar4) <= uVar9 - uVar14));
}


