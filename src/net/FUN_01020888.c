/*
 * Function: FUN_01020888
 * Entry:    01020888
 * Prototype: undefined __stdcall FUN_01020888(int param_1)
 */


void FUN_01020888(int param_1)

{
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  
  Peripherals::AAR_NS.ENABLE = 0;
  Peripherals::AAR_NS.ENABLE = 0;
  FUN_0102074c();
  Peripherals::AAR_NS.SUBSCRIBE_START = 0;
  if (param_1 != 1) {
    if (param_1 == 2) {
      Peripherals::AAR_NS.ENABLE = 3;
      Peripherals::AAR_NS.SCRATCHPTR = 0x210014e4;
      Peripherals::AAR_NS.SUBSCRIBE_START = 0x80000003;
      return;
    }
    if (param_1 == 0) {
      return;
    }
    FUN_01009500(0x3d,0x82,extraout_r2,extraout_r3);
  }
  Peripherals::AAR_NS.ENABLE = 2;
  Peripherals::AAR_NS.SCRATCHPTR = 0x210014e4;
  return;
}


