/*
 * Function: onboarding_ble_process
 * Entry:    00044b90
 * Prototype: undefined4 __stdcall onboarding_ble_process(int param_1, int param_2, undefined2 * param_3, undefined2 * param_4)
 */


undefined4 onboarding_ble_process(int param_1,int param_2,undefined2 *param_3,undefined2 *param_4)

{
  undefined1 uVar1;
  bool bVar2;
  GlassesState *pGVar3;
  GlassesState *pGVar4;
  char *pcVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  
  if (0x17 < *(byte *)((int)param_3 + 1)) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): ble rcv unknown onboarding action:%d\n");
      }
      else {
        ble_printk("%s(): ble rcv unknown onboarding action:%d\n","onboarding_ble_process",
                   (uint)*(byte *)((int)param_3 + 1),BLE_DEBUG,param_4);
      }
    }
    uVar8 = 3;
    *param_4 = *param_3;
    *(undefined1 *)(param_4 + 1) = 0xca;
    uVar9 = CONCAT44(DAT_20004db4,DAT_20004db0);
    goto LAB_00044bc2;
  }
  DAT_20004da8 = 0;
  uVar9 = FUN_00080976();
  DAT_20004db4 = (undefined4)((ulonglong)uVar9 >> 0x20);
  DAT_20004db0 = (undefined4)uVar9;
  if (*(char *)((int)param_3 + 1) == '\x12') goto LAB_00044c52;
  FUN_00042830();
  **(undefined1 **)(param_1 + 0x101c) = 1;
  uVar9 = FUN_00080976();
  *(undefined8 *)(*(int *)(param_1 + 0x101c) + 4) = uVar9;
  *(undefined1 *)(*(int *)(param_1 + 0x101c) + 2) = *(undefined1 *)((int)param_3 + 1);
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): ble rcv onboarding action:%d\n");
    }
    else {
      ble_printk("%s(): ble rcv onboarding action:%d\n","onboarding_ble_process",
                 (uint)*(byte *)(*(int *)(param_1 + 0x101c) + 2),BLE_DEBUG);
    }
  }
  puVar6 = *(undefined1 **)(param_1 + 0x101c);
  switch(puVar6[2]) {
  case 1:
    puVar6[1] = 1;
    puVar6 = *(undefined1 **)(param_1 + 0x101c);
    pcVar5 = "1/6";
    goto LAB_00044c48;
  case 2:
    pcVar5 = "6/6";
    goto LAB_00044c48;
  case 3:
    *(char (*) [4])(puVar6 + 0x1b) = (char  [4])0x362f34;
    DAT_2001db41 = 0;
    DAT_2001db40 = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x101c) + 3) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x101c) + 0xd) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x101c) + 0xe) = 0;
    iVar7 = *(int *)(param_1 + 0x101c);
    *(undefined1 *)(iVar7 + 0xf) = 0;
    *(undefined1 *)(iVar7 + 0x10) = 0;
    *(undefined1 *)(iVar7 + 0x11) = 0;
    *(undefined1 *)(iVar7 + 0x12) = 0;
    iVar7 = *(int *)(param_1 + 0x101c);
    *(undefined1 *)(iVar7 + 0x13) = 0;
    *(undefined1 *)(iVar7 + 0x14) = 0;
    *(undefined1 *)(iVar7 + 0x15) = 0;
    *(undefined1 *)(iVar7 + 0x16) = 0;
    iVar7 = *(int *)(param_1 + 0x101c);
    *(undefined1 *)(iVar7 + 0x17) = 0;
    *(undefined1 *)(iVar7 + 0x18) = 0;
    *(undefined1 *)(iVar7 + 0x19) = 0;
    *(undefined1 *)(iVar7 + 0x1a) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x101c) + 0xc) = 0;
    break;
  case 4:
  case 5:
  case 6:
    *(char (*) [4])(puVar6 + 0x1b) = (char  [4])0x362f33;
    DAT_2001db44 = 0;
    DAT_2001db40 = 0;
    pGVar3 = __get_dashboard_state();
    *(undefined1 *)(*(int *)(param_1 + 0x101c) + 3) = *(undefined1 *)&pGVar3->imu_fusion_context;
    if (*(char *)(*(int *)(param_1 + 0x101c) + 2) == '\x06') {
      *(undefined1 *)(*(int *)(param_1 + 0x101c) + 0x1f) = 0;
    }
    break;
  case 7:
    pcVar5 = "5/6";
    goto LAB_00044c48;
  case 8:
  case 9:
    pcVar5 = "3/6";
    goto LAB_00044c48;
  case 10:
  case 0xb:
    *puVar6 = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x101c) + 1) = 0;
    break;
  case 0xc:
    puVar6[1] = 1;
    puVar6 = *(undefined1 **)(param_1 + 0x101c);
    pcVar5 = "2/6";
