/*
 * Function: get_dashboard_sum_time
 * Entry:    0004da14
 * Prototype: longlong __stdcall get_dashboard_sum_time(void)
 */


longlong get_dashboard_sum_time(void)

{
  GlassesState *pGVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  undefined8 uVar7;
  longlong lVar8;
  
  uVar7 = FUN_000811fa();
  iVar5 = (int)((ulonglong)uVar7 >> 0x20);
  pGVar1 = __get_dashboard_state();
  iVar2 = *(int *)&pGVar1->field_0x10e0;
  bVar6 = *(uint *)&pGVar1->field_0x10dc < (uint)uVar7;
  if ((int)((iVar2 - iVar5) - (uint)bVar6) < 0 ==
      (SBORROW4(iVar2,iVar5) != SBORROW4(iVar2 - iVar5,(uint)bVar6))) {
    pGVar1 = __get_dashboard_state();
    uVar3 = *(uint *)&pGVar1->field_0x10dc;
    iVar5 = *(int *)&pGVar1->field_0x10e0;
    uVar7 = FUN_000811fa();
    lVar8 = CONCAT44((iVar5 - (int)((ulonglong)uVar7 >> 0x20)) - (uint)(uVar3 < (uint)uVar7),
                     uVar3 - (uint)uVar7);
  }
  else {
    lVar8 = FUN_000811fa();
    pGVar1 = __get_dashboard_state();
    lVar8 = lVar8 - *(longlong *)&pGVar1->field_0x10dc;
  }
  uVar4 = (undefined4)((ulonglong)lVar8 >> 0x20);
  if (1 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): get_dashboard_sum_time is %d\n","get_dashboard_sum_time",(int)lVar8,uVar4);
    }
    else {
      ble_printk("%s(): get_dashboard_sum_time is %d\n","get_dashboard_sum_time",(int)lVar8,uVar4);
    }
  }
  return lVar8;
}


