/*
 * Function: adv_pause_enabled
 * Entry:    00084862
 * Prototype: void __stdcall adv_pause_enabled(bt_le_ext_adv * adv, void * data)
 */


/* exclude_from_export_ai */

void adv_pause_enabled(bt_le_ext_adv *adv,void *data)

{
  atomic_val_t aVar1;
  uint *extraout_r2;
  bt_le_ext_adv *adv_00;
  
  aVar1 = atomic_get((atomic_t *)&adv->BT_ADV_NUM_FLAGS_);
  if (-1 < aVar1 << 0x18) {
    return;
  }
  *extraout_r2 = *extraout_r2 | 0x8000;
  bt_le_adv_set_enable_legacy(adv_00,false);
  return;
}


