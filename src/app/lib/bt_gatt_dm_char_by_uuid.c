/*
 * Function: bt_gatt_dm_char_by_uuid
 * Entry:    00051fdc
 * Prototype: bt_gatt_dm_attr * __stdcall bt_gatt_dm_char_by_uuid(bt_gatt_dm * dm, bt_uuid * uuid)
 */


/* exclude_from_export */

bt_gatt_dm_attr * bt_gatt_dm_char_by_uuid(bt_gatt_dm *dm,bt_uuid *uuid)

{
  bt_gatt_chrc *pbVar1;
  int iVar2;
  bt_gatt_dm_attr *prev;
  
  prev = (bt_gatt_dm_attr *)0x0;
  while( true ) {
    prev = bt_gatt_dm_char_next(dm,prev);
    if (prev == (bt_gatt_dm_attr *)0x0) {
      return (bt_gatt_dm_attr *)0x0;
    }
    pbVar1 = bt_gatt_dm_attr_chrc_val(prev);
    if (pbVar1 == (bt_gatt_chrc *)0x0) break;
    iVar2 = bt_uuid_cmp(uuid,(bt_uuid *)*pbVar1);
    if (iVar2 == 0) {
      return prev;
    }
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","chrc != ((void *)0)",
          "WEST_TOPDIR/nrf/subsys/bluetooth/gatt_dm.c",540);
                    /* WARNING: Subroutine does not return */
  k_panic();
}


