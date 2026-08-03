/*
 * Function: sync_rtc_setup
 * Entry:    0004f574
 * Prototype: int __stdcall sync_rtc_setup(void)
 */


/* WARNING: Removing unreachable block (ram,0x0004f5c8) */
/* exclude_from_export */

int sync_rtc_setup(void)

{
  log_msg_desc desc;
  nrfx_err_t nVar1;
  uint uVar2;
  dword in_stack_ffffffc0;
  uint8_t *in_stack_ffffffc4;
  void *in_stack_ffffffc8;
  undefined4 local_30;
  char *local_2c;
  uint uStack_28;
  undefined4 local_1c;
  
  nVar1 = gppi_channel_alloc((uint8_t *)&local_1c);
  if ((undefined1 *)(uint)nVar1 == &DAT_0bad0000) {
    uVar2 = nrf_rtc_timer();
    if ((int)uVar2 < 0) {
      nrfx_dppi_channel_free((sbyte)local_1c);
    }
    else {
      local_1c = (void *)CONCAT22(0x807,CONCAT11((char)uVar2,(sbyte)local_1c));
      uVar2 = mbox_nrf_register_callback
                        ((device *)&PTR_s_mbox_2a000_0008b388,8,(mbox_callback_t *)0x4f6b9,local_1c)
      ;
      if ((-1 < (int)uVar2) &&
         (uVar2 = mbox_nrf_set_enabled((device *)&PTR_s_mbox_2a000_0008b388,8,true), -1 < (int)uVar2
         )) {
        nrfx_gppi_channels_enable(1 << (sbyte)local_1c);
        ppi_ipc_to_rtc((rtc_sync_channels)((uint)local_1c & 0xff),local_1c._1_1_);
        if (uVar2 == 0) {
          return 0;
        }
      }
    }
  }
  else {
    uVar2 = 0xffffffed;
  }
  local_2c = "Failed synchronized RTC setup (err: %d)";
  local_30 = 3;
  desc.level = (dword)&local_30;
  desc.domain = 0x1840;
  desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
  desc.data_len = in_stack_ffffffc0;
  uStack_28 = uVar2;
  z_impl_z_log_msg_static_create(&PTR_s_sync_rtc_0008ba38,desc,in_stack_ffffffc4,in_stack_ffffffc8);
  return uVar2;
}


