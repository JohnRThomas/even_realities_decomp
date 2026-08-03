/*
 * Function: start_tx_locked
 * Entry:    0008828e
 * Prototype: undefined __stdcall start_tx_locked(int param_1)
 */


/* exclude_from_export_ai */

void start_tx_locked(int param_1)

{
  bool bVar1;
  int extraout_r1;
  
  bVar1 = is_tx_ready(*(device **)(param_1 + 4));
  if (!bVar1) {
    *(undefined1 *)(*(int *)(extraout_r1 + 0xc) + 0xcd) = 1;
    return;
  }
  *(undefined1 *)(*(int *)(extraout_r1 + 0xc) + 0xcd) = 0;
  *(undefined4 *)(*(int *)(extraout_r1 + 0xc) + 0xbc) = 0xffffffff;
  tx_start(SUB41(param_1,0));
  return;
}


