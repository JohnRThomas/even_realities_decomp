/*
 * Function: get_mac_info
 * Entry:    00032e70
 * Prototype: undefined4 __stdcall get_mac_info(int param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4 get_mac_info(int param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  GlassesState *pGVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("get_mac_info para is NULL\n");
    return 0xffffffff;
  }
  puVar3 = (undefined1 *)*param_3;
  *puVar3 = 5;
  puVar3[1] = 1;
  puVar3[2] = 3;
  puVar3[3] = 6;
  if (*(char *)(param_1 + 2) == '\x01') {
    pGVar1 = __get_dashboard_state();
    *(undefined4 *)(puVar3 + 4) = *(undefined4 *)&pGVar1->field_0xfde;
    uVar2 = *(undefined2 *)&pGVar1->field_0xfe2;
  }
  else {
    if (*(char *)(param_1 + 2) != '\0') goto LAB_00032eac;
    pGVar1 = __get_dashboard_state();
    *(undefined4 *)(puVar3 + 4) = *(undefined4 *)&pGVar1->field_0xfe4;
    uVar2 = *(undefined2 *)&pGVar1->field_0xfe8;
  }
  *(undefined2 *)(puVar3 + 8) = uVar2;
LAB_00032eac:
  *param_4 = 10;
  return 0;
}


