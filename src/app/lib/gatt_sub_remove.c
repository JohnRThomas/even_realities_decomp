/*
 * Function: gatt_sub_remove
 * Entry:    000860a0
 * Prototype: void __stdcall gatt_sub_remove(bt_conn * conn, gatt_sub * sub, sys_snode_t * prev, bt_gatt_subscribe_params * params)
 */


/* exclude_from_export_ai */

void gatt_sub_remove(bt_conn *conn,gatt_sub *sub,sys_snode_t *prev,bt_gatt_subscribe_params *params)

{
  sys_snode_t *psVar1;
  
  if (params != (bt_gatt_subscribe_params *)0x0) {
    psVar1 = (sys_snode_t *)params[6];
    if (prev == (sys_snode_t *)0x0) {
      sub->list = psVar1;
      if (params + 6 == *(bt_gatt_subscribe_params **)&sub->field_0xc) {
        *(sys_snode_t **)&sub->field_0xc = psVar1;
      }
    }
    else {
      prev->next = psVar1;
      if (params + 6 == *(bt_gatt_subscribe_params **)&sub->field_0xc) {
        *(sys_snode_t **)&sub->field_0xc = prev;
      }
    }
    params[6] = 0;
    (*(code *)*params)(conn,params,0,0,params);
  }
  if (sub->list != 0) {
    return;
  }
  gatt_sub_free(sub);
  return;
}


