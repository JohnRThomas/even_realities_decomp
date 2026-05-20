/*
 * Function: parse_ncs_notification
 * Entry:    0003601c
 * Prototype: undefined __stdcall parse_ncs_notification(char * param_1, undefined4 * param_2)
 */


void parse_ncs_notification(char *param_1,undefined4 *param_2)

{
  cJSON *object;
  cJSON *pcVar1;
  cJSON *pcVar2;
  cJSON *pcVar3;
  cJSON *pcVar4;
  cJSON *pcVar5;
  cJSON *pcVar6;
  cJSON *pcVar7;
  cJSON *pcVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r3;
  
  object = cJSON_Parse(param_1);
  if (object != (cJSON *)0x0) {
    pcVar1 = cJSON_GetObjectItemCaseSensitive(object,"ncs_notification");
    if (pcVar1 == (cJSON *)0x0) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): NOT FOUND NCS JSON NODE!\n");
        }
        else {
          ble_printk("%s(): NOT FOUND NCS JSON NODE!\n","parse_ncs_notification",extraout_r2_00,
                     BLE_DEBUG);
        }
      }
      cJSON_Delete(object);
      return;
    }
    pcVar2 = cJSON_GetObjectItemCaseSensitive(pcVar1,"app_identifier");
    pcVar3 = cJSON_GetObjectItemCaseSensitive(pcVar1,"title");
    pcVar4 = cJSON_GetObjectItemCaseSensitive(pcVar1,"subtitle");
    pcVar5 = cJSON_GetObjectItemCaseSensitive(pcVar1,"message");
    pcVar6 = cJSON_GetObjectItemCaseSensitive(pcVar1,"date");
    pcVar7 = cJSON_GetObjectItemCaseSensitive(pcVar1,"display_name");
    pcVar8 = cJSON_GetObjectItemCaseSensitive(pcVar1,"msg_id");
    pcVar1 = cJSON_GetObjectItemCaseSensitive(pcVar1,"action");
    memset(param_2,0,0x1b4);
    if (pcVar2 != (cJSON *)0x0) {
      strcpy((char *)(param_2 + 4),pcVar2->valuestring);
      iVar9 = strcmp(pcVar2->valuestring,"com.android.phone_incall");
      if (iVar9 == 0) {
        uVar10 = FUN_00080732();
        param_2[1] = uVar10;
      }
    }
    if (pcVar3 != (cJSON *)0x0) {
      strcpy((char *)(param_2 + 0x14),pcVar3->valuestring);
    }
    if (pcVar5 != (cJSON *)0x0) {
      strcpy((char *)(param_2 + 0x24),pcVar5->valuestring);
    }
    if (pcVar4 != (cJSON *)0x0) {
      strcpy((char *)(param_2 + 0x1c),pcVar4->valuestring);
    }
    if (pcVar6 != (cJSON *)0x0) {
      strcpy((char *)(param_2 + 100),pcVar6->valuestring);
    }
    if (pcVar7 != (cJSON *)0x0) {
      strcpy((char *)(param_2 + 0xc),pcVar7->valuestring);
    }
    if (pcVar8 != (cJSON *)0x0) {
      param_2[2] = (int)pcVar8->valueint;
    }
    if (pcVar1 != (cJSON *)0x0) {
      param_2[0x6c] = (int)pcVar1->valueint;
    }
    uVar10 = FUN_00080732();
    *param_2 = uVar10;
    cJSON_Delete(object);
    dump_ancs("#device-receiver",(int)param_2,extraout_r2_01,extraout_r3);
    return;
  }
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG != 0) {
      ble_printk("%s(): error root JSON NODE!\n","parse_ncs_notification",extraout_r2,BLE_DEBUG);
      return;
    }
    printk("%s(): error root JSON NODE!\n");
    return;
  }
  return;
}


