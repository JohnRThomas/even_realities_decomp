/*
 * Function: settings_load_subtree
 * Entry:    00051688
 * Prototype: int __stdcall settings_load_subtree(char * subtree)
 */


/* exclude_from_export */

int settings_load_subtree(char *subtree)

{
  int iVar1;
  undefined4 in_r1;
  int *piVar2;
  k_timeout_t timeout;
  char *local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_18 = 0;
  uStack_14 = 0;
  timeout.ticks._4_4_ = 0xffffffff;
  timeout.ticks._0_4_ = in_r1;
  local_1c = subtree;
  z_impl_k_mutex_lock((k_mutex *)&settings_lock,timeout);
  for (piVar2 = (int *)DAT_2000aae4; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    (**(code **)piVar2[1])(piVar2,&local_1c);
  }
  iVar1 = settings_commit_subtree(subtree);
  z_impl_k_mutex_unlock((k_mutex *)&settings_lock);
  return iVar1;
}


