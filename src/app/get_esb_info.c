/*
 * Function: get_esb_info
 * Entry:    00032488
 * Prototype: int __stdcall get_esb_info(undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


int get_esb_info(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  int iVar1;
  GlassesState *pGVar2;
  undefined1 *puVar3;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("get_esb_info para is NULL\n");
    iVar1 = -1;
  }
  else {
    puVar3 = (undefined1 *)*param_3;
    iVar1 = 0;
    *puVar3 = 0x23;
    puVar3[2] = 3;
    puVar3[1] = 0;
    puVar3[3] = 0xb;
    pGVar2 = __get_dashboard_state();
    puVar3[4] = pGVar2->esb_channel;
    pGVar2 = __get_dashboard_state();
    puVar3[5] = pGVar2->field_0x3;
    pGVar2 = __get_dashboard_state();
    puVar3[6] = pGVar2->field_0x4;
    *(undefined4 *)(puVar3 + 7) = DAT_20006bc8;
    *param_4 = 0xf;
  }
  return iVar1;
}


