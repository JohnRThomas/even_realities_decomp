/*
 * Function: is_on_whitelist_by_identifier
 * Entry:    00036270
 * Prototype: undefined4 __stdcall is_on_whitelist_by_identifier(char * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4
is_on_whitelist_by_identifier
          (char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  size_t sVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  char *extraout_r1;
  char *extraout_r1_00;
  char *extraout_r1_01;
  char *extraout_r1_02;
  char *extraout_r1_03;
  char *extraout_r1_04;
  char *extraout_r1_05;
  undefined4 uVar7;
  undefined4 extraout_r2;
  int extraout_r2_00;
  int extraout_r2_01;
  int extraout_r2_02;
  int extraout_r2_03;
  int extraout_r2_04;
  int extraout_r2_05;
  int extraout_r2_06;
  int extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 extraout_r3;
  uint uVar8;
  undefined4 extraout_r3_00;
  byte bVar9;
  
  iVar6 = BLE_DEBUG;
  if (param_1 == (char *)0x0) {
    uVar7 = 0x46;
    pcVar1 = "[%s-%d] pkg_name is NULL !\n";
  }
  else {
    sVar2 = strlen(param_1);
    if (sVar2 < 0x28) {
      if (iVar6 == 0) {
        printk("pkg_name is %s \n");
      }
      else {
        ble_printk("pkg_name is %s \n",param_1,extraout_r2,extraout_r3);
      }
      iVar3 = strncmp("com.apple.mobilephone",param_1,0x15);
      iVar6 = BLE_DEBUG;
      pcVar1 = extraout_r1;
      iVar5 = extraout_r2_00;
      if ((((iVar3 == 0) ||
           (iVar3 = strncmp("com.apple.mobilephone_missed",param_1,0x1c), pcVar1 = extraout_r1_00,
           iVar5 = extraout_r2_01, iVar3 == 0)) ||
          (iVar3 = strncmp("com.android.phone_incall",param_1,0x18), pcVar1 = extraout_r1_01,
          iVar5 = extraout_r2_02, iVar3 == 0)) ||
         (iVar3 = strncmp("com.android.phone_missed",param_1,0x18), pcVar1 = extraout_r1_02,
         iVar5 = extraout_r2_03, iVar3 == 0)) {
        uVar8 = (uint)DAT_2001aefb;
        if (-1 < (int)(uVar8 << 0x1f)) {
          pcVar4 = "whitelist type call is disable ! \n";
          goto LAB_00036304;
        }
        pcVar4 = "whitelist type call is enable ! \n";
      }
      else {
        iVar3 = strncmp("com.apple.MobileSMS",param_1,0x13);
        pcVar1 = extraout_r1_03;
        iVar5 = extraout_r2_04;
        if ((iVar3 == 0) ||
           (iVar3 = strncmp("com.android.even_sms",param_1,0x14), pcVar1 = extraout_r1_04,
           iVar5 = extraout_r2_05, iVar3 == 0)) {
          uVar8 = (uint)DAT_2001aefb;
          if (-1 < (int)(uVar8 << 0x1e)) {
            pcVar4 = "whitelist type message is disable ! \n";
            goto LAB_00036304;
          }
          pcVar4 = "whitelist type message is enable ! \n";
        }
        else {
          iVar3 = strncmp("com.apple.mobilecal",param_1,0x13);
          iVar5 = extraout_r2_06;
          if ((iVar3 == 0) ||
             (iVar3 = strncmp("com.android.even_calendar",param_1,0x19), iVar5 = extraout_r2_07,
             iVar3 == 0)) {
            uVar8 = (uint)DAT_2001aefb;
            pcVar1 = (char *)(uVar8 << 0x1c);
            if (-1 < (int)pcVar1) {
              pcVar4 = "whitelist type calendar is disable ! \n";
              goto LAB_00036304;
            }
            pcVar4 = "whitelist type calendar is enable ! \n";
          }
          else {
            iVar5 = strncmp("com.apple.mobilemail",param_1,0x14);
            if (iVar5 != 0) {
              if (iVar6 == 0) {
                printk("appcounts is %d \n");
              }
              else {
                ble_printk("appcounts is %d \n",(char *)(uint)DAT_2001aefc,extraout_r2_08,
                           extraout_r3_00);
              }
              if (((int)((uint)DAT_2001aefb << 0x1b) < 0) && (DAT_2001aefc != 0)) {
                bVar9 = 0;
                while (pcVar1 = (char *)(uint)bVar9, pcVar1 < (char *)(uint)DAT_2001aefc) {
                  pcVar4 = &DAT_2001aefd + (int)pcVar1 * 0x38;
                  if (BLE_DEBUG == 0) {
                    printk("g_appWhiteListInfo.listAppInfo[%d].id is %s \n");
                  }
                  else {
                    ble_printk("g_appWhiteListInfo.listAppInfo[%d].id is %s \n",pcVar1,pcVar4,
                               BLE_DEBUG);
                  }
                  sVar2 = strlen(pcVar4);
                  iVar6 = strncmp(pcVar4,param_1,sVar2);
                  bVar9 = bVar9 + 1;
                  if (iVar6 == 0) {
                    return 2;
                  }
                }
              }
              pcVar1 = strstr("com.apple.mobilecal",param_1);
              if (pcVar1 == (char *)0x0) {
                return 1;
              }
              return 3;
            }
            uVar8 = (uint)DAT_2001aefb;
            iVar5 = uVar8 << 0x1d;
            pcVar1 = extraout_r1_05;
            if (-1 < iVar5) {
              pcVar4 = "whitelist type mail is disable ! \n";
LAB_00036304:
              if (iVar6 == 0) {
                printk(pcVar4);
              }
              else {
                ble_printk(pcVar4,pcVar1,iVar5,uVar8);
              }
              return 1;
            }
            pcVar4 = "whitelist type mail is enable ! \n";
          }
        }
      }
      if (iVar6 == 0) {
        printk(pcVar4);
      }
      else {
        ble_printk(pcVar4,pcVar1,iVar5,uVar8);
      }
      return 2;
    }
    uVar7 = 0x4a;
    pcVar1 = "[%s-%d] pkg_name length is too long !\n";
    param_4 = extraout_r3;
  }
  if (iVar6 == 0) {
    printk(pcVar1);
  }
  else {
    ble_printk(pcVar1,"is_on_whitelist_by_identifier",uVar7,param_4);
  }
  return 0;
}


