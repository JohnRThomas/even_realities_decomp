/*
 * Function: get_keyboard_info
 * Entry:    0003278c
 * Prototype: undefined4 __stdcall get_keyboard_info(undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4
get_keyboard_info(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  GlassesState *pGVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined1 uVar3;
  undefined1 *puVar4;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("get_keyboard_info para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else {
    puVar4 = (undefined1 *)*param_3;
    *puVar4 = 0x18;
    puVar4[2] = 3;
    puVar4[1] = 1;
    puVar4[3] = 1;
    pGVar2 = __get_dashboard_state();
    if (*(uint *)&pGVar2->field_0x1090 < 0x3e419) {
      pGVar2 = __get_dashboard_state();
      uVar3 = (undefined1)(*(uint *)&pGVar2->field_0x1090 / 1000);
    }
    else {
      uVar3 = 0xff;
    }
    puVar4[4] = uVar3;
    pGVar2 = __get_dashboard_state();
    printk("before aw9320x_diff_get: %d\n",*(undefined4 *)&pGVar2->field_0x1090);
    pGVar2 = __get_dashboard_state();
    aw9320x_diff_get((uint *)&pGVar2->field_0x1090,extraout_r1,extraout_r2);
    pGVar2 = __get_dashboard_state();
    printk("after aw9320x_diff_get: %d\n",*(undefined4 *)&pGVar2->field_0x1090);
    uVar1 = 0;
    *param_4 = 5;
  }
  return uVar1;
}


