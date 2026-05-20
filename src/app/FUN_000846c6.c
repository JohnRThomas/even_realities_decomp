/*
 * Function: FUN_000846c6
 * Entry:    000846c6
 * Prototype: undefined __stdcall FUN_000846c6(int param_1)
 */


void FUN_000846c6(int param_1)

{
  bt_hci_le_enh_conn_complete(*(bt_hci_evt_le_enh_conn_complete **)(param_1 + 0xc));
  return;
}


