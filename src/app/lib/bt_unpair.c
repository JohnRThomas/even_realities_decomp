/*
 * Function: bt_unpair
 * Entry:    000574b8
 * Prototype: int __stdcall bt_unpair(uint8_t id, bt_addr_le_t * addr)
 */


/* exclude_from_export_ai */

int bt_unpair(uint8_t id,bt_addr_le_t *addr)

{
  int iVar1;
  undefined1 local_11 [5];
  
  if (id == '\0') {
    if ((addr == (bt_addr_le_t *)0x0) || (iVar1 = memcmp(addr,&DAT_000f0b50,7), iVar1 == 0)) {
      bt_foreach_bond('\0',&LAB_00084638_1,local_11);
    }
    else {
      unpair(0);
    }
    iVar1 = 0;
  }
  else {
    iVar1 = -0x16;
  }
  return iVar1;
}


