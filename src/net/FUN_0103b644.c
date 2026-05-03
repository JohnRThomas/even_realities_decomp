/*
 * Function: FUN_0103b644
 * Entry:    0103b644
 * Prototype: undefined __stdcall FUN_0103b644(char * param_1, undefined4 param_2)
 */


void FUN_0103b644(char *param_1,undefined4 param_2)

{
  undefined4 extraout_r1;
  
  if ((param_1 != (char *)0x0) && (*(int *)(param_1 + 0x20) != 0)) {
    if (((*param_1 != '\0') && (*(char *)(*(int *)(param_1 + 0x20) + 0x90) != '\0')) &&
       (0x3ff < *(uint *)(param_1 + 0x24))) {
      FUN_0103b568((int)param_1,1);
      param_2 = extraout_r1;
    }
    FUN_0103b516((int)param_1,param_2);
    return;
  }
  return;
}


