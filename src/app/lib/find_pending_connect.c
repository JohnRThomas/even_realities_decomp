/*
 * Function: find_pending_connect
 * Entry:    000566f8
 * Prototype: bt_conn * __stdcall find_pending_connect(uint8_t role, bt_addr_le_t * peer_addr)
 */


/* exclude_from_export_ai */

bt_conn * find_pending_connect(uint8_t role,bt_addr_le_t *peer_addr)

{
  bt_conn *pbVar1;
  
  pbVar1 = bt_conn_lookup_state_le(DAT_2000206f,(bt_addr_le_t *)(uint)role,5);
  if (pbVar1 == (bt_conn *)0x0) {
    pbVar1 = bt_conn_lookup_state_le(DAT_2000206f,(bt_addr_le_t *)&DAT_000f0b49,4);
    return pbVar1;
  }
  return pbVar1;
}


