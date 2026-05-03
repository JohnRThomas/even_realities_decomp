/*
 * Function: FUN_0007f81e
 * Entry:    0007f81e
 * Prototype: undefined4 __stdcall FUN_0007f81e(byte * param_1)
 */


undefined4 FUN_0007f81e(byte *param_1)

{
  undefined4 uVar1;
  int *extraout_r2;
  int local_20;
  undefined1 local_1c;
  int local_18 [3];
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_20 = 0;
  local_1c = 0;
  if (param_1 == (byte *)0x0) {
    uVar1 = 7;
  }
  else {
    *param_1 = 0xc0;
    FUN_0007f798(param_1,0,&local_20);
    FUN_0007f7f2(param_1,extraout_r2);
    FUN_0007f7be(param_1,local_18);
    uVar1 = 0;
    param_1[0x14] = 0;
    param_1[0x15] = 0;
    param_1[0x16] = 0;
    param_1[0x17] = 0;
    param_1[0x18] = 0;
    param_1[0x19] = 0;
    param_1[0x1a] = 0;
    param_1[0x1b] = 0;
  }
  return uVar1;
}


