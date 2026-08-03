/*
 * Function: bt_addr_le_copy_resolved
 * Entry:    000845ae
 * Prototype: void __stdcall bt_addr_le_copy_resolved(bt_addr_le_t * dst, bt_addr_le_t * src)
 */


/* exclude_from_export_ai */

void bt_addr_le_copy_resolved(bt_addr_le_t *dst,bt_addr_le_t *src)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  
  uVar1 = (src->a).val[0];
  uVar2 = (src->a).val[1];
  uVar3 = (src->a).val[2];
  dst->type = src->type;
  (dst->a).val[0] = uVar1;
  (dst->a).val[1] = uVar2;
  (dst->a).val[2] = uVar3;
  *(undefined2 *)((dst->a).val + 3) = *(undefined2 *)((src->a).val + 3);
  (dst->a).val[5] = (src->a).val[5];
  dst->type = dst->type & 0xfd;
  return;
}


