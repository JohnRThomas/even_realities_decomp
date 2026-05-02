/*
 * Function: FUN_00089c30
 * Entry:    00089c30
 * Prototype: undefined4 __stdcall FUN_00089c30(int * param_1)
 */


undefined4 FUN_00089c30(int *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == (int *)*param_1) || ((int *)*param_1 == (int *)0x0)) {
    if ((int)((uint)*(byte *)(param_1 + 0xc) << 0x1f) < 0) {
      k_free((void *)param_1[5]);
      *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xfe;
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffff0;
  }
  return uVar1;
}


