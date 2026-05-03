/*
 * Function: FUN_0100af90
 * Entry:    0100af90
 * Prototype: undefined __stdcall FUN_0100af90(void)
 */


void FUN_0100af90(void)

{
  FUN_0100af18();
  FUN_0100af60();
  FUN_0100afcc();
  Peripherals::DPPIC_NS.CHENCLR = 0x1ff8;
  return;
}


