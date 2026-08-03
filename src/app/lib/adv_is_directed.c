/*
 * Function: adv_is_directed
 * Entry:    00058944
 * Prototype: bool __stdcall adv_is_directed(bt_le_ext_adv * adv)
 */


/* exclude_from_export */

bool adv_is_directed(bt_le_ext_adv *adv)

{
  int iVar1;
  
  iVar1 = memcmp(&adv->target_addr,&DAT_000f0b50,7);
  return iVar1 != 0;
}


