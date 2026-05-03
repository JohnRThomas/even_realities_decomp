/*
 * Function: FUN_010330f0
 * Entry:    010330f0
 * Prototype: undefined __stdcall FUN_010330f0(void)
 */


void FUN_010330f0(void)

{
  uint uVar1;
  int extraout_r1;
  int extraout_r1_00;
  
  uVar1 = FUN_0103afcc((uint *)&DAT_2100068c);
  *(uint *)(extraout_r1 + 0x524) = uVar1;
  uVar1 = FUN_0103afcc((uint *)&DAT_21000690);
  *(uint *)(extraout_r1_00 + 0x528) = uVar1;
  return;
}


