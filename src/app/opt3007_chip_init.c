/*
 * Function: opt3007_chip_init
 * Entry:    0002fb04
 * Prototype: undefined4 __stdcall opt3007_chip_init(opt3007_context * param_1, undefined4 param_2, undefined4 param_3)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 opt3007_chip_init(opt3007_context *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  GlassesState *pGVar2;
  int iVar3;
  char *pcVar4;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 uVar5;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  uint uVar6;
  ushort local_2c;
  ushort local_2a;
  undefined1 local_28;
  byte local_27;
  undefined1 local_26;
  undefined1 *local_24;
  undefined4 local_20;
  undefined1 local_1c;
  
  local_2c = 0;
  if (param_1 == (opt3007_context *)0x0) {
    pGVar2 = __get_dashboard_state();
    param_1 = &pGVar2->opt3007_context;
    param_3 = extraout_r2;
  }
  DAT_2000854c = param_1;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): opt3007 init start:\n");
    }
    else {
      ble_printk("%s(): opt3007 init start:\n","opt3007_chip_init",param_3,BLE_DEBUG);
    }
  }
  iVar3 = opt3007_reg_read(0x7e,&local_2c);
  if (iVar3 == 0) {
    uVar6 = (uint)local_2c;
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): mfg_id=0x%x,\n");
      }
      else {
        ble_printk("%s(): mfg_id=0x%x,\n","opt3007_chip_init",uVar6,BLE_DEBUG);
      }
    }
    if (uVar6 == 0x5449) {
      iVar3 = opt3007_reg_read(0x7f,&local_2c);
      if (iVar3 != 0) {
        if (LOG_LEVEL < 1) {
          return 0xfffffffb;
        }
        pcVar4 = "%s(): opt3007 dev id=0x%x err!\n";
        goto LAB_0002fb50;
      }
      uVar6 = (uint)local_2c;
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): dev_id=0x%x,\n");
        }
        else {
          ble_printk("%s(): dev_id=0x%x,\n","opt3007_chip_init",uVar6,BLE_DEBUG);
        }
      }
      if (uVar6 == 0x3001) {
        iVar3 = opt3007_reg_read(1,&local_2a);
        uVar5 = extraout_r2_00;
        if (iVar3 == 0) {
          local_27 = (byte)((local_2a & 63999) >> 8) | 6;
          local_28 = 1;
          local_26 = (undefined1)(local_2a & 63999);
          bVar1 = z_device_is_ready(opt3001_i2c_device);
          if (bVar1) {
            local_24 = &local_28;
            local_20 = 3;
            local_1c = 2;
            iVar3 = (**(code **)(opt3001_i2c_device->api + 8))(opt3001_i2c_device,&local_24,1,0x45);
            if (-1 < iVar3) {
              if (DAT_2000854c != (opt3007_context *)0x0) {
                *(undefined4 *)&DAT_2000854c->field_0x10 = 1;
              }
              if (2 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): opt3007 init done!\n");
                }
                else {
                  ble_printk("%s(): opt3007 init done!\n","opt3007_chip_init",iVar3,BLE_DEBUG);
                }
              }
              DAT_20019a6f = 1;
              return 0;
            }
            if (LOG_LEVEL < 1) {
              return 0xfffffffb;
            }
            if (BLE_DEBUG == 0) {
              printk("%s(): opt3007 i2c write err=%d,\n");
              uVar5 = extraout_r2_05;
            }
            else {
              ble_printk("%s(): opt3007 i2c write err=%d,\n","opt3001_reg_write",iVar3,BLE_DEBUG);
              uVar5 = extraout_r2_04;
            }
          }
          else {
            if (LOG_LEVEL < 1) {
              return 0xfffffffb;
            }
            if (BLE_DEBUG == 0) {
              printk("%s(): Bus device is not ready\n");
              uVar5 = extraout_r2_03;
            }
            else {
              ble_printk("%s(): Bus device is not ready\n","opt3001_reg_write",extraout_r2_01,
                         BLE_DEBUG);
              uVar5 = extraout_r2_02;
            }
          }
        }
        if (LOG_LEVEL < 1) {
          return 0xfffffffb;
        }
        if (BLE_DEBUG != 0) {
          ble_printk("%s(): opt3007 Failed to set mode to continuous conversion\n",
                     "opt3007_chip_init",uVar5,BLE_DEBUG);
          return 0xfffffffb;
        }
        printk("%s(): opt3007 Failed to set mode to continuous conversion\n");
        return 0xfffffffb;
      }
      if (LOG_LEVEL < 1) {
        return 0xffffff7a;
      }
      pcVar4 = "%s(): opt3007 Bad device id 0x%x\n";
    }
    else {
      if (LOG_LEVEL < 1) {
        return 0xffffff7a;
      }
      pcVar4 = "%s(): opt3007 Bad manufacturer id 0x%x\n";
    }
    if (BLE_DEBUG == 0) {
      printk(pcVar4);
    }
    else {
      ble_printk(pcVar4,"opt3007_chip_init",uVar6,BLE_DEBUG);
    }
    return 0xffffff7a;
  }
  if (LOG_LEVEL < 1) {
    return 0xfffffffb;
  }
  pcVar4 = "%s(): opt3007 mfg id=0x%x, err\n";
LAB_0002fb50:
  if (BLE_DEBUG == 0) {
    printk(pcVar4);
  }
  else {
    ble_printk(pcVar4,"opt3007_chip_init",(uint)local_2c,BLE_DEBUG);
  }
  return 0xfffffffb;
}


