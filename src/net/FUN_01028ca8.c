/*
 * Function: FUN_01028ca8
 * Entry:    01028ca8
 * Prototype: undefined4 __stdcall FUN_01028ca8(uint param_1)
 */


undefined4 FUN_01028ca8(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 1;
  }
  else {
    uVar1 = FUN_010200d8();
    if ((param_1 & ~uVar1) == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


