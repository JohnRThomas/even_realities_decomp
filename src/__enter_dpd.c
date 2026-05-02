/*
 * Function: ?_enter_dpd
 * Entry:    00063dec
 * Prototype: device * __stdcall ?_enter_dpd(device * param_1, int param_2, undefined4 param_3, undefined4 param_4)
 */


device * __enter_dpd(device *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined1 *extraout_r0;
  device *pdVar2;
  undefined1 *puVar3;
  uint uVar4;
  nrfx_qspi_config_t *p_config;
  undefined *p_context;
  undefined1 local_24 [12];
  
  p_context = param_1->data;
  p_config = (nrfx_qspi_config_t *)param_1->config;
  local_24._0_4_ = param_2;
  local_24._4_4_ = param_3;
  local_24._8_4_ = param_4;
  bVar1 = pm_device_is_busy(param_1);
  if (!bVar1) {
    if (param_2 != 0) {
      if (param_2 != 1) {
        return (device *)0xffffff7a;
      }
      pdVar2 = (device *)____pinctrl_apply_state((pinctrl_dev_config *)p_config[0xd],bVar1);
      if ((int)pdVar2 < 0) {
        return pdVar2;
      }
      puVar3 = (undefined1 *)nrfx_qspi_init(p_config,(nrfx_qspi_handler_t)0x87083,p_context);
      if (puVar3 != &DAT_0bad0000) {
        return (device *)0xfffffffb;
      }
      pdVar2 = (device *)exit_dpd(param_1);
      if ((int)pdVar2 < 0) {
        return pdVar2;
      }
      qspi_device_uninit(param_1);
      return (device *)0x0;
    }
    pdVar2 = (device *)qspi_device_init(param_1);
    if ((int)pdVar2 < 0) {
      return pdVar2;
    }
    bVar1 = (bool)p_context[0x60];
    uVar4 = (uint)bVar1;
    if ((uVar4 == 0) && (qspi_device_uninit(pdVar2), extraout_r0 == &DAT_0bad0000)) {
      local_24._0_4_ = 0xb9;
      local_24._4_4_ = uVar4;
      local_24._8_4_ = uVar4;
      printk("#############################enter_dpd\r\n");
      pdVar2 = (device *)qspi_send_cmd(param_1,(qspi_cmd *)local_24,bVar1);
      if ((int)pdVar2 < 0) {
        return pdVar2;
      }
      nrfx_qspi_uninit();
      uVar4 = ____pinctrl_apply_state((pinctrl_dev_config *)p_config[0xd],'\x01');
      return (device *)(uVar4 & (int)uVar4 >> 0x1f);
    }
  }
  return (device *)0xfffffff0;
}


