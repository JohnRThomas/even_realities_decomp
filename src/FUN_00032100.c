/*
 * Function: FUN_00032100
 * Entry:    00032100
 * Prototype: int __stdcall FUN_00032100(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


int FUN_00032100(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined1 local_c;
  undefined3 uStack_b;
  
  _local_c = CONCAT31((int3)((uint)param_4 >> 8),2);
  local_14 = param_1;
  uStack_10 = param_2;
  iVar1 = (**(code **)(*(int *)(DAT_20002418 + 8) + 8))(DAT_20002418,&local_14,1,0x12,param_1);
  return -(uint)(iVar1 != 0);
}


