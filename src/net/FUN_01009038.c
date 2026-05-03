/*
 * Function: FUN_01009038
 * Entry:    01009038
 * Prototype: uint __stdcall FUN_01009038(byte * param_1, int param_2)
 */


uint FUN_01009038(byte *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    param_2 = param_2 + -1;
    uVar1 = uVar1 | *param_1;
    param_1 = param_1 + 1;
  } while (param_2 != 0);
  return uVar1 - 1 >> 0x1f;
}


