/*
 * Function: $_?_FUN_00053078
 * Entry:    00053078
 * Prototype: undefined4 __stdcall $_?_FUN_00053078(undefined4 * param_1)
 */


undefined4 ____FUN_00053078(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0xffff8fff;
  }
  else {
    iVar2 = param_1[1];
    if (iVar2 == 0x3a000) {
      if (*(int *)*param_1 != 1) {
        return 0xffff8fe9;
      }
      *(int *)*param_1 = 0;
    }
    else if (iVar2 == 0xe80000) {
      (&Peripherals::MUTEX_S.MUTEX_0_)[*(byte *)*param_1] = 0;
    }
    else {
      if (iVar2 == -0x56a3a0d4) {
        return 0xffff8fea;
      }
      z_impl_k_mutex_unlock((k_mutex *)*param_1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


