/*
 * Function: FUN_01035c3c
 * Entry:    01035c3c
 * Prototype: undefined __stdcall FUN_01035c3c(int param_1, char * param_2, char * param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7)
 */


void FUN_01035c3c(int param_1,char *param_2,char *param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  
  if (param_3 == (char *)0x0) {
    param_3 = "";
  }
  FUN_0103bd64(param_2,(int)param_3,0x20);
  *(undefined4 *)(param_2 + 0x24) = param_4;
  *(undefined4 *)(param_2 + 0x28) = param_5;
  *(int *)(param_2 + 0x20) = param_1;
  *(undefined4 *)(param_2 + 0x2c) = param_6;
  *(undefined4 *)(param_2 + 0x30) = param_7;
  uVar1 = *(undefined4 *)(param_1 + 4);
  *(int *)(param_2 + 0x34) = param_1;
  *(undefined4 *)(param_2 + 0x38) = uVar1;
  *(char **)(param_1 + 4) = param_2 + 0x34;
  **(undefined4 **)(param_2 + 0x38) = param_2 + 0x34;
  return;
}


