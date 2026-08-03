/*
 * Function: bt_ancs_register_attr
 * Entry:    00082f1a
 * Prototype: int __stdcall bt_ancs_register_attr(bt_ancs_client * ancs_c, bt_ancs_notif_attr_id_val id, uint8_t * data, uint16_t len)
 */


/* exclude_from_export_ai */

int bt_ancs_register_attr
              (bt_ancs_client *ancs_c,bt_ancs_notif_attr_id_val id,uint8_t *data,uint16_t len)

{
  int iVar1;
  
  if ((((ancs_c == (bt_ancs_client *)0x0) || (data == (uint8_t *)0x0)) || (0xff < len - 1)) ||
     (7 < (uint)id)) {
    iVar1 = -0x16;
  }
  else {
    ancs_c[id * 0x10 + 0x1068] = (bt_ancs_client)0x1;
    *(uint16_t *)(ancs_c + id * 0x10 + 0x1070) = len;
    *(uint8_t **)(ancs_c + id * 0x10 + 0x1074) = data;
    iVar1 = 0;
  }
  return iVar1;
}


