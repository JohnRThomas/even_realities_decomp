/*
 * Function: ble_ancs_data_req_thread
 * Entry:    000198d8
 * Prototype: undefined __stdcall ble_ancs_data_req_thread(int param_1, undefined4 param_2, undefined4 param_3)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ble_ancs_data_req_thread(int param_1,undefined4 param_2,undefined4 param_3)

{
  GlassesState *pGVar1;
  int iVar2;
  size_t extraout_r0;
  size_t sVar3;
  size_t extraout_r0_00;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  uint extraout_r1_02;
  uint extraout_r1_03;
  uint uVar4;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined4 uVar5;
  undefined4 extraout_r1_06;
  uint extraout_r1_07;
  undefined4 extraout_r1_08;
  undefined4 extraout_r2;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  k_timeout_t timeout;
  k_timeout_t timeout_00;
  undefined4 extraout_r2_00;
  
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): enter\n");
    }
    else {
      ble_printk("%s(): enter\n","ble_ancs_data_req_thread",param_3,BLE_DEBUG);
    }
  }
  z_impl_k_sem_init((k_sem *)(param_1 + 0x200),0,10);
  z_impl_k_sem_init((k_sem *)(param_1 + 0x1e8),0,10);
  init_msgq_ancs();
  init_msgq_uid();
  z_impl_k_sleep((k_timeout_t)0x28000);
  do {
    do {
      while( true ) {
        while ((pGVar1 = __get_dashboard_state(), pGVar1->field_0x1 == '\x01' ||
               (pGVar1 = __get_dashboard_state(), pGVar1->field_0x1 == '\b'))) {
          z_impl_k_sleep((k_timeout_t)0x28000);
        }
        pGVar1 = __get_dashboard_state();
        if ((int)((uint)*(ushort *)&pGVar1->field_0x1070 << 0x18) < 0) break;
        sleep(1000);
      }
      uVar5 = extraout_r1;
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): !!!!!!!!!wait -> ancs_get_attr_req_sem\n");
          uVar5 = extraout_r1_06;
        }
        else {
          ble_printk("%s(): !!!!!!!!!wait -> ancs_get_attr_req_sem\n","ble_ancs_data_req_thread",
                     extraout_r2,BLE_DEBUG);
          uVar5 = extraout_r1_00;
        }
      }
      timeout.ticks._4_4_ = 0xffffffff;
      timeout.ticks._0_4_ = uVar5;
      z_impl_k_sem_take((k_sem *)(param_1 + 0x200),timeout);
      iVar2 = dequeue_uid((undefined4 *)&DAT_20006c8c,extraout_r1_01,extraout_r2_00);
    } while (iVar2 != 0);
    sVar3 = 0;
    uVar4 = extraout_r1_02;
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): !!!!!!!!!!!!!!get -> ancs_get_attr_req_sem %d evt_id %d\n",
               "ble_ancs_data_req_thread");
        sVar3 = extraout_r0_00;
        uVar4 = extraout_r1_07;
      }
      else {
        ble_printk("%s(): !!!!!!!!!!!!!!get -> ancs_get_attr_req_sem %d evt_id %d\n",
                   "ble_ancs_data_req_thread",_DAT_20006c8c,(uint)DAT_20006c90);
        sVar3 = extraout_r0;
        uVar4 = extraout_r1_03;
      }
    }
    if (DAT_20006c90 < 2) {
      request_ancs_attr_ext(sVar3,uVar4);
      uVar5 = extraout_r1_04;
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk(
                "%s(): !!!!!!!!!!!!wait -> ancs_get_attr_req_sem add done, and wait -> ancs_get_attr_data_sem\n"
                );
          uVar5 = extraout_r1_08;
        }
        else {
          ble_printk("%s(): !!!!!!!!!!!!wait -> ancs_get_attr_req_sem add done, and wait -> ancs_get_attr_data_sem\n"
                     ,"ble_ancs_data_req_thread",extraout_r2_01,BLE_DEBUG);
          uVar5 = extraout_r1_05;
        }
      }
      timeout_00.ticks._4_4_ = 0x8000;
      timeout_00.ticks._0_4_ = uVar5;
      z_impl_k_sem_take((k_sem *)(param_1 + 0x1e8),timeout_00);
    }
    else {
      *(undefined4 *)(param_1 + 0x1e4) = 2;
      *(undefined4 *)(param_1 + 0x3c) = _DAT_20006c8c;
      *(undefined1 *)(param_1 + 0x41) = 0;
      *(undefined1 *)(param_1 + 0x44) = 10;
      *(undefined1 *)(param_1 + 100) = 10;
      *(undefined1 *)(param_1 + 0x42) = 0;
      enqueue_ancs((void *)(param_1 + 0x34));
      memset((void *)(param_1 + 0x34),0,0x1b4);
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk(
                "%s(): !!!!!!!!!!!!wait -> ancs_get_attr_req_sem remove done, and wait -> ancs_get_attr_data_sem\n"
                );
        }
        else {
          ble_printk("%s(): !!!!!!!!!!!!wait -> ancs_get_attr_req_sem remove done, and wait -> ancs_get_attr_data_sem\n"
                     ,"ble_ancs_data_req_thread",extraout_r2_03,BLE_DEBUG);
        }
      }
    }
    recv_ble_data(param_1);
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): !!!!!!!!!!!!!!!!wait -> ancs_get_attr_data_sem done\n");
      }
      else {
        ble_printk("%s(): !!!!!!!!!!!!!!!!wait -> ancs_get_attr_data_sem done\n",
                   "ble_ancs_data_req_thread",extraout_r2_02,BLE_DEBUG);
      }
    }
  } while( true );
}


