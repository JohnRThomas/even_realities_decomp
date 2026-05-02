/*
 * Function: FUN_0007f7f2
 * Entry:    0007f7f2
 * Prototype: undefined4 __stdcall FUN_0007f7f2(byte * param_1, int * param_2)
 */


undefined4 FUN_0007f7f2(byte *param_1,int *param_2)

{
  byte bVar1;
  
  if ((param_1 != (byte *)0x0) && (param_2 != (int *)0x0)) {
    if (*param_2 == 0) {
      if ((char)param_2[1] != '\0') {
        return 7;
      }
      bVar1 = *param_1 & 0xf7;
    }
    else {
      bVar1 = *param_1 | 8;
    }
    *param_1 = bVar1;
    *(int *)(param_1 + 8) = *param_2;
    param_1[2] = *(byte *)(param_2 + 1);
    return 0;
  }
  return 7;
}


