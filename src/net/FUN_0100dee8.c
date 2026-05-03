/*
 * Function: FUN_0100dee8
 * Entry:    0100dee8
 * Prototype: bool __stdcall FUN_0100dee8(int param_1, uint param_2, int * param_3, int * param_4)
 */


bool FUN_0100dee8(int param_1,uint param_2,int *param_3,int *param_4)

{
  uint uVar1;
  
  if (param_2 < param_1 - 0x1d8U) {
    uVar1 = 0;
  }
  else {
    uVar1 = param_2 - (param_1 - 0x1d8U);
  }
  *param_4 = *param_4 + (uVar1 >> 1);
  *param_3 = *param_3 - (uVar1 >> 1);
  return 1 < uVar1;
}


