/*
 * Function: chnange_test_image
 * Entry:    00032c08
 * Prototype: undefined4 __stdcall chnange_test_image(int param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
chnange_test_image(int param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("chnange_test_image para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else {
    puVar2 = (undefined1 *)*param_3;
    *puVar2 = 0x28;
    puVar2[2] = 3;
    puVar2[1] = 1;
    puVar2[3] = 1;
    FUN_00038234((uint)*(byte *)(param_1 + 4));
    uVar1 = 0;
    puVar2[4] = 0;
    *param_4 = 5;
  }
  return uVar1;
}


