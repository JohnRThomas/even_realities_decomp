/*
 * Function: ?_is_the_same_whitelist_app
 * Entry:    000366ec
 * Prototype: undefined4 __stdcall ?_is_the_same_whitelist_app(char * param_1)
 */


undefined4 __is_the_same_whitelist_app(char *param_1)

{
  cJSON *object;
  cJSON *pcVar1;
  char *pcVar2;
  cJSON *pcVar3;
  cJSON_bool cVar4;
  uint uVar5;
  cJSON *pcVar6;
  int iVar7;
  undefined4 uVar8;
  uint index;
  uint uVar9;
  char acStack_60 [15];
  undefined1 local_51;
  char acStack_50 [39];
  undefined1 local_29;
  
  object = cJSON_Parse(param_1);
  if (object == (cJSON *)0x0) {
    if (BLE_DEBUG == 0) {
      printk("error root JSON NODE !\n");
    }
    else {
      ble_printk("error root JSON NODE !\n");
    }
    return 0;
  }
  pcVar1 = cJSON_GetObjectItem(object,"call_enable");
  if (pcVar1 == (cJSON *)0x0) {
    pcVar2 = "callEnable is NULL !\n";
LAB_00036724:
    if (BLE_DEBUG == 0) {
      printk(pcVar2);
    }
    else {
      ble_printk(pcVar2);
    }
  }
  else {
    if ((bool)(DAT_2001aefb & 1) != (pcVar1->type == 2)) {
      pcVar2 = "callEnable is not the same !\n";
      goto LAB_00036724;
    }
    pcVar1 = cJSON_GetObjectItem(object,"msg_enable");
    if (pcVar1 == (cJSON *)0x0) {
      pcVar2 = "msgEnable is NULL !\n";
      goto LAB_00036724;
    }
    if ((DAT_2001aefb & 3) >> 1 != (uint)(pcVar1->type == 2)) {
      pcVar2 = "msgEnable is not the same !\n";
      goto LAB_00036724;
    }
    pcVar1 = cJSON_GetObjectItem(object,"calendar_enable");
    if (pcVar1 == (cJSON *)0x0) {
      pcVar2 = "jsonCalendarEnable is NULL !\n";
      goto LAB_00036724;
    }
    if ((DAT_2001aefb & 0xf) >> 3 != (uint)(pcVar1->type == 2)) {
      pcVar2 = "calendarEnable is not the same !\n";
      goto LAB_00036724;
    }
    pcVar1 = cJSON_GetObjectItem(object,"ios_mail_enable");
    if (pcVar1 == (cJSON *)0x0) {
      pcVar2 = "iosMailEnableJson is NULL !\n";
      goto LAB_00036724;
    }
    if ((DAT_2001aefb & 7) >> 2 != (uint)(pcVar1->type == 2)) {
      pcVar2 = "iosMailEnable is not the same !\n";
      goto LAB_00036724;
    }
    pcVar1 = cJSON_GetObjectItem(object,s_M_s_fuentes_en_la_app_000be53f + 0x13);
    if (pcVar1 == (cJSON *)0x0) {
      pcVar2 = "appJson is NULL !\n";
      goto LAB_00036724;
    }
    pcVar3 = cJSON_GetObjectItem(pcVar1,"enable");
    if (pcVar3 == (cJSON *)0x0) {
      pcVar2 = "appEnableJson is NULL !\n";
      goto LAB_00036724;
    }
    if ((DAT_2001aefb & 0x1f) >> 4 != (uint)(pcVar3->type == 2)) {
      pcVar2 = "appEnable is not the same !\n";
      goto LAB_00036724;
    }
    pcVar1 = cJSON_GetObjectItem(pcVar1,"list");
    if (pcVar1 == (cJSON *)0x0) {
      pcVar2 = "appListJson is NULL !\n";
      goto LAB_00036724;
    }
    cVar4 = cJSON_IsArray(pcVar1);
    if (cVar4 != 0) {
      uVar5 = cJSON_GetArraySize(pcVar1);
      uVar5 = uVar5 & 0xff;
      if (DAT_2001aefc != uVar5) {
        pcVar2 = "appCounts is not the same !\n";
        goto LAB_00036724;
      }
      uVar9 = 0;
      for (index = uVar9; (index & 0xff) < uVar5; index = index + 1) {
        pcVar3 = cJSON_GetArrayItem(pcVar1,index);
        if (pcVar3 == (cJSON *)0x0) {
          pcVar2 = "singleAppJson is NULL !\n";
LAB_00036860:
          if (BLE_DEBUG == 0) {
            printk(pcVar2);
          }
          else {
            ble_printk(pcVar2);
          }
        }
        else {
          pcVar6 = cJSON_GetObjectItem(pcVar3,"id");
          if (pcVar6 == (cJSON *)0x0) {
            pcVar2 = "appIdJson is NULL !\n";
            goto LAB_00036860;
          }
          pcVar3 = cJSON_GetObjectItem(pcVar3,"name");
          if (pcVar3 == (cJSON *)0x0) {
            pcVar2 = "appNameJson is NULL !\n";
            goto LAB_00036860;
          }
          local_29 = 0;
          local_51 = 0;
          strcpy(acStack_50,pcVar6->valuestring);
          strcpy(acStack_60,pcVar3->valuestring);
          iVar7 = __is_app_name_same(acStack_50,acStack_60);
          if (iVar7 == 0) break;
          uVar9 = uVar9 + 1 & 0xff;
        }
      }
      if (uVar9 == uVar5) {
        if (BLE_DEBUG == 0) {
          printk("the same whitelist ! \n");
        }
        else {
          ble_printk("the same whitelist ! \n");
        }
        uVar8 = 1;
        goto LAB_000368da;
      }
    }
  }
  uVar8 = 0;
LAB_000368da:
  cJSON_Delete(object);
  if (BLE_DEBUG == 0) {
    printk("is_the_same_whitelist_app ret is %d\n",uVar8);
  }
  else {
    ble_printk("is_the_same_whitelist_app ret is %d\n");
  }
  return uVar8;
}


