/*
 * Function: FUN_0102c0c0
 * Entry:    0102c0c0
 * Prototype: undefined4 __stdcall FUN_0102c0c0(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 FUN_0102c0c0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 extraout_r2;
  undefined1 local_9;
  undefined4 uStack_8;
  
  uStack_8 = param_3;
  piVar2 = FUN_01036958((int *)&DAT_210008e0,&local_9,0,0);
  uVar3 = 0;
  if (piVar2 != (int *)0x0) {
    if (0 < DAT_21000580) {
      FUN_01039ee2((byte *)"Message sent error %d\n",piVar2,extraout_r2,DAT_21000580);
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(0);
    }
    uVar3 = 3;
    software_interrupt(2);
  }
  return uVar3;
}


