/*
 * Function: navigation_direction_img_display
 * Entry:    00040308
 * Prototype: undefined __stdcall navigation_direction_img_display(int param_1, undefined4 param_2, undefined4 param_3)
 */


void navigation_direction_img_display(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  
  if (param_1 - 1U < 0x23) {
    iVar2 = FUN_000809e2();
    uVar1 = FUN_00080a3a();
    gui_bmp_bitmap_draw(param_1 + 0x60,iVar2,uVar1 + 0x39,0,0,0);
  }
  else if (1 < LOG_LEVEL) {
    if (BLE_DEBUG != 0) {
      ble_printk("%s(): navigation direction parampter error\n","navigation_direction_img_display",
                 param_3,BLE_DEBUG);
      return;
    }
    printk("%s(): navigation direction parampter error\n");
    return;
  }
  return;
}


