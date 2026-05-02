/*
 * Function: update_imu_mode
 * Entry:    000281dc
 * Prototype: undefined4 __stdcall update_imu_mode(int param_1, uint param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 update_imu_mode(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 uVar3;
  int iVar4;
  
  bVar1 = __is_master();
  if (!bVar1) {
    return 0;
  }
  if (*(char *)(param_1 + 0x14) != '\0') {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): imu_fusion: algo is existed\n\n");
      }
      else {
        ble_printk("%s(): imu_fusion: algo is existed\n\n","update_imu_mode",extraout_r2,BLE_DEBUG);
      }
    }
    return 0xffffffff;
  }
  __is_master();
  *(undefined ***)(param_1 + 0x1c) = &PTR_s_lsm6dso_6b_0008b508;
  if (param_2 == 1) {
    uVar3 = 0xc;
  }
  else {
    if (param_2 != 2) {
      if (param_2 == 0) {
        *(undefined4 *)(param_1 + 0x20) = 0;
        *(undefined4 *)(param_1 + 0x24) = 0;
      }
      goto LAB_00028232;
    }
    uVar3 = 0x1a;
  }
  *(undefined4 *)(param_1 + 0x20) = uVar3;
  *(undefined4 *)(param_1 + 0x24) = 0;
LAB_00028232:
  iVar4 = 1;
  while( true ) {
    iVar2 = FUN_0007fdca(*(int *)(param_1 + 0x1c),3,param_1 + 0x20);
    if (-1 < iVar2) {
      uVar3 = extraout_r3;
      if (param_2 < 3) {
        uVar3 = 0;
      }
      iVar4 = 1;
      if (param_2 < 3) {
        *(undefined4 *)(param_1 + 0x20) = uVar3;
        *(undefined4 *)(param_1 + 0x24) = uVar3;
      }
      while( true ) {
        iVar2 = FUN_0007fdca(*(int *)(param_1 + 0x1c),7,param_1 + 0x20);
        if (-1 < iVar2) {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): imu sensor update to mode %d\n");
            }
            else {
              ble_printk("%s(): imu sensor update to mode %d\n","update_imu_mode",param_2,BLE_DEBUG)
              ;
            }
          }
          return 0;
        }
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): c->imu_fusion: Cannot set sampling frequency for gyro %d.\n\n");
          }
          else {
            ble_printk("%s(): c->imu_fusion: Cannot set sampling frequency for gyro %d.\n\n",
                       "update_imu_mode",iVar4,BLE_DEBUG);
          }
        }
        iVar4 = iVar4 + 1;
        if (iVar4 == 0x15) break;
        z_impl_k_sleep((k_timeout_t)0xa4);
      }
      return 0xfffffffc;
    }
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): c->imu_fusion: Cannot set sampling frequency for accelerometer ret %d retry_time %d.\n\n"
               ,"update_imu_mode",iVar2,iVar4,param_4);
      }
      else {
        ble_printk("%s(): c->imu_fusion: Cannot set sampling frequency for accelerometer ret %d retry_time %d.\n\n"
                   ,"update_imu_mode",iVar2,iVar4);
      }
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == 0x15) break;
    z_impl_k_sleep((k_timeout_t)0xa4);
  }
  return 0xfffffffd;
}


