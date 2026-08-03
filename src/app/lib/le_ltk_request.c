/*
 * Function: le_ltk_request
 * Entry:    000576f0
 * Prototype: void __stdcall le_ltk_request(net_buf * buf)
 */


/* exclude_from_export_ai */

void le_ltk_request(net_buf *buf)

{
  bool bVar1;
  uint16_t uVar2;
  bt_conn *conn;
  net_buf *buf_00;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint16_t *puVar6;
  uint16_t *puVar7;
  uint8_t *ltk;
  dword in_stack_ffffff98;
  uint8_t *in_stack_ffffff9c;
  void *in_stack_ffffffa0;
  undefined4 local_50;
  char *local_4c;
  uint8_t *puVar8;
  void *in_stack_ffffffc0;
  uint8_t auStack_30 [16];
  undefined4 local_20;
  char *local_1c;
  
  puVar7 = (uint16_t *)(buf->field6_0xc).field0.data;
  uVar2 = *puVar7;
  ltk = &stack0xffffffc0;
  conn = bt_conn_lookup_handle(uVar2,BT_CONN_TYPE_LE);
  if (conn == (bt_conn *)0x0) {
    local_4c = "Unable to lookup conn for handle %u";
    local_50 = 3;
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&local_50,3,in_stack_ffffff98,in_stack_ffffff9c,
            in_stack_ffffffa0);
    return;
  }
  uVar4 = (uint)puVar7[5];
  puVar8 = ltk;
  bVar1 = bt_smp_request_ltk(conn,*(uint64_t *)(puVar7 + 1),puVar7[5],ltk);
  if (bVar1) {
    buf_00 = bt_hci_cmd_create(0x201a,'\x12');
    if (buf_00 == (net_buf *)0x0) {
LAB_00057754:
      local_1c = "Out of command buffers";
      local_20 = 2;
      LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1040,&local_20,2,uVar4,puVar8,in_stack_ffffffc0);
      goto LAB_0005776a;
    }
    puVar7 = net_buf_add((net_buf *)&(buf_00->field6_0xc).field0,0x12);
    puVar6 = puVar7 + 1;
    *puVar7 = uVar2;
    do {
      uVar3 = *(undefined4 *)ltk;
      uVar5 = *(undefined4 *)(ltk + 4);
      ltk = ltk + 8;
      *(undefined4 *)puVar6 = uVar3;
      *(undefined4 *)(puVar6 + 2) = uVar5;
      puVar6 = puVar6 + 4;
    } while (ltk != auStack_30);
    uVar2 = 0x201a;
  }
  else {
    buf_00 = bt_hci_cmd_create(0x201b,'\x02');
    if (buf_00 == (net_buf *)0x0) goto LAB_00057754;
    puVar7 = net_buf_add((net_buf *)&(buf_00->field6_0xc).field0,2);
    *puVar7 = uVar2;
    uVar2 = 0x201b;
  }
  bt_hci_cmd_send(uVar2,buf_00);
LAB_0005776a:
  bt_conn_unref(conn);
  return;
}


