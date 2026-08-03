/*
 * Function: bt_pub_key_get
 * Entry:    00059104
 * Prototype: uint8_t * __stdcall bt_pub_key_get(void)
 */


/* exclude_from_export_ai */

uint8_t * bt_pub_key_get(void)

{
  uint8_t *puVar1;
  
  puVar1 = (uint8_t *)&DAT_2001e265;
  if ((DAT_200020d4 & 0x10) == 0) {
    puVar1 = (uint8_t *)0x0;
  }
  return puVar1;
}


