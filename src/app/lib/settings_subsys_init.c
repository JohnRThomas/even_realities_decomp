/*
 * Function: settings_subsys_init
 * Entry:    000519e4
 * Prototype: int __stdcall settings_subsys_init(void)
 */


/* exclude_from_export */

int settings_subsys_init(void)

{
  int iVar1;
  undefined4 in_r1;
  k_timeout_t timeout;
  
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = in_r1;
  z_impl_k_mutex_lock((k_mutex *)&settings_lock,timeout);
  if (DAT_2001e1c3 == '\0') {
    settings_init();
    iVar1 = settings_backend_init();
    if (iVar1 != 0) goto LAB_00051a0c;
    DAT_2001e1c3 = '\x01';
  }
  iVar1 = 0;
LAB_00051a0c:
  z_impl_k_mutex_unlock((k_mutex *)&settings_lock);
  return iVar1;
}