LAB_00044c48:
    *(undefined4 *)(puVar6 + 0x1b) = *(undefined4 *)pcVar5;
    break;
  case 0xf:
  case 0x11:
    pGVar3 = __get_dashboard_state();
    pGVar4 = __get_dashboard_state();
    *(undefined1 *)(*(int *)&pGVar4->field_0x101c + 3) = *(undefined1 *)&pGVar3->imu_fusion_context;
  }
  thunk_FUN_00045444();
  uVar9 = CONCAT44(DAT_20004db4,DAT_20004db0);
LAB_00044c52:
  DAT_20004db4 = (undefined4)((ulonglong)uVar9 >> 0x20);
  DAT_20004db0 = (undefined4)uVar9;
  if (*(short *)(param_2 + 2) == 2) {
    uVar8 = 3;
    *param_4 = *param_3;
    *(undefined1 *)(param_4 + 1) = 0xc9;
    uVar9 = CONCAT44(DAT_20004db4,DAT_20004db0);
  }
  else if (*(short *)(param_2 + 2) == 3) {
    *param_4 = *param_3;
    *(undefined1 *)(param_4 + 1) = 0xc9;
    uVar1 = *(undefined1 *)(param_3 + 1);
    *(undefined1 *)((int)param_4 + 3) = uVar1;
    if (**(char **)(param_1 + 0x101c) != '\0') {
      *(undefined1 *)(param_1 + 0xcd) = uVar1;
    }
    uVar9 = CONCAT44(DAT_20004db4,DAT_20004db0);
    uVar8 = 4;
  }
  else {
    uVar8 = 0;
  }
  DAT_20004db4 = (undefined4)((ulonglong)uVar9 >> 0x20);
  DAT_20004db0 = (undefined4)uVar9;
  if (*(char *)((int)param_3 + 1) != '\x12') {
    pGVar3 = __get_dashboard_state();
    uVar9 = CONCAT44(DAT_20004db4,DAT_20004db0);
    if (*(int *)pGVar3->___glasses_state != 0xe) {
      bVar2 = is_in_box();
      uVar9 = CONCAT44(DAT_20004db4,DAT_20004db0);
      if (!bVar2) {
        pGVar3 = __get_dashboard_state();
        update_persist_task_status((int)pGVar3,0xe,2);
        pGVar3 = __get_dashboard_state();
        pGVar4 = __get_dashboard_state();
        *(byte *)(*(int *)&pGVar4->field_0x101c + 0x20) =
             (pGVar3->jdb_panel_context).panel_brightness_level;
        pGVar3 = __get_dashboard_state();
        (pGVar3->jdb_panel_context).panel_brightness_level = 0x2a;
        uVar9 = CONCAT44(DAT_20004db4,DAT_20004db0);
      }
    }
  }
LAB_00044bc2:
  DAT_20004db4 = (undefined4)((ulonglong)uVar9 >> 0x20);
  DAT_20004db0 = (undefined4)uVar9;
  return uVar8;
}


