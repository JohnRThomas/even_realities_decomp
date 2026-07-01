/*
 * Function: change_work_mode
 * Entry:    000169c0
 * Prototype: undefined __stdcall change_work_mode(uint param_1)
 */


void change_work_mode(uint param_1)

{
  undefined4 extraout_r2;
  int iVar1;
  undefined4 local_50;
  undefined1 auStack_4c [60];
  
  iVar1 = 5000;
  while ((DAT_20010939 != '\0' && (iVar1 = iVar1 + -1, iVar1 != 0))) {
    sleep(1);
  }
  DAT_20010939 = 1;
  if (((byte)GLOBAL_STATE->field_0x1 == param_1) && (GLOBAL_STATE->field_0xfea != '\x05')) {
    DAT_20010939 = 0;
    return;
  }
  GLOBAL_STATE->field_0x1 = (char)param_1;
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): change_work_mode to %d\n");
    }
    else {
      ble_printk("%s(): change_work_mode to %d\n","change_work_mode",param_1 & 0xff,BLE_DEBUG);
    }
  }
  switch(GLOBAL_STATE->field_0x1) {
  case 0:
    update_imu_mode(1,0x10);
    update_imu_mode(1,0x100);
    update_imu_mode(1,0x20);
    update_imu_mode(1,0x80);
    iVar1 = 1;
    goto LAB_00016a58;
  case 1:
    update_imu_mode(1,0x10);
    update_imu_mode(0,0x100);
    update_imu_mode(0,0x20);
    update_imu_mode(1,0x80);
    update_imu_mode(0,0x40);
    update_imu_mode(0,8);
    update_imu_mode(0,2);
    update_imu_mode(0,1);
    update_imu_mode(1,0x400);
    update_imu_mode(1,0x800);
    local_50 = 0;
    memset(auStack_4c,0,0x3c);
    local_50 = CONCAT22(local_50._2_2_,0x801);
    global_ipc_service_send(&local_50,4,extraout_r2);
    break;
  case 2:
    update_imu_mode(1,0x10);
    update_imu_mode(1,0x100);
    update_imu_mode(2,0x20);
    update_imu_mode(1,0x80);
    update_imu_mode(1,0x40);
    update_imu_mode(0,8);
    update_imu_mode(1,2);
    update_imu_mode(1,1);
    update_imu_mode(1,0x400);
    update_imu_mode(1,0x800);
    memset(GLOBAL_STATE->field20_0xc8 + 0x27,0,0x5dc);
    break;
  case 3:
    update_imu_mode(0,0x100);
    update_imu_mode(0,0x10);
    update_imu_mode(1,0x20);
    update_imu_mode(1,0x80);
    update_imu_mode(1,0x40);
    iVar1 = 0;
    goto LAB_00016b70;
  case 4:
  case 5:
  case 6:
    update_imu_mode(0,0x10);
    update_imu_mode(0,0x100);
    update_imu_mode(0,0x20);
    update_imu_mode(1,0x80);
    update_imu_mode(1,0x40);
    update_imu_mode(0,8);
    update_imu_mode(0,2);
    iVar1 = 0;
    goto LAB_00016b80;
  case 7:
    set_shipmode();
    break;
  case 8:
    update_imu_mode(0,0x100);
    update_imu_mode(0,0x10);
    update_imu_mode(0,0x20);
    update_imu_mode(0,0x80);
    update_imu_mode(0,0x40);
    update_imu_mode(0,8);
    update_imu_mode(0,2);
    update_imu_mode(0,1);
    iVar1 = 0;
    goto LAB_00016b8a;
  case 9:
    update_imu_mode(0,0x100);
    update_imu_mode(1,0x10);
    update_imu_mode(1,0x20);
    update_imu_mode(0,0x80);
    iVar1 = 0;
LAB_00016a58:
    update_imu_mode(iVar1,0x40);
    iVar1 = 1;
LAB_00016b70:
    update_imu_mode(iVar1,8);
    update_imu_mode(1,2);
    iVar1 = 1;
LAB_00016b80:
    update_imu_mode(iVar1,1);
    iVar1 = 1;
LAB_00016b8a:
    update_imu_mode(iVar1,0x400);
    update_imu_mode(1,0x800);
  }
  DAT_20010939 = 0;
  return;
}


