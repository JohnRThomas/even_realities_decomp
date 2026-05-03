/*
 * Function: FUN_01036760
 * Entry:    01036760
 * Prototype: undefined4 * __stdcall FUN_01036760(undefined4 * param_1, int param_2, int param_3, int param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, int param_8, undefined1 param_9, undefined4 param_10, uint param_11, int param_12)
 */


undefined4 *
FUN_01036760(undefined4 *param_1,int param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,int param_8,undefined1 param_9,undefined4 param_10
            ,uint param_11,int param_12)

{
  bool bVar1;
  undefined4 *puVar2;
  int extraout_r1;
  int extraout_r2;
  int extraout_r3;
  uint uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getCurrentExceptionNumber();
    uVar3 = uVar3 & 0x1f;
  }
  puVar2 = param_1;
  if (uVar3 != 0) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/thread.c",0x28c,
                 param_4);
    puVar2 = (undefined4 *)FUN_0103a370();
    param_2 = extraout_r1;
    param_3 = extraout_r2;
    param_4 = extraout_r3;
  }
  FUN_0103669c((uint)puVar2,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  if (param_12 != -1 || param_11 != 0xffffffff) {
    if (param_12 == 0 && param_11 == 0) {
      FUN_0103795c(param_1);
    }
    else {
      FUN_0103874c(param_1 + 6,&LAB_0103ba88_1,param_11,param_12);
    }
  }
  return param_1;
}


