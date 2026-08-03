/*
 * Function: uarte_instance_init
 * Entry:    00066044
 * Prototype: int __stdcall uarte_instance_init(device * dev, uint8_t interrupts_active)
 */


/* exclude_from_export */

int uarte_instance_init(device *dev,uint8_t interrupts_active)

{
  log_msg_desc desc;
  nrfx_err_t nVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  
  z_arm_irq_priority_set(8,1,0);
  arch_irq_enable(8);
  puVar7 = (undefined4 *)dev->config;
  puVar5 = (undefined4 *)dev->data;
  puVar4 = (undefined4 *)*puVar7;
  puVar4[0x140] = 0;
  *puVar5 = dev;
  iVar2 = pinctrl_apply_state((pinctrl_dev_config *)puVar7[3],'\0');
  if ((-1 < iVar2) && (iVar2 = uarte_nrfx_configure(dev,puVar5 + 1), iVar2 == 0)) {
    if ((int)(puVar7[1] << 0x1e) < 0) {
      nVar1 = gppi_channel_alloc((uint8_t *)(puVar5 + 7));
      if ((uint)nVar1 != 0xbad0000) {
        local_24 = "Failed to allocate PPI Channel";
        local_28 = 2;
        desc.level = (dword)&local_28;
        desc.domain = 0x1040;
        desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
        desc.data_len = in_stack_ffffffc8;
        z_impl_z_log_msg_static_create
                  (&PTR_s_uart_nrfx_uarte_0008ba40,desc,in_stack_ffffffcc,in_stack_ffffffd0);
        return -5;
      }
      nrfx_gppi_channel_endpoints_setup
                (*(uint8_t *)(puVar5 + 7),(uint32_t)(puVar4 + 0x48),(uint32_t)(puVar4 + 3));
      nrfx_gppi_channels_enable(1 << *(sbyte *)(puVar5 + 7));
    }
    if (puVar5[3] == 0) {
      puVar4[0x140] = 8;
      if (*(char *)(puVar7 + 2) == '\0') {
        puVar4[0x44] = 0;
        puVar4[0x14d] = puVar5[6];
        puVar4[0x14e] = 1;
        *puVar4 = 1;
      }
    }
    else {
      puVar6 = dev->data;
      iVar3 = *(int *)dev->config;
      *(undefined4 *)(iVar3 + 0x304) = 4;
      *(undefined4 *)(*(int *)(puVar6 + 0xc) + 0xc0) = 1;
      *(char **)(iVar3 + 0x304) = ": CityWalk display mode = %d\n";
      *(undefined4 *)(iVar3 + 0x500) = 8;
      if (*(int *)(iVar3 + 0x14c) != 0) {
        *(undefined4 *)(iVar3 + 4) = 1;
        do {
          if (*(int *)(iVar3 + 0x144) != 0) break;
        } while (*(int *)(iVar3 + 0x124) == 0);
        *(undefined4 *)(iVar3 + 0x14c) = 0;
        *(undefined4 *)(iVar3 + 0x110) = 0;
        *(undefined4 *)(iVar3 + 0x144) = 0;
      }
      k_timer_init((k_timer *)(*(int *)(puVar6 + 0xc) + 0x80),(k_timer_expiry_t)0x88337,
                   (k_timer_stop_t)0x0);
      *(undefined **)(*(int *)(puVar6 + 0xc) + 0xb4) = puVar6;
      k_timer_init((k_timer *)(*(int *)(puVar6 + 0xc) + 0x20),&LAB_00088406_1,(k_timer_stop_t)0x0);
      *(undefined **)(*(int *)(puVar6 + 0xc) + 0x54) = puVar6;
    }
    if (-1 < (int)(puVar7[1] << 0x1e)) {
      puVar4[0xc1] = 0x100;
    }
    if ((int)(puVar7[1] << 0x1b) < 0) {
      puVar4[0xc1] = 0x400000;
    }
    puVar4[0x151] = puVar5[5];
    puVar4[0x152] = 0;
    puVar4[2] = 1;
    puVar4[3] = 1;
  }
  return iVar2;
}


