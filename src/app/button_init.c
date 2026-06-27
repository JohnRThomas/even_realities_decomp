/*
 * Function: button_init
 * Entry:    00017b40
 * Prototype: uint __stdcall button_init(undefined4 param_1, undefined4 param_2, gpio_flags_t param_3)
 */


uint button_init(undefined4 param_1,undefined4 param_2,gpio_flags_t param_3)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  gpio_pin_t extraout_r1;
  gpio_pin_t extraout_r1_00;
  gpio_pin_t extraout_r1_01;
  gpio_pin_t pin;
  gpio_pin_t pin_00;
  gpio_pin_t pin_01;
  gpio_pin_t pin_02;
  gpio_pin_t extraout_r1_02;
  gpio_pin_t extraout_r1_03;
  gpio_pin_t extraout_r1_04;
  gpio_pin_t extraout_r1_05;
  gpio_pin_t extraout_r1_06;
  gpio_flags_t flags;
  gpio_flags_t flags_00;
  gpio_flags_t flags_01;
  gpio_flags_t flags_02;
  gpio_flags_t flags_03;
  gpio_flags_t flags_04;
  gpio_flags_t flags_05;
  gpio_flags_t flags_06;
  gpio_flags_t flags_07;
  gpio_flags_t flags_08;
  gpio_flags_t gVar10;
  gpio_flags_t flags_09;
  gpio_flags_t extraout_r2;
  gpio_flags_t flags_10;
  uint uVar11;
  undefined1 local_70 [12];
  undefined1 *puStack_64;
  undefined1 local_60 [12];
  undefined1 *puStack_54;
  undefined1 local_50 [12];
  undefined1 *puStack_44;
  device local_40;
  
  local_70._0_4_ = &gpio0_dev;
  local_70[4] = 0x1a;
  local_70[5] = 0;
  local_70._6_2_ = 0;
  z_impl_gpio_pin_configure((device *)local_70,0,param_3);
  local_70._8_4_ = &gpio0_dev;
  puStack_64 = &DAT_00000019;
  z_impl_gpio_pin_configure((device *)(local_70 + 8),0,flags);
  local_60._0_4_ = &gpio0_dev;
  local_60._4_4_ = &Reserved1;
  z_impl_gpio_pin_configure((device *)local_60,0,flags_00);
  local_60._8_4_ = &gpio0_dev;
  puStack_54 = &DAT_0000001b;
  z_impl_gpio_pin_configure((device *)(local_60 + 8),0,flags_01);
  local_50._0_4_ = &gpio0_dev;
  local_50._4_4_ = &UsageFault;
  z_impl_gpio_pin_configure((device *)local_50,0,flags_02);
  gpio_pin_set(&gpio0_dev,0x18,0);
  local_50._8_4_ = &gpio0_dev;
  puStack_44 = &DAT_00000013;
  z_impl_gpio_pin_configure((device *)(local_50 + 8),0,flags_03);
  gpio_pin_set(&gpio0_dev,0x13,0);
  local_40.name = (undefined *)&gpio0_dev;
  local_40.config = &DAT_00000015;
  z_impl_gpio_pin_configure(&local_40,0,flags_04);
  gpio_pin_set(&gpio0_dev,0x15,0);
  local_40.api = (undefined *)&gpio0_dev;
  local_40.state = &DAT_0000001e;
  z_impl_gpio_pin_configure((device *)&local_40.api,0,flags_05);
  gpio_pin_set(&gpio0_dev,0x1e,1);
  local_40.data = (undefined *)&gpio0_dev;
  local_40.pm = &DAT_00000017;
  z_impl_gpio_pin_configure((device *)&local_40.data,0,flags_06);
  gpio_pin_set(&gpio0_dev,0x17,0);
  bVar1 = z_device_is_ready(&gpio1_dev);
  if (bVar1) {
    iVar3 = z_impl_gpio_pin_configure((device *)&button_irq_gpio_spec,0,flags_07);
    if (-1 < iVar3) {
      GLOBAL_STATE.sem_0.poll_events.prev = &DAT_00000200;
      GLOBAL_STATE.sem_0.poll_events.next = (code *)0x17a3d;
      iVar3 = gpio_manage_callback
                        ((sys_slist_t *)&gpio1_dev,(gpio_callback *)&GLOBAL_STATE.sem_0.limit,true);
      if (iVar3 < 0) {
        if (1 < LOG_LEVEL) {
          pcVar2 = "%s(): Unable to configure SW0 GPIO pin!\n\n";
          gVar10 = flags_09;
          goto LAB_00017c48;
        }
      }
      else {
        z_impl_gpio_pin_interrupt_configure((device *)&button_irq_gpio_spec,0,flags_09);
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): done, pin= %d\n\n");
          }
          else {
            ble_printk("%s(): done, pin= %d\n\n","button_init",9,BLE_DEBUG);
          }
        }
      }
    }
  }
  else if (1 < LOG_LEVEL) {
    pcVar2 = "%s(): SW0 GPIO port device not ready\n\n";
    gVar10 = flags_07;
LAB_00017c48:
    if (BLE_DEBUG == 0) {
      printk(pcVar2);
    }
    else {
      ble_printk(pcVar2,"button_init",gVar10,BLE_DEBUG);
    }
  }
  bVar1 = z_device_is_ready(&gpio1_dev);
  if (bVar1) {
    iVar3 = z_impl_gpio_pin_configure((device *)&button_irq2_gpio_spec,0,flags_08);
    pin = extraout_r1_01;
    if (iVar3 < 0) goto LAB_00017d40;
    GLOBAL_STATE.sem_0.count = 0x400;
    GLOBAL_STATE.sem_0.wait_q.prev = (code *)0x17919;
    iVar3 = gpio_manage_callback
                      ((sys_slist_t *)&gpio1_dev,(gpio_callback *)&GLOBAL_STATE.sem_0,true);
    if (-1 < iVar3) {
      FUN_000274a0();
      z_impl_gpio_pin_interrupt_configure((device *)&button_irq2_gpio_spec,0,flags_10);
      pin = extraout_r1_03;
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): done, pin= %d\n\n");
          pin = extraout_r1_06;
        }
        else {
          ble_printk("%s(): done, pin= %d\n\n","nfc_gpo_init",10,BLE_DEBUG);
          pin = extraout_r1_04;
        }
      }
      goto LAB_00017d40;
    }
    pin = extraout_r1_02;
    if (LOG_LEVEL < 2) goto LAB_00017d40;
    pcVar2 = "%s(): Unable to configure SW0 GPIO pin!\n\n";
    gVar10 = extraout_r2;
  }
  else {
    pin = extraout_r1;
    if (LOG_LEVEL < 2) goto LAB_00017d40;
    pcVar2 = "%s(): SW0 GPIO port device not ready\n\n";
    gVar10 = flags_08;
  }
  if (BLE_DEBUG == 0) {
    printk(pcVar2);
    pin = extraout_r1_05;
  }
  else {
    ble_printk(pcVar2,"nfc_gpo_init",gVar10,BLE_DEBUG);
    pin = extraout_r1_00;
  }
