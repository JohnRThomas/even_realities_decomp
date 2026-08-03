/*
 * Function: get_io_capa
 * Entry:    0005fd98
 * Prototype: uint8_t __stdcall get_io_capa(void)
 */


/* exclude_from_export_ai */

uint8_t get_io_capa(void)

{
  uint8_t uVar1;
  bt_smp *in_r0;
  bt_conn_auth_cb *pbVar2;
  undefined *puVar3;
  
  pbVar2 = latch_auth_cb(in_r0);
  if (pbVar2 == (bt_conn_auth_cb *)0x0) {
    uVar1 = '\x03';
  }
  else {
    puVar3 = pbVar2->passkey_display;
    if (pbVar2->pairing_accept == (undefined *)0x0) {
      if (puVar3 == (undefined *)0x0) {
        uVar1 = '\x03';
      }
      else {
        uVar1 = '\x02';
      }
    }
    else {
      if (puVar3 == (undefined *)0x0) {
        if (DAT_2001e2a6 == '\0') {
          return '\0';
        }
        if (pbVar2->passkey_display_keypress != (undefined *)0x0) {
          return '\x01';
        }
      }
      else if ((pbVar2->passkey_display_keypress != (undefined *)0x0) || (DAT_2001e2a6 == '\0')) {
        return '\x04';
      }
      uVar1 = (puVar3 != (undefined *)0x0) << 1;
    }
  }
  return uVar1;
}


