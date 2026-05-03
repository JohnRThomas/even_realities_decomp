/*
 * Function: FUN_0004d4dc
 * Entry:    0004d4dc
 * Prototype: undefined __stdcall FUN_0004d4dc(undefined4 param_1, undefined4 param_2)
 */


void FUN_0004d4dc(undefined4 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  DAT_20004fd0 = param_1;
  DAT_20004fd4 = param_2;
  uVar1 = get_bootSeconds();
  DAT_20004fd8 = (int)uVar1;
  DAT_20004fdc = (int)((ulonglong)uVar1 >> 0x20);
  return;
}


