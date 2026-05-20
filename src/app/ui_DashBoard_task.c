/*
 * Function: ui_DashBoard_task
 * Entry:    0003d4b8
 * Prototype: undefined4 __stdcall ui_DashBoard_task(undefined4 param_1, uint param_2)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ui_DashBoard_task(undefined4 param_1,uint param_2)

{
  longlong lVar1;
  char cVar2;
  undefined1 uVar3;
  byte bVar4;
  int iVar5;
  char *fmt;
  GlassesState *pGVar6;
  undefined4 extraout_r1;
  undefined4 uVar7;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 uVar8;
  uint uVar9;
  undefined4 extraout_r3;
  global_state_struct_0FF0 *pgVar10;
  uint uVar11;
  uint uVar12;
  int *unaff_r6;
  int unaff_r8;
  int unaff_r9;
  ulonglong uVar13;
  undefined8 uVar14;
  
  uVar9 = 0xc;
  bVar4 = 0;
  uVar11 = (uint)unaff_r6 & 0xff;
  if (param_2 == 0) {
LAB_0003d534:
    cVar2 = bVar4 - (char)uVar9 * (char)(bVar4 / uVar9);
    DAT_2001c4e6 = cVar2;
    *(char *)(uVar11 + 1) = cVar2;
    FUN_000167cc(cVar2);
LAB_0003d54a:
    if (2 < *unaff_r6) {
      uVar9 = (uint)*(byte *)(uVar11 + 1);
      fmt = "%s(): current quicknote index = %d\n";
LAB_0003d55a:
      if (BLE_DEBUG == 0) {
        printk(fmt);
      }
      else {
        ble_printk(fmt,"ui_DashBoard_task",uVar9,BLE_DEBUG);
      }
    }
  }
  else {
    _Reserved3 = 0;
    if ((param_2 & 0xffff) == 0) goto LAB_0003d54a;
    if (unaff_r9 != 4) {
      if (unaff_r9 == 6) {
        if (2 < *unaff_r6) {
          if (BLE_DEBUG == 0) {
            printk("%s(): received system low power event.\n");
          }
          else {
            ble_printk("%s(): received system low power event.\n","ui_DashBoard_task",param_2,
                       BLE_DEBUG);
          }
        }
        pGVar6 = __get_dashboard_state();
        uVar8 = 1;
        pgVar10 = pGVar6->glasses_state_struct_0FF0;
        uVar7 = extraout_r1;
      }
      else {
        if (unaff_r9 != 7) goto LAB_0003d43e;
        if (2 < *unaff_r6) {
          if (BLE_DEBUG == 0) {
            printk("%s(): received system  power resume event.\n");
          }
          else {
            ble_printk("%s(): received system  power resume event.\n","ui_DashBoard_task",param_2,
                       BLE_DEBUG);
          }
        }
        pGVar6 = __get_dashboard_state();
        uVar8 = 0;
        pgVar10 = pGVar6->glasses_state_struct_0FF0;
        uVar7 = extraout_r1_00;
      }
      pgVar10->field_0x60 = (char)uVar8;
      __send_message_count_to_app(pGVar6,uVar7,uVar8,pgVar10);
      goto LAB_0003d43e;
    }
    if (0 < *unaff_r6) {
      if (BLE_DEBUG == 0) {
        printk("%s(): received key press event,_dashboard_prv_data.display_mode = %d\n");
      }
      else {
        ble_printk("%s(): received key press event,_dashboard_prv_data.display_mode = %d\n",
                   "ui_DashBoard_task",(uint)*(byte *)(uVar11 + 0x19),BLE_DEBUG);
      }
    }
    uVar9 = (uint)*(byte *)(uVar11 + 0x1a);
    if (0 < *unaff_r6) {
      if (BLE_DEBUG == 0) {
        printk("%s(): _CurrentCustomAreaType = %d\n");
      }
      else {
        ble_printk("%s(): _CurrentCustomAreaType = %d\n",_dmic_record_start,uVar9,BLE_DEBUG);
      }
    }
    if (uVar9 != 0) {
      if (uVar9 != 1) {
        if (uVar9 == 2) {
          uVar9 = (uint)*(byte *)(uVar11 + 6);
          if ((1 < uVar9) && (*(char *)(uVar11 + 5) != '\x03')) {
            uVar12 = (uint)(byte)(*(char *)(uVar11 + 5) + 1);
            uVar12 = uVar12 - uVar9 * (uVar12 / uVar9);
            uVar9 = uVar12 & 0xff;
            DAT_2001c4e4 = (undefined1)uVar12;
            iVar5 = *unaff_r6;
            *(undefined1 *)(uVar11 + 5) = DAT_2001c4e4;
            if (2 < iVar5) {
              fmt = "%s(): current news index = %d\n";
              goto LAB_0003d55a;
            }
          }
        }
        else if (uVar9 == 3) {
          uVar9 = (uint)*(byte *)(uVar11 + 9);
          if (uVar9 != 0) {
            uVar12 = (uint)(byte)(*(char *)(uVar11 + 8) + 1);
            uVar12 = uVar12 - uVar9 * (uVar12 / uVar9);
            uVar9 = uVar12 & 0xff;
            DAT_2001c4e3 = (undefined1)uVar12;
            iVar5 = *unaff_r6;
            *(undefined1 *)(uVar11 + 8) = DAT_2001c4e3;
            if (0 < iVar5) {
              fmt = "%s(): current calendar index = %d\n";
              goto LAB_0003d55a;
            }
          }
        }
        else if (uVar9 == 4) goto LAB_0003d43e;
        goto LAB_0003d562;
      }
      uVar9 = (uint)*(byte *)(uVar11 + 4);
      if (uVar9 < 2) goto LAB_0003d562;
      uVar12 = (uint)(byte)(*(char *)(uVar11 + 3) + 1);
      uVar12 = uVar12 - uVar9 * (uVar12 / uVar9);
      uVar9 = uVar12 & 0xff;
      DAT_2001c4e5 = (undefined1)uVar12;
      iVar5 = *unaff_r6;
      *(undefined1 *)(uVar11 + 3) = DAT_2001c4e5;
      if (iVar5 < 3) goto LAB_0003d562;
      fmt = "%s(): current stocks index = %d\n";
      goto LAB_0003d55a;
    }
    uVar9 = (uint)*(byte *)(uVar11 + 2);
    if (1 < uVar9) {
      bVar4 = *(char *)(uVar11 + 1) + 1;
      goto LAB_0003d534;
    }
  }
LAB_0003d562:
  pGVar6 = __get_dashboard_state();
  uVar14 = DashBoard_Reflash(unaff_r8,(int)pGVar6,4,(uint)*(byte *)((char)param_2 + 0x154));
  sync_dashboard_key_event_to_app
            ((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),extraout_r2,extraout_r3);
LAB_0003d43e:
  pGVar6 = __get_dashboard_state();
  if (*(char *)pGVar6 == '\x01') {
    iVar5 = FUN_00080756();
    uVar13 = sys_clock_tick_get();
    lVar1 = (uVar13 & 0xffffffff) * 1000;
    uVar12 = (int)(uVar13 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20);
    uVar9 = (uint)lVar1 >> 0xf | uVar12 * 0x20000;
    uVar12 = uVar12 >> 0xf;
    if (iVar5 == 0) {
      pGVar6 = __get_dashboard_state();
      if (pGVar6->glasses_state_struct_0FF0->field_0x60 != '\0') {
        if (*(char *)(uVar11 + 0xe) != '\0') {
          return 0;
        }
        if ((int)((uVar12 - *(int *)(uVar11 + 0x14)) - (uint)(uVar9 < *(uint *)(uVar11 + 0x10))) <
            (int)(uint)(uVar9 - *(uint *)(uVar11 + 0x10) < 0x5dd)) {
          return 0;
        }
      }
      uVar3 = 1;
    }
    else {
      pGVar6 = __get_dashboard_state();
      if (pGVar6->glasses_state_struct_0FF0->field_0x60 != '\x01') {
        if (*(char *)(uVar11 + 0xe) != '\0') {
          return 0;
        }
        if ((int)((uVar12 - *(int *)(uVar11 + 0x14)) - (uint)(uVar9 < *(uint *)(uVar11 + 0x10))) <
            (int)(uint)(uVar9 - *(uint *)(uVar11 + 0x10) < 0x5dd)) {
          return 0;
        }
      }
      uVar3 = 0;
    }
    SendPowerInfoToSlave(uVar3);
    *(undefined1 *)(uVar11 + 0xe) = 1;
  }
                    /* WARNING: Read-only address (ram,0x0003d6e8) is written */
                    /* WARNING: Read-only address (ram,0x0003d6ec) is written */
  return 0;
}


