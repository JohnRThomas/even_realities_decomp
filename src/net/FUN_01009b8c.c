/*
 * Function: FUN_01009b8c
 * Entry:    01009b8c
 * Prototype: uint __stdcall FUN_01009b8c(int param_1)
 */


uint FUN_01009b8c(int param_1)

{
  return (uint)(&DAT_21000008)[(param_1 - 1U) * 0x1000000 >> 0x1d] >> (param_1 - 1U & 0x1f) & 1;
}


