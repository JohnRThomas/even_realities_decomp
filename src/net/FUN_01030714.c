/*
 * Function: FUN_01030714
 * Entry:    01030714
 * Prototype: undefined __stdcall FUN_01030714(uint * param_1, uint * param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_01030714(uint *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  uint *extraout_r1;
  undefined4 extraout_r3;
  
  if (param_1 != (uint *)0x0) goto LAB_0103072e;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/net/buf.c",0x1c7,
               param_4);
  while( true ) {
    param_1 = (uint *)FUN_0103a370();
    param_2 = extraout_r1;
    param_4 = extraout_r3;
LAB_0103072e:
    if (param_2 != (uint *)0x0) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/net/buf.c",0x1c8,
                 param_4);
  }
  FUN_01036e20(param_1,(uint *)0x0,param_2,0,'\x01');
  return;
}


