/*
 * Function: QuickNoteStoreHandler
 * Entry:    000268a0
 * Prototype: int __stdcall QuickNoteStoreHandler(uint param_1, uint param_2, undefined4 param_3)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

int QuickNoteStoreHandler(uint param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  GlassesState *pGVar4;
  char *pcVar5;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar6;
  undefined4 extraout_r2_01;
  char *pcVar7;
  undefined4 extraout_r2_02;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *m1;
  undefined4 *puVar11;
  code *pcVar12;
  int iVar13;
  uint uVar14;
  void *m1_00;
  int iVar15;
  uint local_30;
  uint local_2c;
  undefined4 uStack_28;
  
  local_30 = param_1;
  local_2c = param_2;
  uStack_28 = param_3;
  iVar3 = z_impl_k_msgq_get((k_msgq *)&DAT_20003b00,&local_30,(k_timeout_t)0x0);
  uVar1 = local_2c;
  if (iVar3 != 0) {
    if (LOG_LEVEL < 1) {
      return -1;
    }
    if (BLE_DEBUG == 0) {
      printk("%s(): quick note file queue get failed\r\n\n");
      uVar6 = extraout_r2_01;
    }
    else {
      ble_printk("%s(): quick note file queue get failed\r\n\n","getQuickNoteBKPQueueCacheData",
                 extraout_r2,BLE_DEBUG);
      uVar6 = extraout_r2_00;
    }
    if (LOG_LEVEL < 1) {
      return -1;
    }
    pcVar5 = "%s(): quick note get queue data failed\n";
    goto LAB_000268ec;
  }
  if ((local_30 & 0xff) == 1) {
    uVar14 = local_2c & 0xff;
    if (3 < uVar14) goto LAB_0002690a;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): start quicknote text check...\r\n\n");
      }
      else {
        ble_printk("%s(): start quicknote text check...\r\n\n","QuickNoteStoreHandler",extraout_r2,
                   BLE_DEBUG);
      }
    }
    bVar2 = z_device_is_ready((device *)&PTR_s_mx25r6435f_0_0008b3a0);
    if (!bVar2) goto LAB_0002693a;
    memset(&DAT_20019133,0,0x800);
    pGVar4 = __get_dashboard_state();
    pcVar12 = *(code **)&pGVar4->field_0x1044;
    pGVar4 = __get_dashboard_state();
    iVar3 = (*pcVar12)(pGVar4,0x403000,&DAT_20019133,0x800);
    if (iVar3 != 0) goto LAB_0002697e;
    iVar3 = uVar14 * 0x200;
    iVar15 = uVar14 * 0x143 + 4;
    m1 = (undefined4 *)(&DAT_20019134 + iVar3);
    m1_00 = (void *)(iVar3 + 0x2001915d);
    iVar13 = uVar14 * 0x143 + 0x2d;
    if ((&DAT_20019133)[iVar3] == -0x56) {
      pGVar4 = __get_dashboard_state();
      iVar3 = memcmp(m1,(void *)(*(int *)&pGVar4->field_0x1030 + iVar15),0x29);
      bVar2 = false;
      if (iVar3 != 0) {
        memset(m1,0,0x29);
        pGVar4 = __get_dashboard_state();
        puVar8 = (undefined4 *)(*(int *)&pGVar4->field_0x1030 + iVar15);
        puVar10 = puVar8;
        do {
          puVar9 = puVar10 + 1;
          puVar11 = m1 + 1;
          *m1 = *puVar10;
          puVar10 = puVar9;
          m1 = puVar11;
        } while (puVar9 != puVar8 + 10);
        bVar2 = true;
        *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
      }
      pGVar4 = __get_dashboard_state();
      iVar3 = memcmp(m1_00,(void *)(*(int *)&pGVar4->field_0x1030 + iVar13),0x119);
      if (iVar3 != 0) goto LAB_000269ec;
      if (!bVar2) {
        if (LOG_LEVEL < 3) {
          return 0;
        }
        if (BLE_DEBUG != 0) {
          ble_printk("%s(): The current quicknote text is stored the same as in flash and does not need to be updated\n"
                     ,"QuickNoteStoreHandler",extraout_r2_02,BLE_DEBUG);
          return 0;
        }
        printk(
              "%s(): The current quicknote text is stored the same as in flash and does not need to be updated\n"
              );
        return 0;
      }
    }
    else {
      (&DAT_20019133)[iVar3] = 0xaa;
      memset(m1,0,0x29);
      pGVar4 = __get_dashboard_state();
      puVar8 = (undefined4 *)(*(int *)&pGVar4->field_0x1030 + iVar15);
      puVar10 = puVar8;
      do {
        puVar9 = puVar10 + 1;
        puVar11 = m1 + 1;
        *m1 = *puVar10;
        puVar10 = puVar9;
        m1 = puVar11;
      } while (puVar9 != puVar8 + 10);
      *(undefined1 *)puVar11 = *(undefined1 *)puVar9;
LAB_000269ec:
      memset(m1_00,0,0x119);
      pGVar4 = __get_dashboard_state();
      memcpy(m1_00,(void *)(*(int *)&pGVar4->field_0x1030 + iVar13),0x119);
    }
    FUN_00038b00();
    pGVar4 = __get_dashboard_state();
    pcVar12 = *(code **)&pGVar4->field_0x104c;
    pGVar4 = __get_dashboard_state();
    iVar3 = (*pcVar12)(pGVar4,0x403000,0x1000);
    if (iVar3 == 0) {
      pGVar4 = __get_dashboard_state();
      pcVar12 = *(code **)&pGVar4->field_0x1048;
      pGVar4 = __get_dashboard_state();
      iVar3 = (*pcVar12)(pGVar4,0x403000,&DAT_20019133,0x800);
      if (iVar3 == 0) {
        if (LOG_LEVEL < 3) {
          return 0;
        }
        pcVar5 = "%s(): quicknote %d store sucess\n";
LAB_00026b0a:
        if (BLE_DEBUG == 0) {
          printk(pcVar5);
        }
        else {
          ble_printk(pcVar5,"QuickNoteStoreHandler",uVar1 & 0xff,BLE_DEBUG);
        }
        return 0;
      }
LAB_00026ae8:
      if (LOG_LEVEL < 1) {
        return iVar3;
      }
      pcVar5 = "%s(): Flash write failed! %d\n\n";
      goto LAB_00026a40;
    }
  }
  else {
    if ((local_30 & 0xff) != 2) {
      return 0;
    }
    uVar14 = local_2c & 0xff;
    if (3 < uVar14) {
LAB_0002690a:
      if (LOG_LEVEL < 1) {
        return -1;
      }
      pcVar5 = "%s(): quicknote upgrade index out of range\n";
      uVar6 = extraout_r2;
LAB_000268ec:
      if (BLE_DEBUG != 0) {
        ble_printk(pcVar5,"QuickNoteStoreHandler",uVar6,BLE_DEBUG);
        return -1;
      }
      printk(pcVar5);
      return -1;
    }
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): start quicknote text check...\r\n\n");
      }
      else {
        ble_printk("%s(): start quicknote text check...\r\n\n","QuickNoteStoreHandler",extraout_r2,
                   BLE_DEBUG);
      }
    }
    FUN_00038b00();
    bVar2 = z_device_is_ready((device *)&PTR_s_mx25r6435f_0_0008b3a0);
    if (!bVar2) {
LAB_0002693a:
      if (LOG_LEVEL < 1) {
        return -1;
      }
      pcVar7 = "mx25r6435f@0";
      pcVar5 = "%s():  [%s] device not ready.\n\n";
LAB_0002698e:
      if (BLE_DEBUG == 0) {
        printk(pcVar5);
      }
      else {
        ble_printk(pcVar5,"QuickNoteStoreHandler",pcVar7,BLE_DEBUG);
      }
      return -1;
    }
    memset(&DAT_20019133,0,0x800);
    pGVar4 = __get_dashboard_state();
    pcVar12 = *(code **)&pGVar4->field_0x1044;
    pGVar4 = __get_dashboard_state();
    iVar3 = (*pcVar12)(pGVar4,0x403000,&DAT_20019133,0x800);
    if (iVar3 != 0) {
LAB_0002697e:
      if (LOG_LEVEL < 1) {
        return -1;
      }
      pcVar7 = (char *)0x403000;
      pcVar5 = "%s():  form address [%d] read data failed.\n\n";
      goto LAB_0002698e;
    }
    memset(&DAT_20019133 + uVar14 * 0x200,0xff,0x200);
    pGVar4 = __get_dashboard_state();
    pcVar12 = *(code **)&pGVar4->field_0x104c;
    pGVar4 = __get_dashboard_state();
    iVar3 = (*pcVar12)(pGVar4,0x403000,0x1000);
    if (iVar3 == 0) {
      pGVar4 = __get_dashboard_state();
      pcVar12 = *(code **)&pGVar4->field_0x1048;
      pGVar4 = __get_dashboard_state();
      iVar3 = (*pcVar12)(pGVar4,0x403000,&DAT_20019133,0x800);
      if (iVar3 == 0) {
        if (LOG_LEVEL < 3) {
          return 0;
        }
        pcVar5 = "%s(): quicknote %d delete sucess\n";
        goto LAB_00026b0a;
      }
      goto LAB_00026ae8;
    }
  }
  if (LOG_LEVEL < 3) {
    return iVar3;
  }
  pcVar5 = "%s(): Flash erase failed! %d\n\n";
LAB_00026a40:
  if (BLE_DEBUG == 0) {
    printk(pcVar5);
    return iVar3;
  }
  ble_printk(pcVar5,"QuickNoteStoreHandler",iVar3,BLE_DEBUG);
  return iVar3;
}


