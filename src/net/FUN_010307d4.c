/*
 * Function: FUN_010307d4
 * Entry:    010307d4
 * Prototype: undefined __stdcall FUN_010307d4(int * param_1, int param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_010307d4(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int extraout_r1;
  
  if (param_1 != (int *)0x0) goto LAB_010307ea;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/net/buf_simple.c",0x2b,
               param_4);
  while( true ) {
    param_1 = (int *)FUN_0103a370();
    param_2 = extraout_r1;
LAB_010307ea:
    if (*(ushort *)(param_1 + 1) == 0) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/net/buf_simple.c",
                 0x2c,(uint)*(ushort *)(param_1 + 1));
  }
  *param_1 = param_1[2] + param_2;
  return;
}


