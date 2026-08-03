/*
 * Function: bt_gatt_dm_data_release
 * Entry:    00082d2c
 * Prototype: int __stdcall bt_gatt_dm_data_release(bt_gatt_dm * dm)
 */


/* exclude_from_export */

int bt_gatt_dm_data_release(bt_gatt_dm *dm)

{
  atomic_val_t aVar1;
  int iVar2;
  atomic_t *target;
  
  target = (atomic_t *)((int)&dm[5].uuid + 3);
  aVar1 = atomic_and(target,-3);
  if (aVar1 << 0x1e < 0) {
    svc_attr_memory_release(dm);
    atomic_and(target,-2);
    iVar2 = 0;
  }
  else {
    iVar2 = -0x78;
  }
  return iVar2;
}


