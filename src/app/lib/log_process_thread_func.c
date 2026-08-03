/*
 * Function: log_process_thread_func
 * Entry:    0005098c
 * Prototype: void __stdcall log_process_thread_func(log_backend_evt event, log_backend_evt_arg * arg)
 */


/* WARNING: Removing unreachable block (ram,0x0005099a) */
/* exclude_from_export */

void log_process_thread_func(log_backend_evt event,log_backend_evt_arg *arg)

{
  log_msg_generic *plVar1;
  log_msg_generic *mask;
  log_msg_generic *msg;
  log_msg_generic *extraout_r0;
  log_msg_generic *extraout_r0_00;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar2;
  char *test;
  char *file;
  int line;
  log_msg_generic *plVar3;
  undefined **ppuVar4;
  undefined4 uVar5;
  k_timeout_t timeout;
  
  mask = (log_msg_generic *)z_log_init(false,false);
  if (mask == (log_msg_generic *)0x0) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar5 = 0x667;
  }
  msg = (log_msg_generic *)k_current_get();
  DAT_2000aab0 = msg;
  if ((msg != (log_msg_generic *)0x0) && (9 < buffered_cnt)) {
    k_sem_give((k_sem *)&DAT_20003b98);
    msg = extraout_r0;
  }
  plVar1 = (log_msg_generic *)0x0;
  do {
    do {
      plVar3 = plVar1;
      if ((mask != (log_msg_generic *)0x0) &&
         (msg = (log_msg_generic *)activate_foreach_backend((uint32_t)mask), mask = msg,
         msg == (log_msg_generic *)0x0)) {
        uVar5 = 0xffffffff;
      }
      z_impl_log_process(msg);
      msg = extraout_r0_00;
      plVar1 = extraout_r0_00;
    } while (extraout_r0_00 != (log_msg_generic *)0x0);
    uVar2 = extraout_r1;
    if (plVar3 != (log_msg_generic *)0x0) {
      ppuVar4 = &PTR_PTR_0008ba50;
      while( true ) {
        if (&PTR_s_bt_0008ba60 < ppuVar4) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","backend <= _log_backend_list_end",
                  "WEST_TOPDIR/zephyr/subsys/logging/log_core.c",848);
          _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
          k_panic();
        }
        if ((undefined **)((int)&PTR_DAT_0008ba5c + 3U) < ppuVar4) break;
        if (*(code **)(*ppuVar4 + 0x18) != (code *)0x0) {
          (**(code **)(*ppuVar4 + 0x18))(ppuVar4,0);
          uVar2 = extraout_r1_00;
        }
        ppuVar4 = ppuVar4 + 4;
      }
    }
    timeout.ticks._4_4_ = uVar5;
    timeout.ticks._0_4_ = uVar2;
    msg = (log_msg_generic *)z_impl_k_sem_take((k_sem *)&DAT_20003b98,timeout);
    plVar1 = extraout_r0_00;
  } while( true );
}


