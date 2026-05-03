/*
 * Function: set_aging_test_info
 * Entry:    00033f58
 * Prototype: undefined4 __stdcall set_aging_test_info(int param_1, uint param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4 set_aging_test_info(int param_1,uint param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  if ((((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) || (param_1 == 0)) ||
     (param_2 < 5)) {
    printk("%s para is NULL\n","set_aging_test_info",param_3,param_4,param_4);
    return 0xffffffff;
  }
  if (DAT_2001abc2 != '\x01') {
    printk("warning: not test mode,disable setting\n");
    return 0xfffffffe;
  }
  puVar2 = (undefined1 *)*param_3;
  *puVar2 = 0x3e;
  puVar2[1] = 1;
  puVar2[2] = 3;
  puVar2[3] = 1;
  if (*(byte *)(param_1 + 4) < 2) {
    if (DAT_2001abc0 != *(byte *)(param_1 + 4)) {
      puVar2[4] = 0;
      if (*(char *)(param_1 + 4) == '\0') {
        FUN_00033f24();
      }
      else if (*(char *)(param_1 + 4) == '\x01') {
        FUN_00033e44();
      }
      goto LAB_00033fb2;
    }
    uVar1 = 4;
  }
  else {
    if (BLE_DEBUG == 0) {
      printk("[%s-%d]invalid vaule \n");
    }
    else {
      ble_printk("[%s-%d]invalid vaule \n","set_aging_test_info",0xb1c,BLE_DEBUG);
    }
    uVar1 = 3;
  }
  puVar2[4] = uVar1;
LAB_00033fb2:
  *param_4 = 5;
  return 0;
}


