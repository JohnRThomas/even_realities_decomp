/*
 * Function: FUN_01027ac2
 * Entry:    01027ac2
 * Prototype: undefined __stdcall FUN_01027ac2(undefined4 * param_1)
 */


void FUN_01027ac2(undefined4 *param_1)

{
  undefined4 *local_10;
  short local_a;
  
  local_a = 0;
  for (local_10 = (undefined4 *)*param_1; local_10 != (undefined4 *)0x0;
      local_10 = (undefined4 *)*local_10) {
    local_a = local_a + *(short *)(local_10 + 1);
  }
  FUN_010279f6(param_1,local_a);
  return;
}


