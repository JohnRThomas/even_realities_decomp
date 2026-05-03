/*
 * Function: FUN_0103b90a
 * Entry:    0103b90a
 * Prototype: bool __stdcall FUN_0103b90a(void)
 */


bool FUN_0103b90a(void)

{
  bool bVar1;
  undefined1 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getCurrentExceptionNumber();
    uVar3 = uVar3 & 0x1f;
  }
  uVar2 = (undefined1)uVar3;
  if (uVar3 != 0) {
    uVar2 = 1;
  }
  return (bool)uVar2;
}


