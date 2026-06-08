/*
 * Function: jdb_panel_init
 * Entry:    0004a978
 * Prototype: int __stdcall jdb_panel_init(jdb_panel_context * panel_context)
 */


int jdb_panel_init(jdb_panel_context *panel_context)

{
  ushort uVar1;
  int iVar2;
  uint extraout_r1;
  undefined4 extraout_r2;
  undefined8 uVar3;
  
  panel_context->field849_0x378 = &panel_context[-1].field_0x328;
  FUN_00080e3a();
  uVar3 = set_brightness_to_panel_reg((uint)panel_context->field834_0x369,extraout_r1);
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
    iVar2 = 0;
    panel_context->__initialized = 1;
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
    iVar2 = -1;
  }
  return iVar2;
}


