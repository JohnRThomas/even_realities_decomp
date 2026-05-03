/*
 * Function: FUN_0103b458
 * Entry:    0103b458
 * Prototype: undefined __stdcall FUN_0103b458(int * param_1)
 */


void FUN_0103b458(int *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_1 + 0x18);
  if (*(int *)(*param_1 + 0x10) << 2 < 0) {
    if (iVar1 == 1) {
      *(short *)(param_1[8] + param_1[5] * 8 + 4) =
           ((short)param_1[0xc] + -1) - *(short *)((int)param_1 + 10);
      return;
    }
  }
  else if (iVar1 == 1) {
    *(ushort *)param_1[8] = *(ushort *)param_1[8] | 1;
  }
  return;
}


