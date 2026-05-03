/*
 * Function: FUN_010352d8
 * Entry:    010352d8
 * Prototype: undefined __stdcall FUN_010352d8(uint param_1)
 */


void FUN_010352d8(uint param_1)

{
  ushort uVar1;
  uint uVar2;
  
  uVar2 = FUN_01034c94(param_1);
  if ((uVar2 != 0) && (uVar2 = FUN_01034cc8(param_1), uVar2 == 0)) {
    uVar1 = FUN_01034ce0(param_1);
    uVar2 = (uint)uVar1;
    Peripherals::GPIOTE_NS.INTENCLR = 1 << (uVar2 & 0xff);
    (&Peripherals::GPIOTE_NS.CONFIG_0_)[uVar2] =
         (&Peripherals::GPIOTE_NS.CONFIG_0_)[uVar2] & 0xfffffffc;
    return;
  }
  FUN_0103b17e(param_1);
  return;
}


