/*
 * Function: $_?_FUN_000847ec
 * Entry:    000847ec
 * Prototype: undefined __stdcall $_?_FUN_000847ec(uint8_t * param_1)
 */


void ____FUN_000847ec(uint8_t *param_1)

{
  if ((int)((uint)param_1[8] << 0x1d) < 0) {
    hci_id_add(*param_1,(bt_addr_le_t *)(param_1 + 1),param_1 + 0x2a);
    return;
  }
  return;
}


