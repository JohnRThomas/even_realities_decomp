/*
 * Function: ?_send_notifi_app_white_list_app
 * Entry:    00034d44
 * Prototype: undefined4 __stdcall ?_send_notifi_app_white_list_app(int param_1)
 */


undefined4 __send_notifi_app_white_list_app(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  uint uVar3;
  uint uVar4;
  char cVar5;
  size_t n;
  undefined8 uVar6;
  undefined4 local_178;
  undefined1 auStack_174 [20];
  char acStack_160 [320];
  
  local_178 = 0;
  memset(auStack_174,0,0x11);
  memset(acStack_160,0,0x140);
  uVar2 = FUN_0008a6b0(acStack_160,0,0x140,
                       (byte *)"{\"whitelist_app_add\": {\"%s\":  \"%s\",\"%s\": \"%s\"}}");
  if (BLE_DEBUG == 0) {
    printk("[csh_debug]:send_notifi_app_white_list app buf is: %s \n");
  }
  else {
    ble_printk("[csh_debug]:send_notifi_app_white_list app buf is: %s \n",acStack_160,extraout_r2,
               BLE_DEBUG);
  }
  uVar3 = (uVar2 & 0xffff) / 0x11 & 0xff;
  if ((uVar2 & 0xffff) % 0x11 != 0) {
    uVar3 = uVar3 + 1 & 0xff;
  }
  cVar5 = '\0';
  uVar4 = 0;
  do {
    if (uVar3 <= uVar4) {
      return 0;
    }
    memset((void *)((int)&local_178 + 3),0,0x12);
    uVar1 = local_178;
    n = uVar3 * 0xef + uVar2 + 0x11 & 0xff;
    if ((int)uVar4 < (int)(uVar3 - 1)) {
      n = 0x11;
    }
    local_178._3_1_ = SUB41(uVar1,3);
    local_178._0_3_ = CONCAT12((char)uVar4,CONCAT11((char)uVar3,0xf6));
    memcpy((void *)((int)&local_178 + 3),acStack_160 + uVar4 * 0x11,n);
    uVar6 = (**(code **)(param_1 + 0xc))(&local_178,n + 3);
    if ((int)uVar6 == 0) {
      uVar4 = uVar4 + 1 & 0xff;
      cVar5 = '\0';
    }
    else {
      cVar5 = cVar5 + '\x01';
      if (cVar5 == '\x06') {
        if (BLE_DEBUG != 0) {
          ble_printk("[csh_debug] failed to send whitelist !!\n",(char *)((ulonglong)uVar6 >> 0x20),
                     extraout_r2_00,BLE_DEBUG);
          return 0;
        }
        printk("[csh_debug] failed to send whitelist !!\n");
        return 0;
      }
    }
    z_impl_k_sleep((k_timeout_t)0xa4);
  } while( true );
}


