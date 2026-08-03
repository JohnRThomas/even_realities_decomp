/*
 * Function: bt_l2cap_server_lookup_psm
 * Entry:    0005ac60
 * Prototype: bt_l2cap_server * __stdcall bt_l2cap_server_lookup_psm(uint16_t psm)
 */


/* exclude_from_export */

bt_l2cap_server * bt_l2cap_server_lookup_psm(uint16_t psm)

{
  int *piVar1;
  bt_l2cap_server *pbVar2;
  
  for (piVar1 = (int *)DAT_2000b70c;
      (pbVar2 = (bt_l2cap_server *)0x0, piVar1 != (int *)0x0 &&
      (pbVar2 = (bt_l2cap_server *)(piVar1 + -2), *(uint16_t *)(piVar1 + -2) != psm));
      piVar1 = (int *)*piVar1) {
  }
  return pbVar2;
}


