/*
 * Function: calc_flash_crc
 * Entry:    00024930
 * Prototype: undefined4 __stdcall calc_flash_crc(ushort * param_1, int param_2, uint param_3)
 */


undefined4 calc_flash_crc(ushort *param_1,int param_2,uint param_3)

{
  bool bVar1;
  char *fmt;
  GlassesState *pGVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  code *pcVar9;
  byte local_428 [1028];
  
  if (LOG_LEVEL < 3) {
    if (param_1 == (ushort *)0x0) {
      return 0xffffffff;
    }
    if (param_3 == 0) {
      return 0xffffffff;
    }
  }
  else {
    if (BLE_DEBUG == 0) {
      printk("%s(): join in calc_flash_crc\n\n","calc_flash_crc");
    }
    else {
      ble_printk("%s(): join in calc_flash_crc\n\n");
    }
    if ((param_1 == (ushort *)0x0) || (param_3 == 0)) {
      if (LOG_LEVEL < 3) {
        return 0xffffffff;
      }
      pcVar5 = "calc_flash_crc";
      fmt = "%s(): calc_flash_crc para is NULL\n\n";
      if (BLE_DEBUG != 0) {
        ble_printk("%s(): calc_flash_crc para is NULL\n\n");
        return 0xffffffff;
      }
      goto LAB_000249de;
    }
  }
  uVar6 = (param_3 & 0x3ffffff) >> 10;
  if ((param_3 & 0x3ff) != 0) {
    uVar6 = uVar6 + 1 & 0xffff;
  }
  local_428[0] = 0xff;
  local_428[1] = 0;
  local_428[2] = 0;
  local_428[3] = 0;
  memset(local_428 + 4,0,0x3fc);
  bVar1 = z_device_is_ready((device *)&PTR_s_mx25r6435f_0_0008b3a0);
  if (bVar1) {
    iVar8 = param_2;
    while( true ) {
      if (iVar8 == param_2 + uVar6 * 0x400) {
        if ((DAT_2000304f != '\0') && (DAT_20019a5e == '\0')) {
          __wdt_feed();
        }
        return 0;
      }
      iVar7 = (param_3 + param_2) - iVar8;
      if (0x3ff < iVar7) {
        iVar7 = 0x400;
      }
      pGVar2 = __get_dashboard_state();
      pcVar9 = *(code **)&pGVar2->field_0x1044;
      pGVar2 = __get_dashboard_state();
      iVar3 = (*pcVar9)(pGVar2,iVar8,local_428,iVar7);
      if (iVar3 != 0) break;
      for (uVar4 = 0; (int)(uVar4 & 0xff) < iVar7; uVar4 = uVar4 + 1) {
        if (2 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): 0x%x \n","calc_flash_crc",(uint)local_428[uVar4 & 0xff]);
          }
          else {
            ble_printk("%s(): 0x%x \n","calc_flash_crc");
          }
        }
      }
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): \n\n","calc_flash_crc");
        }
        else {
          ble_printk("%s(): \n\n");
        }
      }
      uVar4 = FUN_000811a0((uint)*param_1,local_428,iVar7);
      iVar8 = iVar8 + 0x400;
      *param_1 = (ushort)uVar4;
    }
    printk("Flash read 0x%x failed: %d\n",iVar8,iVar3);
    return 0xffffffff;
  }
  pcVar5 = "mx25r6435f@0";
  fmt = " [%s] device not ready.\n";
LAB_000249de:
  printk(fmt,pcVar5);
  return 0xffffffff;
}


