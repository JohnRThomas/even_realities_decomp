/*
 * Function: bt_disable
 * Entry:    00057e1c
 * Prototype: int __stdcall bt_disable(void)
 */


/* exclude_from_export_ai */

int bt_disable(void)

{
  uint8_t id;
  atomic_val_t aVar1;
  int iVar2;
  dword in_stack_ffffffb0;
  uint8_t *in_stack_ffffffb4;
  void *in_stack_ffffffb8;
  undefined4 local_40;
  char *local_3c;
  int iStack_38;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_20;
  char *local_1c;
  
  if (DAT_20002168 == 0) {
    iVar2 = -0x13;
    local_1c = "No HCI driver registered";
    local_20 = 2;
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1040,&local_20,2,in_stack_ffffffd0,in_stack_ffffffd4,
            in_stack_ffffffd8);
  }
  else if (*(int *)(DAT_20002168 + 0x10) == 0) {
    iVar2 = -0x86;
  }
  else {
    aVar1 = atomic_or(&DAT_200020d4,2);
    if (aVar1 << 0x1e < 0) {
      iVar2 = -0x78;
    }
    else {
      atomic_and(&DAT_200020d4,-5);
      iVar2 = (**(code **)(DAT_20002168 + 0x10))();
      if (iVar2 == 0) {
        memset(&DAT_20002080,0,0x40);
        bt_addr_le_copy((bt_addr_le_t *)&DAT_20002068,(bt_addr_le_t *)&DAT_000f0b50);
        bt_adv_reset_adv_pool();
        bt_pub_key_hci_disrupted();
        bt_conn_disconnect_all(id);
        DAT_200108f4 = 0;
                    /* WARNING: Subroutine does not return */
        z_thread_abort((k_thread *)&DAT_20006010);
      }
      local_3c = "HCI driver close failed (%d)";
      local_40 = 3;
      iStack_38 = iVar2;
      LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1840,&local_40,3,in_stack_ffffffb0,in_stack_ffffffb4,
              in_stack_ffffffb8);
      atomic_or(&DAT_200020d4,4);
    }
  }
  return iVar2;
}


