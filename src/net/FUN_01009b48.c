/*
 * Function: FUN_01009b48
 * Entry:    01009b48
 * Prototype: undefined __stdcall FUN_01009b48(uint * param_1)
 */


void FUN_01009b48(uint *param_1)

{
  DAT_21000000 = *param_1 | 0x46000;
  DAT_21000004 = param_1[1] | 0x24007f8;
  return;
}


