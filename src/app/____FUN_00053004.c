/*
 * Function: $_?_FUN_00053004
 * Entry:    00053004
 * Prototype: undefined4 __stdcall $_?_FUN_00053004(undefined4 * param_1, undefined4 param_2)
 */


undefined4 ____FUN_00053004(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  k_timeout_t timeout;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0xffff8fff;
  }
  iVar2 = param_1[1];
  if (iVar2 == 0x3a000) {
    if (*(int *)*param_1 == 0) {
      *(int *)*param_1 = 1;
      return 0;
    }
  }
  else {
    if (iVar2 == 0xe80000) {
      uVar1 = (&Peripherals::MUTEX_S.MUTEX_0_)[*(byte *)*param_1];
    }
    else {
      if (iVar2 == -0x56a3a0d4) {
        return 0xffff8fea;
      }
      timeout.ticks._4_4_ = 0xffffffff;
      timeout.ticks._0_4_ = param_2;
      uVar1 = z_impl_k_mutex_lock((k_mutex *)*param_1,timeout);
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 0xffff8fe9;
}


