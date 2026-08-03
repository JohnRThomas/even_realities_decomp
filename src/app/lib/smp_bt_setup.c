/*
 * Function: smp_bt_setup
 * Entry:    00055e00
 * Prototype: void __stdcall smp_bt_setup(void)
 */


/* exclude_from_export */

void smp_bt_setup(void)

{
  log_msg_desc desc;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_20;
  char *local_1c;
  int iStack_18;
  
  DAT_2001e1c5 = 1;
  k_work_init_delayable((k_work_delayable *)&DAT_20005e98,(void *)0x55ad5);
  k_work_init_delayable((k_work_delayable *)&DAT_20005ec8,(void *)0x55a9d);
  z_impl_k_sem_init((k_sem *)&DAT_20005efc,0,1);
  DAT_2000b5b8 = 0x55b2d;
  DAT_2000b5bc = (code *)0x84435;
  DAT_2000b5c0 = (code *)0x843cb;
  DAT_2000b5c4 = (code *)0x843bf;
  DAT_2000b5c8 = (code *)0x843d9;
  iStack_18 = smp_transport_init(&smp_bt_transport);
  if ((iStack_18 != 0) || (iStack_18 = smp_bt_register(), iStack_18 != 0)) {
    local_1c = "Bluetooth SMP transport register failed (err %d)";
    local_20 = 3;
    desc.level = (dword)&local_20;
    desc.domain = 0x1840;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc.data_len = in_stack_ffffffd0;
    z_impl_z_log_msg_static_create
              (&PTR_s_mcumgr_smp_0008b9c8,desc,in_stack_ffffffd4,in_stack_ffffffd8);
  }
  return;
}


