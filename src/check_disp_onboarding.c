/*
 * Function: check_disp_onboarding
 * Entry:    00028ae4
 * Prototype: undefined __stdcall check_disp_onboarding(int param_1, undefined4 param_2, undefined4 param_3)
 */


void check_disp_onboarding(int param_1,undefined4 param_2,undefined4 param_3)

{
  GlassesState *pGVar1;
  int iVar2;
  undefined1 *puVar3;
  GlassesState *pGVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar5;
  undefined4 extraout_r1_01;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined8 uVar6;
  undefined4 local_14;
  undefined4 uStack_10;
  
  local_14 = param_2;
  uStack_10 = param_3;
  if (((param_1 == 0) && (DAT_20019a61 != '\0')) &&
     ((iVar2 = FUN_0007f3da(0,param_2), iVar2 == 0 ||
      (pGVar1 = __get_dashboard_state(), *(char *)(*(int *)&pGVar1->field_0x101c + 2) != '\0')))) {
    if ((((DAT_20019a61 != '\0') &&
         (pGVar1 = __get_dashboard_state(), *(int *)pGVar1->___glasses_state == 0)) &&
        (pGVar1 = __get_dashboard_state(), pGVar1->field_0xd5 == '\0')) &&
       (pGVar1 = __get_dashboard_state(), *(char *)pGVar1 == '\x01')) {
      iVar2 = FUN_0007f3da(pGVar1,extraout_r1);
      puVar3 = (undefined1 *)0x0;
      uVar5 = extraout_r1_00;
      if (iVar2 != 0) {
        pGVar1 = __get_dashboard_state();
        puVar3 = &pGVar1->field_0x1000;
        uVar5 = extraout_r1_01;
        if (*(char *)(*(int *)&pGVar1->field_0x101c + 1) == '\0') {
          return;
        }
      }
      iVar2 = FUN_0007f3da(puVar3,uVar5);
      if (iVar2 == 0) {
        if (1 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): ble device unbound,prepare to show binding tip\n");
          }
          else {
            ble_printk("%s(): ble device unbound,prepare to show binding tip\n",
                       "check_disp_onboarding",extraout_r2,BLE_DEBUG);
          }
        }
        pGVar1 = __get_dashboard_state();
        *(undefined1 *)(*(int *)&pGVar1->field_0x101c + 2) = 0;
      }
      pGVar1 = __get_dashboard_state();
      *(undefined1 *)(*(int *)&pGVar1->field_0x101c + 3) = 0;
      pGVar1 = __get_dashboard_state();
      DAT_2001db40 = *(undefined1 *)(*(int *)&pGVar1->field_0x101c + 3);
      pGVar1 = __get_dashboard_state();
      uVar5 = local_14;
      local_14._3_1_ = SUB41(uVar5,3);
      local_14._0_3_ =
           CONCAT12(1,CONCAT11(DAT_2001db40,*(undefined1 *)(*(int *)&pGVar1->field_0x101c + 2)));
      iVar2 = onboarding_sync_data((undefined1 *)&local_14,3,extraout_r2_00);
      if (iVar2 == 0) {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): ready to show onboarding...\n");
          }
          else {
            ble_printk("%s(): ready to show onboarding...\n","check_disp_onboarding",extraout_r2_01,
                       BLE_DEBUG);
          }
        }
        FUN_00042830();
        pGVar1 = __get_dashboard_state();
        **(undefined1 **)&pGVar1->field_0x101c = 1;
        pGVar1 = __get_dashboard_state();
        update_persist_task_status((int)pGVar1,0xe,2);
        pGVar1 = __get_dashboard_state();
        pGVar4 = __get_dashboard_state();
        *(undefined1 *)(*(int *)&pGVar4->field_0x101c + 0x20) = pGVar1->field_0xed5;
        pGVar1 = __get_dashboard_state();
        pGVar1->field_0xed5 = 0x2a;
        uVar6 = FUN_0007fea6();
        pGVar1 = __get_dashboard_state();
        *(undefined8 *)(*(int *)&pGVar1->field_0x101c + 4) = uVar6;
        pGVar1 = __get_dashboard_state();
        iVar2 = *(int *)&pGVar1->field_0x101c;
        pGVar1 = __get_dashboard_state();
        pGVar1->field_0xcd = *(undefined1 *)(iVar2 + 3);
      }
    }
  }
  else {
    pGVar1 = __get_dashboard_state();
    if (*(char *)pGVar1 == '\x01') {
      FUN_00080992();
      return;
    }
  }
  return;
}


