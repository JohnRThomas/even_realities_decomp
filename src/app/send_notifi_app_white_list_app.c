/*
 * Function: ?_send_notifi_app_white_list_app
 * Entry:    00034d44
 * Prototype: undefined4 __stdcall ?_send_notifi_app_white_list_app(astruct_3 * param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4
__send_notifi_app_white_list_app(astruct_3 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  size_t n;
  undefined4 local_178;
  undefined1 auStack_174 [20];
  char acStack_160 [320];
  
  local_178 = 0;
  memset(auStack_174,0,0x11);
  memset(acStack_160,0,0x140);
  uVar2 = __sprintf_chk(acStack_160,0,0x140,
                        "{\"whitelist_app_add\": {\"%s\":  \"%s\",\"%s\": \"%s\"}}","app_identifier"
                        ,param_2,"display_name",param_3);
  if (BLE_DEBUG == 0) {
    printk("[csh_debug]:send_notifi_app_white_list app buf is: %s \n",acStack_160);
  }
  else {
    ble_printk("[csh_debug]:send_notifi_app_white_list app buf is: %s \n");
  }
  uVar4 = (uVar2 & 0xffff) / 0x11 & 0xff;
  if ((uVar2 & 0xffff) % 0x11 != 0) {
    uVar4 = uVar4 + 1 & 0xff;
  }
  cVar6 = '\0';
  uVar5 = 0;
  do {
    if (uVar4 <= uVar5) {
      return 0;
    }
    memset((void *)((int)&local_178 + 3),0,0x12);
    uVar1 = local_178;
    n = uVar4 * 0xef + uVar2 + 0x11 & 0xff;
    if ((int)uVar5 < (int)(uVar4 - 1)) {
      n = 0x11;
    }
    local_178._3_1_ = SUB41(uVar1,3);
    local_178._0_3_ = CONCAT12((char)uVar5,CONCAT11((char)uVar4,0xf6));
    memcpy((void *)((int)&local_178 + 3),acStack_160 + uVar5 * 0x11,n);
    iVar3 = (*(code *)param_1->field12_0xc)(&local_178,n + 3);
    if (iVar3 == 0) {
      uVar5 = uVar5 + 1 & 0xff;
      cVar6 = '\0';
    }
    else {
      cVar6 = cVar6 + '\x01';
      if (cVar6 == '\x06') {
        if (BLE_DEBUG != 0) {
          ble_printk("[csh_debug] failed to send whitelist !!\n");
          return 0;
        }
        printk("[csh_debug] failed to send whitelist !!\n");
        return 0;
      }
    }
    z_impl_k_sleep((k_timeout_t)0xa4);
  } while( true );
}


