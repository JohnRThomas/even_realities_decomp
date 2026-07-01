/*
 * Function: timeout_handler
 * Entry:    0001570c
 * Prototype: undefined __stdcall timeout_handler(k_timer * param_1, undefined4 param_2, undefined4 param_3)
 */


void timeout_handler(k_timer *param_1,undefined4 param_2,undefined4 param_3)

{
  uint32_t uVar1;
  undefined4 extraout_r3;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar3 = CONCAT44(param_2,param_1);
  uVar1 = sys_clock_tick_get_32();
  if (DAT_20070000 == 0xa5a5a5a5) {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        uVar2 = FUN_0007f2bc();
        printk("%s(): RTC has sync at %lld ms\n","timeout_handler",(int)uVar2,
               (int)((ulonglong)uVar2 >> 0x20),uVar3);
      }
      else {
        uVar2 = FUN_0007f2bc();
        ble_printk("%s(): RTC has sync at %lld ms\n","timeout_handler",(int)uVar2,
                   (int)((ulonglong)uVar2 >> 0x20),uVar3,param_3);
      }
    }
  }
  else {
    Peripherals::IPC_S.TASKS_SEND_2_ = 1;
    DAT_20070000 = uVar1;
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        FUN_0007f2bc();
        printk("%s(): IPC send at %d ticks %lld ms\n","timeout_handler",uVar1);
      }
      else {
        uVar3 = FUN_0007f2bc();
        ble_printk("%s(): IPC send at %d ticks %lld ms\n","timeout_handler",uVar1,extraout_r3,uVar3,
                   param_3);
      }
    }
    if (uVar1 < 0x28001) {
      return;
    }
  }
  z_impl_k_timer_stop(param_1);
  DAT_20002308 = 0;
  return;
}


