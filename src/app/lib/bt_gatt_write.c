/*
 * Function: bt_gatt_write
 * Entry:    0005f4d8
 * Prototype: int __stdcall bt_gatt_write(bt_conn * conn, bt_gatt_write_params * params)
 */


/* exclude_from_export_ai */

int bt_gatt_write(bt_conn *conn,bt_gatt_write_params *params)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  char *test;
  char *test_00;
  char *test_01;
  bt_gatt_write_params *params_00;
  code *func;
  bt_gatt_write_params *extraout_r1;
  char *file;
  char *file_00;
  char *file_01;
  int line;
  int line_00;
  int line_01;
  uint uVar4;
  code *encode;
  bt_att_chan_opt unaff_r4;
  uint8_t op;
  
  if (conn == (bt_conn *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","conn","WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c"
            ,5086);
    _ASSERT("\tinvalid parameters\n\n",test,file,line);
LAB_0005f4f8:
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if ((params == (bt_gatt_write_params *)0x0) || (params->func == (undefined *)0x0)) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","params && params->func",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",5087);
    _ASSERT("\tinvalid parameters\n\n",test_00,file_00,line_00);
    goto LAB_0005f4f8;
  }
  if (params->handle == 0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","params->handle",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",5088);
    _ASSERT("\tinvalid parameters\n\n",test_01,file_01,line_01);
    goto LAB_0005f4f8;
  }
  if (conn->state != 7) {
    return -0x80;
  }
  uVar1 = params->length;
  params_00 = params;
  if (params->offset == 0) {
    iVar2 = gatt_prepare_write(conn,params);
    uVar4 = uVar1 + 2;
    params_00 = extraout_r1;
    if (uVar4 <= iVar2 - 1U) {
      op = '\x12';
      encode = (code *)0x85fd3;
      func = (code *)&BYTE_00085dbb;
      goto LAB_0005f56a;
    }
  }
  iVar2 = gatt_prepare_write(conn,params_00);
  uVar3 = iVar2 - 5U & 0xffff;
  uVar4 = (uint)params->length;
  if (uVar3 <= params->length) {
    uVar4 = uVar3;
  }
  uVar4 = uVar4 + 4 & 0xffff;
  op = '\x16';
  func = (code *)0x865bd;
  encode = (code *)0x8600f;
LAB_0005f56a:
  iVar2 = gatt_req_send(conn,func,params,encode,op,uVar4,unaff_r4);
  return iVar2;
}


