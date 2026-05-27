/*
 * Function: set_canvas_pos_info
 * Entry:    000326e8
 * Prototype: undefined4 __stdcall set_canvas_pos_info(int param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
set_canvas_pos_info(int param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  GlassesState *pGVar3;
  undefined1 uVar4;
  ushort uVar5;
  undefined1 *puVar6;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("set_canvas_pos_info para is NULL\n");
    uVar2 = 0xffffffff;
  }
  else if (DAT_2001abc2 == '\x01') {
    puVar6 = (undefined1 *)*param_3;
    *puVar6 = 0x38;
    puVar6[1] = 1;
    puVar6[2] = 3;
    puVar6[3] = 1;
    uVar5 = *(ushort *)(param_1 + 5);
    uVar4 = 1;
    if ((uVar5 < 0x41) && (uVar1 = *(ushort *)(param_1 + 7), uVar1 < 0x41)) {
      if ((int)((uint)uVar5 << 0x1f) < 0) {
        pGVar3 = __get_dashboard_state();
        uVar5 = uVar5 - 1;
      }
      else {
        pGVar3 = __get_dashboard_state();
      }
      pGVar3->field3671_0x108a = uVar5;
      pGVar3 = __get_dashboard_state();
      uVar4 = 0;
      pGVar3->field3672_0x108c = uVar1;
      DAT_2001c4e0 = 0;
    }
    puVar6[4] = uVar4;
    if (*(char *)(param_1 + 4) != '\0') {
      pGVar3 = __get_dashboard_state();
      FUN_00024abc(pGVar3);
    }
    uVar2 = 0;
    *param_4 = 5;
  }
  else {
    printk("warning: not test mode,disable setting\n");
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}


