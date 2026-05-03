/*
 * Function: FUN_0006b3a0
 * Entry:    0006b3a0
 * Prototype: undefined4 __stdcall FUN_0006b3a0(undefined4 * param_1)
 */


undefined4 FUN_0006b3a0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[10];
  *(undefined4 **)(param_1[9] + 4) = puVar1;
  *puVar1 = param_1[9];
  param_1[9] = param_1 + 9;
  param_1[10] = param_1 + 9;
  if ((code *)param_1[1] != (code *)0x0) {
    (*(code *)param_1[1])();
  }
  if ((6 < DAT_2000be0c) && (DAT_2000be10 != (code *)0x0)) {
    (*DAT_2000be10)(7,"unregistered %s bus\n",*param_1);
  }
  return 0;
}


