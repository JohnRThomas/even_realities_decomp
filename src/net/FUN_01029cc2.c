/*
 * Function: FUN_01029cc2
 * Entry:    01029cc2
 * Prototype: undefined __stdcall FUN_01029cc2(undefined4 * param_1)
 */


void FUN_01029cc2(undefined4 *param_1)

{
  for (; param_1 != (undefined4 *)0x0; param_1 = (undefined4 *)param_1[1]) {
    (*(code *)*param_1)();
  }
  return;
}


