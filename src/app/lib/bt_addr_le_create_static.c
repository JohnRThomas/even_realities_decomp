/*
 * Function: bt_addr_le_create_static
 * Entry:    00084592
 * Prototype: int __stdcall bt_addr_le_create_static(bt_addr_le_t * addr)
 */


/* exclude_from_export */

int bt_addr_le_create_static(bt_addr_le_t *addr)

{
  int iVar1;
  
  addr->type = '\x01';
  iVar1 = bt_rand(&addr->a,6);
  if (iVar1 == 0) {
    (addr->a).val[5] = (addr->a).val[5] | 0xc0;
  }
  return iVar1;
}


