/*
 * Function: bt_gatt_notify_cb
 * Entry:    0005ea00
 * Prototype: int __stdcall bt_gatt_notify_cb(bt_conn * conn, bt_gatt_notify_params * params)
 */


/* WARNING: Removing unreachable block (ram,0x0005ea54) */
/* WARNING: Removing unreachable block (ram,0x0005ea56) */
/* WARNING: Removing unreachable block (ram,0x0005eb16) */
/* WARNING: Removing unreachable block (ram,0x0005ea5c) */
/* WARNING: Removing unreachable block (ram,0x0005eabc) */
/* WARNING: Removing unreachable block (ram,0x0005eac0) */
/* WARNING: Removing unreachable block (ram,0x0005ea6c) */
/* WARNING: Removing unreachable block (ram,0x0005ea90) */
/* WARNING: Removing unreachable block (ram,0x0005ea92) */
/* WARNING: Removing unreachable block (ram,0x0005eaac) */
/* WARNING: Removing unreachable block (ram,0x0005eab6) */
/* WARNING: Removing unreachable block (ram,0x0005eac2) */
/* WARNING: Removing unreachable block (ram,0x0005eaca) */
/* WARNING: Removing unreachable block (ram,0x0005eadc) */
/* WARNING: Removing unreachable block (ram,0x0005ead0) */
/* WARNING: Removing unreachable block (ram,0x0005ea88) */
/* exclude_from_export_ai */

int bt_gatt_notify_cb(bt_conn *conn,bt_gatt_notify_params *params)

{
  char *test;
  char *test_00;
  char *file;
  char *file_00;
  int line;
  int line_00;
  
  if (params == (bt_gatt_notify_params *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","params",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",2787);
    _ASSERT("\tinvalid parameters\n\n",test,file,line);
  }
  else {
    if ((params[1] != 0) || (*params != 0)) {
      atomic_test_bit(&DAT_200020d4,(int)params);
      return -0xb;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","params->attr || params->uuid",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",2788);
    _ASSERT("\tinvalid parameters\n\n",test_00,file_00,line_00);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


