/*
 * Function: bt_id_read_public_addr
 * Entry:    00058558
 * Prototype: uint8_t __stdcall bt_id_read_public_addr(bt_addr_le_t * addr)
 */


/* exclude_from_export */

uint8_t bt_id_read_public_addr(bt_addr_le_t *addr)

{
  int iVar1;
  bt_addr_t *src;
  dword in_stack_ffffffc8;
  net_buf *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_20;
  char *local_1c;
  
  if (addr == (bt_addr_le_t *)0x0) {
    local_1c = "Invalid input parameters";
  }
  else {
    iVar1 = bt_hci_cmd_send_sync(0x1009,(net_buf *)0x0,(net_buf **)&stack0xffffffcc);
    if (iVar1 == 0) {
      src = (bt_addr_t *)((in_stack_ffffffcc->field6_0xc).field0.data + 1);
      iVar1 = memcmp(src,&DAT_000f0b5d,6);
      if ((iVar1 != 0) && (iVar1 = memcmp(src,&DAT_000f0b57,6), iVar1 != 0)) {
        bt_addr_copy(&addr->a,src);
        addr->type = '\0';
        net_buf_unref(in_stack_ffffffcc);
        return '\x01';
      }
      net_buf_unref(in_stack_ffffffcc);
      return '\0';
    }
    local_1c = "Failed to read public address";
  }
  local_20 = 2;
  LOG_WRN(&PTR_s_bt_id_0008b900,0x1080,&local_20,2,in_stack_ffffffc8,(uint8_t *)in_stack_ffffffcc,
          in_stack_ffffffd0);
  return '\0';
}


