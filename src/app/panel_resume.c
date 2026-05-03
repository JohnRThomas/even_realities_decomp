/*
 * Function: panel_resume
 * Entry:    0004a8ac
 * Prototype: undefined4 __stdcall panel_resume(int param_1, undefined4 param_2)
 */


undefined4 panel_resume(int param_1,undefined4 param_2)

{
  ushort uVar1;
  char *fmt;
  undefined4 uVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  uint extraout_r1_02;
  int iVar3;
  int extraout_r2;
  int extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  
  iVar3 = (uint)*(ushort *)(param_1 + 0x504) << 0x17;
  *(int *)(param_1 + 0x378) = param_1 + -0x5c;
  if (iVar3 < 0) {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): panel_resume enter!\n");
        param_2 = extraout_r1_00;
        iVar3 = extraout_r2_00;
      }
      else {
        ble_printk("%s(): panel_resume enter!\n","panel_resume",iVar3,BLE_DEBUG);
        param_2 = extraout_r1;
        iVar3 = extraout_r2;
      }
    }
    if (*(int *)(param_1 + 0x35c) == 0) {
      if (*(int *)(*(int *)(param_1 + 0x378) + 0x14) == 0) {
        panel_on(param_1,param_2,iVar3);
        set_brightness_to_panel_reg((uint)*(byte *)(param_1 + 0x369),extraout_r1_02);
        return 0;
      }
      uVar2 = jbd_panel_resume(param_1,param_2,iVar3);
      uVar1 = spi_read_id(uVar2,extraout_r1_01,extraout_r2_01);
      if ((uVar1 != 0x4010) && (0 < LOG_LEVEL)) {
        if (BLE_DEBUG == 0) {
          printk("%s(): JBD PANEL init failure!\n");
        }
        else {
          ble_printk("%s(): JBD PANEL init failure!\n","panel_resume",extraout_r2_02,BLE_DEBUG);
        }
      }
      *(undefined4 *)(param_1 + 0x35c) = 1;
      return 0;
    }
    if (LOG_LEVEL < 1) {
      return 0xffffffff;
    }
    fmt = "%s(): panel_resume exit due to init_done\n";
  }
  else {
    if (LOG_LEVEL < 1) {
      return 0xffffffff;
    }
    fmt = "%s(): panel_resume exit due to LP_JBD_BIT\n";
  }
  if (BLE_DEBUG == 0) {
    printk(fmt);
  }
  else {
    ble_printk(fmt,"panel_resume",iVar3,BLE_DEBUG);
  }
  return 0xffffffff;
}


