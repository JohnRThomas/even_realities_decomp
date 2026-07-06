/*
 * Function: process_pt_data
 * Entry:    000346f8
 * Prototype: undefined4 __stdcall process_pt_data(undefined4 param_1)
 */


undefined4 process_pt_data(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  device *pdVar3;
  char *pcVar4;
  uint local_28;
  uint local_24;
  undefined *local_20;
  char *local_1c [2];
  
  if ((__UART_DEV_STATE == 2) ||
     (((pdVar3 = (device *)PTR_20002424, __UART_DEV_STATE == 0 ||
       (pdVar3 = UART_DEV_PTR, __UART_DEV_STATE == 1)) && (pdVar3 == (device *)0x0)))) {
    printk("comm para is error\n");
    return 0xffffffff;
  }
  local_28 = 0;
  local_24 = 0;
  local_20 = &DAT_2001acc4;
  local_1c[0] = &DAT_2001adc4;
  FUN_00032158();
  pdVar3 = (device *)PTR_20002424;
  if (__UART_DEV_STATE != 0) {
    pdVar3 = UART_DEV_PTR;
  }
  iVar2 = FUN_000805f2((uint)__UART_DEV_STATE,(st25dv_context *)pdVar3,&local_20,&local_24);
  if (iVar2 != 0) {
    FUN_00032164();
    return 0xfffffffe;
  }
  iVar2 = process_pt_protocol((uint)__UART_DEV_STATE,&DAT_2001acc4,local_24 & 0xff,(int *)local_1c,
                              (byte *)&local_28,param_1);
  if (iVar2 != 0) {
    printk("process_pt_protocol is failed\n");
    FUN_00032164();
    return 0xfffffffd;
  }
  pdVar3 = (device *)PTR_20002424;
  if (__UART_DEV_STATE != 0) {
    pdVar3 = UART_DEV_PTR;
  }
  iVar2 = comm_write((uint)__UART_DEV_STATE,(st25dv_context *)pdVar3,local_1c[0],local_28 & 0xff);
  if (iVar2 != 0) {
    printk("comm_write is failed\n");
    FUN_00032164();
    return 0xfffffffc;
  }
  FUN_00032164();
  if (local_1c[0][9] == -0x80) {
    sleep(1000);
    local_1c[0][9] = '\0';
    FUN_00032158();
    comm_write((uint)__UART_DEV_STATE,(st25dv_context *)PTR_20002424,local_1c[0],local_28 & 0xff);
    FUN_00032164();
  }
  pcVar4 = local_1c[0];
  if (__UART_DEV_STATE != 0) {
    pcVar4 = local_1c[0] + 4;
  }
  cVar1 = *pcVar4;
  if (cVar1 == '\x1b') {
    if (pcVar4[8] == '\0') {
      return 0;
    }
    erase_audio_buffer();
    return 0;
  }
  if (cVar1 == '\x13') {
    if ((pcVar4[4] & 0xfbU) != 0) {
      return 0;
    }
    iVar2 = __enable_charger();
    if (iVar2 == 0) {
      return 0;
    }
    return 0xfffffffb;
  }
  if (cVar1 == '\x06') {
    if (pcVar4[2] == '\x02') {
      DAT_20019a62 = 1;
      set_box_status(LID_CLOSED,true);
      FUN_0002c6f4(10000);
      return 0;
    }
    printk("enter into long trip \n");
    sleep(10000);
    change_work_mode(7);
    return 0;
  }
  if (cVar1 == '\v') {
    if (LOG_LEVEL < 1) goto LAB_0003485e;
    pcVar4 = "%s(): sys reboot because process_pt_data cmd PTP_DEVICE_RESTART\n";
  }
  else {
    if (cVar1 == '<') {
      if (pcVar4[4] != '\0') {
        return 0;
      }
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): sys reboot because process_pt_data cmd %d and ACK_SUCC\n","process_pt_data")
          ;
        }
        else {
          ble_printk("%s(): sys reboot because process_pt_data cmd %d and ACK_SUCC\n");
        }
      }
      goto LAB_0003485e;
    }
    if (cVar1 != '\x01') {
      return 0;
    }
    if (pcVar4[4] != '\0') {
      return 0;
    }
    if (LOG_LEVEL < 1) goto LAB_0003485e;
    pcVar4 = "%s(): sys reboot because process_pt_data cmd ACK_SUCC\n";
  }
  if (BLE_DEBUG == 0) {
    printk(pcVar4,"process_pt_data");
  }
  else {
    ble_printk(pcVar4);
  }
LAB_0003485e:
  sleep(300);
                    /* WARNING: Subroutine does not return */
  sys_reboot(1);
}


