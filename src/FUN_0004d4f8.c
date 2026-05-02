/*
 * Function: FUN_0004d4f8
 * Entry:    0004d4f8
 * Prototype: undefined __stdcall FUN_0004d4f8(longlong * param_1)
 */


void FUN_0004d4f8(longlong *param_1)

{
  longlong lVar1;
  
  lVar1 = get_bootSeconds();
  *param_1 = (lVar1 - CONCAT44(DAT_20004fdc,DAT_20004fd8)) + CONCAT44(DAT_20004fd4,DAT_20004fd0);
  return;
}


