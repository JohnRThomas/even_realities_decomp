/*
 * Function: aging_charge_test
 * Entry:    00034000
 * Prototype: undefined __stdcall aging_charge_test(uint param_1)
 */


void aging_charge_test(uint param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  GlassesState *pGVar5;
  uint extraout_r1;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  undefined8 uVar11;
  longlong lVar12;
  
  if (DAT_2001abc0 == '\x01') {
    uVar11 = FUN_00080638();
    pGVar5 = __get_dashboard_state();
    iVar9 = *(int *)&pGVar5->field_0x10ac;
    pGVar5 = __get_dashboard_state();
    uVar11 = __aeabi_ldivmod((uint)uVar11,(uint)((ulonglong)uVar11 >> 0x20),1000,0);
    pGVar5->field2819_0x10b0 = (int)uVar11 - iVar9;
    pGVar5 = __get_dashboard_state();
    if ((uint)pGVar5->field2819_0x10b0 < 0x385) {
      pGVar5 = __get_dashboard_state();
      uVar6 = 0x3c;
      uVar7 = pGVar5->field2819_0x10b0;
    }
    else {
      pGVar5 = __get_dashboard_state();
      uVar6 = 900;
      uVar7 = pGVar5->field2819_0x10b0;
    }
    if (DAT_2001abc1 == '\x01') {
      pGVar5 = __get_dashboard_state();
      if ((299 < (uint)pGVar5->field2819_0x10b0) &&
         ((((pGVar5 = __get_dashboard_state(), (pGVar5->jdb_panel_context).__initialized == 1 ||
            (pGVar5 = __get_dashboard_state(), pGVar5->field_0xd5 == '\x03')) ||
           (pGVar5 = __get_dashboard_state(), pGVar5->field_0xfea == '\0')) || (DAT_2000a9ac != 0)))
         ) {
        __enter_silent_mode();
      }
      pGVar5 = __get_dashboard_state();
      if (0x60 < (byte)pGVar5->field_0xfc4) {
        DAT_2001abc1 = '\x02';
        pGVar5 = __get_dashboard_state();
        (pGVar5->jdb_panel_context).field834_0x369 = 0x15;
        pGVar5 = __get_dashboard_state();
        set_brightness_to_panel_reg_in_running
                  ((uint)(pGVar5->jdb_panel_context).field834_0x369,extraout_r1);
        uVar11 = FUN_00080638();
        DAT_2000493c = (int)((ulonglong)uVar11 >> 0x20);
        DAT_20004938 = (uint)uVar11;
        uVar11 = FUN_00080638();
        pGVar5 = __get_dashboard_state();
        iVar9 = *(int *)&pGVar5->field_0x10ac;
        pGVar5 = __get_dashboard_state();
        uVar11 = __aeabi_ldivmod((uint)uVar11,(uint)((ulonglong)uVar11 >> 0x20),1000,0);
        pGVar5->field2820_0x10b4 = (int)uVar11 - iVar9;
        goto LAB_000340fe;
      }
    }
    else if (DAT_2001abc1 == '\x02') {
      pGVar5 = __get_dashboard_state();
      if ((((pGVar5->jdb_panel_context).__initialized != 1) ||
          (pGVar5 = __get_dashboard_state(), pGVar5->field_0xd5 != '\x03')) ||
         ((pGVar5 = __get_dashboard_state(), pGVar5->field_0xfea == '\x01' || (DAT_2000a9ac == 0))))
      {
        __exit_silent_mode();
      }
      pGVar5 = __get_dashboard_state();
      if ((byte)pGVar5->field_0xfc4 < 0x47) {
        lVar12 = FUN_00080638();
        lVar12 = lVar12 - CONCAT44(DAT_2000493c,DAT_20004938);
        uVar11 = __aeabi_ldivmod((uint)lVar12,(uint)((ulonglong)lVar12 >> 0x20),1000,0);
        iVar9 = (int)uVar11;
        iVar8 = 0;
        do {
          pGVar5 = __get_dashboard_state();
          iVar4 = iVar8 * 2;
          iVar8 = iVar8 + 1;
          iVar9 = iVar9 - (uint)*(ushort *)(pGVar5->field2780_0x1080 + iVar4 + 0x3c);
        } while (iVar8 != 5);
        pGVar5 = __get_dashboard_state();
        *(short *)((int)&pGVar5->field2824_0x10c4 + 2) = (short)iVar9;
        uVar11 = FUN_00080638();
        iVar9 = (int)((ulonglong)uVar11 >> 0x20);
        bVar10 = DAT_20004938 < (uint)uVar11;
        if ((int)((DAT_2000493c - iVar9) - (uint)bVar10) < 0 ==
            (SBORROW4(DAT_2000493c,iVar9) != SBORROW4(DAT_2000493c - iVar9,(uint)bVar10))) {
          if (0 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): Err:current time is smaller than the discharge test start time!\n");
            }
            else {
              ble_printk("%s(): Err:current time is smaller than the discharge test start time!\n",
                         "aging_charge_test",DAT_20004938,BLE_DEBUG);
            }
          }
        }
        else {
          lVar12 = FUN_00080638();
          lVar12 = lVar12 - CONCAT44(DAT_2000493c,DAT_20004938);
          uVar11 = __aeabi_ldivmod((uint)lVar12,(uint)((ulonglong)lVar12 >> 0x20),1000,0);
          pGVar5 = __get_dashboard_state();
          pGVar5->field2821_0x10b8 = (int)uVar11;
        }
        DAT_2001abc1 = '\0';
        goto LAB_000340fe;
      }
      pGVar5 = __get_dashboard_state();
      if (((byte)pGVar5->field_0xfc4 < 0x4c) &&
         (pGVar5 = __get_dashboard_state(), *(short *)&pGVar5->field2824_0x10c4 == 0)) {
        lVar12 = FUN_00080638();
        lVar12 = lVar12 - CONCAT44(DAT_2000493c,DAT_20004938);
        uVar11 = __aeabi_ldivmod((uint)lVar12,(uint)((ulonglong)lVar12 >> 0x20),1000,0);
        iVar8 = (int)uVar11;
        iVar9 = 0;
        do {
          pGVar5 = __get_dashboard_state();
          iVar4 = iVar9 * 2;
          iVar9 = iVar9 + 1;
          iVar8 = iVar8 - (uint)*(ushort *)(pGVar5->field2780_0x1080 + iVar4 + 0x3c);
        } while (iVar9 != 4);
        pGVar5 = __get_dashboard_state();
        *(short *)&pGVar5->field2824_0x10c4 = (short)iVar8;
        goto LAB_000340fe;
      }
      pGVar5 = __get_dashboard_state();
      if (((byte)pGVar5->field_0xfc4 < 0x51) &&
         (pGVar5 = __get_dashboard_state(), *(short *)((int)&pGVar5->field2823_0x10c0 + 2) == 0)) {
        lVar12 = FUN_00080638();
        lVar12 = lVar12 - CONCAT44(DAT_2000493c,DAT_20004938);
        uVar11 = __aeabi_ldivmod((uint)lVar12,(uint)((ulonglong)lVar12 >> 0x20),1000,0);
        pGVar5 = __get_dashboard_state();
        sVar1 = *(short *)&pGVar5->field2822_0x10bc;
        pGVar5 = __get_dashboard_state();
        sVar2 = *(short *)((int)&pGVar5->field2822_0x10bc + 2);
        pGVar5 = __get_dashboard_state();
        sVar3 = *(short *)&pGVar5->field2823_0x10c0;
        pGVar5 = __get_dashboard_state();
        *(short *)((int)&pGVar5->field2823_0x10c0 + 2) = (((short)uVar11 - sVar1) - sVar2) - sVar3;
        goto LAB_000340fe;
      }
      pGVar5 = __get_dashboard_state();
      if (((byte)pGVar5->field_0xfc4 < 0x56) &&
         (pGVar5 = __get_dashboard_state(), *(short *)&pGVar5->field2823_0x10c0 == 0)) {
        lVar12 = FUN_00080638();
        lVar12 = lVar12 - CONCAT44(DAT_2000493c,DAT_20004938);
        uVar11 = __aeabi_ldivmod((uint)lVar12,(uint)((ulonglong)lVar12 >> 0x20),1000,0);
        pGVar5 = __get_dashboard_state();
        sVar1 = *(short *)&pGVar5->field2822_0x10bc;
        pGVar5 = __get_dashboard_state();
        sVar2 = *(short *)((int)&pGVar5->field2822_0x10bc + 2);
        pGVar5 = __get_dashboard_state();
        *(short *)&pGVar5->field2823_0x10c0 = ((short)uVar11 - sVar1) - sVar2;
        goto LAB_000340fe;
      }
      pGVar5 = __get_dashboard_state();
      if (((byte)pGVar5->field_0xfc4 < 0x5b) &&
         (pGVar5 = __get_dashboard_state(), *(short *)((int)&pGVar5->field2822_0x10bc + 2) == 0)) {
        lVar12 = FUN_00080638();
        lVar12 = lVar12 - CONCAT44(DAT_2000493c,DAT_20004938);
        uVar11 = __aeabi_ldivmod((uint)lVar12,(uint)((ulonglong)lVar12 >> 0x20),1000,0);
        pGVar5 = __get_dashboard_state();
        sVar1 = *(short *)&pGVar5->field2822_0x10bc;
        pGVar5 = __get_dashboard_state();
        *(short *)((int)&pGVar5->field2822_0x10bc + 2) = (short)uVar11 - sVar1;
        goto LAB_000340fe;
      }
      pGVar5 = __get_dashboard_state();
      if (((byte)pGVar5->field_0xfc4 < 0x60) &&
         (pGVar5 = __get_dashboard_state(), *(short *)&pGVar5->field2822_0x10bc == 0)) {
        lVar12 = FUN_00080638();
        lVar12 = lVar12 - CONCAT44(DAT_2000493c,DAT_20004938);
        uVar11 = __aeabi_ldivmod((uint)lVar12,(uint)((ulonglong)lVar12 >> 0x20),1000,0);
        pGVar5 = __get_dashboard_state();
        *(short *)&pGVar5->field2822_0x10bc = (short)uVar11;
        goto LAB_000340fe;
      }
    }
    else {
      pGVar5 = __get_dashboard_state();
      if (((((pGVar5->jdb_panel_context).__initialized != 1) ||
           (pGVar5 = __get_dashboard_state(), pGVar5->field_0xd5 != '\x03')) ||
          (pGVar5 = __get_dashboard_state(), pGVar5->field_0xfea == '\x01')) || (DAT_2000a9ac == 0))
      {
        __exit_silent_mode();
      }
    }
    if (uVar7 - uVar6 * (uVar7 / uVar6) < param_1) {
LAB_000340fe:
      pGVar5 = __get_dashboard_state();
      __save_sys_settings(pGVar5);
      return;
    }
  }
  return;
}


