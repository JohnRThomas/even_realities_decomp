/*
 * Function: global_ipc_service_send
 * Entry:    00027d60
 * Prototype: int __stdcall global_ipc_service_send(void * param_1, size_t param_2)
 */


int global_ipc_service_send(void *param_1,size_t param_2)

{
  GlassesState *pGVar1;
  int iVar2;
  
  if (((DAT_20008460 == 1) && (pGVar1 = __get_dashboard_state(), pGVar1->field_0x1 != '\b')) &&
     (pGVar1 = __get_dashboard_state(), pGVar1->field_0x1 != '\t')) {
    iVar2 = ipc_service_send((ipc_ept *)&DAT_20008458,param_1,param_2);
    if (iVar2 < 0) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): ipc_service_send data failed with ret %d %d\n","global_ipc_service_send",
                 iVar2,DAT_20008454);
        }
        else {
          ble_printk("%s(): ipc_service_send data failed with ret %d %d\n","global_ipc_service_send"
                     ,iVar2);
        }
      }
      DAT_20008454 = DAT_20008454 + 1;
      if (2 < DAT_20008454) {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): sys reboot because ipc failed\n","global_ipc_service_send");
          }
          else {
            ble_printk("%s(): sys reboot because ipc failed\n");
          }
        }
        z_impl_k_sleep((k_timeout_t)0x4000);
                    /* WARNING: Subroutine does not return */
        sys_reboot(1);
      }
    }
    else {
      DAT_20008454 = 0;
    }
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): ipc_service not ready!\n","global_ipc_service_send");
      }
      else {
        ble_printk("%s(): ipc_service not ready!\n");
      }
    }
    iVar2 = -1;
  }
  return iVar2;
}


