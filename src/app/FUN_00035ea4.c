/*
 * Function: FUN_00035ea4
 * Entry:    00035ea4
 * Prototype: bool __stdcall FUN_00035ea4(void)
 */


bool FUN_00035ea4(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = FUN_000352f4();
  if (uVar2 != 0) {
    if ((DAT_2001aef8 == '\x05') && (bVar1 = FUN_00035acc(), bVar1 == 1)) {
      return true;
    }
    if (DAT_2001aef8 == '\x03') {
      iVar3 = FUN_00035e5c();
      return iVar3 == 1;
    }
  }
  return false;
}


