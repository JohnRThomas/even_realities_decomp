/*
 * Function: ui_onboarding_task
 * Entry:    00044e70
 * Prototype: undefined4 __stdcall ui_onboarding_task(int param_1, undefined4 param_2, int param_3)
 */


undefined4 ui_onboarding_task(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  GlassesState *pGVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 uVar3;
  undefined4 extraout_r2_05;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 local_14 [2];
  undefined1 local_12;
  undefined1 uStack_11;
  
  _local_14 = param_2;
  pGVar2 = __get_dashboard_state();
  FUN_000452f0(param_1 + 0x24);
  FUN_0004540c();
  if ((param_3 == 2) || (0x17 < (byte)pGVar2->field_0xf1)) {
    pGVar2 = __get_dashboard_state();
    **(undefined1 **)&pGVar2->field_0x101c = 0;
    pGVar2 = __get_dashboard_state();
    iVar4 = *(int *)&pGVar2->field_0x101c;
    pGVar2 = __get_dashboard_state();
    (pGVar2->jdb_panel_context).field834_0x369 = *(byte *)(iVar4 + 0x20);
    gui_screen_clear(pGVar2,extraout_r1,extraout_r2);
  }
  else {
    if ((param_3 == 1) && (pGVar2 = __get_dashboard_state(), *(char *)pGVar2 == '\x01')) {
      send_response_data_to_ble(pGVar2,extraout_r1_00,extraout_r2_00,1);
    }
    pGVar2 = __get_dashboard_state();
    uVar5 = CONCAT44(DAT_20004db4,DAT_20004db0);
    if (*(char *)pGVar2 == '\x01') {
      pGVar2 = __get_dashboard_state();
      uVar5 = CONCAT44(DAT_20004db4,DAT_20004db0);
      if (*(char *)(*(int *)&pGVar2->field_0x101c + 2) != '\0') {
        uVar5 = FUN_00080976();
        uVar6 = FUN_000809b6((uint)uVar5,(int)((ulonglong)uVar5 >> 0x20),DAT_20004db0,DAT_20004db4);
        uVar5 = CONCAT44(DAT_20004db4,DAT_20004db0);
        if ((int)(uint)((uint)uVar6 < 0x3e9) <= (int)((ulonglong)uVar6 >> 0x20)) {
          DAT_20004da8 = DAT_20004da8 + 1;
          uVar5 = FUN_00080976();
          DAT_20004db4 = (int)((ulonglong)uVar5 >> 0x20);
          DAT_20004db0 = (uint)uVar5;
          if (0x13 < DAT_20004da8) {
            if (1 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk(
                      "%s(): onboarding: disconnection between the AR Glasses and the Bluetooth application!\n"
                      );
                uVar5 = CONCAT44(DAT_20004db4,DAT_20004db0);
              }
              else {
                ble_printk("%s(): onboarding: disconnection between the AR Glasses and the Bluetooth application!\n"
                           ,"ui_onboarding_task",extraout_r2_01,BLE_DEBUG);
                uVar5 = CONCAT44(DAT_20004db4,DAT_20004db0);
              }
            }
            DAT_20004db4 = (int)((ulonglong)uVar5 >> 0x20);
            DAT_20004db0 = (uint)uVar5;
            DAT_20004da8 = 0x14;
            pGVar2 = __get_dashboard_state();
            *(undefined1 *)(*(int *)&pGVar2->field_0x101c + 2) = 0xb;
            pGVar2 = __get_dashboard_state();
            _local_14 = (uint3)*(byte *)(*(int *)&pGVar2->field_0x101c + 2);
            iVar4 = onboarding_sync_data(local_14,3,extraout_r2_02);
            if (iVar4 != 0) {
              return 0;
            }
            pGVar2 = __get_dashboard_state();
            **(undefined1 **)&pGVar2->field_0x101c = 0;
            pGVar2 = __get_dashboard_state();
            *(undefined1 *)(*(int *)&pGVar2->field_0x101c + 1) = 0;
            return 0;
          }
        }
      }
    }
    DAT_20004db4 = (int)((ulonglong)uVar5 >> 0x20);
    DAT_20004db0 = (uint)uVar5;
    pGVar2 = __get_dashboard_state();
    if (((uint)*(byte *)(*(int *)&pGVar2->field_0x101c + 2) == (int)DAT_20003697) &&
       (pGVar2 = __get_dashboard_state(),
       *(char *)(*(int *)&pGVar2->field_0x101c + 3) == DAT_2001db40)) {
      FUN_000428bc();
      FUN_00043924();
    }
    else {
      pGVar2 = __get_dashboard_state();
      if (*(char *)pGVar2 == '\x01') {
        FUN_00044b24();
        pGVar2 = __get_dashboard_state();
        DAT_2001db40 = *(char *)(*(int *)&pGVar2->field_0x101c + 3);
        pGVar2 = __get_dashboard_state();
        local_14 = (undefined1  [2])
                   CONCAT11(DAT_2001db40,*(undefined1 *)(*(int *)&pGVar2->field_0x101c + 2));
        pGVar2 = __get_dashboard_state();
        _local_14 = CONCAT12(*(undefined1 *)(*(int *)&pGVar2->field_0x101c + 0xc),local_14);
        pGVar2 = __get_dashboard_state();
        if ((*(char *)(*(int *)&pGVar2->field_0x101c + 2) != '\n') &&
           (pGVar2 = __get_dashboard_state(), *(char *)(*(int *)&pGVar2->field_0x101c + 2) != '\v'))
        {
          uVar3 = extraout_r2_03;
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              pGVar2 = __get_dashboard_state();
              bVar1 = *(byte *)(*(int *)&pGVar2->field_0x101c + 2);
              pGVar2 = __get_dashboard_state();
              printk("%s(): SYNC onboarding action_cmd %d and sub_step %d to slave\n",
                     "ui_onboarding_task",(uint)bVar1,
                     (uint)*(byte *)(*(int *)&pGVar2->field_0x101c + 3));
              uVar3 = extraout_r2_05;
            }
            else {
              pGVar2 = __get_dashboard_state();
              bVar1 = *(byte *)(*(int *)&pGVar2->field_0x101c + 2);
              pGVar2 = __get_dashboard_state();
              ble_printk("%s(): SYNC onboarding action_cmd %d and sub_step %d to slave\n",
                         "ui_onboarding_task",(uint)bVar1,
                         (uint)*(byte *)(*(int *)&pGVar2->field_0x101c + 3));
              uVar3 = extraout_r2_04;
            }
          }
          onboarding_sync_data(local_14,3,uVar3);
        }
        thunk_FUN_00045444();
        FUN_00042830();
        uVar5 = FUN_00080976();
        pGVar2 = __get_dashboard_state();
        *(undefined8 *)(*(int *)&pGVar2->field_0x101c + 4) = uVar5;
        pGVar2 = __get_dashboard_state();
        iVar4 = *(int *)&pGVar2->field_0x101c;
        pGVar2 = __get_dashboard_state();
        pGVar2->field_0xcd = *(undefined1 *)(iVar4 + 3);
      }
    }
  }
  return 0;
}


