/*
 * Function: FUN_01023230
 * Entry:    01023230
 * Prototype: undefined __stdcall FUN_01023230(undefined1 param_1)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01023230(undefined1 param_1)

{
  uint uVar1;
  uint *puVar2;
  int extraout_r2;
  undefined4 extraout_r3;
  int unaff_r6;
  
  if (DAT_2100173a != ' ') {
    DAT_2100171a = param_1;
    _MasterStackPointer = 0x96f3b83d;
    return;
  }
  FUN_01025edc(0x70,0x38b,0x20,&DAT_210016f0);
  uVar1 = unaff_r6 >> 0x1b;
  if (extraout_r2 == 0) {
    Peripherals::DPPIC_NS.CHENCLR = 1 << (uVar1 & 0xff);
    return;
  }
  puVar2 = (uint *)FUN_01025a1c(0,0,extraout_r2,extraout_r3);
  *puVar2 = uVar1 | 0x80000000;
                    /* WARNING: Read-only address (ram,0x00000000) is written */
  _MasterStackPointer = uVar1 | 0x80000000;
  Peripherals::DPPIC_NS.CHENSET = 1 << (uVar1 & 0xff);
  return;
}


