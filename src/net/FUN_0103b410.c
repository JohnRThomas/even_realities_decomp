/*
 * Function: FUN_0103b410
 * Entry:    0103b410
 * Prototype: int __stdcall FUN_0103b410(int param_1, ushort * param_2, undefined4 * param_3)
 */


int FUN_0103b410(int param_1,ushort *param_2,undefined4 *param_3)

{
  ushort uVar1;
  int iVar2;
  
  DataMemoryBarrier(0x1b);
  uVar1 = *(ushort *)(param_1 + 0x30);
  if ((uint)*(ushort *)(*(int *)(param_1 + 0x1c) + 2) == (uint)uVar1) {
    iVar2 = 0;
  }
  else {
    *(ushort *)(param_1 + 0x30) = uVar1 + 1;
    uVar1 = *(ushort *)
             (*(int *)(param_1 + 0x1c) + ((uint)uVar1 & *(ushort *)(param_1 + 10) - 1) * 2 + 4);
    *param_2 = uVar1;
    iVar2 = FUN_0103b37e(*(int **)(param_1 + 0x28),
                         *(uint *)(*(int *)(param_1 + 0x18) + (uint)uVar1 * 0x10));
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x18) + (uint)*param_2 * 0x10 + 8);
  }
  return iVar2;
}


