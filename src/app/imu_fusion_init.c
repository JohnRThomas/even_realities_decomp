/*
 * Function: imu_fusion_init
 * Entry:    00028088
 * Prototype: undefined4 __stdcall imu_fusion_init(char * param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 imu_fusion_init(char *param_1,undefined4 param_2,undefined4 param_3)

{
  k_timeout_t delay;
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  uint in_stack_ffffffdc;
  
  if (param_1[0x14] == '\0') {
    __is_master();
    *(undefined ***)(param_1 + 0x1c) = &PTR_s_lsm6dso_6b_0008b508;
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): imu_fusion: sensor device is ready:\n\n");
      }
      else {
        ble_printk("%s(): imu_fusion: sensor device is ready:\n\n","imu_fusion_init",extraout_r2,
                   BLE_DEBUG);
      }
    }
    bVar1 = __is_master();
    if (bVar1) {
      uVar2 = 0x34;
    }
    else {
      uVar2 = 0;
    }
    *(undefined4 *)(param_1 + 0x20) = uVar2;
    param_1[0x24] = '\0';
    param_1[0x25] = '\0';
    param_1[0x26] = '\0';
    param_1[0x27] = '\0';
    iVar3 = FUN_0007fdca(*(int *)(param_1 + 0x1c),3,param_1 + 0x20);
    if (iVar3 < 0) {
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): c->imu_fusion: Cannot set sampling frequency for accelerometer ret %d.\n\n")
          ;
        }
        else {
          ble_printk("%s(): c->imu_fusion: Cannot set sampling frequency for accelerometer ret %d.\n\n"
                     ,"imu_fusion_init",iVar3,BLE_DEBUG);
        }
      }
      uVar2 = 0xfffffffd;
    }
    else {
      __is_master();
      param_1[0x20] = '\0';
      param_1[0x21] = '\0';
      param_1[0x22] = '\0';
      param_1[0x23] = '\0';
      param_1[0x24] = '\0';
      param_1[0x25] = '\0';
      param_1[0x26] = '\0';
      param_1[0x27] = '\0';
      iVar4 = FUN_0007fdca(*(int *)(param_1 + 0x1c),7,param_1 + 0x20);
      iVar3 = LOG_LEVEL;
      if (iVar4 < 0) {
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): c->imu_fusion: Cannot set sampling frequency for gyro.\n\n");
          }
          else {
            ble_printk("%s(): c->imu_fusion: Cannot set sampling frequency for gyro.\n\n",
                       "imu_fusion_init",extraout_r2_00,BLE_DEBUG);
          }
        }
        uVar2 = 0xfffffffc;
      }
      else {
        param_1[0x18] = '\0';
        param_1[0x19] = '\0';
        param_1[0x1a] = '\0';
        param_1[0x1b] = '\0';
        if (1 < iVar3) {
          if (BLE_DEBUG == 0) {
            printk("%s(): sensor_fusion_init:\n\n");
          }
          else {
            ble_printk("%s(): sensor_fusion_init:\n\n","imu_fusion_init",extraout_r2_00,BLE_DEBUG);
          }
        }
        FUN_00028694((undefined4 *)(param_1 + 0x28));
        param_1[0x14] = '\0';
        param_1[0x15] = '\x01';
        FUN_00027fa8(param_1);
        uVar2 = 0;
        delay.ticks._4_4_ = 0;
        delay.ticks._0_4_ = in_stack_ffffffdc;
        z_impl_k_thread_create
                  ((k_thread *)&DAT_20004188,(k_thread_stack_t *)&DAT_200242e0,0x700,
                   (k_thread_entry_t *)0xfec1,param_1,(void *)0x0,(void *)0x0,-0xb,0,delay);
      }
    }
  }
  else {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): imu_fusion: algo is existed\n\n");
      }
      else {
        ble_printk("%s(): imu_fusion: algo is existed\n\n","imu_fusion_init",param_3,BLE_DEBUG);
      }
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


