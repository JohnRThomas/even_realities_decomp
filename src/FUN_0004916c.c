/*
 * Function: FUN_0004916c
 * Entry:    0004916c
 * Prototype: int __stdcall FUN_0004916c(int param_1)
 */


int FUN_0004916c(int param_1)

{
  int iVar1;
  
  if (param_1 - 1U < 0x10) {
    iVar1 = (int)"%s(): can\'t find resource ,exit .....\n"[param_1 + 0x26];
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


