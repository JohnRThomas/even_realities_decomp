/*
 * Function: enter_notification_burial_point
 * Entry:    0004dc7c
 * Prototype: undefined __stdcall enter_notification_burial_point(void)
 */


void enter_notification_burial_point(void)

{
  char cVar1;
  byte bVar2;
  GlassesState *pGVar3;
  undefined8 uVar5;
  uint uVar4;
  
  cVar1 = FUN_00033d5c();
  if ((cVar1 != '\x01') && (pGVar3 = __get_dashboard_state(), pGVar3->field_0x110e != '\x01')) {
    bVar2 = FUN_00081216();
    uVar4 = (uint)bVar2;
    if (uVar4 < 7) {
      pGVar3 = __get_dashboard_state();
      pGVar3->field_0x110e = 1;
      pGVar3 = __get_dashboard_state();
      pGVar3->field_0x110f = bVar2;
      pGVar3 = __get_dashboard_state();
      uVar5 = FUN_000811fa();
      *(undefined8 *)&pGVar3->field_0x1110 = uVar5;
      pGVar3 = __get_dashboard_state();
      *(int *)(&(pGVar3->__burial_point_ctx).field_0xd0 + uVar4 * 0xc) =
           *(int *)(&(pGVar3->__burial_point_ctx).field_0xd0 + uVar4 * 0xc) + 1;
      pGVar3 = __get_dashboard_state();
      *(int *)&(pGVar3->__burial_point_ctx).field_0xc4 =
           *(int *)&(pGVar3->__burial_point_ctx).field_0xc4 + 1;
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG != 0) {
          pGVar3 = __get_dashboard_state();
          ble_printk("%s(): [enter_notification_burial_point] start_time is %d\n",
                     "enter_notification_burial_point",*(undefined4 *)&pGVar3->field_0x1110,
                     *(undefined4 *)&pGVar3->field_0x1114);
          return;
        }
        pGVar3 = __get_dashboard_state();
        printk("%s(): [enter_notification_burial_point] start_time is %d\n",
               "enter_notification_burial_point",*(undefined4 *)&pGVar3->field_0x1110,
               *(undefined4 *)&pGVar3->field_0x1114);
        return;
      }
    }
  }
  return;
}


