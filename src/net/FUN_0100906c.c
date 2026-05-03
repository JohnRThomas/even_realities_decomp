/*
 * Function: FUN_0100906c
 * Entry:    0100906c
 * Prototype: undefined __stdcall FUN_0100906c(int * param_1, uint * param_2, uint * param_3)
 */


void FUN_0100906c(int *param_1,uint *param_2,uint *param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  
  uVar3 = *param_2;
  uVar5 = param_2[1];
  uVar7 = param_2[2];
  uVar9 = param_2[3];
  uVar10 = param_2[4];
  uVar11 = param_2[5];
  uVar12 = param_2[6];
  uVar13 = param_2[7];
  uVar2 = *param_3;
  uVar15 = param_3[1];
  uVar4 = uVar3 + uVar2;
  bVar17 = CARRY4(uVar5,uVar15) || CARRY4(uVar5 + uVar15,(uint)CARRY4(uVar3,uVar2));
  iVar6 = uVar5 + uVar15 + CARRY4(uVar3,uVar2);
  uVar2 = param_3[2];
  uVar3 = param_3[3];
  bVar18 = CARRY4(uVar7,uVar2) || CARRY4(uVar7 + uVar2,(uint)bVar17);
  iVar8 = uVar7 + uVar2 + (uint)bVar17;
  bVar17 = CARRY4(uVar9,uVar3) || CARRY4(uVar9 + uVar3,(uint)bVar18);
  uVar9 = uVar9 + uVar3 + bVar18;
  uVar2 = param_3[4];
  uVar5 = param_3[5];
  bVar18 = CARRY4(uVar10,uVar2) || CARRY4(uVar10 + uVar2,(uint)bVar17);
  uVar3 = uVar10 + uVar2 + (uint)bVar17;
  bVar17 = CARRY4(uVar11,uVar5) || CARRY4(uVar11 + uVar5,(uint)bVar18);
  uVar11 = uVar11 + uVar5 + bVar18;
  uVar2 = param_3[6];
  uVar16 = param_3[7];
  bVar19 = CARRY4(uVar12,uVar2) || CARRY4(uVar12 + uVar2,(uint)bVar17);
  uVar12 = uVar12 + uVar2 + bVar17;
  iVar14 = uVar13 + uVar16 + bVar19;
  uVar5 = uVar4 + 1;
  bVar17 = iVar6 + 1U < (uint)(0xfffffffe < uVar4);
  uVar4 = (iVar6 + 1) - (uint)(0xfffffffe >= uVar4);
  bVar18 = iVar8 + 1U < (uint)bVar17;
  uVar7 = (iVar8 + 1) - (uint)!bVar17;
  bVar17 = uVar9 < bVar18;
  uVar10 = uVar9 - !bVar18;
  bVar18 = uVar3 < (uVar9 != 0 || bVar17);
  uVar9 = uVar3 - (uVar9 == 0 && !bVar17);
  bVar17 = uVar11 < (uVar3 != 0 || bVar18);
  uVar15 = uVar11 - (uVar3 == 0 && !bVar18);
  bVar1 = uVar12 - 1 < (uint)(uVar11 != 0 || bVar17);
  uVar11 = (uVar12 - 1) - (uint)(uVar11 == 0 && !bVar17);
  uVar3 = (uint)(iVar14 + 1U < (uint)(1 < uVar12 || bVar1)) -
          (uint)(!CARRY4(uVar13,uVar16) && !CARRY4(uVar13 + uVar16,(uint)bVar19));
  bVar20 = CARRY4(uVar4,uVar3) || CARRY4(uVar4 + uVar3,(uint)CARRY4(uVar5,uVar3));
  bVar21 = CARRY4(uVar7,uVar3) || CARRY4(uVar7 + uVar3,(uint)bVar20);
  bVar17 = CARRY4(uVar10,(uint)bVar21);
  bVar18 = CARRY4(uVar9,(uint)bVar17);
  bVar19 = CARRY4(uVar15,(uint)bVar18);
  uVar2 = -((int)uVar3 >> 0x1f);
  *param_1 = uVar5 + uVar3;
  param_1[1] = uVar4 + uVar3 + (uint)CARRY4(uVar5,uVar3);
  param_1[2] = uVar7 + uVar3 + (uint)bVar20;
  param_1[3] = uVar10 + bVar21;
  param_1[4] = uVar9 + bVar17;
  param_1[5] = uVar15 + bVar18;
  param_1[6] = uVar11 + uVar2 + bVar19;
  param_1[7] = ((iVar14 + 1) - (uint)(1 >= uVar12 && !bVar1)) +
               uVar3 + (CARRY4(uVar11,uVar2) || CARRY4(uVar11 + uVar2,(uint)bVar19));
  return;
}


