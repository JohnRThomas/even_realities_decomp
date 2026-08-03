/*
 * Function: _close
 * Entry:    0004e3d0
 * Prototype: undefined4 __stdcall _close(uint param_1)
 */


/* exclude_from_export_ai */

undefined4 _close(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r1;
  k_timeout_t timeout;
  
  iVar1 = console_write(param_1);
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = param_1 * 0x28;
    timeout.ticks._4_4_ = 0xffffffff;
    timeout.ticks._0_4_ = extraout_r1;
    z_impl_k_mutex_lock((k_mutex *)(iVar1 + 0x20002574),timeout);
    uVar2 = (**(code **)(*(int *)(&DAT_2000256c + iVar1) + 8))
                      (*(undefined4 *)(&DAT_20002568 + iVar1));
    z_impl_k_mutex_unlock((k_mutex *)(iVar1 + 0x20002574));
    _close16(param_1);
  }
  return uVar2;
}


