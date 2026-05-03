/*
 * Function: FUN_0007f798
 * Entry:    0007f798
 * Prototype: undefined4 __stdcall FUN_0007f798(byte * param_1, byte param_2, int * param_3)
 */


undefined4 FUN_0007f798(byte *param_1,byte param_2,int *param_3)

{
  if (((param_1 != (byte *)0x0) && (param_3 != (int *)0x0)) &&
     ((*param_3 != 0 || ((char)param_3[1] == '\0')))) {
    *param_1 = *param_1 | param_2 & 7;
    param_1[1] = *(byte *)(param_3 + 1);
    *(int *)(param_1 + 4) = *param_3;
    return 0;
  }
  return 7;
}


