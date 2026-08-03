/*
 * Function: bt_gatt_cb_register
 * Entry:    0005dc84
 * Prototype: void __stdcall bt_gatt_cb_register(bt_gatt_cb * cb)
 */


/* exclude_from_export_ai */

void bt_gatt_cb_register(bt_gatt_cb *cb)

{
  sys_snode_t *psVar1;
  
  (cb->node).next = (sys_snode_t *)0x0;
  psVar1 = &cb->node;
  if (DAT_2000b8f4 == (sys_snode_t *)0x0) {
    DAT_2000b8f0 = psVar1;
    DAT_2000b8f4 = psVar1;
    return;
  }
  *DAT_2000b8f4 = (sys_snode_t)psVar1;
  DAT_2000b8f4 = psVar1;
  return;
}


