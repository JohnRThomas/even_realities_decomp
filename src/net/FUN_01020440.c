/*
 * Function: FUN_01020440
 * Entry:    01020440
 * Prototype: undefined __stdcall FUN_01020440(uint param_1, uint param_2, int param_3)
 */


void FUN_01020440(uint param_1,uint param_2,int param_3)

{
  FUN_01020888(2);
  DAT_210014d8 = 1;
  Peripherals::AAR_NS.ADDRPTR = param_3 - 3;
  Peripherals::AAR_NS.IRKPTR = param_1;
  Peripherals::AAR_NS.NIRK = param_2;
  return;
}


