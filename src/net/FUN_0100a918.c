/*
 * Function: FUN_0100a918
 * Entry:    0100a918
 * Prototype: int __stdcall FUN_0100a918(ushort param_1, undefined4 param_2, undefined4 param_3)
 */


int FUN_0100a918(ushort param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_c;
  
  local_c = 0;
  if (DAT_21000bb4 == 0) {
    FUN_01009500(0x18,0xec,param_3,0);
  }
  if ((param_1 < *(byte *)(DAT_21000bb4 + 8)) &&
     (*(int *)((uint)param_1 * 4 + *(int *)(DAT_21000bb4 + 4)) != 0)) {
    local_c = FUN_01027f90(*(int *)((uint)param_1 * 4 + *(int *)(DAT_21000bb4 + 4)));
  }
  return local_c;
}