LAB_00017d40:
  uVar4 = gpio_pin_get((device *)&DAT_0000001a,pin);
  uVar5 = gpio_pin_get((device *)&DAT_00000019,pin_00);
  uVar6 = gpio_pin_get((device *)&Reserved1,pin_01);
  uVar7 = gpio_pin_get((device *)&DAT_0000001b,pin_02);
  uVar8 = gpio_pin_get_raw(&gpio0_dev,0x18);
  uVar9 = gpio_pin_get_raw(&gpio0_dev,0x13);
  gpio_pin_get_raw(&gpio0_dev,0x15);
  gpio_pin_get_raw(&gpio0_dev,0x1e);
  if (1 < LOG_LEVEL) {
    uVar11 = uVar4 & 0xff;
    if (BLE_DEBUG == 0) {
      printk("%s(): DEVICE_ID1_PIN: %d, device1_status: %d\n","get_device_hw_id",26,uVar11);
    }
    else {
      ble_printk("%s(): DEVICE_ID1_PIN: %d, device1_status: %d\n","get_device_hw_id",26,uVar11);
    }
    if (1 < LOG_LEVEL) {
      uVar5 = uVar5 & 0xff;
      if (BLE_DEBUG == 0) {
        printk("%s(): DEVICE_ID2_PIN: %d, device2_status: %d\n","get_device_hw_id",25,uVar5);
      }
      else {
        ble_printk("%s(): DEVICE_ID2_PIN: %d, device2_status: %d\n","get_device_hw_id",0x19,uVar5);
      }
      if (1 < LOG_LEVEL) {
        uVar6 = uVar6 & 0xff;
        if (BLE_DEBUG == 0) {
          printk("%s(): DEVICE_ID3_PIN: %d, device3_status: %d\n","get_device_hw_id",28,uVar6);
        }
        else {
          ble_printk("%s(): DEVICE_ID3_PIN: %d, device3_status: %d\n","get_device_hw_id",0x1c,uVar6)
          ;
        }
        if (1 < LOG_LEVEL) {
          uVar7 = uVar7 & 0xff;
          if (BLE_DEBUG == 0) {
            printk("%s(): DEVICE_ID4_PIN: %d, device4_status: %d\n","get_device_hw_id",0x1b,uVar7);
          }
          else {
            ble_printk("%s(): DEVICE_ID4_PIN: %d, device4_status: %d\n","get_device_hw_id",0x1b,
                       uVar7);
          }
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): device_compat_val: %d %d %d %d\n","get_device_hw_id",uVar11,uVar5,uVar6,
                     uVar7);
            }
            else {
              ble_printk("%s(): device_compat_val: %d %d %d %d\n","get_device_hw_id",uVar11,uVar5);
            }
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk(
                      "%s(): panel_power_status %d tmr_status %d nfc_lpd_status %d touch_power_status %d\n"
                      );
              }
              else {
                ble_printk("%s(): panel_power_status %d tmr_status %d nfc_lpd_status %d touch_power_status %d\n"
                           ,"get_device_hw_id",uVar8 & 0xff,uVar9 & 0xff);
              }
            }
          }
        }
      }
    }
  }
  return uVar4 & 0xff;
}


