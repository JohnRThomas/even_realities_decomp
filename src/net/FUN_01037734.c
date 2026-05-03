/*
 * Function: FUN_01037734
 * Entry:    01037734
 * Prototype: undefined __stdcall FUN_01037734(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_01037734(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *extraout_r3;
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (((undefined4 **)DAT_21004b40 == &DAT_21004b40) ||
     (puVar2 = DAT_21004b40, DAT_21004b40 == (undefined4 *)0x0)) {
    puVar2 = DAT_21004b34;
  }
  puVar1 = DAT_21004b30;
  if (param_1 == 0) {
    if (DAT_21004b30 == (undefined4 *)0x0) {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",0x8f,0);
      FUN_0103a370();
      puVar1 = extraout_r3;
    }
    if ((((*(byte *)((int)puVar1 + 0xd) & 0x1f) == 0) && (puVar2[6] == 0)) &&
       (0x7f < *(ushort *)((int)puVar1 + 0xe))) {
      DAT_21004b3c = puVar1;
      return;
    }
  }
  if (puVar2 != puVar1) {
    FUN_010376e4((undefined *)puVar2);
  }
  DAT_21004b3c = puVar2;
  return;
}


