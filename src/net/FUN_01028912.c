/*
 * Function: FUN_01028912
 * Entry:    01028912
 * Prototype: undefined4 __stdcall FUN_01028912(uint param_1, uint param_2, int param_3)
 */


undefined4 FUN_01028912(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (param_1 == param_2) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
    if (param_3 != 0) {
      uVar1 = FUN_0100feb0(param_1 ^ param_2);
      if (uVar1 < 2) {
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}


