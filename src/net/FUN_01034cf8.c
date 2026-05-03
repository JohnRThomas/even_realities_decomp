/*
 * Function: FUN_01034cf8
 * Entry:    01034cf8
 * Prototype: undefined __stdcall FUN_01034cf8(uint param_1)
 */


void FUN_01034cf8(uint param_1)

{
  uint uVar1;
  undefined4 extraout_r1;
  
  uVar1 = FUN_01034c68(param_1);
  uVar1 = (uint)*(ushort *)((int)&DAT_210006a8 + (uVar1 + 8) * 2);
  if ((int)(uVar1 << 0x17) < 0) {
    (*(code *)(&DAT_210006a8)[((uVar1 << 0x13) >> 0x1c) * 2])(param_1);
  }
  if (DAT_210006b0 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x01034d2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_210006b0)(param_1,extraout_r1,DAT_210006b4);
    return;
  }
  return;
}


