/*
 * Function: reset_all_usr_data
 * Entry:    000251e8
 * Prototype: undefined __stdcall reset_all_usr_data(char * param_1, int param_2)
 */


void reset_all_usr_data(char *param_1,int param_2)

{
  uint uVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar2;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar3;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  int iVar4;
  
  FUN_00038b00();
  cleanStocksIndex();
  cleanNewsIndex();
  cleanCalenadrIndex();
  uVar2 = extraout_r1;
  uVar3 = extraout_r2;
  if (*param_1 == '\x01') {
    delAudioStreamRecord(0xff,extraout_r1,extraout_r2);
    sleep(1000);
    uVar2 = extraout_r1_00;
    uVar3 = extraout_r2_00;
  }
  iVar4 = 0;
  do {
    deleteQuickNoteData(iVar4,uVar2,uVar3);
    iVar4 = iVar4 + 1;
    uVar1 = sleep(200);
    uVar2 = extraout_r1_01;
    uVar3 = extraout_r2_01;
  } while (iVar4 != 4);
  cleanAppLanguageInfo(uVar1,extraout_r1_01);
  uVar1 = sleep(200);
  cleanDashBoardStartUpModeInfo(uVar1,extraout_r1_02);
  sleep(200);
  __clear_user_settings((int)param_1);
  __clear_hardware_settings((int)param_1);
  sleep(500);
  __deinit_ncs_memory();
  sleep(500);
  bt_unpair('\0',(bt_addr_le_t *)0x0);
  if (param_2 != 0) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): sys reboot because enter ship mode failed\n");
      }
      else {
        ble_printk("%s(): sys reboot because enter ship mode failed\n","reset_all_usr_data",
                   extraout_r2_02,BLE_DEBUG);
      }
    }
    sleep(500);
                    /* WARNING: Subroutine does not return */
    sys_reboot(1);
  }
  sleep(1000);
  set_shipmode();
  sleep(1000);
  return;
}


