/*
 * Function: power_manager_log_event
 * Entry:    00052bd8
 * Prototype: void __stdcall power_manager_log_event(int * event)
 */


/* exclude_from_export */

void power_manager_log_event(int *event)

{
  code *pcVar1;
  byte bVar2;
  log_msg_desc desc;
  char *pcVar3;
  dword in_stack_ffffffb8;
  uint8_t *in_stack_ffffffbc;
  void *in_stack_ffffffc0;
  undefined1 *local_38;
  char *local_34;
  char *pcStack_30;
  undefined *local_2c;
  char *local_28;
  undefined1 *local_24;
  undefined2 local_20;
  undefined1 *local_18;
  undefined2 local_14;
  undefined2 uStack_12;
  
  if ((undefined **)event[1] != &PTR_s_power_manager_restrict_event_000f8bbc) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)software_udf(0xff,0x52c8c);
    (*pcVar1)();
  }
  bVar2 = *(byte *)(event + 3);
  if ((uint)event[2] < 2) {
    if ((char)bVar2 < '\x03') {
      if (-2 < (char)bVar2) {
        pcVar3 = (char *)(uint)bVar2;
        local_28 = pcVar3;
        if (pcVar3 < (char *)0x3) {
          local_28 = (&PTR_s_SUSPENDED_0008e930)[(int)pcVar3];
        }
        pcStack_30 = "power_manager_restrict_event";
        if ((char *)0x2 < pcVar3) {
          local_28 = "ALIVE";
        }
        local_2c = (&PTR_s_main_000f8c04)[event[2]];
        local_18 = &DAT_03010200;
        _local_14 = CONCAT22(uStack_12,0x402);
        local_34 = "e:%s module \"%s\" restricts to %s";
        local_24 = &DAT_03010200;
        local_20 = 0x402;
        local_38 = &DAT_03000005;
        desc.level = (dword)&local_38;
        desc.domain = 0x34c0;
        desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
        desc.data_len = in_stack_ffffffb8;
        z_impl_z_log_msg_static_create
                  (&PTR_s_app_event_manager_0008b8a0,desc,in_stack_ffffffbc,in_stack_ffffffc0);
        return;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","lvl >= POWER_MANAGER_LEVEL_ALIVE",
              "WEST_TOPDIR/nrf/subsys/caf/events/power_manager_event.c",23);
    }
    else {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","lvl <= POWER_MANAGER_LEVEL_MAX",
              "WEST_TOPDIR/nrf/subsys/caf/events/power_manager_event.c",22);
    }
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","event->module_idx < module_count()",
            "WEST_TOPDIR/nrf/subsys/caf/events/power_manager_event.c",21);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


