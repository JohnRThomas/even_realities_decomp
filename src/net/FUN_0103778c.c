/*
 * Function: FUN_0103778c
 * Entry:    0103778c
 * Prototype: undefined __stdcall FUN_0103778c(undefined4 * param_1)
 */


void FUN_0103778c(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *extraout_r3;
  undefined4 *puVar2;
  
  if (((*(char *)((int)param_1 + 0xd) < '\0') || ((*(byte *)((int)param_1 + 0xd) & 0x1f) != 0)) ||
     (param_1[6] != 0)) {
    return;
  }
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 0x80;
  puVar2 = (undefined4 *)0x0;
  if (param_1 == (undefined4 *)&DAT_210043a8) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",0xc1,0);
    param_1 = (undefined4 *)FUN_0103a370();
    puVar2 = extraout_r3;
  }
  puVar1 = &DAT_21004b40;
  if ((undefined4 **)DAT_21004b40 != &DAT_21004b40) {
    puVar2 = DAT_21004b40;
  }
  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    if ((*(char *)((int)param_1 + 0xe) != *(char *)((int)puVar2 + 0xe)) &&
       (*(char *)((int)param_1 + 0xe) < *(char *)((int)puVar2 + 0xe))) {
      puVar1 = (undefined4 *)puVar2[1];
      *param_1 = puVar2;
      param_1[1] = puVar1;
      *puVar1 = param_1;
      puVar2[1] = param_1;
      goto LAB_010377f6;
    }
    if (puVar2 == DAT_21004b44) break;
  }
  *param_1 = &DAT_21004b40;
  param_1[1] = DAT_21004b44;
  *DAT_21004b44 = param_1;
  DAT_21004b44 = param_1;
LAB_010377f6:
  FUN_01037734(0,&DAT_21004b28,puVar1,puVar2);
  return;
}


