/*
 * Function: local_store_write
 * Entry:    00024124
 * Prototype: undefined4 __stdcall local_store_write(char * param_1, void * param_2, size_t param_3)
 */


undefined4 local_store_write(char *param_1,void *param_2,size_t param_3)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  char local_98 [4];
  undefined4 auStack_94 [6];
  undefined1 auStack_7c [100];
  
  pcVar6 = "ar_glass_userdata_settings/";
  pcVar3 = local_98;
  do {
    pcVar5 = pcVar3;
    uVar1 = *(undefined4 *)pcVar6;
    uVar4 = *(undefined4 *)(pcVar6 + 4);
    pcVar6 = pcVar6 + 8;
    *(undefined4 *)pcVar5 = uVar1;
    *(undefined4 *)(pcVar5 + 4) = uVar4;
    pcVar3 = pcVar5 + 8;
  } while (pcVar6 != "gs/");
  builtin_strncpy(pcVar5 + 8,"gs/",4);
  memset(auStack_7c,0,100);
  ____strncpy(local_98,param_1,0x80);
  iVar2 = settings_save_one(local_98,param_2,param_3);
  if (iVar2 == 0) {
    if (LOG_LEVEL < 3) {
      return 0;
    }
    if (BLE_DEBUG == 0) {
      pcVar3 = "%s(): save success:[%s], len=%d\n";
      goto LAB_00024198;
    }
    pcVar3 = "%s(): save success:[%s], len=%d\n";
  }
  else {
    if (LOG_LEVEL < 1) {
      return 0;
    }
    if (BLE_DEBUG == 0) {
      pcVar3 = "%s(): failed to store key: %s --- %d\n";
LAB_00024198:
      printk(pcVar3,"local_store_write",param_1,param_3);
      return 0;
    }
    pcVar3 = "%s(): failed to store key: %s --- %d\n";
  }
  ble_printk(pcVar3,"local_store_write",param_1,param_3);
  return 0;
}


