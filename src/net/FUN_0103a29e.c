/*
 * Function: FUN_0103a29e
 * Entry:    0103a29e
 * Prototype: int __stdcall FUN_0103a29e(int * param_1)
 */


int FUN_0103a29e(int *param_1)

{
  int iVar1;
  ushort uVar2;
  
  uVar2 = *(ushort *)(param_1 + 7) & 7;
  if ((*(ushort *)(param_1 + 7) & 7) == 0) {
    if (*param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 3;
    }
    return iVar1;
  }
  if (uVar2 != 2) {
    if (uVar2 != 1) {
      return 0;
    }
    if (*param_1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 5;
    }
    return iVar1;
  }
  return (uint)(*(short *)((int)param_1 + 0x1e) == 0) << 2;
}


