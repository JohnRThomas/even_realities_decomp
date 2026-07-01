/*
 * Function: check_bonded_addr
 * Entry:    000184fc
 * Prototype: undefined __stdcall check_bonded_addr(bt_addr_le_t * param_1, undefined4 param_2, size_t param_3)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void check_bonded_addr(bt_addr_le_t *param_1,undefined4 param_2,size_t param_3)

{
  char acStack_28 [36];
  
  bt_addr_le_to_str(param_1,acStack_28,param_3);
  *(undefined1 *)(_DAT_20006c98 + 0x367) = 0;
  if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): Got %s bind addr\n\n");
    }
    else {
      ble_printk("%s(): Got %s bind addr\n\n","check_bonded_addr",acStack_28,BLE_DEBUG);
    }
  }
  return;
}


