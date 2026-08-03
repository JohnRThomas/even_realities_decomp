/*
 * Function: bt_enable
 * Entry:    00057cf0
 * Prototype: int __stdcall bt_enable(bt_ready_cb_t cb)
 */


/* exclude_from_export */

int bt_enable(bt_ready_cb_t cb)

{
  k_timeout_t delay;
  atomic_t *target;
  atomic_val_t aVar1;
  int extraout_r0;
  int iVar2;
  dword in_stack_ffffff90;
  uint8_t *in_stack_ffffff94;
  void *in_stack_ffffff98;
  dword in_stack_ffffffb0;
  uint8_t *in_stack_ffffffb4;
  void *in_stack_ffffffb8;
  uint in_stack_ffffffc4;
  undefined4 local_20;
  char *local_1c;
  
  if (DAT_20002168 == 0) {
    iVar2 = -0x13;
    local_1c = "No HCI driver registered";
    local_20 = 2;
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1040,&local_20,2,in_stack_ffffffb0,in_stack_ffffffb4,
            in_stack_ffffffb8);
  }
  else {
    target = (atomic_t *)atomic_and(&DAT_200020d4,-3);
    aVar1 = atomic_or(target,1);
    if (aVar1 << 0x1f < 0) {
      iVar2 = -0x78;
    }
    else {
      iVar2 = bt_settings_init();
      if (iVar2 == 0) {
        DAT_2000b64c = cb;
        z_impl_k_sem_init((k_sem *)&DAT_20002128,1,1);
        k_queue_init((k_queue *)&DAT_2000214c);
        delay.ticks._4_4_ = 0;
        delay.ticks._0_4_ = in_stack_ffffffc4;
        z_impl_k_thread_create
                  ((k_thread *)&DAT_20006010,(k_thread_stack_t *)&DAT_2002c0f8,0x400,
                   (k_thread_entry_t *)0x5789d,(void *)0x0,(void *)0x0,(void *)0x0,-9,0,delay);
        k_thread_name_set(&DAT_20006010,"BT TX");
        k_work_queue_init((k_work_q *)&DAT_200060e8);
        k_work_queue_start((k_work_q *)&DAT_200060e8,(k_thread_stack_t *)&DAT_2002c4f8,0x898,-8,
                           (k_work_queue_config *)0x0);
        k_thread_name_set(&DAT_200060e8,"BT RX");
        iVar2 = (**(code **)(DAT_20002168 + 0xc))();
        if (iVar2 == 0) {
          if (cb == (bt_ready_cb_t)0x0) {
            bt_init();
            iVar2 = extraout_r0;
          }
          else {
            k_work_submit((k_work *)&DAT_200020c4);
          }
        }
        else {
          LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&stack0xffffffc0,3,in_stack_ffffff90,
                  in_stack_ffffff94,in_stack_ffffff98);
        }
      }
    }
  }
  return iVar2;
}


