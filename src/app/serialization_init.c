/*
 * Function: serialization_init
 * Entry:    00027e3c
 * Prototype: undefined4 __stdcall serialization_init(void)
 */


undefined4 serialization_init(void)

{
  int iVar1;
  char *fmt;
  undefined4 extraout_r1;
  k_timeout_t timeout;
  
  iVar1 = ipc_service_open_instance((device *)&PTR_s_ipc0_0008b3b8);
  if ((iVar1 < 0) && (iVar1 != -0x78)) {
    if (LOG_LEVEL < 1) {
      return 0xffffffff;
    }
    fmt = "%s(): ipc_service_open_instance() failure\n";
  }
  else {
    iVar1 = ipc_service_register_endpoint
                      ((device *)&PTR_s_ipc0_0008b3b8,(ipc_ept *)&DAT_20008458,
                       (ipc_ept_cfg *)&st25dv_device.data);
    if (-1 < iVar1) {
      timeout.ticks._4_4_ = 0xffffffff;
      timeout.ticks._0_4_ = extraout_r1;
      z_impl_k_sem_take((k_sem *)&DAT_20003b68,timeout);
      DAT_20008460 = 1;
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): ipc_service[HOST] has ready!\n\n","serialization_init");
        }
        else {
          ble_printk("%s(): ipc_service[HOST] has ready!\n\n");
        }
      }
      return 0;
    }
    if (LOG_LEVEL < 1) {
      return 0xffffffff;
    }
    fmt = "%s(): ipc_service_register_endpoint() failure\n";
  }
  if (BLE_DEBUG == 0) {
    printk(fmt,"serialization_init");
  }
  else {
    ble_printk(fmt);
  }
  return 0xffffffff;
}


