/*
 * Function: FUN_01008af0
 * Entry:    01008af0
 * Prototype: undefined8 __stdcall FUN_01008af0(uint * param_1, uint * param_2, int param_3)
 */


undefined8 FUN_01008af0(uint *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  
  uVar9 = -param_3;
  uVar1 = *param_1;
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  uVar5 = *param_2 & uVar9;
  uVar6 = param_2[1] & uVar9;
  bVar10 = CARRY4(uVar2,uVar6) || CARRY4(uVar2 + uVar6,(uint)CARRY4(uVar1,uVar5));
  uVar7 = param_2[2] & uVar9;
  bVar11 = CARRY4(uVar3,uVar7) || CARRY4(uVar3 + uVar7,(uint)bVar10);
  uVar8 = param_2[3] & uVar9;
  bVar12 = CARRY4(uVar4,uVar8) || CARRY4(uVar4 + uVar8,(uint)bVar11);
  *param_1 = uVar1 + uVar5;
  param_1[1] = uVar2 + uVar6 + CARRY4(uVar1,uVar5);
  param_1[2] = uVar3 + uVar7 + bVar10;
  param_1[3] = uVar4 + uVar8 + bVar11;
  uVar1 = param_1[4];
  uVar2 = param_1[5];
  uVar3 = param_1[6];
  uVar4 = param_1[7];
  uVar5 = param_2[4] & uVar9;
  bVar10 = CARRY4(uVar1,uVar5) || CARRY4(uVar1 + uVar5,(uint)bVar12);
  uVar6 = param_2[5] & uVar9;
  bVar11 = CARRY4(uVar2,uVar6) || CARRY4(uVar2 + uVar6,(uint)bVar10);
  uVar7 = param_2[6] & uVar9;
  bVar13 = CARRY4(uVar3,uVar7) || CARRY4(uVar3 + uVar7,(uint)bVar11);
  uVar9 = param_2[7] & uVar9;
  param_1[4] = uVar1 + uVar5 + (uint)bVar12;
  param_1[5] = uVar2 + uVar6 + bVar10;
  param_1[6] = uVar3 + uVar7 + bVar11;
  param_1[7] = uVar4 + uVar9 + bVar13;
  return CONCAT44(param_2 + 8,(uint)(CARRY4(uVar4,uVar9) || CARRY4(uVar4 + uVar9,(uint)bVar13)));
}


