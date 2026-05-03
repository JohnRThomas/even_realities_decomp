/*
 * Function: FUN_010129a6
 * Entry:    010129a6
 * Prototype: undefined __stdcall FUN_010129a6(undefined4 param_1, undefined4 param_2, undefined4 param_3, byte param_4)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010129a6(undefined4 param_1,undefined4 param_2,undefined4 param_3,byte param_4)

{
  int iVar1;
  undefined1 *extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  byte extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 auStack_28 [2];
  byte abStack_20 [12];
  undefined4 *puStack_14;
  
  DAT_21000f20 = param_1;
  DAT_21000f24 = param_4;
  if (param_4 != 0) {
    FUN_01009500(0x2d,0x31d,param_3,(uint)param_4);
    param_4 = extraout_r3;
  }
  FUN_01026284((undefined4 *)&DAT_21000f24,param_4,0x24);
  FUN_010210b0();
  FUN_010204a8();
  if (DAT_21000f48 != 0) {
    return;
  }
  FUN_01009500(0x2d,800,extraout_r2,0);
  puStack_14 = &DAT_21000f20;
  FUN_01026284((undefined4 *)&LAB_00000002,0,0x150);
  Reserved3 = 10000;
  LAB_00000002 = 0xff;
  _Reset = 0x13;
  DAT_00000046 = FUN_0100ac40();
  FUN_01028384(auStack_28,(int)DAT_00000046,0);
  FUN_01028580((int)DAT_00000046,'\x01',0);
  FUN_01028384(auStack_28,(int)DAT_00000046,4);
  FUN_01028580((int)DAT_00000046,'\0',0);
  LAB_00000012 = 0;
  FUN_010131a4((undefined2 *)&UNK_0000002a);
  iVar1 = FUN_0100dfbc((undefined4 *)abStack_20);
  if (iVar1 != 0) {
    FUN_0100e040(0x30,abStack_20);
    return;
  }
  FUN_01009500(0x2d,0x339,extraout_r2_00,extraout_r3_00);
  *extraout_r1 = 0xff;
  **(undefined1 **)(extraout_r1 + 0x44) = 1;
  return;
}


