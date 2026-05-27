/*
 * Function: get_brightness_lum_info
 * Entry:    000324e0
 * Prototype: undefined4 __stdcall get_brightness_lum_info(undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
get_brightness_lum_info
          (undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  GlassesState *pGVar2;
  undefined1 *puVar3;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("get_brightness_lum_info para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else {
    puVar3 = (undefined1 *)*param_3;
    *puVar3 = 0x37;
    puVar3[1] = 1;
    puVar3[2] = 3;
    puVar3[3] = 8;
    pGVar2 = __get_dashboard_state();
    *(undefined2 *)(puVar3 + 4) = *(undefined2 *)&pGVar2->field_0xed8;
    pGVar2 = __get_dashboard_state();
    *(undefined2 *)(puVar3 + 6) = pGVar2->field3450_0xeda;
    pGVar2 = __get_dashboard_state();
    *(undefined2 *)(puVar3 + 8) = pGVar2->field3451_0xedc;
    pGVar2 = __get_dashboard_state();
    uVar1 = 0;
    *(undefined2 *)(puVar3 + 10) = pGVar2->field3452_0xede;
    *param_4 = 0xc;
  }
  return uVar1;
}


