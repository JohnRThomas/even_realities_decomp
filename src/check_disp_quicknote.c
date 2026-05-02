/*
 * Function: check_disp_quicknote
 * Entry:    00029dc8
 * Prototype: undefined __stdcall check_disp_quicknote(undefined4 param_1, uint param_2)
 */


void check_disp_quicknote(undefined4 param_1,uint param_2)

{
  GlassesState *pGVar1;
  uint uVar2;
  undefined4 extraout_r2;
  undefined4 uVar3;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  int iVar4;
  uint local_14;
  
  local_14 = param_2;
  pGVar1 = __get_dashboard_state();
  if (*(char *)pGVar1 == '\x01') {
    pGVar1 = __get_dashboard_state();
    if (**(char **)&pGVar1->field_0x1034 != '\x01') {
      pGVar1 = __get_dashboard_state();
      if (**(char **)&pGVar1->field_0x1034 != '\x02') {
        return;
      }
      pGVar1 = __get_dashboard_state();
      **(undefined1 **)&pGVar1->field_0x1034 = 0;
      local_14 = CONCAT22(local_14._2_2_,1);
      iVar4 = 1;
      do {
        pGVar1 = __get_dashboard_state();
        uVar2 = sync_to_slave((char *)pGVar1,6,&local_14,2);
        if ((int)uVar2 < 5000) {
          display_DelayClose(10000);
          z_impl_k_yield();
          return;
        }
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): SYNC TO Slave failed %d times,don\'t exec quick note start function.\n");
          }
          else {
            ble_printk("%s(): SYNC TO Slave failed %d times,don\'t exec quick note start function.\n"
                       ,"check_disp_quicknote",iVar4,BLE_DEBUG);
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 4);
      return;
    }
    pGVar1 = __get_dashboard_state();
    **(undefined1 **)&pGVar1->field_0x1034 = 0;
    pGVar1 = __get_dashboard_state();
    uVar3 = extraout_r2;
    if (pGVar1->field_0xd5 != '\f') {
      local_14 = CONCAT22(local_14._2_2_,0x101);
      pGVar1 = __get_dashboard_state();
      uVar2 = sync_to_slave((char *)pGVar1,6,&local_14,2);
      if ((int)uVar2 < 5000) {
        pGVar1 = __get_dashboard_state();
        FUN_00080224((int)pGVar1,0);
        pGVar1 = __get_dashboard_state();
        pGVar1->field_0xec = 0xc;
        pGVar1 = __get_dashboard_state();
        *(undefined1 *)(*(int *)&pGVar1->field_0x1034 + 1) = 1;
        pGVar1 = __get_dashboard_state();
        *(undefined1 *)(*(int *)&pGVar1->field_0x1034 + 2) = 0;
        pGVar1 = __get_dashboard_state();
        *(undefined1 *)(*(int *)&pGVar1->field_0x1034 + 3) = 7;
        pGVar1 = __get_dashboard_state();
        memset((void *)(*(int *)&pGVar1->field_0x1034 + 8),0,0x14a);
        pGVar1 = __get_dashboard_state();
        update_persist_task_status((int)pGVar1,0xc,2);
        return;
      }
      if (LOG_LEVEL < 2) {
        return;
      }
      if (BLE_DEBUG != 0) {
        ble_printk("%s(): SYNC TO Slave failed...,don\'t exec quick note start function.\n",
                   "check_disp_quicknote",extraout_r2_00,BLE_DEBUG);
        return;
      }
      printk("%s(): SYNC TO Slave failed...,don\'t exec quick note start function.\n");
      return;
    }
LAB_00029e06:
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG != 0) {
        ble_printk("%s(): quicknote is running, exit this time\n","check_disp_quicknote",uVar3,
                   BLE_DEBUG);
        return;
      }
      printk("%s(): quicknote is running, exit this time\n");
      return;
    }
  }
  else {
    pGVar1 = __get_dashboard_state();
    if (**(char **)&pGVar1->field_0x1034 == '\x01') {
      pGVar1 = __get_dashboard_state();
      **(undefined1 **)&pGVar1->field_0x1034 = 0;
      pGVar1 = __get_dashboard_state();
      uVar3 = extraout_r2_01;
      if (pGVar1->field_0xd5 == '\f') goto LAB_00029e06;
      local_14 = CONCAT22(local_14._2_2_,1);
      pGVar1 = __get_dashboard_state();
    }
    else {
      pGVar1 = __get_dashboard_state();
      if (**(char **)&pGVar1->field_0x1034 != '\x02') {
        return;
      }
      pGVar1 = __get_dashboard_state();
      **(undefined1 **)&pGVar1->field_0x1034 = 0;
      local_14 = local_14 & 0xffff0000;
      pGVar1 = __get_dashboard_state();
    }
    FUN_000294d0((int)pGVar1,6,&local_14,2);
  }
  return;
}


