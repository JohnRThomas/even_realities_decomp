/*
 * Function: FUN_0101fe50
 * Entry:    0101fe50
 * Prototype: undefined4 __stdcall FUN_0101fe50(uint * param_1, undefined4 param_2, undefined4 * param_3)
 */


undefined4 FUN_0101fe50(uint *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  if (999 < uVar2) {
    param_3 = &DAT_21000eac;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x12;
  }
  if (999 < uVar2) {
    param_3[2] = uVar2;
  }
  return uVar1;
}


