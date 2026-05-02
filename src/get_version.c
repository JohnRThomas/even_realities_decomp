/*
 * Function: get_version
 * Entry:    000321e0
 * Prototype: undefined4 __stdcall get_version(undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
get_version(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("get_version para is NULL\n");
    uVar2 = 0xffffffff;
  }
  else {
    puVar3 = (undefined1 *)*param_3;
    *puVar3 = 0x24;
    if (DAT_2001abc2 == '\x01') {
      uVar1 = 0x5b;
    }
    else {
      uVar1 = 1;
    }
    puVar3[1] = 1;
    puVar3[4] = uVar1;
    puVar3[2] = 3;
    puVar3[5] = 6;
    puVar3[3] = 3;
    puVar3[6] = 3;
    uVar2 = 0;
    *param_4 = 7;
  }
  return uVar2;
}


