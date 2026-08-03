/*
 * Function: mfd_npm1300_init
 * Entry:    00064fb8
 * Prototype: int __stdcall mfd_npm1300_init(device * dev)
 */


/* exclude_from_export */

int mfd_npm1300_init(device *dev)

{
  gpio_pin_t gVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  device *pdVar5;
  uint uVar6;
  char *test;
  char *test_00;
  char *test_01;
  char *test_02;
  char *file;
  char *file_00;
  char *file_01;
  char *file_02;
  int line;
  int line_00;
  int line_01;
  uint uVar7;
  code *pcVar8;
  int line_02;
  undefined4 uVar9;
  mfd_npm1300_config *puVar9;
  uint uVar10;
  k_mutex *mutex;
  uint uVar11;
  undefined4 *puVar12;
  
  puVar9 = (mfd_npm1300_config *)dev->config;
  mutex = (k_mutex *)dev->data;
  bVar3 = z_device_is_ready((puVar9->i2c).bus);
  if (bVar3) {
    z_impl_k_mutex_init(mutex);
    mutex[1].wait_q.head = (undefined *)dev;
    if ((puVar9->host_int_gpios).port == (device *)0x0) {
      return 0;
    }
    iVar4 = i2c_write_dt((i2c_dt_spec *)dev,&DAT_00000006,(uint)puVar9->pmic_int_pin);
    if (iVar4 < 0) {
      return iVar4;
    }
    bVar3 = z_device_is_ready((puVar9->host_int_gpios).port);
    if (bVar3) {
      uVar2 = (puVar9->host_int_gpios).dt_flags;
      uVar11 = (uint)uVar2;
      pdVar5 = (puVar9->host_int_gpios).port;
      uVar6 = (uint)(puVar9->host_int_gpios).pin;
      puVar12 = (undefined4 *)pdVar5->api;
      if ((uVar11 & 0x30) == 0x30) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                "(flags & ((1 << 4) | (1 << 5))) != ((1 << 4) | (1 << 5))",
                "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",970);
        _ASSERT("\tPull Up and Pull Down should not be enabled simultaneously\n",test,file,line);
      }
      else if ((uVar2 & 2) == 0) {
        if ((uVar11 & 6) == 4) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                  "(flags & (1 << 1)) != 0 || (flags & (1 << 2)) == 0",
                  "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",977);
        }
        else {
          uVar10 = 1 << uVar6;
          if ((uVar10 & *(uint *)pdVar5->config) == 0) {
            _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                    "(cfg->port_pin_mask & (gpio_port_pins_t)(1UL << (pin))) != 0U",
                    "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",996);
            _ASSERT("\tUnsupported pin\n",test_01,file_01,line_01);
          }
          else {
            uVar7 = *(uint *)pdVar5->data;
            if ((int)(uVar11 << 0x1f) < 0) {
              uVar7 = uVar7 | uVar10;
            }
            else {
              uVar7 = uVar7 & ~uVar10;
            }
            *(uint *)pdVar5->data = uVar7;
            iVar4 = (*(code *)*puVar12)(pdVar5,uVar6,uVar11 | 0x10000);
            if (iVar4 < 0) {
              return iVar4;
            }
            gVar1 = (puVar9->host_int_gpios).pin;
            mutex[1].owner = (undefined *)0x87509;
            mutex[1].lock_count = 1 << gVar1;
            pdVar5 = (puVar9->host_int_gpios).port;
            pcVar8 = *(code **)(pdVar5->api + 0x1c);
            if (pcVar8 == (code *)0x0) {
              return -0x86;
            }
            iVar4 = (*pcVar8)(pdVar5,&mutex[1].wait_q.tail,1);
            if (iVar4 < 0) {
              return iVar4;
            }
            mutex[2].wait_q.head = (undefined *)0x65149;
            pdVar5 = (puVar9->host_int_gpios).port;
            uVar6 = (uint)(puVar9->host_int_gpios).pin;
            uVar11 = 1 << uVar6;
            if ((uVar11 & *(uint *)pdVar5->config) != 0) {
              if ((uVar11 & *(uint *)pdVar5->data) == 0) {
                uVar9 = 0x4000000;
              }
              else {
                uVar9 = 0x2000000;
              }
              uVar6 = (**(code **)(pdVar5->api + 0x18))(pdVar5,uVar6,0x1400000,uVar9);
              return uVar6 & (int)uVar6 >> 0x1f;
            }
            _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                    "(cfg->port_pin_mask & (gpio_port_pins_t)(1UL << (pin))) != 0U",
                    "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",898);
            _ASSERT("\tUnsupported pin\n",test_02,file_02,line_02);
          }
        }
      }
      else {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                "!((flags & (1U << 16)) && !(flags & (1U << 17)) && (flags & (1 << 1)))",
                "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",974);
        _ASSERT("\tInput cannot be enabled for \'Open Drain\', \'Open Source\' modes without Output\n"
                ,test_00,file_00,line_00);
      }
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
  }
  return -0x13;
}


