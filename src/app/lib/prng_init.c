/*
 * Function: prng_init
 * Entry:    00058f10
 * Prototype: int __stdcall prng_init(void)
 */


/* exclude_from_export */

int prng_init(void)

{
  log_msg_desc desc;
  int iVar1;
  tc_hmac_prng_struct *h;
  dword in_stack_ffffffd8;
  uint8_t *in_stack_ffffffdc;
  void *in_stack_ffffffe0;
  undefined4 local_10;
  char *local_c;
  
  iVar1 = bt_hci_le_rand(&stack0xffffffd8,8);
  if (iVar1 == 0) {
    h = (tc_hmac_prng_struct *)tc_hmac_prng_init(&DAT_200061e0,&stack0xffffffd8,8);
    if (h == (tc_hmac_prng_struct *)0x0) {
      local_c = "Failed to initialize PRNG";
      local_10 = 2;
      iVar1 = -5;
      desc.level = (dword)&local_10;
      desc.domain = 0x1040;
      desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
      desc.data_len = in_stack_ffffffd8;
      z_impl_z_log_msg_static_create
                (&PTR_s_bt_host_crypto_0008b8f8,desc,in_stack_ffffffdc,in_stack_ffffffe0);
    }
    else {
      iVar1 = prng_reseed(h);
    }
  }
  return iVar1;
}


