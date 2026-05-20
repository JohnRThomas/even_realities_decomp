/*
 * Function: simulator_ancs_calendar_schedule_trigger
 * Entry:    00023c98
 * Prototype: undefined __stdcall simulator_ancs_calendar_schedule_trigger(void)
 */


void simulator_ancs_calendar_schedule_trigger(void)

{
  void *pvVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  
  pvVar1 = FUN_00018320();
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): enter\n");
    }
    else {
      ble_printk("%s(): enter\n","simulator_ancs_calendar_schedule_trigger",extraout_r2,BLE_DEBUG);
    }
  }
  memset((void *)((int)pvVar1 + 0x34),0,0x1b4);
  strcpy((char *)((int)pvVar1 + 0x44),"com.apple.mobilecal");
  strcpy((char *)((int)pvVar1 + 0x84),&DAT_000a1ba6);
  strcpy((char *)((int)pvVar1 + 0xc4),&DAT_000a1bae);
  strcpy((char *)((int)pvVar1 + 100),&DAT_000a1bbb);
  dump_ancs("calendar-sched",(int)pvVar1 + 0x34,extraout_r2_00,extraout_r3);
  k_sem_give((k_sem *)((int)pvVar1 + 0x1e8));
  return;
}


