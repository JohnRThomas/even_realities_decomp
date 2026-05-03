/*
 * Function: set_battery_info
 * Entry:    00032650
 * Prototype: undefined4 __stdcall set_battery_info(undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
set_battery_info(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  GlassesState *pGVar2;
  char cVar3;
  short sVar4;
  undefined1 *puVar5;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("set_battery_info para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else {
    FUN_00028d88();
    puVar5 = (undefined1 *)*param_3;
    *puVar5 = 0x11;
    puVar5[1] = 1;
    puVar5[2] = 3;
    puVar5[3] = 7;
    pGVar2 = __get_dashboard_state();
    puVar5[4] = pGVar2->field_0xfc4;
    pGVar2 = __get_dashboard_state();
    puVar5[5] = pGVar2->field_0xfc8;
    pGVar2 = __get_dashboard_state();
    puVar5[6] = (char)pGVar2->field_0xfcc < '\x01';
    pGVar2 = __get_dashboard_state();
    cVar3 = pGVar2->field_0xfcc;
    if (cVar3 < '\0') {
      cVar3 = -cVar3;
    }
    puVar5[7] = cVar3;
    pGVar2 = __get_dashboard_state();
    puVar5[8] = 0 < *(short *)&pGVar2->field_0xfce;
    pGVar2 = __get_dashboard_state();
    sVar4 = *(short *)&pGVar2->field_0xfce;
    uVar1 = 0;
    if (sVar4 < 0) {
      sVar4 = -sVar4;
    }
    puVar5[10] = (char)sVar4;
    puVar5[9] = (char)((ushort)sVar4 >> 8);
    *param_4 = 0xb;
  }
  return uVar1;
}


