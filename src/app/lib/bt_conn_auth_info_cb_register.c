/*
 * Function: bt_conn_auth_info_cb_register
 * Entry:    0005a5dc
 * Prototype: int __stdcall bt_conn_auth_info_cb_register(bt_conn_auth_info_cb * cb)
 */


/* exclude_from_export */

int bt_conn_auth_info_cb_register(bt_conn_auth_info_cb *cb)

{
  sys_snode_t *psVar1;
  sys_snode_t *psVar2;
  
  if (cb == (bt_conn_auth_info_cb *)0x0) {
    return -0x16;
  }
  (cb->node).next = (sys_snode_t *)0x0;
  psVar2 = &cb->node;
  psVar1 = psVar2;
  if (DAT_2000b704 != (sys_snode_t *)0x0) {
    *DAT_2000b704 = (sys_snode_t)psVar2;
    psVar1 = DAT_2000b700;
  }
  DAT_2000b700 = psVar1;
  DAT_2000b704 = psVar2;
  return 0;
}


