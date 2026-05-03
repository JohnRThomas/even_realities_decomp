/*
 * Function: FUN_0100b23c
 * Entry:    0100b23c
 * Prototype: bool __stdcall FUN_0100b23c(uint param_1, byte * param_2, uint param_3, byte * param_4)
 */


bool FUN_0100b23c(uint param_1,byte *param_2,uint param_3,byte *param_4)

{
  return (uint)(param_2[5] ^ param_4[5]) +
         (uint)(param_2[4] ^ param_4[4]) +
         (uint)(param_2[3] ^ param_4[3]) +
         (uint)(param_2[2] ^ param_4[2]) +
         (uint)(param_2[1] ^ param_4[1]) + (uint)(*param_2 ^ *param_4) + (param_1 ^ param_3) == 0;
}


