/*
 * Function: switch_to_dfu_mode
 * Entry:    00015820
 * Prototype: undefined __stdcall switch_to_dfu_mode(k_sem * param_1)
 */


void switch_to_dfu_mode(k_sem *param_1)

{
  bool bVar1;
  int iVar2;
  
  DAT_2001095c = 1;
  bVar1 = k_is_in_isr();
  if (bVar1) {
    k_sem_give(param_1);
    return;
  }
  iVar2 = (**(code **)(GLOBAL_STATE._0_4_ + 0x1054))("runtime_mode",&DAT_2001095c,1);
  if (iVar2 == 0) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): sys reboot because system reset %d, %d\n","switch_to_dfu_mode",0);
      }
      else {
        ble_printk("%s(): sys reboot because system reset %d, %d\n","switch_to_dfu_mode",0,
                   (uint)DAT_2001095c);
      }
    }
    sleep(500);
                    /* WARNING: Subroutine does not return */
    sys_reboot(1);
  }
  if (LOG_LEVEL < 1) {
    return;
  }
  if (BLE_DEBUG != 0) {
    ble_printk("%s(): failed to switch to ble mode [%d]\n","switch_to_dfu_mode",iVar2,BLE_DEBUG);
    return;
  }
  printk("%s(): failed to switch to ble mode [%d]\n");
  return;
}


