/*
 * Function: panel_suspend
 * Entry:    0004a780
 * Prototype: undefined __stdcall panel_suspend(int param_1, undefined4 param_2, undefined4 param_3)
 */


void panel_suspend(int param_1,undefined4 param_2,undefined4 param_3)

{
  int extraout_r0;
  int iVar1;
  int extraout_r0_00;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  
  *(int *)(param_1 + 0x378) = param_1 + -0x5c;
  iVar1 = param_1;
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): panel_suspend enter!\n");
      iVar1 = extraout_r0_00;
      param_2 = extraout_r1_01;
      param_3 = extraout_r2_01;
    }
    else {
      ble_printk("%s(): panel_suspend enter!\n","panel_suspend",param_3,BLE_DEBUG);
      iVar1 = extraout_r0;
      param_2 = extraout_r1;
      param_3 = extraout_r2;
    }
  }
  jbd_panel_suspend(iVar1,param_2,param_3);
  panel_off(param_1,extraout_r1_00,extraout_r2_00);
  *(undefined4 *)(param_1 + 0x35c) = 0;
  return;
}


