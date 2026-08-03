/*
 * Function: bt_gatt_notification
 * Entry:    0008661a
 * Prototype: void __stdcall bt_gatt_notification(bt_conn * conn, uint16_t handle, void * data, uint16_t length)
 */


/* exclude_from_export */

void bt_gatt_notification(bt_conn *conn,uint16_t handle,void *data,uint16_t length)

{
  gatt_sub *pgVar1;
  int iVar2;
  undefined4 *puVar3;
  bt_gatt_subscribe_params *params;
  bt_gatt_subscribe_params *pbVar4;
  
  pgVar1 = gatt_sub_find(conn);
  if ((pgVar1 == (gatt_sub *)0x0) ||
     (puVar3 = (undefined4 *)pgVar1->list, puVar3 == (undefined4 *)0x0)) {
    return;
  }
  pbVar4 = (bt_gatt_subscribe_params *)*puVar3;
  if (pbVar4 != (bt_gatt_subscribe_params *)0x0) {
    pbVar4 = pbVar4 + -6;
  }
  if (*(uint16_t *)(puVar3 + -3) != handle) goto LAB_00086670;
  params = puVar3 + -6;
  do {
    if ((*(byte *)((int)params + 0x12) <= conn->sec_level) &&
       (iVar2 = (*(code *)*params)(conn,params,data,length), iVar2 == 0)) {
      bt_gatt_unsubscribe(conn,params);
    }
LAB_00086670:
    if (pbVar4 == (bt_gatt_subscribe_params *)0x0) {
      return;
    }
    do {
      params = pbVar4;
      if (params[6] == 0) {
        pbVar4 = (bt_gatt_subscribe_params *)0x0;
        if (*(uint16_t *)(params + 3) != handle) {
          return;
        }
        break;
      }
      pbVar4 = (bt_gatt_subscribe_params *)(params[6] + -0x18);
    } while (*(uint16_t *)(params + 3) != handle);
  } while( true );
}


