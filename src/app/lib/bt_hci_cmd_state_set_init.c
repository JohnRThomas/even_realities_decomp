/*
 * Function: bt_hci_cmd_state_set_init
 * Entry:    00056f5c
 * Prototype: void __stdcall bt_hci_cmd_state_set_init(net_buf * buf, bt_hci_cmd_state_set * state, atomic_t * target, int bit, bool val)
 */


/* exclude_from_export */

void bt_hci_cmd_state_set_init
               (net_buf *buf,bt_hci_cmd_state_set *state,atomic_t *target,int bit,bool val)

{
  int iVar1;
  
  *state = (bt_hci_cmd_state_set)target;
  state[1] = bit;
  *(bool *)(state + 2) = val;
  iVar1 = net_buf_id(buf);
  *(bt_hci_cmd_state_set **)(&DAT_2000b5d8 + iVar1 * 0xc) = state;
  return;
}


