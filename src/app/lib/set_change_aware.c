/*
 * Function: set_change_aware
 * Entry:    00086370
 * Prototype: void __stdcall set_change_aware(gatt_cf_cfg * cfg, bool aware)
 */


/* exclude_from_export */

void set_change_aware(gatt_cf_cfg *cfg,bool aware)

{
  bool bVar1;
  
  bVar1 = set_change_aware_no_store(cfg,aware);
  if (bVar1) {
    gatt_delayed_store_enqueue(cfg->id,&cfg->peer,1);
    return;
  }
  return;
}


