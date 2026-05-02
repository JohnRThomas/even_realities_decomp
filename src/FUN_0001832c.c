/*
 * Function: FUN_0001832c
 * Entry:    0001832c
 * Prototype: undefined __stdcall FUN_0001832c(undefined4 * param_1)
 */


void FUN_0001832c(undefined4 *param_1)

{
  void *buf;
  
  param_1[0x93] = param_1 + 0xe5;
  *param_1 = 0x23fd9;
  z_impl_k_mutex_init((k_mutex *)&GLOBAL_STATE.sem_1);
  param_1[3] = 0x17f85;
  z_impl_k_sem_init((k_sem *)(param_1 + 0x86),0,1);
  z_impl_k_sem_init((k_sem *)(param_1 + 0x8c),0,2);
  param_1[0x94] = param_1 + 0x235;
  *(undefined1 *)((int)param_1 + 0x365) = 0;
  *(undefined1 *)((int)param_1 + 0x366) = 0;
  *(undefined1 *)(param_1 + 0xd9) = 0;
  GLOBAL_STATE.sem_1.poll_events.prev = param_1;
  buf = malloc(0x15);
  param_1[0x95] = buf;
  memset(buf,0,0x15);
  return;
}


