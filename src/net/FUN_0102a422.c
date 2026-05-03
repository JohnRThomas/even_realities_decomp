/*
 * Function: FUN_0102a422
 * Entry:    0102a422
 * Prototype: undefined __stdcall FUN_0102a422(int * param_1)
 */


void FUN_0102a422(int *param_1)

{
  int *piVar1;
  
  if (*param_1 != 0) {
    piVar1 = (int *)*param_1;
    *param_1 = *piVar1;
    *(undefined1 *)piVar1 = 0;
    *(undefined1 *)((int)piVar1 + 1) = 0;
    *(undefined1 *)((int)piVar1 + 2) = 0;
    *(undefined1 *)((int)piVar1 + 3) = 0;
  }
  return;
}


