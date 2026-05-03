/*
 * Function: FUN_0103080c
 * Entry:    0103080c
 * Prototype: undefined __stdcall FUN_0103080c(int * param_1, uint param_2)
 */


void FUN_0103080c(int *param_1,uint param_2)

{
  int iVar1;
  uint extraout_r1;
  int *extraout_r3;
  
  iVar1 = *param_1;
  if ((uint)(iVar1 - param_1[2]) < param_2) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/net/buf_simple.c",
                 0x12d,param_1);
    iVar1 = FUN_0103a370();
    param_2 = extraout_r1;
    param_1 = extraout_r3;
  }
  *param_1 = iVar1 - param_2;
  *(short *)(param_1 + 1) = (short)param_2 + (short)param_1[1];
  return;
}


