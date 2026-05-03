/*
 * Function: FUN_01037cd4
 * Entry:    01037cd4
 * Prototype: undefined __stdcall FUN_01037cd4(int * param_1, int * param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_01037cd4(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  
  FUN_01037c9c(param_1,param_2);
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 2;
  if (param_2 != (int *)0x0) {
    param_1[2] = (int)param_2;
    if (param_1 == (int *)&DAT_210043a8) {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",0xc1,
                   &DAT_210043a8);
      FUN_0103a370();
    }
    piVar1 = (int *)*param_2;
    if (param_2 != piVar1) {
      for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
        if ((*(char *)((int)param_1 + 0xe) != *(char *)((int)piVar1 + 0xe)) &&
           (*(char *)((int)param_1 + 0xe) < *(char *)((int)piVar1 + 0xe))) {
          puVar2 = (undefined4 *)piVar1[1];
          *param_1 = (int)piVar1;
          param_1[1] = (int)puVar2;
          *puVar2 = param_1;
          piVar1[1] = (int)param_1;
          return;
        }
        if (piVar1 == (int *)param_2[1]) break;
      }
    }
    puVar2 = (undefined4 *)param_2[1];
    *param_1 = (int)param_2;
    param_1[1] = (int)puVar2;
    *puVar2 = param_1;
    param_2[1] = (int)param_1;
  }
  return;
}


