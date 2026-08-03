/*
 * Function: settings_save_one
 * Entry:    00051614
 * Prototype: int __stdcall settings_save_one(char * name, void * value, size_t val_len)
 */


/* exclude_from_export */

int settings_save_one(char *name,void *value,size_t val_len)

{
  int iVar1;
  k_timeout_t timeout;
  
  iVar1 = DAT_2000aae0;
  if (DAT_2000aae0 == 0) {
    iVar1 = -2;
  }
  else {
    timeout.ticks._4_4_ = 0xffffffff;
    timeout.ticks._0_4_ = value;
    z_impl_k_mutex_lock((k_mutex *)&settings_lock,timeout);
    iVar1 = (**(code **)(*(int *)(iVar1 + 4) + 8))(iVar1,name,value,val_len);
    z_impl_k_mutex_unlock((k_mutex *)&settings_lock);
  }
  return iVar1;
}


