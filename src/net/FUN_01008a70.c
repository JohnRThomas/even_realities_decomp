/*
 * Function: FUN_01008a70
 * Entry:    01008a70
 * Prototype: bool __stdcall FUN_01008a70(int * param_1, uint * param_2, uint * param_3)
 */


bool FUN_01008a70(int *param_1,uint *param_2,uint *param_3)

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
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  bool bVar22;
  
  uVar5 = *param_2;
  uVar6 = param_2[1];
  uVar7 = param_2[2];
  uVar8 = param_2[3];
  uVar9 = param_2[4];
  uVar10 = param_2[5];
  uVar11 = param_2[6];
  uVar12 = param_2[7];
  uVar1 = *param_3;
  uVar13 = param_3[1];
  bVar17 = CARRY4(uVar6,uVar13) || CARRY4(uVar6 + uVar13,(uint)CARRY4(uVar5,uVar1));
  uVar2 = param_3[2];
  uVar14 = param_3[3];
  bVar18 = CARRY4(uVar7,uVar2) || CARRY4(uVar7 + uVar2,(uint)bVar17);
  bVar19 = CARRY4(uVar8,uVar14) || CARRY4(uVar8 + uVar14,(uint)bVar18);
  uVar3 = param_3[4];
  uVar15 = param_3[5];
  bVar20 = CARRY4(uVar9,uVar3) || CARRY4(uVar9 + uVar3,(uint)bVar19);
  bVar21 = CARRY4(uVar10,uVar15) || CARRY4(uVar10 + uVar15,(uint)bVar20);
  uVar4 = param_3[6];
  uVar16 = param_3[7];
  bVar22 = CARRY4(uVar11,uVar4) || CARRY4(uVar11 + uVar4,(uint)bVar21);
  *param_1 = uVar5 + uVar1;
  param_1[1] = uVar6 + uVar13 + CARRY4(uVar5,uVar1);
  param_1[2] = uVar7 + uVar2 + (uint)bVar17;
  param_1[3] = uVar8 + uVar14 + bVar18;
  param_1[4] = uVar9 + uVar3 + (uint)bVar19;
  param_1[5] = uVar10 + uVar15 + bVar20;
  param_1[6] = uVar11 + uVar4 + bVar21;
  param_1[7] = uVar12 + uVar16 + bVar22;
  return (bool)('\x01' - (!CARRY4(uVar12,uVar16) && !CARRY4(uVar12 + uVar16,(uint)bVar22)));
}


