/*
 * Function: jdb_panel_init
 * Entry:    0004a978
 * Prototype: undefined4 __stdcall jdb_panel_init(int param_1)
 */


undefined4 jdb_panel_init(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  uint extraout_r1;
  undefined4 extraout_r2;
  undefined8 uVar3;
  
  *(int *)(param_1 + 0x378) = param_1 + -0x5c;
  FUN_00080e3a();
  uVar3 = set_brightness_to_panel_reg((uint)*(byte *)(param_1 + 0x369),extraout_r1);
  uVar1 = spi_read_id((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),extraout_r2);
  DAT_2000aa54 = (uint)uVar1;
  if (DAT_2000aa54 == 0x4010) {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): JBD PANEL init ok!, device id: 0x%x\n");
      }
      else {
        ble_printk("%s(): JBD PANEL init ok!, device id: 0x%x\n","jdb_panel_init",0x4010,BLE_DEBUG);
      }
    }
    uVar2 = 0;
    *(undefined4 *)(param_1 + 0x35c) = 1;
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): JBD PANEL init failure!, device id: 0x%x\n");
      }
      else {
        ble_printk("%s(): JBD PANEL init failure!, device id: 0x%x\n","jdb_panel_init",DAT_2000aa54,
                   BLE_DEBUG);
      }
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


