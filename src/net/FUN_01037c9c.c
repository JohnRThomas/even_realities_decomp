/*
 * Function: FUN_01037c9c
 * Entry:    01037c9c
 * Prototype: undefined __stdcall FUN_01037c9c(int * param_1, undefined4 param_2)
 */


void FUN_01037c9c(int *param_1,undefined4 param_2)

{
  undefined4 extraout_r1;
  int iVar1;
  int extraout_r2;
  uint uVar2;
  
  iVar1 = (int)*(char *)((int)param_1 + 0xd);
  if (iVar1 < 0) {
    uVar2 = *(byte *)((int)param_1 + 0xd) & 0x7f;
    *(char *)((int)param_1 + 0xd) = (char)uVar2;
    FUN_01037b1c(&DAT_21004b40,param_1,iVar1,uVar2);
    param_2 = extraout_r1;
    iVar1 = extraout_r2;
  }
  FUN_01037734((uint)(DAT_21004b30 - (int)param_1 == 0),param_2,iVar1,DAT_21004b30 - (int)param_1);
  return;
}


