/*
 * Function: opt3007_reg_read
 * Entry:    0002fa1c
 * Prototype: undefined4 __stdcall opt3007_reg_read(undefined1 param_1, ushort * param_2)
 */


undefined4 opt3007_reg_read(undefined1 param_1,ushort *param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 extraout_r2;
  undefined4 uVar3;
  undefined1 local_38 [4];
  ushort local_34 [2];
  undefined1 *local_30;
  undefined4 local_2c;
  undefined1 local_28;
  ushort *local_24;
  undefined4 local_20;
  undefined1 local_1c;
  
  uVar3 = 0;
  local_34[0] = 0;
  bVar1 = z_device_is_ready(opt3001_i2c_device);
  if (bVar1) {
    local_2c = 1;
    local_24 = local_34;
    local_28 = 0;
    local_20 = 2;
    local_1c = 7;
    local_38[0] = param_1;
    local_30 = local_38;
    iVar2 = (**(code **)(opt3001_i2c_device->api + 8))(opt3001_i2c_device,&local_30,2,0x45);
    if (iVar2 < 0) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): ERR: opt3007 i2c read addr=0x%x,\n");
        }
        else {
          ble_printk("%s(): ERR: opt3007 i2c read addr=0x%x,\n","opt3001_reg_read",0x45,BLE_DEBUG);
        }
      }
      uVar3 = 0xfffffffe;
    }
    else {
      *param_2 = local_34[0] << 8 | local_34[0] >> 8;
    }
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): Bus device is not ready\n");
      }
      else {
        ble_printk("%s(): Bus device is not ready\n","opt3001_reg_read",extraout_r2,BLE_DEBUG);
      }
    }
    uVar3 = 0xffffffed;
  }
  return uVar3;
}


