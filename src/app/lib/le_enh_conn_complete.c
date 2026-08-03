/*
 * Function: le_enh_conn_complete
 * Entry:    000846c6
 * Prototype: undefined __stdcall le_enh_conn_complete(int param_1)
 */


/* exclude_from_export */

void le_enh_conn_complete(int param_1)

{
  bt_hci_le_enh_conn_complete(*(bt_hci_evt_le_enh_conn_complete **)(param_1 + 0xc));
  return;
}


