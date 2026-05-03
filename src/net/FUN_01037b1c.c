/*
 * Function: FUN_01037b1c
 * Entry:    01037b1c
 * Prototype: undefined __stdcall FUN_01037b1c(undefined4 param_1, int * param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_01037b1c(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int *extraout_r1;
  int *piVar1;
  int iVar2;
  
  if (param_2 == (int *)&DAT_210043a8) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",0x484,
                 &DAT_210043a8);
    FUN_0103a370();
    param_2 = extraout_r1;
  }
  iVar2 = *param_2;
  piVar1 = (int *)param_2[1];
  *piVar1 = iVar2;
  *(int **)(iVar2 + 4) = piVar1;
  *param_2 = 0;
  param_2[1] = 0;
  return;
}


