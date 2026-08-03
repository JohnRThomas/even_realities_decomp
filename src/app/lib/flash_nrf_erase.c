/*
 * Function: flash_nrf_erase
 * Entry:    00064504
 * Prototype: int __stdcall flash_nrf_erase(device * dev, off_t addr, size_t size)
 */


/* exclude_from_export */

int flash_nrf_erase(device *dev,off_t addr,size_t size)

{
  log_msg_desc desc;
  bool bVar1;
  uint32_t uVar2;
  undefined4 extraout_r1;
  k_timeout_t timeout;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  off_t oStack_20;
  size_t local_1c;
  
  uVar2 = flash_page_size_get();
  bVar1 = is_regular_addr_valid(addr,size);
  if (bVar1) {
    if ((addr == uVar2 * ((uint)addr / uVar2)) && (size == uVar2 * (size / uVar2))) {
      if (uVar2 <= size) {
        timeout.ticks._4_4_ = 0xffffffff;
        timeout.ticks._0_4_ = extraout_r1;
        z_impl_k_sem_take((k_sem *)&DAT_2000bb3c,timeout);
        uVar2 = flash_page_size_get();
        do {
          nrfx_nvmc_page_erase(addr);
          size = size - uVar2;
          addr = addr + uVar2;
        } while (size != 0);
        k_sem_give((k_sem *)&DAT_2000bb3c);
      }
      return 0;
    }
    local_24 = "unaligned address: 0x%08lx:%zu";
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
  local_1c = size;
  z_impl_z_log_msg_static_create(&PTR_s_flash_nrf_0008b960,desc,in_stack_ffffffcc,in_stack_ffffffd0)
  ;
  return -0x16;
}


