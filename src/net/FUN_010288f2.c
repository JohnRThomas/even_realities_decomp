/*
 * Function: FUN_010288f2
 * Entry:    010288f2
 * Prototype: bool __stdcall FUN_010288f2(uint param_1)
 */


bool FUN_010288f2(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & param_1 << 1;
  uVar1 = uVar1 & uVar1 << 1;
  uVar1 = uVar1 & uVar1 << 1;
  uVar1 = uVar1 & uVar1 << 1;
  uVar1 = uVar1 & uVar1 << 1;
  return (uVar1 & uVar1 << 1) == 0;
}


