/*
 * Function: db_hash_read
 * Entry:    0005dedc
 * Prototype: ssize_t __stdcall db_hash_read(bt_conn * conn, bt_gatt_attr * attr, void * buf, uint16_t len, uint16_t offset)
 */


/* exclude_from_export */

ssize_t db_hash_read(bt_conn *conn,bt_gatt_attr *attr,void *buf,uint16_t len,uint16_t offset)

{
  bool bVar1;
  gatt_cf_cfg *pgVar2;
  ssize_t sVar3;
  int bit;
  int bit_00;
  atomic_t *target;
  void *in_stack_00000004;
  uint16_t in_stack_00000008;
  
  k_work_cancel_delayable_sync(&db_hash.work,(k_work_sync *)&db_hash.sync_work);
  atomic_test_bit((atomic_t *)&DAT_20006628,bit);
  db_hash_gen();
  set_all_change_unaware();
  db_hash_store();
  pgVar2 = find_cf_cfg(conn);
  if ((pgVar2 != (gatt_cf_cfg *)0x0) && ((int)((uint)pgVar2->data_CF_NUM_BYTES_ << 0x1f) < 0)) {
    target = (atomic_t *)((int)&pgVar2->CF_NUM_FLAGS_ + 3);
    bVar1 = atomic_test_bit(target,bit_00);
    if (-1 < (int)((uint)bVar1 << 0x1f)) {
      atomic_set_bit(target,2);
    }
  }
  sVar3 = bt_gatt_attr_read(buf,(bt_gatt_attr *)(uint)len,(void *)(uint)offset,0x6560,0x10,
                            in_stack_00000004,in_stack_00000008);
  return sVar3;
}


