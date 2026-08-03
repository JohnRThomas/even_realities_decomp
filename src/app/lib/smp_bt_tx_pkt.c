/*
 * Function: smp_bt_tx_pkt
 * Entry:    00055b2c
 * Prototype: int __stdcall smp_bt_tx_pkt(net_buf * nb)
 */


/* exclude_from_export_ai */

int smp_bt_tx_pkt(net_buf *nb)

{
  ushort uVar1;
  byte bVar2;
  char cVar3;
  bool bVar4;
  uint16_t uVar5;
  conn_param_data *pcVar6;
  int *dwork;
  undefined4 extraout_r1;
  uint uVar7;
  uint uVar8;
  int iVar9;
  bt_conn *conn;
  k_timeout_t timeout;
  bt_gatt_notify_params bStack_68;
  undefined *local_64;
  uint8_t *local_60;
  short local_5c;
  undefined4 local_58;
  bt_conn_info bStack_50;
  char local_2c;
  
  memset(&bStack_68,0,0x18);
  conn = (bt_conn *)nb->user_data;
  local_64 = &DAT_2000290c;
  local_60 = (nb->field6_0xc).field0.data;
  local_58 = 0x84445;
  if (((conn != (bt_conn *)0x0) && (iVar9 = bt_conn_get_info(conn,&bStack_50), iVar9 == 0)) &&
     (local_2c == '\x02')) {
    uVar5 = smp_bt_get_mtu(nb);
    uVar8 = (uint)uVar5;
    if (uVar8 == 0) {
LAB_00055b8c:
      iVar9 = 1;
      goto LAB_00055b56;
    }
    pcVar6 = conn_param_data_get(conn);
    if (pcVar6 != (conn_param_data *)0x0) {
      bVar2 = *(byte *)((int)&pcVar6[5].smp_notify_sem + 1);
      if ((bVar2 != 0) && (uVar7 = (uint)*(byte *)&nb[1].node.next, uVar7 == bVar2)) {
        tx_rsp((int *)(pcVar6 + 6),dwork,(ulonglong)CONCAT14(bVar2,uVar7));
        uVar7 = 0;
        bVar4 = false;
        while( true ) {
          uVar1 = (nb->field6_0xc).field0.len;
          iVar9 = 0;
          if (uVar1 <= uVar7) break;
          cVar3 = *(char *)((int)&pcVar6[5].smp_notify_sem + 1);
          if ((cVar3 == '\0') || (*(char *)&nb[1].node.next != cVar3)) goto LAB_00055b54;
          if ((uint)uVar1 < uVar7 + uVar8) {
            uVar8 = (uint)(ushort)(uVar1 - (short)uVar7);
          }
          local_5c = (short)uVar8;
          iVar9 = bt_gatt_notify_cb(conn,&bStack_68);
          if (iVar9 == -0xc) {
            if (!bVar4) {
              if (uVar8 < 0x14) {
                iVar9 = 2;
                break;
              }
              uVar8 = uVar8 >> 1;
            }
            z_impl_k_yield();
          }
          else {
            if (iVar9 != 0) goto LAB_00055b8c;
            uVar1 = (short)uVar7 + (short)uVar8;
            uVar7 = (uint)uVar1;
            local_60 = (nb->field6_0xc).field0.data + uVar1;
            timeout.ticks._4_4_ = 0xffffffff;
            timeout.ticks._0_4_ = extraout_r1;
            z_impl_k_sem_take((k_sem *)(pcVar6 + 6),timeout);
            bVar4 = true;
          }
        }
        goto LAB_00055b56;
      }
    }
  }
LAB_00055b54:
  iVar9 = 5;
LAB_00055b56:
  smp_bt_ud_free(&nb->user_data);
  net_buf_unref(nb);
  return iVar9;
}


