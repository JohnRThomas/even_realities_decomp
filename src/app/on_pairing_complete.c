/*
 * Function: ?_on_pairing_complete
 * Entry:    00018834
 * Prototype: undefined __stdcall ?_on_pairing_complete(k_work * param_1, undefined4 param_2)
 */


void __on_pairing_complete(k_work *param_1,undefined4 param_2)

{
  char cVar1;
  k_work_delayable *addr;
  GlassesState *pGVar2;
  int iVar3;
  size_t len;
  char acStack_38 [36];
  
  addr = k_work_delayable_from_work(param_1);
  bt_addr_le_to_str((bt_addr_le_t *)addr,acStack_38,len);
  pGVar2 = __get_dashboard_state();
  if (pGVar2->field_0x1089 != '\0') {
    pGVar2 = __get_dashboard_state();
    pGVar2->field_0x1089 = 0;
  }
  cVar1 = FUN_00033d5c();
  if (cVar1 == '\0') {
    pGVar2 = __get_dashboard_state();
    iVar3 = memcmp(pGVar2->field2780_0x1080 + 1,addr,7);
    if (iVar3 != 0) {
      pGVar2 = __get_dashboard_state();
      bt_unpair('\0',(bt_addr_le_t *)(pGVar2->field2780_0x1080 + 1));
      pGVar2 = __get_dashboard_state();
      *(undefined1 *)((int)&pGVar2->field2781_0x1087 + 1) = 0;
      pGVar2 = __get_dashboard_state();
      *(undefined4 *)&pGVar2->field_0x1060 = 0;
      pGVar2 = __get_dashboard_state();
      k_sem_give(&pGVar2->sem_6);
    }
  }
  pGVar2 = __get_dashboard_state();
  *(sys_snode_t **)(pGVar2->field2780_0x1080 + 1) = (addr->work).node.next;
  *(undefined2 *)(pGVar2->field2780_0x1080 + 5) = *(undefined2 *)&(addr->work).handler;
  *(undefined1 *)&pGVar2->field2781_0x1087 = *(undefined1 *)((int)&(addr->work).handler + 2);
  printk("Pairing completed: %s, bonded: %d\n",acStack_38,param_2);
  *(undefined1 *)(GLOBAL_STATE.sem_8.limit + 0x367) = 0;
  return;
}


