/*
 * Function: FUN_0103b7b2
 * Entry:    0103b7b2
 * Prototype: int * __stdcall FUN_0103b7b2(int param_1, int * param_2, int param_3)
 */


int * FUN_0103b7b2(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined *puVar5;
  int *piVar6;
  undefined8 uVar7;
  undefined4 uStack_24;
  int iStack_20;
  
  uStack_24 = param_2;
  iStack_20 = param_3;
  uVar7 = (**(code **)(*(int *)(*(int *)(param_1 + 0xa0) + 0x20) + 8))();
  uVar1 = (undefined4)((ulonglong)uVar7 >> 0x20);
  if (-1 < (int)uVar7 << 0x1d) {
    return (int *)0x0;
  }
  puVar5 = (undefined *)0x0;
  if (param_3 != 0) {
    puVar5 = &DAT_00003a98;
  }
  piVar6 = (int *)(param_1 + 0x58);
  while( true ) {
    FUN_0103b686(piVar6,uVar1);
    piVar4 = *(int **)(param_1 + 0xb4);
    iVar3 = *(int *)(*(int *)(param_1 + 0xa0) + 0x18);
    if ((piVar4 != (int *)(param_1 + 0xb4)) && (piVar4 != (int *)0x0)) break;
    if (iVar3 == 1) {
      piVar4 = (int *)FUN_0103b410(*(int *)(param_1 + 0xa8),(ushort *)((int)&uStack_24 + 2),param_2)
      ;
      FUN_01036fe4(piVar6);
      if (piVar4 != (int *)0x0) goto LAB_0103b812;
    }
    else {
      FUN_01036fe4(piVar6);
    }
    if (puVar5 == (undefined *)0x0) {
      return (int *)0x0;
    }
    FUN_01038424(0x21,0);
    puVar5 = puVar5 + -1;
    uVar1 = extraout_r1;
  }
  piVar2 = (int *)piVar4[1];
  *(int **)(*piVar4 + 4) = piVar2;
  *piVar2 = *piVar4;
  *piVar4 = (int)piVar4;
  piVar4[1] = (int)piVar4;
  if (iVar3 == 1) {
    uStack_24 = (int *)CONCAT22(*(ushort *)(piVar4 + 2),(undefined2)uStack_24);
    iVar3 = FUN_0103b406(*(int *)(param_1 + 0xa8),(uint)*(ushort *)(piVar4 + 2));
    *param_2 = iVar3;
  }
  FUN_01036fe4(piVar6);
LAB_0103b812:
  piVar4[2] = (uint)uStack_24 >> 0x10;
  *param_2 = *param_2 + -0x10;
  return piVar4 + 4;
}


