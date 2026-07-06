/*
 * Function: dmic_record_start
 * Entry:    0003d71c
 * Prototype: undefined __stdcall dmic_record_start(void)
 */


void dmic_record_start(void)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  pGVar1->field_0x106d = 4;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): received open dmic command\n","dmic_record_start");
    }
    else {
      ble_printk("%s(): received open dmic command\n");
    }
  }
  FUN_00030b28();
  startAudioStreamRecord();
  DAT_20008558 = 1;
  pGVar1 = __get_dashboard_state();
  *(undefined4 *)&pGVar1->field_0x1060 = 0x1d;
  pGVar1 = __get_dashboard_state();
  k_sem_give(&pGVar1->sem_4);
  return;
}


