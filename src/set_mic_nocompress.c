/*
 * Function: set_mic_nocompress
 * Entry:    00032940
 * Prototype: undefined4 __stdcall set_mic_nocompress(int param_1, uint param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4 set_mic_nocompress(int param_1,uint param_2,undefined4 *param_3,undefined1 *param_4)

{
  byte bVar1;
  GlassesState *pGVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  
  if ((((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) || (param_1 == 0)) ||
     (param_2 < 5)) {
    printk("%s para is NULL\n","set_mic_nocompress",param_3,param_4,param_4);
    return 0xffffffff;
  }
  if (DAT_2001abc2 != '\x01') {
    printk("warning: not test mode,disable setting\n");
    return 0xfffffffe;
  }
  puVar4 = (undefined1 *)*param_3;
  *puVar4 = 0x3a;
  puVar4[1] = 1;
  puVar4[2] = 3;
  puVar4[3] = 1;
  bVar1 = *(byte *)(param_1 + 4);
  if (bVar1 < 2) {
    pGVar2 = __get_dashboard_state();
    if (pGVar2->field_0x10a4 != bVar1) {
      puVar4[4] = 0;
      pGVar2 = __get_dashboard_state();
      pGVar2->field_0x10a4 = *(undefined1 *)(param_1 + 4);
      goto LAB_0003299c;
    }
    uVar3 = 4;
  }
  else {
    if (BLE_DEBUG == 0) {
      printk("[%s-%d]invalid vaule \n");
    }
    else {
      ble_printk("[%s-%d]invalid vaule \n","set_mic_nocompress",0xaa7,BLE_DEBUG);
    }
    uVar3 = 3;
  }
  puVar4[4] = uVar3;
LAB_0003299c:
  *param_4 = 5;
  return 0;
}


