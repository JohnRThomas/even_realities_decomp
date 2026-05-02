/*
 * Function: $_?_sync_rtc_setup
 * Entry:    0004f574
 * Prototype: int __stdcall $_?_sync_rtc_setup(void)
 */


/* WARNING: Removing unreachable block (ram,0x0004f5c8) */

int ____sync_rtc_setup(void)

{
  ulonglong uVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint in_stack_00000000;
  uint8_t *in_stack_ffffffc4;
  void *in_stack_ffffffc8;
  undefined4 local_30;
  char *local_2c;
  uint uStack_28;
  undefined4 local_1c;
  
  puVar2 = (undefined1 *)gppi_channel_alloc((uint8_t *)&local_1c);
  if (puVar2 == &DAT_0bad0000) {
    uVar3 = nrf_rtc_timer();
    if ((int)uVar3 < 0) {
      nrfx_dppi_channel_free((sbyte)local_1c);
    }
    else {
      local_1c = CONCAT22(0x807,CONCAT11((char)uVar3,(sbyte)local_1c));
      uVar3 = twim_nrfx_pm_action((device *)&DAT_0008b388,8);
      if ((-1 < (int)uVar3) &&
         (uVar3 = mbox_nrf_set_enabled((device *)&DAT_0008b388,8,true), -1 < (int)uVar3)) {
        nrfx_gppi_channels_enable(1 << (sbyte)local_1c);
        ppi_ipc_to_rtc((rtc_sync_channels)(local_1c & 0xff),local_1c._1_1_);
        if (uVar3 == 0) {
          return 0;
        }
      }
    }
  }
  else {
    uVar3 = 0xffffffed;
  }
  local_2c = "Failed synchronized RTC setup (err: %d)";
  local_30 = 3;
  uVar1 = (ulonglong)in_stack_00000000;
  in_stack_00000000 = (int)((uVar1 << 0x20) >> 0x20);
  uStack_28 = uVar3;
  z_impl_z_log_msg_static_create
            (&DAT_0008ba38,
             (log_msg_desc)
             CONCAT88(CONCAT44(in_stack_00000000,(int)(uVar1 << 0x20)),
                      CONCAT44((dword)&local_30,0x1840)),in_stack_ffffffc4,in_stack_ffffffc8);
  return uVar3;
}


