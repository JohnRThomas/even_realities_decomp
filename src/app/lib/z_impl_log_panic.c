/*
 * Function: z_impl_log_panic
 * Entry:    00050918
 * Prototype: void __stdcall z_impl_log_panic(void)
 */


/* exclude_from_export */

void z_impl_log_panic(void)

{
  log_msg_generic *msg;
  log_msg_generic *extraout_r0;
  char *test;
  char *file;
  int line;
  undefined **ppuVar1;
  
  if (panic_mode == '\0') {
    msg = (log_msg_generic *)z_log_init(true,false);
    ppuVar1 = &PTR_PTR_0008ba50;
    while( true ) {
      if (&PTR_s_bt_0008ba60 < ppuVar1) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","backend <= _log_backend_list_end",
                "WEST_TOPDIR/zephyr/subsys/logging/log_core.c",392);
        _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      if ((undefined **)((int)&PTR_DAT_0008ba5c + 3U) < ppuVar1) break;
      if (ppuVar1[1][5] != '\0') {
        msg = (log_msg_generic *)(**(code **)(*ppuVar1 + 8))(ppuVar1);
      }
      ppuVar1 = ppuVar1 + 4;
    }
    do {
      z_impl_log_process(msg);
      msg = extraout_r0;
    } while (extraout_r0 != (log_msg_generic *)0x0);
    panic_mode = '\x01';
  }
  return;
}


