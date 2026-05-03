/*
 * Function: FUN_01034db4
 * Entry:    01034db4
 * Prototype: P1_NS * __stdcall FUN_01034db4(uint * param_1)
 */


P1_NS * FUN_01034db4(uint *param_1)

{
  uint uVar1;
  uint *extraout_r1;
  uint *extraout_r1_00;
  uint *puVar2;
  uint extraout_r2;
  uint extraout_r2_00;
  uint uVar3;
  undefined4 extraout_r3;
  
  uVar1 = FUN_0103b0aa(*param_1);
  puVar2 = extraout_r1;
  uVar3 = extraout_r2;
  if (uVar1 != 0) goto LAB_01034dd8;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
               "WEST_TOPDIR/modules/hal/nordic/nrfx/hal/nrf_gpio.h",0x32f,extraout_r3);
  while( true ) {
    FUN_0103a370();
    puVar2 = extraout_r1_00;
    uVar3 = extraout_r2_00;
LAB_01034dd8:
    *puVar2 = uVar3 & 0x1f;
    if (uVar3 >> 5 == 0) break;
    if (uVar3 >> 5 == 1) {
      return &Peripherals::P1_NS;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/modules/hal/nordic/nrfx/hal/nrf_gpio.h",0x338,uVar3 & 0x1f);
  }
  return (P1_NS *)&Peripherals::P0_NS;
}


