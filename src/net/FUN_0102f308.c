/*
 * Function: FUN_0102f308
 * Entry:    0102f308
 * Prototype: undefined __stdcall FUN_0102f308(char param_1)
 */


void FUN_0102f308(char param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (-1 < (int)uVar1) {
    *(int *)(&DAT_e000e100 + ((uVar1 >> 5) + 0x20) * 4) = 1 << (uVar1 & 0x1f);
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  return;
}


