/*
 * Function: exit_dashboard_burial_point
 * Entry:    0004db68
 * Prototype: undefined __stdcall exit_dashboard_burial_point(void)
 */


void exit_dashboard_burial_point(void)

{
  byte bVar1;
  GlassesState *pGVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  
  pGVar2 = __get_dashboard_state();
  if ((pGVar2->field_0x10da != '\0') && (bVar1 = FUN_00081216(), bVar1 < 7)) {
    pGVar2 = __get_dashboard_state();
    pGVar2->field_0x10da = 0;
    lVar5 = get_dashboard_sum_time();
    uVar4 = (uint)((ulonglong)lVar5 >> 0x20);
    uVar3 = (uint)lVar5;
    FUN_000812a2(uVar3,uVar4);
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        pGVar2 = __get_dashboard_state();
        printk("%s(): [exit_dashboard_burial_point] sum_time is %d ms,dashboard_sum_time is %d s\n",
               "exit_dashboard_burial_point",uVar3,uVar4,
               *(undefined4 *)&(pGVar2->__burial_point_ctx).field_0xc);
      }
      else {
        pGVar2 = __get_dashboard_state();
        ble_printk("%s(): [exit_dashboard_burial_point] sum_time is %d ms,dashboard_sum_time is %d s\n"
                   ,"exit_dashboard_burial_point",uVar3,uVar4,
                   *(undefined4 *)&(pGVar2->__burial_point_ctx).field_0xc);
      }
    }
  }
  return;
}


