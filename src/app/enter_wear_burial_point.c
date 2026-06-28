/*
 * Function: enter_wear_burial_point
 * Entry:    0004d940
 * Prototype: undefined __stdcall enter_wear_burial_point(void)
 */


void enter_wear_burial_point(void)

{
  char cVar1;
  byte bVar2;
  GlassesState *pGVar3;
  undefined8 uVar5;
  uint uVar4;
  
  cVar1 = FUN_00033d5c();
  if ((cVar1 != '\x01') && (pGVar3 = __get_dashboard_state(), pGVar3->field_0x10f4 != '\x01')) {
    bVar2 = FUN_00081216();
    uVar4 = (uint)bVar2;
    if (uVar4 < 7) {
      pGVar3 = __get_dashboard_state();
      pGVar3->field_0x10f4 = 1;
      pGVar3 = __get_dashboard_state();
      pGVar3->field_0x10f5 = bVar2;
      pGVar3 = __get_dashboard_state();
      uVar5 = FUN_000811fa();
      *(undefined8 *)&pGVar3->field_0x10f6 = uVar5;
      pGVar3 = __get_dashboard_state();
      *(int *)(&(pGVar3->__burial_point_ctx).field_0x20 + uVar4 * 0xc) =
           *(int *)(&(pGVar3->__burial_point_ctx).field_0x20 + uVar4 * 0xc) + 1;
      pGVar3 = __get_dashboard_state();
      *(int *)&(pGVar3->__burial_point_ctx).field_0x8 =
           *(int *)&(pGVar3->__burial_point_ctx).field_0x8 + 1;
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG != 0) {
          pGVar3 = __get_dashboard_state();
          ble_printk("%s(): [enter_wear_burial_point] start_time is %d\n","enter_wear_burial_point",
                     *(undefined4 *)&pGVar3->field_0x10f6,*(undefined4 *)&pGVar3->field_0x10fa);
          return;
        }
        pGVar3 = __get_dashboard_state();
        printk("%s(): [enter_wear_burial_point] start_time is %d\n","enter_wear_burial_point",
               *(undefined4 *)&pGVar3->field_0x10f6,*(undefined4 *)&pGVar3->field_0x10fa);
        return;
      }
    }
  }
  return;
}


