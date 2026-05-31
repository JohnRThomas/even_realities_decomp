/*
 * Function: ?_is_the_same_whitelist_app
 * Entry:    000366ec
 * Prototype: char * __stdcall ?_is_the_same_whitelist_app(char * param_1)
 */


char * __is_the_same_whitelist_app(char *param_1)

{
  cJSON *object;
  cJSON *pcVar1;
  char *pcVar2;
  cJSON *pcVar3;
  cJSON_bool cVar4;
  cJSON *pcVar5;
  int iVar6;
  char *extraout_r1;
  char *extraout_r1_00;
  char *extraout_r1_01;
  char *extraout_r1_02;
  char *extraout_r1_03;
  char *extraout_r1_04;
  char *extraout_r1_05;
  char *extraout_r1_06;
  char *extraout_r1_07;
  char *extraout_r1_08;
  char *extraout_r1_09;
  char *extraout_r1_10;
  char *extraout_r1_11;
  char *extraout_r1_12;
  char *extraout_r1_13;
  undefined4 extraout_r2;
  uint extraout_r2_00;
  uint uVar7;
  uint extraout_r2_01;
  uint extraout_r2_02;
  uint extraout_r2_03;
  uint extraout_r2_04;
  uint extraout_r2_05;
  uint extraout_r2_06;
  uint extraout_r2_07;
  undefined4 extraout_r2_08;
  undefined4 uVar8;
  uint extraout_r2_09;
  undefined4 extraout_r2_10;
  undefined4 extraout_r2_11;
  uint extraout_r2_12;
  undefined4 extraout_r2_13;
  uint extraout_r2_14;
  uint uVar9;
  undefined4 extraout_r2_15;
  char *pcVar10;
  uint index;
  uint uVar11;
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
      ble_printk("error root JSON NODE !\n",extraout_r1,extraout_r2,BLE_DEBUG);
    }
    return (char *)0x0;
  }
  pcVar1 = cJSON_GetObjectItem(object,"call_enable");
  pcVar10 = extraout_r1_00;
  if (pcVar1 == (cJSON *)0x0) {
    pcVar2 = "callEnable is NULL !\n";
    uVar7 = extraout_r2_00;
LAB_00036724:
    if (BLE_DEBUG == 0) {
      printk(pcVar2);
    }
    else {
      ble_printk(pcVar2,pcVar10,uVar7,BLE_DEBUG);
    }
  }
  else {
    uVar7 = DAT_2001aefb & 1;
    if (uVar7 != (pcVar1->type == 2)) {
      pcVar2 = "callEnable is not the same !\n";
      goto LAB_00036724;
    }
    pcVar1 = cJSON_GetObjectItem(object,"msg_enable");
    pcVar10 = extraout_r1_01;
    if (pcVar1 == (cJSON *)0x0) {
      pcVar2 = "msgEnable is NULL !\n";
      uVar7 = extraout_r2_01;
      goto LAB_00036724;
    }
    uVar7 = (DAT_2001aefb & 3) >> 1;
    if (uVar7 != (pcVar1->type == 2)) {
      pcVar2 = "msgEnable is not the same !\n";
      goto LAB_00036724;
    }
    pcVar1 = cJSON_GetObjectItem(object,"calendar_enable");
    pcVar10 = extraout_r1_02;
    if (pcVar1 == (cJSON *)0x0) {
      pcVar2 = "jsonCalendarEnable is NULL !\n";
      uVar7 = extraout_r2_02;
      goto LAB_00036724;
    }
    uVar7 = (DAT_2001aefb & 0xf) >> 3;
    if (uVar7 != (pcVar1->type == 2)) {
      pcVar2 = "calendarEnable is not the same !\n";
      goto LAB_00036724;
    }
    pcVar1 = cJSON_GetObjectItem(object,"ios_mail_enable");
    pcVar10 = extraout_r1_03;
    if (pcVar1 == (cJSON *)0x0) {
      pcVar2 = "iosMailEnableJson is NULL !\n";
      uVar7 = extraout_r2_03;
      goto LAB_00036724;
    }
    uVar7 = (DAT_2001aefb & 7) >> 2;
    if (uVar7 != (pcVar1->type == 2)) {
      pcVar2 = "iosMailEnable is not the same !\n";
      goto LAB_00036724;
    }
    pcVar1 = cJSON_GetObjectItem(object,s_M_s_fuentes_en_la_app_000be53f + 0x13);
    if (pcVar1 == (cJSON *)0x0) {
      pcVar2 = "appJson is NULL !\n";
      pcVar10 = extraout_r1_04;
      uVar7 = extraout_r2_04;
      goto LAB_00036724;
    }
    pcVar3 = cJSON_GetObjectItem(pcVar1,"enable");
    if (pcVar3 == (cJSON *)0x0) {
      pcVar2 = "appEnableJson is NULL !\n";
      pcVar10 = extraout_r1_05;
      uVar7 = extraout_r2_05;
      goto LAB_00036724;
    }
    pcVar10 = (char *)(pcVar3->type + -2);
    uVar7 = (DAT_2001aefb & 0x1f) >> 4;
    if (uVar7 != (pcVar10 == (char *)0x0)) {
      pcVar2 = "appEnable is not the same !\n";
      goto LAB_00036724;
    }
    pcVar1 = cJSON_GetObjectItem(pcVar1,"list");
    if (pcVar1 == (cJSON *)0x0) {
      pcVar2 = "appListJson is NULL !\n";
      pcVar10 = extraout_r1_06;
      uVar7 = extraout_r2_06;
      goto LAB_00036724;
    }
    cVar4 = cJSON_IsArray(pcVar1);
    if (cVar4 != 0) {
      uVar7 = cJSON_GetArraySize(pcVar1);
      uVar7 = uVar7 & 0xff;
      if (DAT_2001aefc != uVar7) {
        pcVar2 = "appCounts is not the same !\n";
        pcVar10 = extraout_r1_07;
        uVar7 = extraout_r2_07;
        goto LAB_00036724;
      }
      uVar11 = 0;
      pcVar10 = extraout_r1_07;
      uVar9 = extraout_r2_07;
      for (index = uVar11; (index & 0xff) < uVar7; index = index + 1) {
        pcVar3 = cJSON_GetArrayItem(pcVar1,index);
        if (pcVar3 == (cJSON *)0x0) {
          pcVar2 = "singleAppJson is NULL !\n";
          pcVar10 = extraout_r1_08;
          uVar8 = extraout_r2_08;
LAB_00036860:
          if (BLE_DEBUG == 0) {
            printk(pcVar2);
            pcVar10 = extraout_r1_12;
            uVar9 = extraout_r2_12;
          }
          else {
            ble_printk(pcVar2,pcVar10,uVar8,BLE_DEBUG);
            pcVar10 = extraout_r1_09;
            uVar9 = extraout_r2_09;
          }
        }
        else {
          pcVar5 = cJSON_GetObjectItem(pcVar3,"id");
          if (pcVar5 == (cJSON *)0x0) {
            pcVar2 = "appIdJson is NULL !\n";
            pcVar10 = extraout_r1_10;
            uVar8 = extraout_r2_10;
            goto LAB_00036860;
          }
          pcVar3 = cJSON_GetObjectItem(pcVar3,"name");
          if (pcVar3 == (cJSON *)0x0) {
            pcVar2 = "appNameJson is NULL !\n";
            pcVar10 = extraout_r1_11;
            uVar8 = extraout_r2_11;
            goto LAB_00036860;
          }
          local_29 = 0;
          local_51 = 0;
          strcpy(acStack_50,pcVar5->valuestring);
          strcpy(acStack_60,pcVar3->valuestring);
          iVar6 = __is_app_name_same(acStack_50,acStack_60,extraout_r2_13);
          pcVar10 = extraout_r1_13;
          uVar9 = extraout_r2_14;
          if (iVar6 == 0) break;
          uVar11 = uVar11 + 1 & 0xff;
        }
      }
      if (uVar11 == uVar7) {
        if (BLE_DEBUG == 0) {
          printk("the same whitelist ! \n");
        }
        else {
          ble_printk("the same whitelist ! \n",pcVar10,uVar9,BLE_DEBUG);
        }
        pcVar10 = &DAT_00000001;
        goto LAB_000368da;
      }
    }
  }
  pcVar10 = (char *)0x0;
LAB_000368da:
  cJSON_Delete(object);
  if (BLE_DEBUG == 0) {
    printk("is_the_same_whitelist_app ret is %d\n");
  }
  else {
    ble_printk("is_the_same_whitelist_app ret is %d\n",pcVar10,extraout_r2_15,BLE_DEBUG);
  }
  return pcVar10;
}


