/*
 * Function: FUN_0102eb68
 * Entry:    0102eb68
 * Prototype: undefined __stdcall FUN_0102eb68(uint param_1, uint param_2, uint param_3, undefined1 * param_4, uint * param_5, uint param_6, byte * param_7, undefined4 * param_8)
 */


void FUN_0102eb68(uint param_1,uint param_2,uint param_3,undefined1 *param_4,uint *param_5,
                 uint param_6,byte *param_7,undefined4 *param_8)

{
  byte *pbVar1;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint *puVar2;
  
  pbVar1 = param_7;
  puVar2 = param_5;
  if (param_7 == (byte *)0x0) goto LAB_0102ebac;
  pbVar1 = FUN_0102c3ac((undefined4 *)0x0,&MemManage,param_6,(char *)param_7,param_8);
  if (-1 < (int)pbVar1) goto LAB_0102ebac;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/logging/log_msg.c",0x78
               ,extraout_r3);
  while( true ) {
    FUN_0103a370();
    pbVar1 = param_7;
    puVar2 = param_5;
LAB_0102ebac:
    param_3 = param_3 & 7;
    param_5 = (uint *)FUN_0102e6b4(((uint)(pbVar1 + (int)puVar2 + 0x17) & 0xfffffff8) >> 2);
    param_1 = (param_1 & 7) << 3 | param_3 << 6 | ((uint)pbVar1 & 0x7ff) << 9 | (int)puVar2 << 0x14;
    if (((param_5 == (uint *)0x0) || (param_7 == (byte *)0x0)) ||
       (pbVar1 = FUN_0102c3ac(param_5 + 4,pbVar1,param_6,(char *)param_7,param_8), -1 < (int)pbVar1)
       ) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/logging/log_msg.c",
                 0x92,extraout_r3_00);
  }
  FUN_0103aab8(param_5,param_2,param_1,param_4);
  return;
}


