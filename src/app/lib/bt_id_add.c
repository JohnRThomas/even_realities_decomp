/*
 * Function: bt_id_add
 * Entry:    00058308
 * Prototype: void __stdcall bt_id_add(bt_keys * keys)
 */


/* exclude_from_export */

void bt_id_add(bt_keys *keys)

{
  bt_conn *conn;
  int iVar1;
  net_buf *buf;
  undefined4 uVar2;
  char *pcVar3;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_20;
  char *local_1c;
  
  if (keys == (bt_keys *)0x0) {
    return;
  }
  if ((DAT_20002120 == 0) || (DAT_20002120 < DAT_20002121)) {
    DAT_20002121 = DAT_20002121 + 1;
    keys->state = keys->state | 4;
    return;
  }
  conn = bt_conn_lookup_state_le('\0',(bt_addr_le_t *)0x0,6);
  if (conn != (bt_conn *)0x0) {
    DAT_200020d4 = DAT_200020d4 | 0x8000;
    keys->state = keys->state | 1;
    bt_conn_unref(conn);
    return;
  }
  bt_le_ext_adv_foreach((void *)0x84863,(void *)0x0);
  if ((DAT_20002121 == 0) || (iVar1 = addr_res_enable('\0'), iVar1 == 0)) {
    if (DAT_20002121 == DAT_20002120) {
      local_1c = "Resolving list size exceeded. Switching to host.";
      local_20 = 2;
      LOG_WRN(&PTR_s_bt_id_0008b900,0x1080,&local_20,
              "Resolving list size exceeded. Switching to host.",in_stack_ffffffd0,in_stack_ffffffd4
              ,in_stack_ffffffd8);
      iVar1 = bt_hci_cmd_send_sync(0x2029,(net_buf *)0x0,(net_buf **)0x0);
      if (iVar1 == 0) {
        DAT_20002121 = DAT_20002121 + 1;
        keys->state = keys->state | 4;
        goto LAB_00058208;
      }
      pcVar3 = "Failed to clear resolution list";
      local_1c = "Failed to clear resolution list";
    }
    else {
      iVar1 = hci_id_add(keys->id,&keys->addr,(uint8_t *)((int)&keys->irk_val0 + 2));
      if (iVar1 == 0) {
        DAT_20002121 = DAT_20002121 + 1;
        keys->state = keys->state | 4;
        if (-1 < (int)((uint)DAT_200020a7 << 0x1d)) {
          local_1c = "Set privacy mode command is not supported";
          goto LAB_000581a6;
        }
        bt_addr_le_copy((bt_addr_le_t *)&stack0xffffffd0,&keys->addr);
        in_stack_ffffffd4 = (uint8_t *)CONCAT13(1,(int3)in_stack_ffffffd4);
        buf = bt_hci_cmd_create(0x204e,'\b');
        if (buf != (net_buf *)0x0) {
          net_buf_add_mem((net_buf *)&(buf->field6_0xc).field0,&stack0xffffffd0,8);
          iVar1 = bt_hci_cmd_send_sync(0x204e,buf,(net_buf **)0x0);
          if (iVar1 == 0) goto LAB_00058208;
        }
        local_1c = "Failed to set privacy mode";
      }
      else {
        local_1c = "Failed to add IRK to controller";
      }
      pcVar3 = &DAT_00000002;
    }
    uVar2 = 0x1040;
  }
  else {
    local_1c = "Failed to disable address resolution";
LAB_000581a6:
    pcVar3 = &DAT_00000002;
    uVar2 = 0x1080;
  }
  local_20 = 2;
  LOG_WRN(&PTR_s_bt_id_0008b900,uVar2,&local_20,pcVar3,in_stack_ffffffd0,in_stack_ffffffd4,
          in_stack_ffffffd8);
LAB_00058208:
  addr_res_enable('\x01');
  bt_le_ext_adv_foreach((void *)0x84839,(void *)0x0);
  return;
}


