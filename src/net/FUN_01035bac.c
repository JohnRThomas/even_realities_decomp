/*
 * Function: FUN_01035bac
 * Entry:    01035bac
 * Prototype: undefined4 __stdcall FUN_01035bac(int param_1, uint param_2, undefined4 param_3)
 */


undefined4 FUN_01035bac(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 < *(ushort *)(param_1 + 10)) {
    iVar2 = *(int *)(param_1 + 0x20) +
            (*(ushort *)(param_1 + 10) - 1 & (uint)*(ushort *)(*(int *)(param_1 + 0x20) + 2)) * 8;
    *(uint *)(iVar2 + 4) = param_2;
    *(undefined4 *)(iVar2 + 8) = param_3;
    DataMemoryBarrier(0x1b);
    *(short *)(*(int *)(param_1 + 0x20) + 2) = *(short *)(*(int *)(param_1 + 0x20) + 2) + 1;
    *(short *)(param_1 + 0x26) = *(short *)(param_1 + 0x26) + 1;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffff441;
  }
  return uVar1;
}


