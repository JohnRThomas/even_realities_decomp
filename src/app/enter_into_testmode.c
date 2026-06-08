/*
 * Function: enter_into_testmode
 * Entry:    00033d94
 * Prototype: undefined4 __stdcall enter_into_testmode(int param_1, uint param_2, undefined4 * param_3, undefined1 * param_4)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 enter_into_testmode(int param_1,uint param_2,undefined4 *param_3,undefined1 *param_4)

{
  GlassesState *pGVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  
  if ((((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) || (param_1 == 0)) ||
     (param_2 < 5)) {
    printk("%s para is NULL\n","enter_into_testmode");
    return 0xffffffff;
  }
  puVar4 = (undefined1 *)*param_3;
  *puVar4 = 1;
  puVar4[1] = 1;
  puVar4[2] = 3;
  puVar4[3] = 1;
  if (*(byte *)(param_1 + 4) < 2) {
    uVar2 = (uint)DAT_2001abc2;
    if (uVar2 != *(byte *)(param_1 + 4)) {
      puVar4[4] = 0;
      __set_test_mode((char *)(uint)*(byte *)(param_1 + 4),param_2,uVar2);
      pGVar1 = __get_dashboard_state();
      FUN_0007f556((int)pGVar1);
      goto LAB_00033dda;
    }
    uVar3 = 4;
  }
  else {
    if (BLE_DEBUG == 0) {
      printk("[%s-%d]invalid vaule\n");
    }
    else {
      ble_printk("[%s-%d]invalid vaule\n","enter_into_testmode",0xa67,BLE_DEBUG);
    }
    uVar3 = 3;
  }
  puVar4[4] = uVar3;
LAB_00033dda:
  *param_4 = 5;
  return 0;
}


