/*
 * Function: bt_gatt_encrypt_change
 * Entry:    0005fa40
 * Prototype: void __stdcall bt_gatt_encrypt_change(bt_conn * conn)
 */


/* exclude_from_export */

void bt_gatt_encrypt_change(bt_conn *conn)

{
  bool bVar1;
  gatt_sub *pgVar2;
  undefined4 in_r1;
  int extraout_r1;
  int bit;
  int bit_00;
  int extraout_r1_00;
  atomic_t *target;
  int *piVar3;
  bt_conn *local_18;
  undefined1 local_14;
  undefined3 uStack_13;
  
  _local_14 = CONCAT31((int3)((uint)in_r1 >> 8),1);
  local_18 = conn;
  bVar1 = bt_addr_le_is_bonded(conn->id,&(conn->le).dst);
  if ((bVar1) && (pgVar2 = gatt_sub_find(conn), pgVar2 != (gatt_sub *)0x0)) {
    bit = extraout_r1;
    for (piVar3 = (int *)pgVar2->list; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
      atomic_test_bit(piVar3 + -1,bit);
      atomic_test_bit(target,bit_00);
      gatt_write_ccc(conn,piVar3 + -6);
      bit = extraout_r1_00;
    }
  }
  bt_gatt_foreach_attr(1,0xffff,(bt_gatt_attr_func_t)0x5e801,&local_18);
  bVar1 = bt_gatt_change_aware(conn,false);
  if (!bVar1) {
    sc_indicate(1,0xffff);
  }
  return;
}


