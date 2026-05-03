/*
 * Function: FUN_0008304c
 * Entry:    0008304c
 * Prototype: undefined4 __stdcall FUN_0008304c(undefined4 param_1, int param_2, undefined4 * param_3, uint param_4)
 */


undefined4 FUN_0008304c(undefined4 param_1,int param_2,undefined4 *param_3,uint param_4)

{
  undefined4 uVar1;
  undefined4 local_c;
  
  uVar1 = 0;
  local_c = 0;
  if (*(code **)(param_2 + 0x1c) != (code *)0x0) {
    if (param_4 == 4) {
      local_c = *param_3;
      param_4 = (uint)*(ushort *)((int)param_3 + 2);
    }
    else {
      uVar1 = 0xffffffea;
    }
    (**(code **)(param_2 + 0x1c))(param_2 + -8,&local_c,uVar1,param_4,param_1);
  }
  return 1;
}


