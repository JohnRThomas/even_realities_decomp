/*
 * Function: try_to_save_file
 * Entry:    000256ec
 * Prototype: undefined __stdcall try_to_save_file(int param_1)
 */


void try_to_save_file(int param_1)

{
  uint uVar1;
  uint uVar2;
  GlassesState *pGVar3;
  int iVar4;
  size_t n;
  uint uVar5;
  uint local_f8;
  char local_f4;
  byte local_f3;
  undefined1 local_f2;
  undefined1 local_f1;
  undefined1 local_f0;
  undefined1 auStack_ef [195];
  byte local_2c;
  
  __dequeue_file(&local_f4);
  uVar1 = DAT_200083bc;
  uVar2 = DAT_200083b8;
  uVar5 = (uint)local_2c;
  if (((uVar5 < 0x15) && (local_f4 == '\r')) && (local_f3 == 0xe)) {
    if ((DAT_200083b4 == 0x1c0000) && (0x1fffff < DAT_200083bc)) {
      return;
    }
    if (DAT_200083b8 < 0x1000) {
      __write_font(DAT_200083bc,&DAT_20017d30,DAT_200083b8);
      LAST_FILE_CRC = crc32(LAST_FILE_CRC,&DAT_20017d30,DAT_200083b8);
      if (LOG_LEVEL < 1) {
        return;
      }
      if (BLE_DEBUG == 0) {
        printk("%s(): crc cal end crc32_value %08X\n");
        return;
      }
      ble_printk("%s(): crc cal end crc32_value %08X\n","try_to_save_file",LAST_FILE_CRC,BLE_DEBUG);
      return;
    }
  }
  else {
    if (DAT_200083bc == 0) {
      local_f8 = CONCAT31(CONCAT21(CONCAT11(local_f3,local_f2),local_f1),local_f0);
      DAT_200083bc = local_f8;
      LAST_FILE_CRC = crc32(LAST_FILE_CRC,&local_f3,4);
      if (local_f8 == 0x1c0000) {
        DAT_200083b4 = local_f8;
        pGVar3 = __get_dashboard_state();
        **(undefined1 **)&pGVar3->field_0x1010 = 0xc;
        pGVar3 = __get_dashboard_state();
        if (*(int *)pGVar3->___glasses_state != 0x10) {
          if (*(char *)(*(int *)(param_1 + 0x1010) + 7) == '\0') {
            *(undefined1 *)(*(int *)(param_1 + 0x1010) + 7) = 10;
          }
          pGVar3 = __get_dashboard_state();
          update_persist_task_status((int)pGVar3,0x10,2);
        }
      }
      uVar1 = DAT_200083b8;
      memcpy(&DAT_20017d30 + DAT_200083b8,auStack_ef,uVar5 - 5);
      iVar4 = uVar1 - 5;
      uVar1 = DAT_200083bc;
    }
    else {
      memcpy(&DAT_20017d30 + DAT_200083b8,&local_f3,uVar5 - 1);
      iVar4 = uVar2 - 1;
    }
    DAT_200083b8 = iVar4 + uVar5;
    if ((DAT_200083b4 == 0x1c0000) && (0x1fffff < uVar1)) {
      return;
    }
    if (DAT_200083b8 < 0x1000) {
      return;
    }
  }
  __write_font(DAT_200083bc,&DAT_20017d30,0x1000);
  LAST_FILE_CRC = crc32(LAST_FILE_CRC,&DAT_20017d30,0x1000);
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): crc32_value %08X\n");
    }
    else {
      ble_printk("%s(): crc32_value %08X\n","try_to_save_file",LAST_FILE_CRC,BLE_DEBUG);
    }
  }
  DAT_200083bc = DAT_200083bc + 0x1000;
  n = DAT_200083b8 - 0x1000;
  memcpy(&DAT_20017d30,&DAT_20018d30,n);
  DAT_200083b8 = n;
  return;
}


