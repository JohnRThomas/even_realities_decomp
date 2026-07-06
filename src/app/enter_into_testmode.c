/*
 * Function: enter_into_testmode
 * Entry:    00033d94
 * Prototype: undefined4 __stdcall enter_into_testmode(int param_1, uint param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4 enter_into_testmode(int param_1,uint param_2,undefined4 *param_3,undefined1 *param_4)

{
  GlassesState *pGVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  
  if ((((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) || (param_1 == 0)) ||
     (param_2 < 5)) {
    printk("%s para is NULL\n","enter_into_testmode");
    return 0xffffffff;
  }
  puVar3 = (undefined1 *)*param_3;
  *puVar3 = 1;
  puVar3[1] = 1;
  puVar3[2] = 3;
  puVar3[3] = 1;
  if (*(byte *)(param_1 + 4) < 2) {
    if (DAT_2001abc2 != *(byte *)(param_1 + 4)) {
      puVar3[4] = 0;
      __set_test_mode((uint)*(byte *)(param_1 + 4));
      pGVar1 = __get_dashboard_state();
      FUN_0007f556((int)pGVar1);
      goto LAB_00033dda;
    }
    uVar2 = 4;
  }
  else {
    if (BLE_DEBUG == 0) {
      printk("[%s-%d]invalid vaule\n","enter_into_testmode",0xa67);
    }
    else {
      ble_printk("[%s-%d]invalid vaule\n");
    }
    uVar2 = 3;
  }
  puVar3[4] = uVar2;
LAB_00033dda:
  *param_4 = 5;
  return 0;
}


