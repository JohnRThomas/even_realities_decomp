/*
 * Function: power_on_opt3007
 * Entry:    00032cd0
 * Prototype: undefined4 __stdcall power_on_opt3007(undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
power_on_opt3007(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("power_on_opt3007 para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else {
    puVar2 = (undefined1 *)*param_3;
    *puVar2 = 0x30;
    puVar2[2] = 3;
    puVar2[1] = 1;
    puVar2[3] = 1;
    __enable_power_for_panel();
    uVar1 = 0;
    puVar2[4] = 0;
    *param_4 = 5;
  }
  return uVar1;
}


