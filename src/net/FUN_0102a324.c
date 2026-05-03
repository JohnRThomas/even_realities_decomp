/*
 * Function: FUN_0102a324
 * Entry:    0102a324
 * Prototype: bool __stdcall FUN_0102a324(int param_1)
 */


bool FUN_0102a324(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x10);
  if ((cVar1 != '\0') && (cVar1 != '\x01')) {
    return cVar1 != '\a';
  }
  return false;
}


