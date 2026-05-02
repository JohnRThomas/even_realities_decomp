/*
 * Function: get_role_info_right
 * Entry:    00032c40
 * Prototype: undefined4 __stdcall get_role_info_right(undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
get_role_info_right(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  bool bVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("get_role_info_right para is NULL\n");
    uVar2 = 0xffffffff;
  }
  else {
    puVar3 = (undefined1 *)*param_3;
    *puVar3 = 0x2b;
    puVar3[2] = 3;
    puVar3[1] = 1;
    puVar3[3] = 1;
    bVar1 = __is_master();
    if (bVar1) {
      puVar3[4] = bVar1;
    }
    else {
      bVar1 = __is_master();
      if (bVar1 == true) {
        puVar3[4] = 0;
      }
    }
    uVar2 = 0;
    *param_4 = 5;
  }
  return uVar2;
}


