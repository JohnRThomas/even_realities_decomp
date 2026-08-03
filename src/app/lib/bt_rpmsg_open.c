/*
 * Function: bt_rpmsg_open
 * Entry:    0006346c
 * Prototype: int __stdcall bt_rpmsg_open(void)
 */


/* exclude_from_export */

int bt_rpmsg_open(void)

{
  int iVar1;
  undefined4 extraout_r1;
  k_timeout_t timeout;
  char local_20 [4];
  char *local_1c;
  int iStack_18;
  
  iVar1 = ipc_service_open_instance((device *)&PTR_s_ipc0_0008b3b8);
  if ((iVar1 == 0) || (iVar1 == -0x78)) {
    iVar1 = ipc_service_register_endpoint
                      ((device *)&PTR_s_ipc0_0008b3b8,(ipc_ept *)&DAT_2000ba64,
                       (ipc_ept_cfg *)&DAT_20002a78);
    if (iVar1 == 0) {
      timeout.ticks._4_4_ = 0x8000;
      timeout.ticks._0_4_ = extraout_r1;
      iVar1 = z_impl_k_sem_take((k_sem *)&DAT_20003b80,timeout);
      if (iVar1 == 0) {
        return 0;
      }
      local_1c = "Endpoint binding failed with %d";
    }
    else {
      local_1c = "Registering endpoint failed with %d";
    }
  }
  else {
    local_1c = "IPC service instance initialization failed: %d\n";
  }
  local_20[0] = '\x03';
  local_20[1] = '\0';
  local_20[2] = '\0';
  local_20[3] = '\0';
  iStack_18 = iVar1;
  LOG_ERR(&PTR_s_bt_hci_driver_0008b8f0,0x1840,local_20);
  return iVar1;
}


