/*
 * Function: set_change_aware_no_store
 * Entry:    00086350
 * Prototype: bool __stdcall set_change_aware_no_store(gatt_cf_cfg * cfg, bool aware)
 */


/* exclude_from_export */

bool set_change_aware_no_store(gatt_cf_cfg *cfg,bool aware)

{
  byte extraout_r0;
  byte bVar1;
  atomic_t *target;
  byte extraout_r1;
  
  target = (atomic_t *)((int)&cfg->CF_NUM_FLAGS_ + 3);
  if (aware) {
    atomic_set_bit(target,1);
    bVar1 = ~extraout_r0 & extraout_r1;
  }
  else {
    bVar1 = atomic_test_and_clear_bit(target,-2);
  }
  return (bool)bVar1;
}


