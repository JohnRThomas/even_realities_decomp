/*
 * Function: FUN_0102b91c
 * Entry:    0102b91c
 * Prototype: undefined4 __stdcall FUN_0102b91c(undefined4 param_1, undefined1 * param_2, undefined1 * param_3)
 */


undefined4 FUN_0102b91c(undefined4 param_1,undefined1 *param_2,undefined1 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10c;
  undefined1 auStack_108 [252];
  
  local_10c = 0;
  FUN_0103bdee(auStack_108,0,0xf8);
  FUN_0103bcfa((undefined1 *)&local_10c,param_2,param_3,&UNK_000000fc);
  iVar1 = FUN_0102ac98();
  if (iVar1 == 1) {
LAB_0102b978:
    uVar2 = 0;
  }
  else {
    if (param_3 < &UNK_000000fc) {
      iVar1 = FUN_0102ac68();
      if (iVar1 == 0) {
        FUN_0102ac48((undefined1 *)&local_10c,param_3);
        DAT_21004c9c = 1;
        goto LAB_0102b978;
      }
    }
    else if (0 < DAT_21000580) {
      FUN_01039ee2((byte *)"data len exceed:%d %d\n",param_3,0xfb,DAT_21000580);
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


