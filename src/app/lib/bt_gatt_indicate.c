/*
 * Function: bt_gatt_indicate
 * Entry:    0005e624
 * Prototype: int __stdcall bt_gatt_indicate(bt_conn * conn, bt_gatt_indicate_params * params)
 */


/* WARNING: Removing unreachable block (ram,0x0005e678) */
/* WARNING: Removing unreachable block (ram,0x0005e67a) */
/* WARNING: Removing unreachable block (ram,0x0005e742) */
/* WARNING: Removing unreachable block (ram,0x0005e680) */
/* WARNING: Removing unreachable block (ram,0x0005e6e0) */
/* WARNING: Removing unreachable block (ram,0x0005e6e4) */
/* WARNING: Removing unreachable block (ram,0x0005e690) */
/* WARNING: Removing unreachable block (ram,0x0005e6b4) */
/* WARNING: Removing unreachable block (ram,0x0005e6b6) */
/* WARNING: Removing unreachable block (ram,0x0005e6d0) */
/* WARNING: Removing unreachable block (ram,0x0005e6da) */
/* WARNING: Removing unreachable block (ram,0x0005e6e6) */
/* WARNING: Removing unreachable block (ram,0x0005e6ee) */
/* WARNING: Removing unreachable block (ram,0x0005e704) */
/* WARNING: Removing unreachable block (ram,0x0005e6f4) */
/* WARNING: Removing unreachable block (ram,0x0005e6ac) */
/* exclude_from_export_ai */

int bt_gatt_indicate(bt_conn *conn,bt_gatt_indicate_params *params)

{
  char *test;
  char *test_00;
  char *file;
  char *file_00;
  int line;
  int line_00;
  
  if (params == (bt_gatt_indicate_params *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","params",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",3012);
    _ASSERT("\tinvalid parameters\n\n",test,file,line);
  }
  else {
    if ((params->attr != (undefined *)0x0) || (params->uuid != (undefined *)0x0)) {
      atomic_test_bit(&DAT_200020d4,(int)params);
      return -0xb;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","params->attr || params->uuid",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",3013);
    _ASSERT("\tinvalid parameters\n\n",test_00,file_00,line_00);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


