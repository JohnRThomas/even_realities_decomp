/*
 * Function: FUN_00087c90
 * Entry:    00087c90
 * Prototype: undefined __stdcall FUN_00087c90(int * param_1, undefined1 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_00087c90(int *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_29;
  undefined1 *local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined1 local_14;
  
  local_28 = &local_29;
  local_24 = 1;
  local_20 = 0;
  local_14 = 2;
  local_29 = param_2;
  local_1c = param_3;
  uStack_18 = param_4;
  (**(code **)(*(int *)(*param_1 + 8) + 8))(*param_1,&local_28,2,(short)param_1[1]);
  return;
}


