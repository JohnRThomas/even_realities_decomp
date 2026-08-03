/*
 * Function: bt_gatt_identity_resolved
 * Entry:    0005fb28
 * Prototype: void __stdcall bt_gatt_identity_resolved(bt_conn * conn, bt_addr_le_t * private_addr, bt_addr_le_t * id_addr)
 */


/* exclude_from_export_ai */

void bt_gatt_identity_resolved(bt_conn *conn,bt_addr_le_t *private_addr,bt_addr_le_t *id_addr)

{
  bool bVar1;
  gatt_cf_cfg *pgVar2;
  bt_conn_le *addr;
  bt_addr_le_t *local_20;
  bt_addr_le_t *pbStack_1c;
  
  addr = &conn->le;
  local_20 = private_addr;
  pbStack_1c = id_addr;
  bVar1 = bt_addr_le_is_bonded(conn->id,&addr->dst);
  bt_gatt_foreach_attr(1,0xffff,(bt_gatt_attr_func_t)0x5d5a9,&local_20);
  if (bVar1) {
    bt_gatt_store_ccc(conn->id,&addr->dst);
  }
  pgVar2 = find_cf_cfg_by_addr(conn->id,private_addr);
  if ((pgVar2 != (gatt_cf_cfg *)0x0) && (bt_addr_le_copy(&pgVar2->peer,id_addr), bVar1)) {
    bt_gatt_store_cf(conn->id,&addr->dst);
  }
  return;
}


