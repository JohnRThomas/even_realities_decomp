/*
 * Function: bt_init_stub_outline
 * Entry:    00057c98
 * Prototype: void __stdcall bt_init_stub_outline(void)
 */


/* exclude_from_export */

void bt_init_stub_outline(void)

{
  dword in_r0;
  uint8_t *in_r1;
  void *in_r2;
  
  if (DAT_20002007 == '\0') {
    LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x10c0,&stack0xfffffff0,2,in_r0,in_r1,in_r2);
  }
  else {
    atomic_or(&DAT_200020d4,8);
    bt_dev_show_info();
  }
  return;
}


