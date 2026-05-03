/*
 * Function: get_flash_burn_info
 * Entry:    00033d24
 * Prototype: undefined4 __stdcall get_flash_burn_info(undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
get_flash_burn_info(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("get_flash_burn_info para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else {
    puVar2 = (undefined1 *)*param_3;
    *puVar2 = 0x35;
    puVar2[2] = 3;
    puVar2[1] = 1;
    puVar2[3] = 1;
    uVar1 = is_ext_flash_burned(param_1,param_2,3);
    puVar2[4] = (char)uVar1;
    uVar1 = 0;
    *param_4 = 5;
  }
  return uVar1;
}


