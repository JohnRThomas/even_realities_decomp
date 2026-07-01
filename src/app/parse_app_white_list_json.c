/*
 * Function: ?_parse_app_white_list_json
 * Entry:    00036458
 * Prototype: undefined4 __stdcall ?_parse_app_white_list_json(char * param_1)
 */


undefined4 __parse_app_white_list_json(char *param_1)

{
  cJSON *object;
  cJSON *pcVar1;
  char *fmt;
  cJSON *pcVar2;
  cJSON_bool cVar3;
  uint uVar4;
  char *pcVar5;
  cJSON *pcVar6;
  char *extraout_r1;
  char *extraout_r1_00;
  char *extraout_r1_01;
  char *extraout_r1_02;
  char *extraout_r1_03;
  char *extraout_r1_04;
  char *extraout_r1_05;
  char *extraout_r1_06;
  char *pcVar7;
  char *extraout_r1_07;
  char *extraout_r1_08;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 uVar8;
  undefined4 extraout_r2_08;
  undefined4 extraout_r2_09;
  uint uVar9;
  
  pcVar7 = param_1;
  object = cJSON_Parse(param_1);
  if (object == (cJSON *)0x0) {
    if (BLE_DEBUG == 0) {
      printk("error root JSON NODE,json_buffer is %s\n");
    }
    else {
      ble_printk("error root JSON NODE,json_buffer is %s\n",param_1,extraout_r2,BLE_DEBUG,pcVar7);
    }
  }
  else {
    memset(&DAT_2001aefb,0,0x15e2);
    pcVar1 = cJSON_GetObjectItem(object,"call_enable");
    if (pcVar1 == (cJSON *)0x0) {
      fmt = "callEnable is NULL !\n";
      pcVar5 = extraout_r1;
      uVar8 = extraout_r2_00;
    }
    else {
      DAT_2001aefb = DAT_2001aefb & 0xfe | pcVar1->type == 2;
      pcVar1 = cJSON_GetObjectItem(object,"msg_enable");
      if (pcVar1 == (cJSON *)0x0) {
        fmt = "msgEnable is NULL !\n";
        pcVar5 = extraout_r1_00;
        uVar8 = extraout_r2_01;
      }
      else {
        DAT_2001aefb = DAT_2001aefb & 0xfd | (pcVar1->type == 2) << 1;
        pcVar1 = cJSON_GetObjectItem(object,"calendar_enable");
        if (pcVar1 == (cJSON *)0x0) {
          fmt = "jsonCaledarEnable is NULL !\n";
          pcVar5 = extraout_r1_01;
          uVar8 = extraout_r2_02;
        }
        else {
          DAT_2001aefb = DAT_2001aefb & 0xf7 | (pcVar1->type == 2) << 3;
          pcVar1 = cJSON_GetObjectItem(object,"ios_mail_enable");
          if (pcVar1 == (cJSON *)0x0) {
            fmt = "jsonIosMailEnable is NULL !\n";
            pcVar5 = extraout_r1_02;
            uVar8 = extraout_r2_03;
          }
          else {
            DAT_2001aefb = DAT_2001aefb & 0xfb | (pcVar1->type == 2) << 2;
            pcVar1 = cJSON_GetObjectItem(object,s_M_s_fuentes_en_la_app_000be53f + 0x13);
            if (pcVar1 == (cJSON *)0x0) {
              fmt = "appJson is NULL !\n";
              pcVar5 = extraout_r1_03;
              uVar8 = extraout_r2_04;
            }
            else {
              pcVar2 = cJSON_GetObjectItem(pcVar1,"enable");
              if (pcVar2 == (cJSON *)0x0) {
                fmt = "appEnableJson is NULL !\n";
                pcVar5 = extraout_r1_04;
                uVar8 = extraout_r2_05;
              }
              else {
                DAT_2001aefb = DAT_2001aefb & 0xef | (pcVar2->type == 2) << 4;
                pcVar1 = cJSON_GetObjectItem(pcVar1,"list");
                if (pcVar1 != (cJSON *)0x0) {
                  cVar3 = cJSON_IsArray(pcVar1);
                  if (cVar3 != 0) {
                    uVar4 = cJSON_GetArraySize(pcVar1);
                    uVar9 = 0;
                    DAT_2001aefc = (byte)uVar4;
                    if (99 < (uVar4 & 0xff)) {
                      DAT_2001aefc = 100;
                    }
                    uVar4 = 0;
                    for (; (uVar9 & 0xff) < (uint)DAT_2001aefc; uVar9 = uVar9 + 1) {
                      pcVar2 = cJSON_GetArrayItem(pcVar1,uVar9 & 0xff);
                      if (pcVar2 == (cJSON *)0x0) {
                        pcVar5 = "singleAppJson is NULL !\n";
                        pcVar7 = extraout_r1_06;
                        uVar8 = extraout_r2_07;
LAB_000365b8:
                        if (BLE_DEBUG == 0) {
                          printk(pcVar5);
                        }
                        else {
                          ble_printk(pcVar5,pcVar7,uVar8,BLE_DEBUG);
                        }
                      }
                      else {
                        pcVar6 = cJSON_GetObjectItem(pcVar2,"id");
                        if (pcVar6 == (cJSON *)0x0) {
                          pcVar5 = "appIdJson is NULL !\n";
                          pcVar7 = extraout_r1_07;
                          uVar8 = extraout_r2_08;
                          goto LAB_000365b8;
                        }
                        pcVar2 = cJSON_GetObjectItem(pcVar2,"name");
                        if (pcVar2 == (cJSON *)0x0) {
                          pcVar5 = "appNameJson is NULL !\n";
                          pcVar7 = extraout_r1_08;
                          uVar8 = extraout_r2_09;
                          goto LAB_000365b8;
                        }
                        memset(&DAT_2001aefd + uVar4 * 0x38,0,0x28);
                        memset(&DAT_2001af25 + uVar4 * 0x38,0,0x10);
                        strcpy(&DAT_2001aefd + uVar4 * 0x38,pcVar6->valuestring);
                        strcpy(&DAT_2001af25 + uVar4 * 0x38,pcVar2->valuestring);
                        uVar4 = uVar4 + 1 & 0xff;
                      }
                    }
                  }
                  cJSON_Delete(object);
                  return 1;
                }
                fmt = "appListJson is NULL !\n";
                pcVar5 = extraout_r1_05;
                uVar8 = extraout_r2_06;
              }
            }
          }
        }
      }
    }
    if (BLE_DEBUG == 0) {
      printk(fmt);
    }
    else {
      ble_printk(fmt,pcVar5,uVar8,BLE_DEBUG,pcVar7);
    }
    cJSON_Delete(object);
  }
  return 0;
}


