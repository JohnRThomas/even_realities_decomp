/*
 * Function: bt_conn_exists_le
 * Entry:    0005a154
 * Prototype: bool __stdcall bt_conn_exists_le(uint8_t id, bt_addr_le_t * peer)
 */


/* exclude_from_export */

bool bt_conn_exists_le(uint8_t id,bt_addr_le_t *peer)

{
  bool bVar1;
  bt_conn *conn;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined1 *local_20;
  char *local_1c;
  char *pcStack_18;
  undefined2 local_14;
  
  conn = bt_conn_lookup_addr_le(id,peer);
  bVar1 = false;
  if (conn != (bt_conn *)0x0) {
    if (conn->state < 9) {
      pcStack_18 = (&PTR_s_disconnected_000bf655_0xa_0008edb0)[conn->state];
    }
    else {
      pcStack_18 = "(unknown)";
    }
    local_1c = "Found valid connection in %s state";
    local_14 = 0x200;
    local_20 = &DAT_01000003;
    LOG_WRN(&PTR_s_bt_conn_0008b8b8,0x1c80,&local_20,&DAT_01000003,in_stack_ffffffd0,
            in_stack_ffffffd4,in_stack_ffffffd8);
    bt_conn_unref(conn);
    bVar1 = true;
  }
  return bVar1;
}


