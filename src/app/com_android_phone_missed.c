/*
 * Function: com_android_phone_missed
 * Entry:    00034e60
 * Prototype: undefined4 __stdcall com_android_phone_missed(int param_1)
 */


undefined4 com_android_phone_missed(int param_1)

{
  size_t n;
  int iVar1;
  undefined4 extraout_r0;
  undefined4 extraout_r0_00;
  GlassesState *pGVar2;
  undefined4 uVar3;
  char cVar4;
  char *s2;
  char *s;
  undefined4 *puVar5;
  undefined4 uStack_40;
  char *local_3c [4];
  char *local_2c;
  char *pcStack_28;
  char *pcStack_24;
  char *pcStack_20;
  char *local_1c;
  
  puVar5 = &uStack_40;
  if (param_1 == 0) {
    return 0;
  }
  local_3c[0] = "com.android.phone_missed";
  local_3c[1] = "com.android.phone_incall";
  local_3c[2] = "com.apple.mobilephone";
  local_3c[3] = "com.apple.mobilephone_missed";
  local_2c = "com.apple.MobileSMS";
  pcStack_28 = "com.android.even_sms";
  pcStack_24 = "com.apple.mobilemail";
  pcStack_20 = "com.apple.mobilecal";
  local_1c = "com.android.even_calendar";
  cVar4 = '\t';
  s2 = (char *)(param_1 + 0x10);
  while( true ) {
    puVar5 = puVar5 + 1;
    s = (char *)*puVar5;
    n = strlen(s);
    iVar1 = strncmp(s,s2,n);
    if (iVar1 == 0) break;
    cVar4 = cVar4 + -1;
    if (cVar4 == '\0') {
      pGVar2 = __get_dashboard_state();
      uVar3 = __send_notifi_app_white_list_app((int)&pGVar2->field_0x77c,s2,param_1 + 0x30);
      return uVar3;
    }
  }
  if (BLE_DEBUG != 0) {
    ble_printk("[%s-%d] special package nane:%s,need not send to app !\n",
               "send_whilelist_app_info_wrapper",0x137,s2);
    return extraout_r0;
  }
  printk("[%s-%d] special package nane:%s,need not send to app !\n",
         "send_whilelist_app_info_wrapper",0x137,s2);
  return extraout_r0_00;
}


