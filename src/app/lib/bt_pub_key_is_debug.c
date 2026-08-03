/*
 * Function: bt_pub_key_is_debug
 * Entry:    00058f9c
 * Prototype: bool __stdcall bt_pub_key_is_debug(uint8_t * cmp_pub_key)
 */


/* exclude_from_export_ai */

bool bt_pub_key_is_debug(uint8_t *cmp_pub_key)

{
  int iVar1;
  
  iVar1 = memcmp(cmp_pub_key,s_5_H_____t_0_Ecv__RZ_2cm__eI_bt_e_000f1a34,0x40);
  return iVar1 == 0;
}


