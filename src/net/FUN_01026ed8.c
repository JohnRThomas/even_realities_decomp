/*
 * Function: FUN_01026ed8
 * Entry:    01026ed8
 * Prototype: undefined4 __stdcall FUN_01026ed8(undefined1 * param_1)
 */


undefined4 FUN_01026ed8(undefined1 *param_1)

{
  uint uVar1;
  undefined1 uVar2;
  
  uVar1 = FUN_01025f68();
  if ((int)uVar1 < 0x200) {
    if ((int)uVar1 < -0x1ff) {
      uVar2 = 0x81;
    }
    else {
      if ((int)uVar1 < 0) {
        uVar1 = uVar1 + 3;
      }
      uVar2 = (undefined1)((int)uVar1 >> 2);
    }
  }
  else {
    uVar2 = 0x7f;
  }
  *param_1 = uVar2;
  return 0;
}


