/*
 * Function: is_on_whitelist_by_identifier
 * Entry:    00036270
 * Prototype: undefined4 __stdcall is_on_whitelist_by_identifier(char * param_1)
 */


undefined4 is_on_whitelist_by_identifier(char *param_1)

{
  char *pcVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  byte bVar7;
  
  iVar4 = BLE_DEBUG;
  if (param_1 == (char *)0x0) {
    uVar6 = 0x46;
    pcVar1 = "[%s-%d] pkg_name is NULL !\n";
  }
  else {
    sVar2 = strlen(param_1);
    if (sVar2 < 0x28) {
      if (iVar4 == 0) {
        printk("pkg_name is %s \n",param_1);
      }
      else {
        ble_printk("pkg_name is %s \n");
      }
      iVar3 = strncmp("com.apple.mobilephone",param_1,0x15);
      iVar4 = BLE_DEBUG;
      if ((((iVar3 == 0) ||
           (iVar3 = strncmp("com.apple.mobilephone_missed",param_1,0x1c), iVar3 == 0)) ||
          (iVar3 = strncmp("com.android.phone_incall",param_1,0x18), iVar3 == 0)) ||
         (iVar3 = strncmp("com.android.phone_missed",param_1,0x18), iVar3 == 0)) {
        if (-1 < (int)((uint)DAT_2001aefb << 0x1f)) {
          pcVar1 = "whitelist type call is disable ! \n";
          goto LAB_00036304;
        }
        pcVar1 = "whitelist type call is enable ! \n";
      }
      else {
        iVar3 = strncmp("com.apple.MobileSMS",param_1,0x13);
        if ((iVar3 == 0) || (iVar3 = strncmp("com.android.even_sms",param_1,0x14), iVar3 == 0)) {
          if (-1 < (int)((uint)DAT_2001aefb << 0x1e)) {
            pcVar1 = "whitelist type message is disable ! \n";
            goto LAB_00036304;
          }
          pcVar1 = "whitelist type message is enable ! \n";
        }
        else {
          iVar3 = strncmp("com.apple.mobilecal",param_1,0x13);
          if ((iVar3 == 0) ||
             (iVar3 = strncmp("com.android.even_calendar",param_1,0x19), iVar3 == 0)) {
            if (-1 < (int)((uint)DAT_2001aefb << 0x1c)) {
              pcVar1 = "whitelist type calendar is disable ! \n";
              goto LAB_00036304;
            }
            pcVar1 = "whitelist type calendar is enable ! \n";
          }
          else {
            iVar3 = strncmp("com.apple.mobilemail",param_1,0x14);
            if (iVar3 != 0) {
              if (iVar4 == 0) {
                printk("appcounts is %d \n",(uint)DAT_2001aefc);
              }
              else {
                ble_printk("appcounts is %d \n");
              }
              if (((int)((uint)DAT_2001aefb << 0x1b) < 0) && (DAT_2001aefc != 0)) {
                bVar7 = 0;
                while (uVar5 = (uint)bVar7, uVar5 < DAT_2001aefc) {
                  pcVar1 = &DAT_2001aefd + uVar5 * 0x38;
                  if (BLE_DEBUG == 0) {
                    printk("g_appWhiteListInfo.listAppInfo[%d].id is %s \n",uVar5,pcVar1);
                  }
                  else {
                    ble_printk("g_appWhiteListInfo.listAppInfo[%d].id is %s \n");
                  }
                  sVar2 = strlen(pcVar1);
                  iVar4 = strncmp(pcVar1,param_1,sVar2);
                  bVar7 = bVar7 + 1;
                  if (iVar4 == 0) {
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
            if (-1 < (int)((uint)DAT_2001aefb << 0x1d)) {
              pcVar1 = "whitelist type mail is disable ! \n";
LAB_00036304:
              if (iVar4 == 0) {
                printk(pcVar1);
              }
              else {
                ble_printk(pcVar1);
              }
              return 1;
            }
            pcVar1 = "whitelist type mail is enable ! \n";
          }
        }
      }
      if (iVar4 == 0) {
        printk(pcVar1);
      }
      else {
        ble_printk(pcVar1);
      }
      return 2;
    }
    uVar6 = 0x4a;
    pcVar1 = "[%s-%d] pkg_name length is too long !\n";
  }
  if (iVar4 == 0) {
    printk(pcVar1,"is_on_whitelist_by_identifier",uVar6);
  }
  else {
    ble_printk(pcVar1);
  }
  return 0;
}


