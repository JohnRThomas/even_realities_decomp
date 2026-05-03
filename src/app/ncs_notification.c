/*
 * Function: ncs_notification
 * Entry:    00023bc4
 * Prototype: undefined4 __stdcall ncs_notification(char * param_1, char * param_2, undefined * param_3)
 */


undefined4 ncs_notification(char *param_1,char *param_2,undefined *param_3)

{
  cJSON *object;
  cJSON *object_00;
  char *s;
  size_t sVar1;
  
  object = cJSON_CreateObject();
  cJSON_AddStringToObject(object,"app_identifier","com.tencent.xin");
  cJSON_AddStringToObject(object,"title",param_1);
  cJSON_AddStringToObject(object,"subtitle","aaa");
  cJSON_AddStringToObject(object,"message",param_2);
  cJSON_AddStringToObject(object,"date","08-04 09:50");
  cJSON_AddStringToObject(object,"display_name",&DAT_000a1b63);
  object_00 = cJSON_CreateObject();
  cJSON_AddItemToObject(object_00,"ncs_notification",object);
  s = cJSON_Print(object_00);
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): %s\n");
    }
    else {
      ble_printk("%s(): %s\n","mobile_send_notification_to_ble_device_test",s,BLE_DEBUG);
    }
  }
  sVar1 = ____strlen(s);
  subcontracing_send_data_pkcs7((int)s,sVar1,0x4b,param_3);
  cJSON_Delete(object_00);
  return 0;
}


