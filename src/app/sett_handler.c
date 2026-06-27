/*
 * Function: sett_handler
 * Entry:    000241d4
 * Prototype: int __stdcall sett_handler(char * param_1, undefined4 param_2, undefined * param_3, undefined4 param_4)
 */


int sett_handler(char *param_1,undefined4 param_2,undefined *param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 *puVar2;
  GlassesState *pGVar3;
  undefined4 uVar4;
  global_state_struct_0FF0 *pgVar5;
  uint uVar6;
  
  iVar1 = strcmp(param_1,"ble_whitelist_app");
  if (iVar1 == 0) {
    puVar2 = FUN_00036268();
    uVar4 = 0x15e2;
LAB_000241ee:
    iVar1 = (*(code *)param_3)(param_4,puVar2,uVar4);
    if (-1 < iVar1) {
      return 0;
    }
LAB_0002422c:
    if (LOG_LEVEL < 2) {
      return iVar1;
    }
    if (BLE_DEBUG == 0) {
      printk("%s(): Failed to read %s, error: %d\n","sett_handler",param_1,iVar1);
      return iVar1;
    }
    ble_printk("%s(): Failed to read %s, error: %d\n","sett_handler",param_1,iVar1);
    return iVar1;
  }
  iVar1 = strcmp(param_1,"dashboard_ts");
  if (iVar1 == 0) {
    pGVar3 = __get_dashboard_state();
    if (pGVar3->glasses_state_struct_0FF0 == (global_state_struct_0FF0 *)0x0) {
      return 0;
    }
    pGVar3 = __get_dashboard_state();
    iVar1 = (*(code *)param_3)(param_4,pGVar3->glasses_state_struct_0FF0,0x75);
    if (iVar1 < 0) goto LAB_0002422c;
    if (LOG_LEVEL < 3) {
      return 0;
    }
    if (BLE_DEBUG == 0) {
      pGVar3 = __get_dashboard_state();
      pgVar5 = pGVar3->glasses_state_struct_0FF0;
LAB_00024270:
      uVar6 = *(uint *)pgVar5;
LAB_00024272:
      printk("%s(): key:%s, val=%d\n","sett_handler",param_1,uVar6);
      return 0;
    }
    pGVar3 = __get_dashboard_state();
    pgVar5 = pGVar3->glasses_state_struct_0FF0;
  }
  else {
    iVar1 = strcmp(param_1,"countdown_ts");
    if (iVar1 != 0) {
      iVar1 = strcmp(param_1,"first_enter_flag");
      if (iVar1 == 0) {
        pGVar3 = __get_dashboard_state();
        iVar1 = (*(code *)param_3)(param_4,&pGVar3->field_0x1064);
        if (iVar1 < 0) goto LAB_0002422c;
        if (LOG_LEVEL < 3) {
          return 0;
        }
        if (BLE_DEBUG != 0) {
          pGVar3 = __get_dashboard_state();
          uVar6 = *(uint *)&pGVar3->field_0x1064;
          goto LAB_0002425c;
        }
        pGVar3 = __get_dashboard_state();
        uVar6 = *(uint *)&pGVar3->field_0x1064;
        goto LAB_00024272;
      }
      iVar1 = strcmp(param_1,"brightness_level");
      if (iVar1 == 0) {
        pGVar3 = __get_dashboard_state();
        iVar1 = (*(code *)param_3)(param_4,&(pGVar3->jdb_panel_context).field834_0x369,1);
        if (iVar1 < 0) goto LAB_0002422c;
        if (LOG_LEVEL < 3) {
          return 0;
        }
        if (BLE_DEBUG == 0) {
          pGVar3 = __get_dashboard_state();
          uVar6 = (uint)(pGVar3->jdb_panel_context).field834_0x369;
          goto LAB_00024272;
        }
        pGVar3 = __get_dashboard_state();
        uVar6 = (uint)(pGVar3->jdb_panel_context).field834_0x369;
        goto LAB_0002425c;
      }
      iVar1 = strcmp(param_1,"3dof_enable");
      if (iVar1 == 0) {
        pGVar3 = __get_dashboard_state();
        iVar1 = (*(code *)param_3)(param_4,&(pGVar3->imu_fusion_context).field_0x7c,1);
        if (iVar1 < 0) goto LAB_0002422c;
        if (LOG_LEVEL < 3) {
          return 0;
        }
        if (BLE_DEBUG == 0) {
          pGVar3 = __get_dashboard_state();
          uVar6 = (uint)(byte)(pGVar3->imu_fusion_context).field_0x7c;
          goto LAB_00024272;
        }
        pGVar3 = __get_dashboard_state();
        uVar6 = (uint)(byte)(pGVar3->imu_fusion_context).field_0x7c;
        goto LAB_0002425c;
      }
      iVar1 = strcmp(param_1,"display_mode");
      if (iVar1 == 0) {
        pGVar3 = __get_dashboard_state();
        iVar1 = (*(code *)param_3)(param_4,&pGVar3->field_0xfee,1);
        if (iVar1 < 0) goto LAB_0002422c;
        if (LOG_LEVEL < 3) {
          return 0;
        }
        if (BLE_DEBUG == 0) {
          pGVar3 = __get_dashboard_state();
          uVar6 = (uint)(byte)pGVar3->field_0xfee;
          goto LAB_00024272;
        }
        pGVar3 = __get_dashboard_state();
        uVar6 = (uint)(byte)pGVar3->field_0xfee;
        goto LAB_0002425c;
      }
      iVar1 = strcmp(param_1,"runtime_mode");
      if (iVar1 == 0) {
        pGVar3 = __get_dashboard_state();
        iVar1 = (*(code *)param_3)(param_4,&pGVar3->field_0x1);
        if (iVar1 < 0) goto LAB_0002422c;
        if (LOG_LEVEL < 3) {
          return 0;
        }
        if (BLE_DEBUG == 0) {
          pGVar3 = __get_dashboard_state();
          uVar6 = (uint)(byte)pGVar3->field_0x1;
          goto LAB_00024272;
        }
        pGVar3 = __get_dashboard_state();
        uVar6 = (uint)(byte)pGVar3->field_0x1;
        goto LAB_0002425c;
      }
      iVar1 = strcmp(param_1,"user_sched_info");
      if (iVar1 != 0) {
        iVar1 = strcmp(param_1,"wakeup_angle");
        if (iVar1 != 0) {
          return 0;
        }
        pGVar3 = __get_dashboard_state();
        iVar1 = (*(code *)param_3)(param_4,&(pGVar3->imu_fusion_context).field_0x10,1);
        if (iVar1 < 0) goto LAB_0002422c;
        if (LOG_LEVEL < 3) {
          return 0;
        }
        if (BLE_DEBUG == 0) {
          pGVar3 = __get_dashboard_state();
          uVar6 = (uint)(byte)(pGVar3->imu_fusion_context).field_0x10;
          goto LAB_00024272;
        }
        pGVar3 = __get_dashboard_state();
        uVar6 = (uint)(byte)(pGVar3->imu_fusion_context).field_0x10;
        goto LAB_0002425c;
      }
      pGVar3 = __get_dashboard_state();
      if (*(int *)&pGVar3->field_0xff8 == 0) {
        return 0;
      }
      pGVar3 = __get_dashboard_state();
      uVar4 = 0x16a;
      puVar2 = *(undefined1 **)&pGVar3->field_0xff8;
      goto LAB_000241ee;
    }
    pGVar3 = __get_dashboard_state();
    if (pGVar3->glasses_state_struct_0FF4 == (global_state_struct_0FF4 *)0x0) {
      return 0;
    }
    pGVar3 = __get_dashboard_state();
    iVar1 = (*(code *)param_3)(param_4,pGVar3->glasses_state_struct_0FF4,7);
    if (iVar1 < 0) goto LAB_0002422c;
    if (LOG_LEVEL < 3) {
      return 0;
    }
    if (BLE_DEBUG == 0) {
      pGVar3 = __get_dashboard_state();
      pgVar5 = (global_state_struct_0FF0 *)pGVar3->glasses_state_struct_0FF4;
      goto LAB_00024270;
    }
    pGVar3 = __get_dashboard_state();
    pgVar5 = (global_state_struct_0FF0 *)pGVar3->glasses_state_struct_0FF4;
  }
  uVar6 = *(uint *)pgVar5;
LAB_0002425c:
  ble_printk("%s(): key:%s, val=%d\n","sett_handler",param_1,uVar6);
  return 0;
}


