/*
 * Function: sett_init
 * Entry:    000244d4
 * Prototype: undefined __stdcall sett_init(int * param_1)
 */


void sett_init(int *param_1)

{
  int iVar1;
  char *fmt;
  undefined4 extraout_r2;
  
  iVar1 = settings_subsys_init();
  if (iVar1 == 0) {
    iVar1 = settings_register((settings_handler *)&DAT_20002368);
    if (iVar1 == 0) {
      if (1 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): init ok\n");
        }
        else {
          ble_printk("%s(): init ok\n","sett_init",extraout_r2,BLE_DEBUG);
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
    printk(fmt);
  }
  else {
    ble_printk(fmt,"sett_init",iVar1,BLE_DEBUG);
  }
LAB_000244f8:
  *param_1 = iVar1;
  param_1[1] = 0x24125;
  param_1[2] = (int)&LAB_0007f532_1;
  param_1[3] = 0x240dd;
  return;
}


