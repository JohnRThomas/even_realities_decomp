/*
 * Function: FUN_0102a338
 * Entry:    0102a338
 * Prototype: bool __stdcall FUN_0102a338(int param_1)
 */


bool FUN_0102a338(int param_1)

{
  bool bVar1;
  
  if (*(char *)(param_1 + 0x10) == '\x01') {
    bVar1 = true;
  }
  else {
    bVar1 = FUN_0102a324(param_1);
  }
  return bVar1;
}


