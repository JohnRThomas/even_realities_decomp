/*
 * Function: get_brightness_info
 * Entry:    00032db8
 * Prototype: undefined4 __stdcall get_brightness_info(int param_1, uint param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4 get_brightness_info(int param_1,uint param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  GlassesState *pGVar2;
  undefined1 *puVar3;
  
  if ((((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) || (param_1 == 0)) ||
     (param_2 < 4)) {
    printk("%s para is NULL\n","get_brightness_info",param_3,param_4,param_4);
    uVar1 = 0xffffffff;
  }
  else {
    puVar3 = (undefined1 *)*param_3;
    *puVar3 = 0x3b;
    puVar3[2] = 3;
    puVar3[1] = 1;
    puVar3[3] = 1;
    pGVar2 = __get_dashboard_state();
    uVar1 = 0;
    puVar3[4] = (pGVar2->jdb_panel_context).field834_0x369;
    *param_4 = 5;
  }
  return uVar1;
}


