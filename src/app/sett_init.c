/*
 * Function: sett_init
 * Entry:    000244d4
 * Prototype: undefined __stdcall sett_init(settings_context * param_1)
 */


void sett_init(settings_context *param_1)

{
  int iVar1;
  char *fmt;
  
  iVar1 = settings_subsys_init();
  if (iVar1 == 0) {
    iVar1 = settings_register((settings_handler *)&DAT_20002368);
    if (iVar1 == 0) {
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): init ok\n","sett_init");
        }
        else {
          ble_printk("%s(): init ok\n");
        }
      }
      iVar1 = 1;
      goto LAB_000244f8;
    }
    if (LOG_LEVEL < 2) goto LAB_000244f8;
    fmt = "%s(): Cannot register settings handler %d\n";
  }
  else {
    if (LOG_LEVEL < 2) goto LAB_000244f8;
    fmt = "%s(): Failed to initialize settings subsystem, error: %d\n";
  }
  if (BLE_DEBUG == 0) {
    printk(fmt,"sett_init",iVar1);
  }
  else {
    ble_printk(fmt);
  }
LAB_000244f8:
  param_1->state = iVar1;
  param_1->write_cb = (local_store_write_cb *)0x24125;
  param_1->something_cb = 0x7f533;
  param_1->delete_cb = 0x240dd;
  return;
}


