/*
 * Function: FUN_0103bdee
 * Entry:    0103bdee
 * Prototype: undefined __stdcall FUN_0103bdee(undefined1 * param_1, undefined1 param_2, int param_3)
 */


void FUN_0103bdee(undefined1 *param_1,undefined1 param_2,int param_3)

{
  undefined1 *puVar1;
  
  puVar1 = param_1 + param_3;
  for (; param_1 != puVar1; param_1 = param_1 + 1) {
    *param_1 = param_2;
  }
  return;
}


