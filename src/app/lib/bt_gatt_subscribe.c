/*
 * Function: bt_gatt_subscribe
 * Entry:    0005f670
 * Prototype: int __stdcall bt_gatt_subscribe(bt_conn * conn, bt_gatt_subscribe_params * params)
 */


/* exclude_from_export */

int bt_gatt_subscribe(bt_conn *conn,bt_gatt_subscribe_params *params)

{
  bool bVar1;
  gatt_sub *sub;
  int iVar2;
  char *test;
  char *test_00;
  char *test_01;
  char *test_02;
  char *file;
  char *file_00;
  char *file_01;
  char *file_02;
  int line;
  int line_00;
  int line_01;
  int line_02;
  int *piVar3;
  
  if (conn == (bt_conn *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","conn","WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c"
            ,5245);
    _ASSERT("\tinvalid parameters\n\n",test,file,line);
LAB_0005f690:
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if ((params == (bt_gatt_subscribe_params *)0x0) || (*params == 0)) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","params && params->notify",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",0x147e);
    _ASSERT("\tinvalid parameters\n\n",test_00,file_00,line_00);
    goto LAB_0005f690;
  }
  if ((short)params[4] == 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","params->value",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",0x147f);
    _ASSERT("\tinvalid parameters\n\n",test_01,file_01,line_01);
    goto LAB_0005f690;
  }
  if (*(short *)((int)params + 0xe) == 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","params->ccc_handle",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",0x1485);
    _ASSERT("\tinvalid parameters\n\n",test_02,file_02,line_02);
    goto LAB_0005f690;
  }
  if (conn->state != 7) {
    return -0x80;
  }
  sub = gatt_sub_find(conn);
  if (sub == (gatt_sub *)0x0) {
    sub = gatt_sub_find((bt_conn *)0x0);
    if (sub == (gatt_sub *)0x0) {
      return -0xc;
    }
    bt_addr_le_copy(&sub->peer,&(conn->le).dst);
    sub->id = conn->id;
  }
  piVar3 = (int *)sub->list;
  if (piVar3 != (int *)0x0) {
    bVar1 = false;
    do {
      if (params == piVar3 + -6) {
        return -0x78;
      }
      if (((short)piVar3[-3] == (short)params[3]) &&
         (*(ushort *)(params + 4) <= *(ushort *)(piVar3 + -2))) {
        bVar1 = true;
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)0x0);
    if (bVar1) goto LAB_0005f75a;
  }
  iVar2 = gatt_write_ccc(conn,params);
  if (iVar2 != 0) {
    if (sub->list != 0) {
      return iVar2;
    }
    gatt_sub_free(sub);
    return iVar2;
  }
LAB_0005f75a:
  params[6] = sub->list;
  sub->list = params + 6;
  if (*(int *)&sub->field_0xc == 0) {
    *(bt_gatt_subscribe_params **)&sub->field_0xc = params + 6;
  }
  return 0;
}


