/*
 * Function: gui_utf_adv_draw_configure
 * Entry:    00045868
 * Prototype: undefined4 __stdcall gui_utf_adv_draw_configure(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 gui_utf_adv_draw_configure(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  switch(param_1) {
  case 4:
    DAT_2000a9ec = 0;
    DAT_2000a9e8 = 4;
    puVar1 = &DAT_2000a9e4;
    DAT_2000a9f0 = param_3;
    DAT_2000a9f4 = param_2;
    goto LAB_000458d2;
  case 5:
    DAT_2000a9f4 = 0;
    DAT_2000a9f0 = 0;
    DAT_2000a9ec = 3;
    DAT_2000a9e8 = 5;
    break;
  case 6:
    DAT_2000a9ec = 2;
    DAT_2000a9e8 = 6;
    break;
  default:
    if (LOG_LEVEL < 1) {
      return 0xffffffff;
    }
    if (BLE_DEBUG != 0) {
      ble_printk("%s(): unkonown adv command\n","gui_utf_adv_draw_configure",param_3,BLE_DEBUG);
      return 0xffffffff;
    }
    printk("%s(): unkonown adv command\n");
    return 0xffffffff;
  case 8:
    DAT_2000a9d8 = 0;
    DAT_2000a9dc = 0;
    DAT_2000a9e0 = 0;
    DAT_2000a9e4 = 0;
    DAT_2000a9e8 = 0;
    DAT_2000a9ec = 0;
    DAT_2000a9f0 = 0;
    DAT_2000a9f4 = 0;
    DAT_2001db47 = 0;
    DAT_2001db48 = 0;
    return 0xffffffff;
  }
  DAT_2000a9e4 = 0;
  puVar1 = &DAT_2000a9d8;
LAB_000458d2:
  DAT_2001db48 = 0;
  *puVar1 = 0;
  DAT_2000a9e0 = 0;
  DAT_2000a9dc = 1;
  return 0xffffffff;
}


