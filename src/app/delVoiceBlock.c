/*
 * Function: delVoiceBlock
 * Entry:    00030948
 * Prototype: undefined __stdcall delVoiceBlock(uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void delVoiceBlock(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  char *pcVar3;
  char *fmt;
  GlassesState *pGVar4;
  int iVar5;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  code *pcVar6;
  
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): received audio delete command\n");
      param_3 = extraout_r2_00;
    }
    else {
      ble_printk("%s(): received audio delete command\n","delVoiceBlock",param_3,BLE_DEBUG);
      param_3 = extraout_r2;
    }
  }
  if (((param_1 - 5 & 0xff) < 0xfa) || (param_1 == 0)) {
    if (0 < LOG_LEVEL) {
      pcVar3 = "%s(): input parameter error...\n";
LAB_0003097a:
      if (BLE_DEBUG != 0) {
        ble_printk(pcVar3,"delVoiceBlock",param_3,param_4);
        return;
      }
      printk(pcVar3,"delVoiceBlock",param_3,param_4);
      return;
    }
  }
  else {
    bVar2 = z_device_is_ready((device *)&PTR_s_mx25r6435f_0_0008b3a0);
    if (bVar2) {
      memset(&DAT_20019a78,0,0x1000);
      pGVar4 = __get_dashboard_state();
      pcVar6 = *(code **)&pGVar4->field_0x1044;
      pGVar4 = __get_dashboard_state();
      iVar5 = (*pcVar6)(pGVar4,0x400000,&DAT_20019a78,0x1000);
      if (iVar5 == 0) {
        pGVar4 = __get_dashboard_state();
        pcVar6 = *(code **)&pGVar4->field_0x104c;
        pGVar4 = __get_dashboard_state();
        pcVar3 = (char *)(*pcVar6)(pGVar4,0x400000,0x1000);
        iVar5 = LOG_LEVEL;
        if (pcVar3 == (char *)0x0) {
          DAT_20019a79 = 0xaa;
          DAT_20019a78 = 0x5a;
          DAT_20019a7a = 0xa5;
          DAT_20019a7b = 0x5a;
          DAT_20019a7c = 0;
          DAT_20019a7d = 0;
          DAT_20019a7e = 0;
          DAT_20019a7f = 0;
          if (param_1 < 5) {
            iVar1 = (param_1 - 1) * 0x14;
            (&DAT_20019a80)[iVar1] = 0;
            (&DAT_20019a81)[iVar1] = 0;
            (&DAT_20019a82)[iVar1] = 0;
            (&DAT_20019a83)[iVar1] = 0;
            (&DAT_20019a8c)[iVar1] = 0;
            (&DAT_20019a8d)[iVar1] = 0;
            (&DAT_20019a8e)[iVar1] = 0;
            (&DAT_20019a8f)[iVar1] = 0;
            if (2 < iVar5) {
              if (BLE_DEBUG == 0) {
                printk("%s(): success delete voice block num.(%d)\n");
              }
              else {
                ble_printk("%s(): success delete voice block num.(%d)\n","delVoiceBlock",param_1,
                           BLE_DEBUG);
              }
            }
          }
          else {
            memcpy(&DAT_20019a78,&INT_0008d800,0x58);
            if (2 < iVar5) {
              if (BLE_DEBUG == 0) {
                printk("%s(): success delete all voice block \n");
              }
              else {
                ble_printk("%s(): success delete all voice block \n","delVoiceBlock",extraout_r2_01,
                           BLE_DEBUG);
              }
            }
          }
          pGVar4 = __get_dashboard_state();
          pcVar6 = *(code **)&pGVar4->field_0x1048;
          pGVar4 = __get_dashboard_state();
          pcVar3 = (char *)(*pcVar6)(pGVar4,0x400000,&DAT_20019a78,0x1000);
          if (pcVar3 == (char *)0x0) {
            if (2 < LOG_LEVEL) {
              pcVar3 = "%s(): audio manager block delete success\n";
              param_3 = 0;
              goto LAB_0003097a;
            }
          }
          else if (0 < LOG_LEVEL) {
            fmt = "%s(): Flash write failed! %d\n\n";
            goto LAB_000309ae;
          }
        }
        else if (2 < LOG_LEVEL) {
          fmt = "%s(): Flash erase failed! %d\n\n";
          goto LAB_000309ae;
        }
      }
      else if (0 < LOG_LEVEL) {
        pcVar3 = &DAT_00400000;
        fmt = "%s():  form address [%d] read data failed.\n\n";
        goto LAB_000309ae;
      }
    }
    else if (0 < LOG_LEVEL) {
      pcVar3 = "mx25r6435f@0";
      fmt = "%s():  [%s] device not ready.\n\n";
LAB_000309ae:
      if (BLE_DEBUG != 0) {
        ble_printk(fmt,"delVoiceBlock",pcVar3,param_4);
        return;
      }
      printk(fmt,"delVoiceBlock",pcVar3,param_4);
      return;
    }
  }
  return;
}


