/*
 * Function: FUN_0103ba90
 * Entry:    0103ba90
 * Prototype: undefined4 __stdcall FUN_0103ba90(int * param_1)
 */


undefined4 FUN_0103ba90(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = 0;
  while ((piVar2 = (int *)*param_1, param_1 != piVar2 && (piVar2 != (int *)0x0))) {
    FUN_01038010(piVar2);
    FUN_0103781c(piVar2);
    uVar1 = 1;
  }
  return uVar1;
}


