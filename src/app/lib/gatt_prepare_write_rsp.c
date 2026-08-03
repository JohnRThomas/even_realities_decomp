/*
 * Function: gatt_prepare_write_rsp
 * Entry:    000865bc
 * Prototype: void __stdcall gatt_prepare_write_rsp(bt_conn * conn, uint8_t err, void * pdu, uint16_t length, void * user_data)
 */


/* exclude_from_export_ai */

void gatt_prepare_write_rsp(bt_conn *conn,uint8_t err,void *pdu,uint16_t length,void *user_data)

{
  ushort uVar1;
  int iVar2;
  code *encode;
  uint uVar3;
  uint n;
  void *m1;
  bt_att_chan_opt in_stack_ffffffc8;
  char local_28 [4];
  char *local_24;
  
  if (err != '\0') {
                    /* WARNING: Could not recover jumptable at 0x000865d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)user_data)(conn,err,user_data);
    return;
  }
  uVar1 = *(ushort *)((int)user_data + 0xc);
  n = length - 4;
  if (uVar1 < n) {
    local_24 = "Incorrect length, canceling write";
LAB_0005f5d2:
    local_28[0] = '\x02';
    local_28[1] = '\0';
    local_28[2] = '\0';
    local_28[3] = '\0';
    LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1040,local_28);
    encode = (code *)0x85f43;
  }
  else {
    m1 = *(void **)((int)user_data + 8);
    iVar2 = memcmp(m1,(void *)((int)pdu + 4),n);
    if ((*(short *)((int)pdu + 2) != *(short *)((int)user_data + 6)) || (iVar2 != 0)) {
      local_24 = "Incorrect offset or data in response, canceling write";
      goto LAB_0005f5d2;
    }
    uVar3 = uVar1 - n;
    *(short *)((int)user_data + 6) = *(short *)((int)pdu + 2) + (short)n;
    *(uint *)((int)user_data + 8) = (int)m1 + n;
    *(short *)((int)user_data + 0xc) = (short)uVar3;
    if ((uVar3 & 0xffff) != 0) {
      iVar2 = bt_gatt_write(conn,user_data);
      goto LAB_0005f5f8;
    }
    encode = (code *)0x85f55;
  }
  iVar2 = gatt_req_send(conn,&BYTE_00085dbb,user_data,encode,'\x18',1,in_stack_ffffffc8);
LAB_0005f5f8:
  if (iVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0005f608. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)user_data)(conn,0xe,user_data);
    return;
  }
  return;
}


