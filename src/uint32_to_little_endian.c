/*
 * Function: uint32_to_little_endian
 * Entry:    0004d590
 * Prototype: undefined4 __stdcall uint32_to_little_endian(undefined1 * param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 uint32_to_little_endian(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): buf is NULL !\n");
      }
      else {
        ble_printk("%s(): buf is NULL !\n","uint32_to_little_endian",param_3,BLE_DEBUG);
      }
    }
    uVar1 = 0;
  }
  else {
    *param_1 = (char)param_2;
    param_1[1] = (char)((uint)param_2 >> 8);
    param_1[2] = (char)((uint)param_2 >> 0x10);
    param_1[3] = (char)((uint)param_2 >> 0x18);
    uVar1 = 1;
  }
  return uVar1;
}


