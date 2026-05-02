/*
 * Function: check_bind_status
 * Entry:    00028c8c
 * Prototype: undefined __stdcall check_bind_status(int param_1, int param_2, int param_3)
 */


void check_bind_status(int param_1,int param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  
  if (param_2 == 0) {
    if ((((DAT_20019a51 == '\0') ||
         (cVar1 = DAT_20019a51 + -1, bVar2 = DAT_20019a51 == '\x01', DAT_20019a51 = cVar1, bVar2))
        && (*(char *)(param_1 + 0x1089) == '\x01')) &&
       (*(undefined1 *)(param_1 + 0x1089) = 0, 0 < LOG_LEVEL)) {
      if (BLE_DEBUG == 0) {
        printk("%s(): disable allow bind mode\n");
        return;
      }
      ble_printk("%s(): disable allow bind mode\n","check_bind_status",param_3,BLE_DEBUG);
      return;
    }
  }
  else {
    if (param_3 == 0) {
      if ((*(char *)(param_1 + 0x1089) == '\0') &&
         (*(undefined1 *)(param_1 + 0x1089) = 1, 0 < LOG_LEVEL)) {
        if (BLE_DEBUG == 0) {
          printk("%s(): enable allow bind mode\n");
        }
        else {
          ble_printk("%s(): enable allow bind mode\n","check_bind_status",0,BLE_DEBUG);
        }
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x1089) = 0;
    }
    DAT_20019a51 = '\x03';
  }
  return;
}


