/*
 * Function: ?_parse_app_white_list_json
 * Entry:    00036458
 * Prototype: undefined4 __stdcall ?_parse_app_white_list_json(char * param_1)
 */


undefined4 __parse_app_white_list_json(char *param_1)

{
  cJSON *object;
  cJSON *pcVar1;
  char *pcVar2;
  cJSON *pcVar3;
  cJSON_bool cVar4;
  uint uVar5;
  cJSON *pcVar6;
  uint uVar7;
  
  object = cJSON_Parse(param_1);
  if (object == (cJSON *)0x0) {
    if (BLE_DEBUG == 0) {
      printk("error root JSON NODE,json_buffer is %s\n",param_1);
    }
    else {
      ble_printk("error root JSON NODE,json_buffer is %s\n");
    }
  }
  else {
    memset(&DAT_2001aefb,0,0x15e2);
    pcVar1 = cJSON_GetObjectItem(object,"call_enable");
    if (pcVar1 == (cJSON *)0x0) {
      pcVar2 = "callEnable is NULL !\n";
    }
    else {
      DAT_2001aefb = DAT_2001aefb & 0xfe | pcVar1->type == 2;
      pcVar1 = cJSON_GetObjectItem(object,"msg_enable");
      if (pcVar1 == (cJSON *)0x0) {
        pcVar2 = "msgEnable is NULL !\n";
      }
      else {
        DAT_2001aefb = DAT_2001aefb & 0xfd | (pcVar1->type == 2) << 1;
        pcVar1 = cJSON_GetObjectItem(object,"calendar_enable");
        if (pcVar1 == (cJSON *)0x0) {
          pcVar2 = "jsonCaledarEnable is NULL !\n";
        }
        else {
          DAT_2001aefb = DAT_2001aefb & 0xf7 | (pcVar1->type == 2) << 3;
          pcVar1 = cJSON_GetObjectItem(object,"ios_mail_enable");
          if (pcVar1 == (cJSON *)0x0) {
            pcVar2 = "jsonIosMailEnable is NULL !\n";
          }
          else {
            DAT_2001aefb = DAT_2001aefb & 0xfb | (pcVar1->type == 2) << 2;
            pcVar1 = cJSON_GetObjectItem(object,s_M_s_fuentes_en_la_app_000be53f + 0x13);
            if (pcVar1 == (cJSON *)0x0) {
              pcVar2 = "appJson is NULL !\n";
            }
            else {
              pcVar3 = cJSON_GetObjectItem(pcVar1,"enable");
              if (pcVar3 == (cJSON *)0x0) {
                pcVar2 = "appEnableJson is NULL !\n";
              }
              else {
                DAT_2001aefb = DAT_2001aefb & 0xef | (pcVar3->type == 2) << 4;
                pcVar1 = cJSON_GetObjectItem(pcVar1,"list");
                if (pcVar1 != (cJSON *)0x0) {
                  cVar4 = cJSON_IsArray(pcVar1);
                  if (cVar4 != 0) {
                    uVar5 = cJSON_GetArraySize(pcVar1);
                    uVar7 = 0;
                    DAT_2001aefc = (byte)uVar5;
                    if (99 < (uVar5 & 0xff)) {
                      DAT_2001aefc = 100;
                    }
                    uVar5 = 0;
                    for (; (uVar7 & 0xff) < (uint)DAT_2001aefc; uVar7 = uVar7 + 1) {
                      pcVar3 = cJSON_GetArrayItem(pcVar1,uVar7 & 0xff);
                      if (pcVar3 == (cJSON *)0x0) {
                        pcVar2 = "singleAppJson is NULL !\n";
LAB_000365b8:
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
                          goto LAB_000365b8;
                        }
                        pcVar3 = cJSON_GetObjectItem(pcVar3,"name");
                        if (pcVar3 == (cJSON *)0x0) {
                          pcVar2 = "appNameJson is NULL !\n";
                          goto LAB_000365b8;
                        }
                        memset(&DAT_2001aefd + uVar5 * 0x38,0,0x28);
                        memset(&DAT_2001af25 + uVar5 * 0x38,0,0x10);
                        strcpy(&DAT_2001aefd + uVar5 * 0x38,pcVar6->valuestring);
                        strcpy(&DAT_2001af25 + uVar5 * 0x38,pcVar3->valuestring);
                        uVar5 = uVar5 + 1 & 0xff;
                      }
                    }
                  }
                  cJSON_Delete(object);
                  return 1;
                }
                pcVar2 = "appListJson is NULL !\n";
              }
            }
          }
        }
      }
    }
    if (BLE_DEBUG == 0) {
      printk(pcVar2);
    }
    else {
      ble_printk(pcVar2);
    }
    cJSON_Delete(object);
  }
  return 0;
}


