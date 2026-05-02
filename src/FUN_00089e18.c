/*
 * Function: FUN_00089e18
 * Entry:    00089e18
 * Prototype: undefined4 __stdcall FUN_00089e18(k_thread * param_1, uint32_t param_2)
 */


undefined4 FUN_00089e18(k_thread *param_1,uint32_t param_2)

{
  undefined4 uVar1;
  uint32_t extraout_r1;
  k_thread *thread;
  
  uVar1 = 0;
  while ((thread = (k_thread *)param_1->base, param_1 != thread && (thread != (k_thread *)0x0))) {
    ____signal_triggered_work((k_poll_event *)thread,param_2);
    z_ready_thread(thread);
    uVar1 = 1;
    param_2 = extraout_r1;
  }
  return uVar1;
}


