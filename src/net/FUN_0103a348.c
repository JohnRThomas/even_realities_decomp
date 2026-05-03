/*
 * Function: FUN_0103a348
 * Entry:    0103a348
 * Prototype: undefined4 __stdcall FUN_0103a348(int * param_1)
 */


undefined4 FUN_0103a348(int *param_1)

{
  uint uVar1;
  
  if (param_1 != (int *)0x0) {
    uVar1 = param_1[1] & 3;
    if ((uVar1 == 2) || (uVar1 == 3)) {
      if (*param_1 != 0) goto LAB_0103a36a;
    }
    else if (uVar1 == 1) {
LAB_0103a36a:
      param_1[2] = 0;
      return 0;
    }
  }
  return 0xffffffea;
}


