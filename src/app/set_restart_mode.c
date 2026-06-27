/*
 * Function: set_restart_mode
 * Entry:    000323c4
 * Prototype: undefined4 __stdcall set_restart_mode(undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
set_restart_mode(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  GlassesState *pGVar2;
  undefined1 *puVar3;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("set_restart_mode para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else {
    puVar3 = (undefined1 *)*param_3;
    *puVar3 = 0xe1;
    uVar1 = 0;
    puVar3[2] = 3;
    puVar3[1] = 1;
    puVar3[3] = 1;
    puVar3[4] = 0;
    *param_4 = 5;
    pGVar2 = __get_dashboard_state();
    pGVar2->field_0x1089 = 2;
  }
  return uVar1;
}


