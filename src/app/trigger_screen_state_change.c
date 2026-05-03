/*
 * Function: trigger_screen_state_change
 * Entry:    0002d838
 * Prototype: uint __stdcall trigger_screen_state_change(char * param_1, int param_2, uint param_3, undefined4 param_4)
 */


uint trigger_screen_state_change(char *param_1,int param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_2 + 0xfec);
  if (uVar1 == param_3) {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): %s: ignore:%d.\n","trigger_screen_state_change",param_1,uVar1,param_4);
      }
      else {
        ble_printk("%s(): %s: ignore:%d.\n","trigger_screen_state_change",param_1,uVar1);
      }
    }
    param_3 = 0xffffffff;
  }
  else {
    if (param_3 == 0) {
      *(undefined1 *)(param_2 + 0xfec) = 0;
    }
    else {
      *(undefined1 *)(param_2 + 0xfec) = 1;
      k_sem_give((k_sem *)(param_2 + 0x50));
    }
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): %s: trigger_on_screen -> %d\n","trigger_screen_state_change",param_1,
               (uint)*(byte *)(param_2 + 0xfec),param_4);
      }
      else {
        ble_printk("%s(): %s: trigger_on_screen -> %d\n","trigger_screen_state_change",param_1,
                   (uint)*(byte *)(param_2 + 0xfec));
      }
    }
  }
  return param_3;
}


