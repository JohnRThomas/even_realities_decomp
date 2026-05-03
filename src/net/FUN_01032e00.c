/*
 * Function: FUN_01032e00
 * Entry:    01032e00
 * Prototype: undefined __stdcall FUN_01032e00(void)
 */


void FUN_01032e00(void)

{
  undefined4 extraout_r2;
  undefined8 uVar1;
  int aiStack_1c [3];
  undefined4 local_10;
  undefined *local_c;
  
  FUN_0103bdee((undefined1 *)aiStack_1c,0,0x10);
  local_10._0_2_ = CONCAT11(1,(undefined1)local_10);
  local_c = &DAT_21004988;
  do {
    FUN_01038f24(aiStack_1c,1,0xffffffff,0xffffffff);
    uVar1 = FUN_0103bcdc(0x21004988);
    local_10 = local_10 & 0xffe03fff;
    FUN_01032cf0((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),extraout_r2);
  } while( true );
}


