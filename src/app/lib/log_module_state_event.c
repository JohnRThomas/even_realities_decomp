/*
 * Function: log_module_state_event
 * Entry:    00052b0c
 * Prototype: void __stdcall log_module_state_event(app_event_header * aeh)
 */


/* exclude_from_export */

void log_module_state_event(app_event_header *aeh)

{
  code *pcVar1;
  log_msg_desc desc;
  sys_snode_t *psVar2;
  dword in_stack_ffffffb8;
  uint8_t *in_stack_ffffffbc;
  void *in_stack_ffffffc0;
  undefined1 *local_38;
  char *local_34;
  char *pcStack_30;
  sys_snode_t *local_2c;
  undefined *local_28;
  undefined1 *local_24;
  undefined2 local_20;
  undefined1 *local_18;
  undefined2 local_14;
  undefined2 uStack_12;
  
  if (aeh->type_id != (event_type *)&DAT_000f8b8c) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)software_udf(0xff,0x52ba6);
    (*pcVar1)();
  }
  if (*(byte *)&aeh[1].type_id < 4) {
    local_28 = (&PTR_s_READY_0008e920)[*(byte *)&aeh[1].type_id];
    if (local_28 == (undefined *)0x0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","state_name[event->state] != ((void *)0)",
              "WEST_TOPDIR/nrf/subsys/caf/events/module_state_event.c",29);
    }
    else {
      pcStack_30 = "module_state_event";
      psVar2 = aeh[1].node.next;
      if (psVar2 != (sys_snode_t *)0x0) {
        local_2c = psVar2->next;
        local_18 = &DAT_03010200;
        _local_14 = CONCAT22(uStack_12,0x402);
        local_34 = "e:%s module:%s state:%s";
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
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","id",
              "WEST_TOPDIR/nrf/include/caf/events/module_state_event.h",81);
    }
  }
  else {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","event->state < MODULE_STATE_COUNT",
            "WEST_TOPDIR/nrf/subsys/caf/events/module_state_event.c",28);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


