/*
 * Function: adv_unpause_enabled
 * Entry:    00084838
 * Prototype: void __stdcall adv_unpause_enabled(bt_le_ext_adv * adv, void * data)
 */


/* exclude_from_export_ai */

void adv_unpause_enabled(bt_le_ext_adv *adv,void *data)

{
  uint uVar1;
  
  uVar1 = adv->BT_ADV_NUM_FLAGS_;
  adv->BT_ADV_NUM_FLAGS_ = uVar1 & 0xffff7fff;
  if (-1 < (int)(uVar1 << 0x10)) {
    return;
  }
  bt_le_adv_set_enable_legacy(adv,true);
  return;
}


