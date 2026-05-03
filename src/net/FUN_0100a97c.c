/*
 * Function: FUN_0100a97c
 * Entry:    0100a97c
 * Prototype: int __stdcall FUN_0100a97c(ushort param_1, undefined4 param_2, undefined4 param_3)
 */


int FUN_0100a97c(ushort param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_c;
  
  local_c = 0;
  if (DAT_21000bb4 == 0) {
    FUN_01009500(0x18,0xfa,param_3,0);
  }
  if ((param_1 < *(byte *)(DAT_21000bb4 + 8)) &&
     (*(int *)((uint)param_1 * 4 + *(int *)(DAT_21000bb4 + 4)) != 0)) {
    local_c = FUN_01027fa6(*(ushort **)((uint)param_1 * 4 + *(int *)(DAT_21000bb4 + 4)));
  }
  return local_c;
}


