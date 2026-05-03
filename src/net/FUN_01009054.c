/*
 * Function: FUN_01009054
 * Entry:    01009054
 * Prototype: undefined __stdcall FUN_01009054(byte * param_1, byte * param_2, byte * param_3, int param_4)
 */


void FUN_01009054(byte *param_1,byte *param_2,byte *param_3,int param_4)

{
  do {
    *param_1 = *param_2 ^ *param_3;
    param_4 = param_4 + -1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    param_3 = param_3 + 1;
  } while (param_4 != 0);
  return;
}


