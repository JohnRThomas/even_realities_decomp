/*
 * Function: prng_reseed
 * Entry:    00058ea4
 * Prototype: int __stdcall prng_reseed(tc_hmac_prng_struct * h)
 */


/* exclude_from_export_ai */

int prng_reseed(tc_hmac_prng_struct *h)

{
  longlong lVar1;
  log_msg_desc desc;
  int iVar2;
  int iVar3;
  void *data;
  ulonglong uVar4;
  dword dVar5;
  uint8_t *in_stack_ffffffac;
  undefined4 local_38;
  char *local_34;
  uint8_t auStack_30 [36];
  
  iVar2 = bt_hci_le_rand(auStack_30,0x20);
  if (iVar2 == 0) {
    uVar4 = sys_clock_tick_get();
    lVar1 = (uVar4 & 0xffffffff) * 1000;
    data = (void *)((uint)lVar1 >> 0xf |
                   ((int)(uVar4 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20)) * 0x20000);
    dVar5 = 8;
    iVar3 = tc_hmac_prng_reseed(&DAT_200061e0,auStack_30,0x20,&stack0xffffffb0,8);
    if (iVar3 == 0) {
      local_34 = "Failed to re-seed PRNG";
      local_38 = 2;
      iVar2 = -5;
      desc.level = (dword)&local_38;
      desc.domain = 0x1040;
      desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc.data_len = dVar5;
      z_impl_z_log_msg_static_create(&PTR_s_bt_host_crypto_0008b8f8,desc,in_stack_ffffffac,data);
    }
  }
  return iVar2;
}


