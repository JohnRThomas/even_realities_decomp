/*
 * Function: FUN_01028094
 * Entry:    01028094
 * Prototype: undefined4 * __stdcall FUN_01028094(undefined4 * param_1)
 */


undefined4 * FUN_01028094(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    *param_1 = *puVar1;
  }
  return puVar1;
}


