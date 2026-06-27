/*
 * Function: ble_msg_dispatch_thread
 * Entry:    00028a0c
 * Prototype: undefined __stdcall ble_msg_dispatch_thread(byte * param_1, undefined4 param_2, undefined4 param_3)
 */


void ble_msg_dispatch_thread(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  int32_t ms;
  GlassesState *pGVar1;
  undefined4 *puVar2;
  
  if (1 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): enter\n");
    }
    else {
      ble_printk("%s(): enter\n","ble_msg_dispatch_thread",param_3,BLE_DEBUG);
    }
  }
  puVar2 = *(undefined4 **)(param_1 + 0x1068);
  *puVar2 = 0;
  *(undefined1 *)(puVar2 + 1) = 0;
  memset(*(void **)(param_1 + 0x1000),0,0x217);
  memset(*(void **)(param_1 + 0x1004),0,0xf5);
  memset(*(void **)(param_1 + 0x1008),0,0x1e8);
  memset(*(void **)(param_1 + 0x100c),0,0x1e8);
  memset(*(void **)(param_1 + 0x1010),0,0x1e9);
  memset(*(void **)(param_1 + 0xffc),0,0xaf);
  do {
    if ((int)((uint)*(ushort *)(param_1 + 0x1070) << 0x18) < 0) {
      process_for_new_message_come_on(param_1,param_1 + 0xee8);
      while ((param_1[1] == 1 || (pGVar1 = __get_dashboard_state(), pGVar1->field_0x1 == '\b'))) {
        z_impl_k_sleep((k_timeout_t)0x28000);
      }
      ms = 0x19;
    }
    else {
      ms = 1000;
    }
    k_msleep(ms);
  } while( true );
}


