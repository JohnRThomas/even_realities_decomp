/*
 * Function: set_comflag
 * Entry:    00032d40
 * Prototype: undefined4 __stdcall set_comflag(int param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 set_comflag(int param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  GlassesState *pGVar2;
  undefined1 *puVar3;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("set_comflag para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else if (DAT_2001abc2 == '\x01') {
    puVar3 = (undefined1 *)*param_3;
    *puVar3 = 0x32;
    puVar3[1] = 1;
    puVar3[2] = 3;
    puVar3[3] = 1;
    puVar3[4] = *(undefined1 *)(param_1 + 4);
    pGVar2 = __get_dashboard_state();
    if ((pGVar2->field_0x10a0 == '\0') && (*(char *)(param_1 + 4) == '\x01')) {
      FUN_00034d2c();
    }
    pGVar2 = __get_dashboard_state();
    pGVar2->field_0x10a0 = *(undefined1 *)(param_1 + 4);
    uVar1 = 0;
    *param_4 = 5;
  }
  else {
    printk("warning: not test mode,disable setting\n");
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}


