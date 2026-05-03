/*
 * Function: FUN_0102e594
 * Entry:    0102e594
 * Prototype: undefined4 __stdcall FUN_0102e594(int param_1, undefined1 * param_2)
 */


undefined4 FUN_0102e594(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    DAT_2100061c = param_1;
    FUN_0102f068(param_2);
    uVar1 = 0;
  }
  return uVar1;
}


