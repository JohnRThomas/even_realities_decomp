/*
 * Function: FUN_01034c24
 * Entry:    01034c24
 * Prototype: undefined4 __stdcall FUN_01034c24(uint param_1)
 */


undefined1 * FUN_01034c24(uint param_1)

{
  undefined1 *puVar1;
  
  Peripherals::DPPIC_NS.CHENCLR = 1 << (param_1 & 0xff);
  puVar1 = FUN_01034b28(&DAT_210006a4,param_1);
  return puVar1;
}


