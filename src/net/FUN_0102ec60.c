/*
 * Function: FUN_0102ec60
 * Entry:    0102ec60
 * Prototype: undefined4 __stdcall FUN_0102ec60(undefined1 param_1, undefined4 * param_2)
 */


undefined4 FUN_0102ec60(undefined1 param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (*(int *)param_2[1] == param_2[3]) {
    FUN_0103ab04(param_2);
  }
  iVar1 = *(int *)param_2[1];
  *(int *)param_2[1] = iVar1 + 1;
  *(undefined1 *)(param_2[2] + iVar1) = param_1;
  if ((uint)param_2[3] < *(uint *)param_2[1]) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/logging/log_output.c"
                 ,0x7a,param_2[3]);
    FUN_0103a370();
  }
  return 0;
}


