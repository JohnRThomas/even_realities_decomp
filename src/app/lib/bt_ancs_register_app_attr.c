/*
 * Function: bt_ancs_register_app_attr
 * Entry:    00082f4a
 * Prototype: int __stdcall bt_ancs_register_app_attr(bt_ancs_client * ancs_c, bt_ancs_app_attr_id_val id, uint8_t * data, uint16_t len)
 */


/* exclude_from_export_ai */

int bt_ancs_register_app_attr
              (bt_ancs_client *ancs_c,bt_ancs_app_attr_id_val id,uint8_t *data,uint16_t len)

{
  int iVar1;
  
  if ((((ancs_c == (bt_ancs_client *)0x0) || (data == (uint8_t *)0x0)) || (0xff < len - 1)) ||
     (id != 0)) {
    iVar1 = -0x16;
  }
  else {
    ancs_c[0x10e8] = (bt_ancs_client)0x1;
    *(uint16_t *)(ancs_c + 0x10f0) = len;
    *(uint8_t **)(ancs_c + 0x10f4) = data;
    iVar1 = 0;
  }
  return iVar1;
}


