/*
 * Function: FUN_010108f4
 * Entry:    010108f4
 * Prototype: undefined __stdcall FUN_010108f4(int param_1)
 */


void FUN_010108f4(int param_1)

{
  ulonglong uVar1;
  
  uVar1 = FUN_010200cc();
  *(ulonglong *)(param_1 + 4) = uVar1 & 0x1807f704492f;
  return;
}


