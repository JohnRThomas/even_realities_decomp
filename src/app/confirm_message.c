/*
 * Function: confirm_message
 * Entry:    00035b54
 * Prototype: undefined __stdcall confirm_message(int param_1)
 */


void confirm_message(int param_1)

{
  bool bVar1;
  byte bVar2;
  GlassesState *pGVar3;
  int iVar4;
  uint uVar5;
  void *pvVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  undefined4 extraout_r1_04;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 *puVar10;
  int iVar11;
  uint uVar12;
  undefined8 uVar13;
  undefined1 *puVar9;
  
  iVar11 = DAT_2000989c;
  if (DAT_200098a4 == '\0') {
    return;
  }
  if (DAT_2000989c != param_1) {
    return;
  }
  if (DAT_200098a1 != '\x04') {
    return;
  }
  uVar12 = DAT_20009a44 & 0xff;
  pGVar3 = __get_dashboard_state();
  if (((pGVar3->is_master == true) && (uVar12 == 0)) &&
     (iVar4 = FUN_0003555c(10,iVar11), iVar4 != 0)) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): add found same message, uidtail %d\n","confirm_message",iVar11);
      }
      else {
        ble_printk("%s(): add found same message, uidtail %d\n");
      }
    }
    memset(&DAT_20009894,0,0x1b4);
    return;
  }
  DAT_20019a5c = 1;
  pGVar3 = __get_dashboard_state();
  if (pGVar3->field20_0xc8[0xd] != '\x04') {
    clear_timeout_message(0);
  }
  pGVar3 = __get_dashboard_state();
  if ((pGVar3->field_0x10d6 != '\0') &&
     (pGVar3 = __get_dashboard_state(), *(char *)&pGVar3->imu_fusion_context != '\x01')) {
    __get_dashboard_state();
  }
  uVar5 = FUN_000352f4();
  if (DAT_20009a44 == 0) {
    if (uVar5 == 10) {
      iVar11 = 0;
      puVar10 = &DAT_2000878c;
      do {
        pvVar6 = memcpy(puVar10,puVar10 + 0x6d,0x1b4);
        *(char *)((int)pvVar6 + 0xc) = (char)iVar11;
        iVar11 = iVar11 + 1;
        puVar10 = puVar10 + 0x6d;
      } while (iVar11 != 9);
      uVar5 = 9;
    }
    pvVar6 = memcpy(&DAT_2000878c + uVar5 * 0x6d,&DAT_20009894,0x1b4);
    iVar11 = (&DAT_2000878c)[uVar5 * 0x6d];
    *(char *)((int)pvVar6 + 0xc) = (char)uVar5;
    if (iVar11 == 0) {
      uVar7 = FUN_00080732();
      (&DAT_2000878c)[uVar5 * 0x6d] = uVar7;
    }
    (&DAT_2000879a)[uVar5 * 0x1b4] = 1;
    if ((&DAT_20008790)[uVar5 * 0x6d] != 0) {
      uVar7 = FUN_00080732();
      (&DAT_20008790)[uVar5 * 0x6d] = uVar7;
    }
  }
  else if (DAT_20009a44 == 2) {
    if (uVar5 != 0) {
      bVar1 = false;
      bVar2 = 0;
      puVar10 = &DAT_2000878c;
      do {
        if ((puVar10[2] == DAT_2000989c) || (bVar1)) {
          pvVar6 = memcpy(puVar10,puVar10 + 0x6d,0x1b4);
          bVar1 = true;
          *(byte *)((int)pvVar6 + 0xc) = bVar2;
        }
        bVar2 = bVar2 + 1;
        puVar10 = puVar10 + 0x6d;
      } while (bVar2 < uVar5);
      if (bVar1) {
        memset(&DAT_2000878c + (uVar5 - 1) * 0x6d,0,0x1b4);
      }
    }
  }
  else if ((DAT_20009a44 == 1) && (uVar5 != 0)) {
    puVar10 = &DAT_2000878c;
    uVar8 = 0;
    do {
      if (puVar10[2] == DAT_2000989c) {
        memcpy(&DAT_2000878c + uVar8 * 0x6d,&DAT_20009894,0x1b4);
        break;
      }
      uVar8 = uVar8 + 1;
      puVar10 = puVar10 + 0x6d;
    } while ((uVar8 & 0xff) < uVar5);
  }
  memset(&DAT_20009894,0,0x1b4);
  for (uVar5 = 10; uVar5 < APP_WHITE_LIST_BUF; uVar5 = uVar5 + 1 & 0xff) {
    if ((&DAT_20008950)[uVar5 * 0x1b4] == '\0') goto LAB_00035c9a;
    pvVar6 = memcpy(&DAT_2000878c + uVar5 * 0x6d,&DAT_20008940 + uVar5 * 0x6d,0x1b4);
    *(char *)((int)pvVar6 + 0xc) = (char)uVar5;
    *(undefined1 *)((int)pvVar6 + 0xd) = 0;
  }
  if (10 < APP_WHITE_LIST_BUF) {
LAB_00035c9a:
    APP_WHITE_LIST_BUF = APP_WHITE_LIST_BUF - 1;
  }
  memset(&DAT_2000878c + (uint)APP_WHITE_LIST_BUF * 0x6d,0,0x1b4);
  pGVar3 = __get_dashboard_state();
  if (pGVar3->field20_0xc8[0xd] == '\x04') {
    pGVar3 = __get_dashboard_state();
    uVar5 = FUN_00035310();
    uVar13 = CONCAT44(extraout_r1_00,uVar5);
    pGVar3->field20_0xc8[0x15] = (char)uVar5;
    uVar7 = extraout_r2_02;
  }
  else {
    uVar13 = clear_timeout_message(0);
    uVar7 = extraout_r2;
  }
  if (uVar12 == 0) {
    uVar12 = FUN_000352c4();
    pGVar3 = __get_dashboard_state();
    if (pGVar3->field20_0xc8[0xd] == '\x04') {
      uVar7 = extraout_r2_00;
      uVar13 = CONCAT44(extraout_r1,pGVar3);
      if (uVar12 != 0xff) {
        uVar13 = FUN_0002dd98();
        uVar7 = extraout_r2_01;
      }
    }
    else {
      bVar1 = is_in_box();
      uVar7 = extraout_r2_03;
      uVar13 = CONCAT44(extraout_r1_01,&DAT_00000001);
      if (!bVar1) {
        pGVar3 = __get_dashboard_state();
        if (pGVar3->field20_0xc8[0xd] != '\0') {
          pGVar3 = __get_dashboard_state();
          uVar13 = CONCAT44(extraout_r1_03,&pGVar3->field_0x1000);
          uVar7 = extraout_r2_05;
          if (pGVar3->field_0x10d6 == '\0') goto LAB_00035ce4;
          pGVar3 = __get_dashboard_state();
          uVar13 = CONCAT44(extraout_r1_04,pGVar3);
          uVar7 = extraout_r2_06;
          if (pGVar3->field20_0xc8[0xd] != '\x06') goto LAB_00035ce4;
        }
        bVar2 = FUN_00035acc();
        puVar9 = (undefined1 *)(uint)bVar2;
        uVar7 = extraout_r2_04;
        uVar13 = CONCAT44(extraout_r1_02,puVar9);
        if (puVar9 != &DAT_00000001) {
          uVar7 = 1;
          DAT_2001aef8 = 1;
          uVar13 = CONCAT44(extraout_r1_02,puVar9);
        }
      }
    }
  }
LAB_00035ce4:
  if (DAT_20019a6d == '\0') {
    __normal_g_arrMsgContent((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),uVar7);
    __push_g_arrMsgContent();
  }
  DAT_20019a5c = 0;
  pGVar3 = __get_dashboard_state();
  if ((pGVar3->field_0x10d6 != '\0') &&
     (pGVar3 = __get_dashboard_state(), *(char *)&pGVar3->imu_fusion_context != '\x01')) {
    __get_dashboard_state();
  }
  return;
}


