/*
 * Function: FUN_0103b48a
 * Entry:    0103b48a
 * Prototype: undefined __stdcall FUN_0103b48a(int * param_1)
 */


void FUN_0103b48a(int *param_1)

{
  int iVar1;
  
  DataMemoryBarrier(0x1b);
  iVar1 = *(int *)(*param_1 + 0x18);
  if ((*(uint *)(*param_1 + 0x10) & 0x20000000) == 0) {
    if ((iVar1 != 1) || ((int)((uint)*(ushort *)param_1[7] << 0x1f) < 0)) goto LAB_0103b4bc;
  }
  else if ((iVar1 != 1) ||
          (*(ushort *)((int)param_1 + 0x26) <=
           (ushort)((*(short *)(param_1[8] + 2) + -1) - *(short *)(param_1[7] + param_1[5] * 2 + 4))
          )) goto LAB_0103b4bc;
  if ((code *)param_1[4] != (code *)0x0) {
    (*(code *)param_1[4])(param_1);
  }
LAB_0103b4bc:
  *(undefined2 *)((int)param_1 + 0x26) = 0;
  return;
}


