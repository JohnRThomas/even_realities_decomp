/*
 * Function: exit_mic_mode
 * Entry:    00032900
 * Prototype: undefined4 __stdcall exit_mic_mode(undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
exit_mic_mode(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  GlassesState *pGVar2;
  undefined1 *puVar3;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("exit_mic_mode para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else {
    puVar3 = (undefined1 *)*param_3;
    *puVar3 = 0x1a;
    uVar1 = 0;
    puVar3[4] = 0;
    puVar3[1] = 1;
    puVar3[3] = 1;
    puVar3[2] = 3;
    *param_4 = 5;
    FUN_00030458();
    pGVar2 = __get_dashboard_state();
    k_sem_give(&pGVar2->sem_4);
  }
  return uVar1;
}


