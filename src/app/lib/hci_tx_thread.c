/*
 * Function: hci_tx_thread
 * Entry:    0005789c
 * Prototype: void __stdcall hci_tx_thread(void)
 */


/* exclude_from_export */

void hci_tx_thread(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  net_buf *buf;
  k_poll_event *in_r1;
  uint extraout_r1;
  uint extraout_r1_00;
  k_poll_event *extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 uVar4;
  uint extraout_r1_04;
  uint extraout_r1_05;
  uint uVar5;
  uint extraout_r1_06;
  uint extraout_r1_07;
  uint uVar6;
  undefined *puVar7;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  dword in_stack_ffffffa0;
  uint8_t *in_stack_ffffffa4;
  void *in_stack_ffffffa8;
  undefined4 local_50;
  char *local_4c;
  uint uStack_48;
  dword in_stack_ffffffc0;
  uint8_t *in_stack_ffffffc4;
  void *in_stack_ffffffc8;
  undefined4 local_30;
  char *local_2c;
  
  do {
    DAT_20002970 = DAT_20002970 & 0xffe03fff;
    iVar2 = conn_prepare_events((bt_conn *)&DAT_20002978,in_r1);
    iVar2 = iVar2 + 1;
    iVar3 = z_impl_k_poll((k_poll_event *)&DAT_20002964,iVar2,(k_timeout_t)0xffffffffffffffff);
    uVar5 = extraout_r1;
    if (iVar3 != 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","err == 0",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/hci_core.c",2782);
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(0);
      }
      software_interrupt(2);
      uVar5 = extraout_r1_00;
    }
    puVar7 = &DAT_20002964;
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      uVar6 = (*(uint *)(puVar7 + 0xc) & 0x1fffff) >> 0xe;
      if (2 < uVar6) {
        if (uVar6 == 4) {
          if (puVar7[0xc] == '\0') {
            timeout.ticks._4_4_ = 0;
            timeout.ticks._0_4_ = uVar5;
            buf = net_buf_get((k_fifo *)&DAT_2000214c,timeout);
            uVar4 = extraout_r1_02;
            if (buf == (net_buf *)0x0) {
              _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buf",
                      "WEST_TOPDIR/zephyr/subsys/bluetooth/host/hci_core.c",2672);
              bVar1 = (bool)isCurrentModePrivileged();
              if (bVar1) {
                setBasePriority(0);
              }
              software_interrupt(2);
              uVar4 = extraout_r1_03;
            }
            timeout_00.ticks._4_4_ = 0xffffffff;
            timeout_00.ticks._0_4_ = uVar4;
            z_impl_k_sem_take((k_sem *)&DAT_20002128,timeout_00);
            if (DAT_20002140 != (net_buf *)0x0) {
              local_2c = "Uncleared pending sent_cmd";
              local_30 = 2;
              LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1040,&local_30,2,in_stack_ffffffc0,
                      in_stack_ffffffc4,in_stack_ffffffc8);
              net_buf_unref(DAT_20002140);
              DAT_20002140 = (net_buf *)0x0;
            }
            DAT_20002140 = net_buf_ref(buf);
            uVar6 = bt_send(buf);
            uVar5 = extraout_r1_04;
            if (uVar6 != 0) {
              local_4c = "Unable to send to driver (err %d)";
              local_50 = 3;
              uStack_48 = uVar6;
              LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&local_50,3,in_stack_ffffffa0,
                      in_stack_ffffffa4,in_stack_ffffffa8);
              k_sem_give((k_sem *)&DAT_20002128);
              iVar3 = net_buf_id(buf);
              hci_cmd_done(*(uint16_t *)(&DAT_2000b5d6 + iVar3 * 0xc),'\x1f',buf);
              net_buf_unref(buf);
              uVar5 = extraout_r1_05;
            }
          }
          else if (puVar7[0xc] == '\x01') {
            bt_conn_process_tx((bt_conn *)(*(int *)(puVar7 + 0x10) + -0x38));
            uVar5 = extraout_r1_06;
          }
        }
        else {
          local_4c = "Unexpected k_poll event state %u";
          local_50 = 3;
          uStack_48 = uVar6;
          LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1880,&local_50,uVar6,in_stack_ffffffa0,
                  in_stack_ffffffa4,in_stack_ffffffa8);
          uVar5 = extraout_r1_07;
        }
      }
      puVar7 = puVar7 + 0x14;
    }
    z_impl_k_yield();
    in_r1 = extraout_r1_01;
  } while( true );
}


