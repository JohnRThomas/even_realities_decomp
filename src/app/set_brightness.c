/*
 * Function: set_brightness
 * Entry:    0003236c
 * Prototype: undefined4 __stdcall set_brightness(int param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4 set_brightness(int param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  byte bVar1;
  undefined4 uVar2;
  GlassesState *pGVar3;
  code *pcVar4;
  undefined1 *puVar5;
  bool bVar6;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("set_brightness para is NULL\n");
    uVar2 = 0xffffffff;
  }
  else {
    puVar5 = (undefined1 *)*param_3;
    *puVar5 = 0x33;
    puVar5[1] = 1;
    puVar5[2] = 3;
    puVar5[3] = 1;
    bVar1 = *(byte *)(param_1 + 4);
    pGVar3 = __get_dashboard_state();
    bVar6 = (pGVar3->jdb_panel_context).field834_0x369 == bVar1;
    if (!bVar6) {
      pGVar3 = __get_dashboard_state();
      pcVar4 = (code *)(pGVar3->jdb_panel_context).set_brightness_cb;
      pGVar3 = __get_dashboard_state();
      (*pcVar4)(&pGVar3->jdb_panel_context,bVar1);
    }
    puVar5[4] = bVar6;
    uVar2 = 0;
    *param_4 = 5;
  }
  return uVar2;
}


