/*
 * Function: settings_load_subtree_direct
 * Entry:    000516d4
 * Prototype: int __stdcall settings_load_subtree_direct(char * subtree, settings_load_direct_cb cb, void * param)
 */


/* exclude_from_export */

int settings_load_subtree_direct(char *subtree,settings_load_direct_cb cb,void *param)

{
  int *piVar1;
  k_timeout_t timeout;
  char *local_14;
  settings_load_direct_cb puStack_10;
  void *local_c;
  
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = cb;
  local_14 = subtree;
  puStack_10 = cb;
  local_c = param;
  z_impl_k_mutex_lock((k_mutex *)&settings_lock,timeout);
  for (piVar1 = (int *)DAT_2000aae4; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    (**(code **)piVar1[1])(piVar1,&local_14);
  }
  z_impl_k_mutex_unlock((k_mutex *)&settings_lock);
  return 0;
}


