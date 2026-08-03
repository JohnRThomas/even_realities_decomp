/*
 * Function: app_event_manager_alloc
 * Entry:    00052810
 * Prototype: void * __stdcall app_event_manager_alloc(size_t size)
 */


/* exclude_from_export */

void * app_event_manager_alloc(size_t size)

{
  log_msg_desc desc;
  void *pvVar1;
  uint8_t *in_r1;
  void *in_r2;
  
  pvVar1 = k_malloc(size);
  if (pvVar1 == (void *)0x0) {
    desc.level = (dword)&stack0xfffffff0;
    desc.domain = 0x1040;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc.data_len = size;
    z_impl_z_log_msg_static_create(&PTR_s_app_event_manager_0008b8a0,desc,in_r1,in_r2);
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0",
            "WEST_TOPDIR/nrf/subsys/app_event_manager/app_event_manager.c",123);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  return pvVar1;
}


