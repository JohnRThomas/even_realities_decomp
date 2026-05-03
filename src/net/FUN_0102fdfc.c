/*
 * Function: FUN_0102fdfc
 * Entry:    0102fdfc
 * Prototype: undefined4 __stdcall FUN_0102fdfc(undefined4 param_1)
 */


undefined4 FUN_0102fdfc(undefined4 param_1)

{
  byte local_18 [4];
  char *local_14;
  undefined4 uStack_10;
  
  local_14 = "Failed to allocate new MPU region %u\n";
  local_18[0] = 3;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  uStack_10 = param_1;
  FUN_0102ea44(0x103c064,0x1840,local_18,(undefined1 *)0x0);
  return 0xffffffea;
}


