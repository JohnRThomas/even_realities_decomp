/*
 * Function: hci_data_buf_overflow
 * Entry:    00056724
 * Prototype: void __stdcall hci_data_buf_overflow(net_buf * buf)
 */


/* exclude_from_export_ai */

void hci_data_buf_overflow(net_buf *buf)

{
  dword in_stack_ffffffd8;
  uint8_t *in_stack_ffffffdc;
  void *in_stack_ffffffe0;
  undefined4 local_18;
  char *local_14;
  uint uStack_10;
  
  uStack_10 = (uint)*(buf->field6_0xc).field0.data;
  local_14 = "Data buffer overflow (link type 0x%02x)";
  local_18 = 3;
  LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1880,&local_18,3,in_stack_ffffffd8,in_stack_ffffffdc,
          in_stack_ffffffe0);
  return;
}


