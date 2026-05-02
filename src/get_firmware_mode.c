/*
 * Function: get_firmware_mode
 * Entry:    00032f3c
 * Prototype: undefined4 __stdcall get_firmware_mode(int param_1, uint param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4 get_firmware_mode(int param_1,uint param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if ((((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) || (param_1 == 0)) ||
     (param_2 < 4)) {
    printk("%s para is NULL\n","get_firmware_mode",param_3,param_4,param_4);
    uVar1 = 0xffffffff;
  }
  else {
    puVar2 = (undefined1 *)*param_3;
    puVar2[1] = 1;
    puVar2[2] = 3;
    *puVar2 = 4;
    puVar2[3] = DAT_2001abc2;
    uVar1 = 0;
    *param_4 = 4;
  }
  return uVar1;
}


