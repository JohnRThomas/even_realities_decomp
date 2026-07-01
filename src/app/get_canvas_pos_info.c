/*
 * Function: get_canvas_pos_info
 * Entry:    0003253c
 * Prototype: undefined4 __stdcall get_canvas_pos_info(undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
get_canvas_pos_info(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  GlassesState *pGVar2;
  undefined1 *puVar3;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("get_canvas_pos_info para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else {
    puVar3 = (undefined1 *)*param_3;
    *puVar3 = 0x39;
    puVar3[1] = 1;
    puVar3[2] = 3;
    puVar3[3] = 4;
    pGVar2 = __get_dashboard_state();
    *(undefined2 *)(puVar3 + 4) = pGVar2->field1214_0x108a;
    pGVar2 = __get_dashboard_state();
    uVar1 = 0;
    *(undefined2 *)(puVar3 + 6) = pGVar2->field1215_0x108c;
    *param_4 = 8;
  }
  return uVar1;
}


