/*
 * Function: FUN_0100ced8
 * Entry:    0100ced8
 * Prototype: undefined __stdcall FUN_0100ced8(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0100ced8(void)

{
  uint uVar1;
  
  uVar1 = (uint)(char)(*(char *)(_FUN_0100cefc + 1) + -1);
  if ((int)uVar1 < 0) {
    return;
  }
  do {
    FUN_0100c22c(uVar1 & 0xff);
    uVar1 = (uint)(char)((char)uVar1 + -1);
  } while (uVar1 != 0xffffffff);
  return;
}


