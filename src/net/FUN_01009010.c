/*
 * Function: FUN_01009010
 * Entry:    01009010
 * Prototype: uint __stdcall FUN_01009010(byte * param_1, byte * param_2, int param_3)
 */


uint FUN_01009010(byte *param_1,byte *param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    param_3 = param_3 + -1;
    uVar1 = uVar1 | *param_1 ^ *param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (param_3 != 0);
  return uVar1 - 1 >> 0x1f;
}


