/*
 * Function: gatt_sub_free
 * Entry:    0005d124
 * Prototype: void __stdcall gatt_sub_free(gatt_sub * sub)
 */


/* exclude_from_export */

void gatt_sub_free(gatt_sub *sub)

{
  if (sub->list != 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","gatt_sub_is_empty(sub)",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",3420);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  bt_addr_le_copy(&sub->peer,(bt_addr_le_t *)&DAT_000f0b50);
  return;
}


