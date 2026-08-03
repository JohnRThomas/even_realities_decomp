/*
 * Function: z_cstart
 * Entry:    00074b68
 * Prototype: void __stdcall z_cstart(void)
 */


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

void z_cstart(void)

{
  bool bVar1;
  int iVar2;
  _timeout *timeout;
  bool can_sleep;
  k_thread *extraout_r1;
  void *p1;
  undefined4 extraout_r2;
  void *p2;
  undefined4 extraout_r3;
  void *p3;
  k_thread kStack_e0;
  undefined4 uStack_64;
  undefined4 uStack_60;
  
  z_sys_init_run_level(INIT_LEVEL_EARLY);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(0x2002d728);
  }
  setMainStackPointerLimit(0x2002cf28);
  DAT_e000ed22 = 0xe0;
  DAT_e000ed1f = 0;
  DAT_e000ed18 = 0;
  DAT_e000ed19 = 0;
  DAT_e000ed1a = 0;
  DAT_e000ed20 = 0;
  _DAT_e000ed24 = _DAT_e000ed24 | 0x70000;
  DAT_e000ed23 = 0;
  z_arm_interrupt_stack_setup();
  arch_nop();
  _DAT_e000ed28 = 0xffffffff;
  _DAT_e000ed2c = 0xffffffff;
  iVar2 = z_arm_mpu_init();
  bVar1 = (bool)z_arm_fault(iVar2,extraout_r1,extraout_r2,extraout_r3);
  log_core_init(bVar1,can_sleep);
  kStack_e0.join_queue._0_2_ = 0x101;
  uStack_64 = 0;
  uStack_60 = 0;
  z_dummy_thread_init(&kStack_e0);
  _current.base = (dword)&kStack_e0;
  z_device_state_init();
  z_sys_init_run_level(INIT_LEVEL_PRE_KERNEL_1);
  z_sys_init_run_level(INIT_LEVEL_PRE_KERNEL_2);
  z_timeout_expires(timeout);
  _current.poller = (dword)&DAT_200069d8;
  z_setup_new_thread((k_thread *)&DAT_200069d8,(k_thread_stack_t *)&DAT_2002d868,0x4000,
                     (k_thread_entry_t *)0x74aa1,(void *)0x0,(void *)0x0,(void *)0x0,0,1,"main");
  DAT_200069e5 = DAT_200069e5 & 0xfb;
  z_ready_thread((k_thread *)&DAT_200069d8);
  z_thread_entry((k_thread_entry_t *)0x0,p1,p2,p3);
  sys_clock_isr(&DAT_200069d8);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


