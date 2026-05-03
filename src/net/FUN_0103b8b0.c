/*
 * Function: FUN_0103b8b0
 * Entry:    0103b8b0
 * Prototype: bool __stdcall FUN_0103b8b0(int param_1)
 */


bool FUN_0103b8b0(int param_1)

{
  byte bVar1;
  bool bVar2;
  
  bVar2 = false;
  if (param_1 != 0) {
    bVar1 = (*(char **)(param_1 + 0xc))[1];
    bVar2 = (bool)(bVar1 & 1);
    if ((bVar1 & 1) != 0) {
      bVar2 = **(char **)(param_1 + 0xc) == '\0';
    }
  }
  return bVar2;
}


