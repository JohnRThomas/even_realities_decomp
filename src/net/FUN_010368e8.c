/*
 * Function: FUN_010368e8
 * Entry:    010368e8
 * Prototype: bool __stdcall FUN_010368e8(uint * param_1)
 */


bool FUN_010368e8(uint *param_1)

{
  bool bVar1;
  
  bVar1 = *param_1 == (DAT_21004b30 | DAT_21004b38);
  if (bVar1) {
    *param_1 = 0;
  }
  return bVar1;
}


