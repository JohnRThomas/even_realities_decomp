/*
 * Function: FUN_00056cd4
 * Entry:    00056cd4
 * Prototype: undefined __stdcall FUN_00056cd4(net_buf * param_1)
 */


void FUN_00056cd4(net_buf *param_1)

{
  uint8_t uVar1;
  uint8_t *puVar2;
  
  puVar2 = net_buf_simple_pull_mem(&(param_1->field6_0xc).b,4);
  uVar1 = puVar2[1];
  hci_cmd_done(*(uint16_t *)(puVar2 + 2),*puVar2,param_1);
  if (uVar1 != '\0') {
    k_sem_give((k_sem *)&DAT_20002128);
    return;
  }
  return;
}


