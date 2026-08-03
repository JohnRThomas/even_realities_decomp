/*
 * Function: sys_notify_finalize
 * Entry:    0004edac
 * Prototype: sys_notify_generic_callback __stdcall sys_notify_finalize(sys_notify * notify, int res)
 */


/* exclude_from_export */

sys_notify_generic_callback sys_notify_finalize(sys_notify *notify,int res)

{
  uint uVar1;
  
  uVar1 = notify->callback & 3;
  notify->method = res;
  if (uVar1 == 2) {
    notify->callback = 0;
    if ((k_poll_signal *)notify->signal != (k_poll_signal *)0x0) {
      k_poll_signal_raise((k_poll_signal *)notify->signal,res);
    }
  }
  else {
    if (uVar1 == 3) {
      notify->callback = 0;
      return notify->signal;
    }
    if (uVar1 != 1) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0","WEST_TOPDIR/zephyr/lib/os/notify.c",69);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    notify->callback = 0;
  }
  return (sys_notify_generic_callback)0x0;
}


