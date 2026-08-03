/*
 * Function: bt_addr_copy
 * Entry:    00084772
 * Prototype: void __stdcall bt_addr_copy(bt_addr_t * dst, bt_addr_t * src)
 */


/* exclude_from_export */

void bt_addr_copy(bt_addr_t *dst,bt_addr_t *src)

{
  *(undefined4 *)dst->val = *(undefined4 *)src->val;
  *(undefined2 *)(dst->val + 4) = *(undefined2 *)(src->val + 4);
  return;
}


