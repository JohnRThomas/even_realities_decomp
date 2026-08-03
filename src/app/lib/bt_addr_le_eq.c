/*
 * Function: bt_addr_le_eq
 * Entry:    00085e6a
 * Prototype: bool __stdcall bt_addr_le_eq(bt_addr_le_t * a, bt_addr_le_t * b)
 */


/* exclude_from_export */

bool bt_addr_le_eq(bt_addr_le_t *a,bt_addr_le_t *b)

{
  int iVar1;
  
  iVar1 = memcmp(a,b,7);
  return iVar1 == 0;
}


