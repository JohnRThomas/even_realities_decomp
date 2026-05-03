/*
 * Function: FUN_0103a322
 * Entry:    0103a322
 * Prototype: undefined4 __stdcall FUN_0103a322(undefined1 * param_1, int * param_2)
 */


undefined4 FUN_0103a322(undefined1 *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((((param_1 == (undefined1 *)0x0) || (param_2 == (int *)0x0)) || (*param_2 == 0)) ||
     (param_2[1] == 0)) {
    uVar1 = 0xffffffea;
  }
  else {
    FUN_0103bdee(param_1,0,0x20);
    uVar1 = 0;
    *(int **)(param_1 + 0x10) = param_2;
  }
  return uVar1;
}


