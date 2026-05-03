/*
 * Function: FUN_01012950
 * Entry:    01012950
 * Prototype: byte __stdcall FUN_01012950(int param_1)
 */


byte FUN_01012950(int param_1)

{
  byte bVar1;
  
  if ((*(char *)(param_1 + 0x84) == '\0') && (*(char *)(param_1 + 0xbc) == '\0')) {
    if (*(char *)(param_1 + 0xae) == '\0') {
      return 0;
    }
    bVar1 = FUN_01020088();
    return bVar1 ^ 1;
  }
  return 1;
}


