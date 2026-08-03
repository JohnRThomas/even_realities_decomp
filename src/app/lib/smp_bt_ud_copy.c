/*
 * Function: smp_bt_ud_copy
 * Entry:    000843ca
 * Prototype: int __stdcall smp_bt_ud_copy(net_buf * dst, net_buf * src)
 */


/* exclude_from_export_ai */

int smp_bt_ud_copy(net_buf *dst,net_buf *src)

{
  if (src->user_data != (uint8_t *)0x0) {
    dst->user_data = src->user_data;
    *(undefined1 *)&dst[1].node.next = *(undefined1 *)&src[1].node.next;
  }
  return 0;
}


