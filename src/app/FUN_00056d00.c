/*
 * Function: FUN_00056d00
 * Entry:    00056d00
 * Prototype: undefined __stdcall FUN_00056d00(net_buf * param_1)
 */


void FUN_00056d00(net_buf *param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = net_buf_simple_pull_mem(&(param_1->field6_0xc).b,3);
  cVar1 = *pcVar2;
  hci_cmd_done(*(uint16_t *)(pcVar2 + 1),*(param_1->field6_0xc).field0.data,param_1);
  if (cVar1 != '\0') {
    k_sem_give((k_sem *)&DAT_20002128);
    return;
  }
  return;
}


