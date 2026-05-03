/*
 * Function: FUN_01012b08
 * Entry:    01012b08
 * Prototype: undefined __stdcall FUN_01012b08(int param_1, uint param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_01012b08(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int local_20;
  undefined2 local_1c;
  undefined4 local_18;
  ushort local_14;
  
  local_18 = *(undefined4 *)(param_1 + 8);
  local_14 = *(ushort *)(param_1 + 4);
  local_20 = param_1 + 0x28;
  local_1c = (undefined2)param_4;
  FUN_01012514(param_2,&local_20,(uint)local_14,param_4);
  return;
}


