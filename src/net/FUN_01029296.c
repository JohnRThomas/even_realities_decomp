/*
 * Function: FUN_01029296
 * Entry:    01029296
 * Prototype: undefined4 __stdcall FUN_01029296(undefined4 * param_1)
 */


undefined4 FUN_01029296(undefined4 *param_1)

{
  char cVar1;
  
  cVar1 = FUN_0100b204(0,param_1);
  if (cVar1 == '\0') {
    *param_1 = 0;
    *(undefined2 *)(param_1 + 1) = 0;
  }
  return 0;
}


