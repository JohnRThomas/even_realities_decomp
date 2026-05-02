/*
 * Function: get_mic_info
 * Entry:    00032828
 * Prototype: undefined4 __stdcall get_mic_info(undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
get_mic_info(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("get_mic_info para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else if (DAT_2001abc2 == '\x01') {
    puVar2 = (undefined1 *)*param_3;
    uVar1 = 0;
    *puVar2 = 0x19;
    puVar2[1] = 1;
    puVar2[2] = 3;
    puVar2[3] = 1;
    puVar2[4] = 0;
    *param_4 = 5;
    FUN_0008040c();
    DAT_200100d8 = 0;
    DAT_200085cc = 0;
    DAT_20002420 = 0x400000;
  }
  else {
    printk("warning: not test mode,disable setting\n");
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}


