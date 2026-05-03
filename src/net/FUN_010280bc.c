/*
 * Function: FUN_010280bc
 * Entry:    010280bc
 * Prototype: undefined4 * __stdcall FUN_010280bc(undefined4 * param_1)
 */


undefined4 * FUN_010280bc(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    *param_1 = *puVar1;
  }
  return puVar1;
}


