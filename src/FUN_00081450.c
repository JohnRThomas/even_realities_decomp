/*
 * Function: FUN_00081450
 * Entry:    00081450
 * Prototype: undefined __stdcall FUN_00081450(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_00081450(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_4;
  
  uStack_4 = param_4;
  (**(code **)(param_1 + 0xc))
            (param_2,param_3,&uStack_4,*(code **)(param_1 + 0xc),param_1,&uStack_4,param_3);
  return;
}


