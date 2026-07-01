/*
 * Function: convert_app_whitelist_to_json
 * Entry:    00036984
 * Prototype: uint __stdcall convert_app_whitelist_to_json(char * param_1)
 */


uint convert_app_whitelist_to_json(char *param_1)

{
  char *fmt;
  cJSON *object;
  cJSON *object_00;
  char *pcVar1;
  cJSON *array;
  cJSON *object_01;
  size_t sVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 extraout_r2;
  int iVar5;
  uint uVar6;
  
  pcVar1 = param_1;
  if (param_1 == (char *)0x0) {
    uVar3 = 0x1f1;
    fmt = "[%s-%d]buf is null \n";
  }
  else {
    object = cJSON_CreateObject();
    if (object != (cJSON *)0x0) {
      cJSON_AddBoolToObject(object,"call_enable",DAT_2001aefb & 1);
      cJSON_AddBoolToObject(object,"msg_enable",(DAT_2001aefb & 3) >> 1);
      cJSON_AddBoolToObject(object,"ios_mail_enable",(DAT_2001aefb & 7) >> 2);
      cJSON_AddBoolToObject(object,"calendar_enable",(DAT_2001aefb & 0xf) >> 3);
      object_00 = cJSON_CreateObject();
      if (object_00 == (cJSON *)0x0) {
        uVar3 = 0x206;
        pcVar1 = "[%s-%d]appJson is null \n";
      }
      else {
        cJSON_AddBoolToObject(object_00,"enable",(DAT_2001aefb & 0x1f) >> 4);
        array = cJSON_CreateArray();
        if (array == (cJSON *)0x0) {
          uVar3 = 0x20e;
          pcVar1 = "[%s-%d]appListInfoJson is null \n";
        }
        else {
          uVar6 = 0;
          while( true ) {
            uVar4 = uVar6 & 0xff;
            if (DAT_2001aefc <= uVar4) {
              cJSON_AddItemToObject(object_00,"list",array);
              cJSON_AddItemToObject(object,s_M_s_fuentes_en_la_app_000be53f + 0x13,object_00);
              pcVar1 = cJSON_PrintUnformatted(object);
              if (BLE_DEBUG == 0) {
                printk("cJsonStr is %s \n");
              }
              else {
                ble_printk("cJsonStr is %s \n",pcVar1,extraout_r2,BLE_DEBUG);
              }
              strcpy(param_1,pcVar1);
              sVar2 = strlen(pcVar1);
              free(pcVar1);
              cJSON_Delete(object);
              return sVar2 & 0xffff;
            }
            object_01 = cJSON_CreateObject();
            uVar6 = uVar6 + 1;
            if (object_01 == (cJSON *)0x0) break;
            iVar5 = uVar4 * 0x38;
            cJSON_AddStringToObject(object_01,"id",&DAT_2001aefd + iVar5);
            cJSON_AddStringToObject(object_01,"name",&DAT_2001af25 + iVar5);
            add_item_to_array(array,object_01);
          }
          uVar3 = 0x219;
          pcVar1 = "[%s-%d]appItem is null \n";
        }
      }
      if (BLE_DEBUG == 0) {
        printk(pcVar1);
      }
      else {
        ble_printk(pcVar1,"convert_app_whitelist_to_json",uVar3,BLE_DEBUG);
      }
      cJSON_Delete(object);
      return 0;
    }
    uVar3 = 0x1fa;
    fmt = "[%s-%d]jsonRoot is null \n";
  }
  if (BLE_DEBUG == 0) {
    printk(fmt);
  }
  else {
    ble_printk(fmt,"convert_app_whitelist_to_json",uVar3,BLE_DEBUG,pcVar1);
  }
  return 0;
}


