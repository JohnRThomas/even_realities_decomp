/*
 * Function: tx_meta_data_free
 * Entry:    0005b5e8
 * Prototype: void __stdcall tx_meta_data_free(bt_att_tx_meta_data * data)
 */


/* exclude_from_export_ai */

void tx_meta_data_free(bt_att_tx_meta_data *data)

{
  bt_att_tx_meta_data *buf;
  
  if (data == (bt_att_tx_meta_data *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","data","WEST_TOPDIR/zephyr/subsys/bluetooth/host/att.c",
            196);
  }
  else {
    buf = (bt_att_tx_meta_data *)(data->att_chan + 0x148);
    if ((data < (bt_att_tx_meta_data *)&DAT_2000b7b4) || ((bt_att_tx_meta_data *)0x2000b87b < data))
    {
      if (buf == data) {
        memset(buf,0,0x14);
        return;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","alloc_from_global",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/att.c",0xcd);
    }
    else {
      if (buf != data) {
        memset(data,0,0x14);
        k_queue_append(&gatt_prep_queue._queue,data);
        return;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!alloc_from_global",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/att.c",0xcb);
    }
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


