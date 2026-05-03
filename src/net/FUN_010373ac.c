/*
 * Function: FUN_010373ac
 * Entry:    010373ac
 * Prototype: undefined __stdcall FUN_010373ac(undefined1 * param_1, int param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_010373ac(undefined1 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  int extraout_r1;
  int iVar2;
  undefined4 extraout_r3;
  
  puVar1 = param_1;
  iVar2 = param_2;
  if (param_1 != (undefined1 *)0x0) goto LAB_010373c6;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/work.c",0x89,param_4);
  while( true ) {
    puVar1 = (undefined1 *)FUN_0103a370();
    iVar2 = extraout_r1;
    param_4 = extraout_r3;
LAB_010373c6:
    if (iVar2 != 0) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/work.c",0x8a,param_4)
    ;
  }
  FUN_0103bdee(puVar1,0,0x10);
  *(int *)(param_1 + 4) = param_2;
  return;
}


