/*
 * Function: bt_set_name
 * Entry:    00057f20
 * Prototype: undefined4 __stdcall bt_set_name(char * param_1)
 */


undefined4 bt_set_name(char *param_1)

{
  size_t n;
  int iVar1;
  undefined4 uVar2;
  dword in_stack_ffffffd8;
  uint8_t *in_stack_ffffffdc;
  void *in_stack_ffffffe0;
  undefined4 local_18;
  char *local_14;
  
  n = strlen(param_1);
  if (n < 0x1d) {
    iVar1 = strcmp((char *)&BLE_NAME_LEN,param_1);
    if (iVar1 != 0) {
      memcpy(&BLE_NAME_LEN,param_1,n);
      (&BLE_NAME_LEN)[n] = 0;
      iVar1 = bt_settings_store_name(&BLE_NAME_LEN,n);
      if (iVar1 != 0) {
        local_14 = "Unable to store name";
        local_18 = 2;
        LOG_WRN(&PTR_s_bt_hci_core_0008b8e8,0x1080,&local_18,2,in_stack_ffffffd8,in_stack_ffffffdc,
                in_stack_ffffffe0);
      }
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffff4;
  }
  return uVar2;
}


