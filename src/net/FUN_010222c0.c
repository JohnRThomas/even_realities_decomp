/*
 * Function: FUN_010222c0
 * Entry:    010222c0
 * Prototype: int __stdcall FUN_010222c0(uint param_1)
 */


int FUN_010222c0(uint param_1)

{
  int iVar1;
  
  if (param_1 < DAT_210016e8) {
    iVar1 = param_1 * 0x30 + DAT_210016e4;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


