/*
 * Function: opt3001_chip_init
 * Entry:    00065bd8
 * Prototype: int __stdcall opt3001_chip_init(device * dev)
 */


/* exclude_from_export */

int opt3001_chip_init(device *dev)

{
  log_msg_desc desc;
  log_msg_desc desc_00;
  bool bVar1;
  int iVar2;
  ushort uVar3;
  dword in_stack_ffffffb0;
  uint8_t *in_stack_ffffffb4;
  void *in_stack_ffffffb8;
  undefined4 local_40;
  char *local_3c;
  uint uStack_38;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  undefined1 *in_stack_ffffffd8;
  undefined4 local_18;
  char *local_14;
  
  bVar1 = z_device_is_ready(*(device **)dev->config);
  if (bVar1) {
    iVar2 = opt3001_reg_read((device *)dev->config,'~',(uint16_t *)&stack0xffffffd0);
    if (iVar2 != 0) {
      return -0x16;
    }
    uStack_38 = in_stack_ffffffd0 & 0xffff;
    if (uStack_38 == 0x5449) {
      iVar2 = opt3001_reg_read((device *)dev->config,'\x7f',(uint16_t *)&stack0xffffffd0);
      if (iVar2 != 0) {
        return -0x16;
      }
      uStack_38 = in_stack_ffffffd0 & 0xffff;
      if (uStack_38 == 0x3001) {
        iVar2 = opt3001_reg_read((device *)dev->config,'\x01',(uint16_t *)&stack0xffffffd2);
        if (iVar2 == 0) {
          uVar3 = (ushort)(in_stack_ffffffd0 >> 0x10) & 63999;
          iVar2 = *(int *)dev->config;
          in_stack_ffffffd8 = &stack0xffffffd4;
          in_stack_ffffffd4 =
               (uint8_t *)
               CONCAT31((int3)(CONCAT13((char)((uint)in_stack_ffffffd4 >> 0x18),
                                        CONCAT12((char)uVar3,(uVar3 >> 8 | 6) << 8)) >> 8),1);
          iVar2 = (**(code **)(*(int *)(iVar2 + 8) + 8))
                            (iVar2,&stack0xffffffd8,1,(short)*(int *)((int)dev->config + 4));
          if (iVar2 == 0) {
            return 0;
          }
        }
        local_14 = "Failed to set mode to continuous conversion";
        goto LAB_00065bf4;
      }
      local_3c = "Bad device id 0x%x";
    }
    else {
      local_3c = "Bad manufacturer id 0x%x";
    }
    local_40 = 3;
    desc.level = (dword)&local_40;
    desc.domain = 0x1840;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc.data_len = in_stack_ffffffb0;
    z_impl_z_log_msg_static_create(&PTR_s_opt3001_0008ba00,desc,in_stack_ffffffb4,in_stack_ffffffb8)
    ;
  }
  else {
    local_14 = "Bus device is not ready";
LAB_00065bf4:
    local_18 = 2;
    desc_00.level = (dword)&local_18;
    desc_00.domain = 0x1040;
    desc_00.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc_00.data_len = in_stack_ffffffd0;
    z_impl_z_log_msg_static_create
              (&PTR_s_opt3001_0008ba00,desc_00,in_stack_ffffffd4,in_stack_ffffffd8);
  }
  return -0x16;
}


