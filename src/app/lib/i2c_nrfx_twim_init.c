/*
 * Function: i2c_nrfx_twim_init
 * Entry:    00064a84
 * Prototype: int __stdcall i2c_nrfx_twim_init(device * dev)
 */


/* exclude_from_export */

int i2c_nrfx_twim_init(device *dev)

{
  log_msg_desc desc;
  nrfx_err_t nVar1;
  int iVar2;
  nrfx_twim_t *p_instance;
  undefined *p_context;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined1 *local_28;
  char *local_24;
  undefined *puStack_20;
  undefined2 local_1c;
  
  p_instance = (nrfx_twim_t *)dev->config;
  p_context = dev->data;
  (*(code *)p_instance[7])();
  iVar2 = pinctrl_apply_state((pinctrl_dev_config *)p_instance[8],'\0');
  if (-1 < iVar2) {
    nVar1 = nrfx_twim_init(p_instance,(nrfx_twim_config_t *)(p_instance + 2),
                           (nrfx_twim_evt_handler_t)0x64b01,p_context);
    if ((undefined1 *)(uint)nVar1 == &DAT_0bad0000) {
      nrfx_twim_enable(p_instance);
      iVar2 = 0;
    }
    else {
      puStack_20 = dev->name;
      local_24 = "Failed to initialize device: %s";
      local_1c = 0x200;
      local_28 = &DAT_01000003;
      desc.level = (dword)&local_28;
      desc.domain = 0x1c40;
      desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc.data_len = in_stack_ffffffc8;
      z_impl_z_log_msg_static_create
                (&PTR_s_i2c_nrfx_twim_0008b980,desc,in_stack_ffffffcc,in_stack_ffffffd0);
      iVar2 = -5;
    }
  }
  return iVar2;
}


