/*
 * Function: FUN_010374a4
 * Entry:    010374a4
 * Prototype: undefined __stdcall FUN_010374a4(undefined4 * param_1, int param_2, int param_3, int param_4, int * param_5)
 */


void FUN_010374a4(undefined4 *param_1,int param_2,int param_3,int param_4,int *param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int extraout_r1;
  int extraout_r2;
  int extraout_r3;
  undefined4 in_stack_ffffffdc;
  
  puVar1 = param_1;
  if (param_1 != (undefined4 *)0x0) goto LAB_010374c4;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/work.c",0x2c8,param_4);
  while( true ) {
    while( true ) {
      puVar1 = (undefined4 *)FUN_0103a370();
      param_2 = extraout_r1;
      param_3 = extraout_r2;
      param_4 = extraout_r3;
LAB_010374c4:
      if (param_2 != 0) break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/work.c",0x2c9,
                   param_4);
    }
    if ((puVar1[0x2c] & 1) == 0) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/work.c",0x2ca,param_4
                );
  }
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = param_1 + 0x28;
  param_1[0x29] = param_1 + 0x28;
  param_1[0x2a] = param_1 + 0x2a;
  param_1[0x2b] = param_1 + 0x2a;
  if (param_5 == (int *)0x0) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0x101;
    if ((char)param_5[1] == '\0') {
      uVar2 = 1;
    }
  }
  param_1[0x2c] = uVar2;
  FUN_01036760(param_1,param_2,param_3,0x103711d,param_1,0,0,param_4,0,in_stack_ffffffdc,0xffffffff,
               -1);
  if ((param_5 != (int *)0x0) && (*param_5 != 0)) {
    FUN_0103b916();
  }
  FUN_0103795c(param_1);
  return;
}


