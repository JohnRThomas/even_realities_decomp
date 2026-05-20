/*
 * Function: dump_ancs
 * Entry:    0004d3f8
 * Prototype: undefined __stdcall dump_ancs(undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4)
 */


void dump_ancs(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar1;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  
  if (BLE_DEBUG == 0) {
    printk("app_identifier:(%s)\n");
    uVar1 = extraout_r2_01;
  }
  else {
    ble_printk("app_identifier:(%s)\n",(char *)(param_2 + 0x10),param_3,BLE_DEBUG);
    uVar1 = extraout_r2;
  }
  if (BLE_DEBUG == 0) {
    printk("message:(%s)\n");
    uVar1 = extraout_r2_02;
  }
  else {
    ble_printk("message:(%s)\n",(char *)(param_2 + 0x90),uVar1,BLE_DEBUG);
    uVar1 = extraout_r2_00;
  }
  if (BLE_DEBUG != 0) {
    ble_printk("uid :(%d)\n",*(char **)(param_2 + 8),uVar1,param_4);
    return;
  }
  printk("uid :(%d)\n");
  return;
}


