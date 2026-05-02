/*
 * Function: FUN_00053640
 * Entry:    00053640
 * Prototype: undefined __stdcall FUN_00053640(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00053640(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getCurrentExceptionNumber();
    uVar2 = uVar2 & 0x1f;
  }
  iVar3 = (uVar2 - 0x10) * 8;
  (**(code **)(&DAT_0008b554 + iVar3))
            (*(undefined4 *)(&DAT_0008b550 + iVar3),&UNK_0008b558 + iVar3,param_3,
             *(code **)(&DAT_0008b554 + iVar3),param_1);
  if (DAT_2000be48 != DAT_2000be38) {
    _DAT_e000ed04 = 0x10000000;
  }
  return;
}


