/*
 * Function: bt_setup_public_id_addr
 * Entry:    000585dc
 * Prototype: int __stdcall bt_setup_public_id_addr(void)
 */


/* exclude_from_export */

int bt_setup_public_id_addr(void)

{
  int iVar1;
  uint8_t *irk;
  bt_addr_le_t bStack_10;
  
  DAT_20002007 = bt_id_read_public_addr(&bStack_10);
  iVar1 = 0;
  if (DAT_20002007 != '\0') {
    iVar1 = id_create('\0',&bStack_10,irk);
  }
  return iVar1;
}


