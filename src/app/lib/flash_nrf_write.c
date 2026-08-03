/*
 * Function: flash_nrf_write
 * Entry:    000645b8
 * Prototype: int __stdcall flash_nrf_write(device * dev, off_t addr, void * data, size_t len)
 */


/* exclude_from_export */

int flash_nrf_write(device *dev,off_t addr,void *data,size_t len)

{
  log_msg_desc desc;
  int iVar1;
  bool bVar2;
  undefined4 extraout_r1;
  uint uVar3;
  k_timeout_t timeout;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  off_t oStack_20;
  size_t local_1c;
  
  bVar2 = is_regular_addr_valid(addr,len);
  if (bVar2) {
    if (((addr | len) & 3) == 0) {
      if (len != 0) {
        timeout.ticks._4_4_ = 0xffffffff;
        timeout.ticks._0_4_ = extraout_r1;
        z_impl_k_sem_take((k_sem *)&DAT_2000bb3c,timeout);
        for (uVar3 = 0; uVar3 != (len & 0xfffffffc); uVar3 = uVar3 + 4) {
          nrfx_nvmc_word_write(uVar3 + addr,*(uint32_t *)((int)data + uVar3));
        }
        do {
          iVar1 = Peripherals::KMU_S._1024_4_;
        } while (-1 < iVar1 << 0x1f);
        k_sem_give((k_sem *)&DAT_2000bb3c);
      }
      return 0;
    }
    local_24 = "not word-aligned: 0x%08lx:%zu";
  }
  else {
    local_24 = "invalid address: 0x%08lx:%zu";
  }
  local_28 = 4;
  desc.level = (dword)&local_28;
  desc.domain = 0x2040;
  desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
  desc.data_len = in_stack_ffffffc8;
  oStack_20 = addr;
  local_1c = len;
  z_impl_z_log_msg_static_create(&PTR_s_flash_nrf_0008b960,desc,in_stack_ffffffcc,in_stack_ffffffd0)
  ;
  return -0x16;
}


