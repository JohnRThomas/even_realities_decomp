/*
 * Function: qspi_nor_init
 * Entry:    00063ea8
 * Prototype: int __stdcall qspi_nor_init(device * dev)
 */


/* exclude_from_export */

int qspi_nor_init(device *dev)

{
  nrfx_err_t res;
  int iVar1;
  char *pcVar2;
  uint8_t sr_num;
  undefined4 extraout_r1;
  undefined4 uVar3;
  undefined4 extraout_r1_00;
  char **param3;
  undefined *puVar4;
  nrfx_qspi_config_t *p_config;
  uint uVar5;
  char local_50 [4];
  char *local_4c;
  char *local_48;
  char *local_44;
  char *local_40;
  char *local_3c;
  char *local_38;
  uint local_34;
  undefined2 local_30;
  byte local_2e;
  undefined1 *local_2c;
  undefined4 local_28;
  undefined1 local_24 [8];
  undefined4 local_1c;
  
  iVar1 = pinctrl_apply_state(*(pinctrl_dev_config **)(dev->config + 0x34),'\0');
  if (iVar1 < 0) {
    return iVar1;
  }
  z_arm_irq_priority_set(0x2b,1,0);
  p_config = (nrfx_qspi_config_t *)dev->config;
  Peripherals::CLOCK_S.HFCLK192MCTRL = 0;
  res = nrfx_qspi_init(p_config,(nrfx_qspi_handler_t *)0x87083,dev->data);
  Peripherals::CLOCK_S.HFCLK192MCTRL = 2;
  iVar1 = qspi_get_zephyr_ret_code(res);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = exit_dpd(dev);
  if (iVar1 < 0) {
    return iVar1;
  }
  if (*(byte *)((int)p_config + 0x1d) - 2 < 2) {
    uVar5 = 1;
  }
  else if ((byte)p_config[7] - 3 < 2) {
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  pcVar2 = (char *)qspi_rdsr(dev,sr_num);
  if ((int)pcVar2 < 0) {
    iVar1 = 0x1840;
    local_3c = "RDSR failed: %d";
    param3 = &local_40;
    local_40 = (char *)0x3;
    local_38 = pcVar2;
LAB_00063f36:
    LOG_ERR(&PTR_s_qspi_nor_0008ba20,iVar1,(char *)param3);
  }
  else {
    if (uVar5 != ((uint)pcVar2 & 0x7f) >> 6) {
      local_30 = (byte)pcVar2 ^ 0x40;
      local_28 = 1;
      local_1c = (undefined1 **)0x0;
      local_24._0_4_ = 1;
      local_2c = (undefined1 *)&local_30;
      local_24._4_4_ = &local_2c;
      pcVar2 = (char *)qspi_send_cmd(dev,(qspi_cmd *)local_24,true);
      uVar3 = extraout_r1;
      if (pcVar2 != (char *)0x0) {
        if (-1 < (int)pcVar2) {
          return (int)pcVar2;
        }
LAB_00063f84:
        local_40 = "clear";
        if (uVar5 != 0) {
          local_40 = "set";
        }
        local_44 = "QE %s failed: %d";
        local_38 = (char *)CONCAT22(local_38._2_2_,0x200);
        iVar1 = 0x2440;
        param3 = &local_48;
        local_48 = &DAT_01000004;
        local_3c = pcVar2;
        goto LAB_00063f36;
      }
      do {
        pcVar2 = (char *)qspi_rdsr(dev,(uint8_t)uVar3);
        if ((int)pcVar2 < 0) goto LAB_00063f84;
        uVar3 = extraout_r1_00;
      } while ((int)pcVar2 * -0x80000000 < 0);
    }
    qspi_device_uninit(dev);
    local_28 = 3;
    local_24._4_4_ = 0;
    local_24._0_4_ = 0x9f;
    local_2c = (undefined1 *)&local_30;
    local_1c = &local_2c;
    iVar1 = qspi_device_init(dev);
    if (iVar1 == 0) {
      iVar1 = qspi_send_cmd(dev,(qspi_cmd *)local_24,false);
      qspi_device_uninit(dev);
      if (iVar1 == 0) {
        puVar4 = dev->config;
        iVar1 = memcmp(puVar4 + 0x30,&local_30,3);
        if (iVar1 == 0) {
          return 0;
        }
        local_48 = (char *)(uint)(byte)local_30;
        local_44 = (char *)(uint)local_30._1_1_;
        local_40 = (char *)(uint)local_2e;
        local_3c = (char *)(uint)(byte)puVar4[0x30];
        local_38 = (char *)(uint)(byte)puVar4[0x31];
        local_34 = (uint)(byte)puVar4[0x32];
        local_4c = "JEDEC id [%02x %02x %02x] expect [%02x %02x %02x]";
        local_50[0] = '\b';
        local_50[1] = '\0';
        local_50[2] = '\0';
        local_50[3] = '\0';
        LOG_ERR(&PTR_s_qspi_nor_0008ba20,0x4040,local_50);
      }
    }
    else {
      qspi_device_uninit(dev);
    }
    pcVar2 = (char *)0xffffffed;
  }
  return (int)pcVar2;
}


