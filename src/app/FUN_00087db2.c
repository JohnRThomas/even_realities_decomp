/*
 * Function: FUN_00087db2
 * Entry:    00087db2
 * Prototype: undefined4 __stdcall FUN_00087db2(int * param_1, int param_2, uint param_3, ushort * param_4)
 */


undefined4 FUN_00087db2(int *param_1,int param_2,uint param_3,ushort *param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  
  uVar1 = *(ushort *)(param_1 + 2);
  iVar5 = *param_1;
  uVar4 = param_1[1];
  iVar3 = uVar4 * ((uint)*(ushort *)((int)param_1 + 10) - (uint)uVar1) + iVar5;
  if (((int)param_3 < iVar5) || (iVar3 < param_2)) {
LAB_00087dce:
    uVar2 = 0xffffffea;
  }
  else {
    uVar6 = uVar1;
    if ((param_2 < iVar5) || (uVar6 = *(ushort *)((int)param_1 + 10), iVar3 < (int)param_3)) {
      *param_4 = uVar6;
      return 0xffffffde;
    }
    if (uVar4 == 0) {
      *param_4 = uVar1;
    }
    else {
      uVar4 = (uint)uVar1 + ((param_2 - iVar5) + (uVar4 - 1)) / uVar4;
      *param_4 = (ushort)uVar4;
      if (param_3 < param_1[1] * ((uVar4 & 0xffff) - (uint)*(ushort *)(param_1 + 2)) + *param_1)
      goto LAB_00087dce;
    }
    uVar2 = 0;
  }
  return uVar2;
}


