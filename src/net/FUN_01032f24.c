/*
 * Function: FUN_01032f24
 * Entry:    01032f24
 * Prototype: undefined4 __stdcall FUN_01032f24(void)
 */


undefined4 FUN_01032f24(void)

{
  Peripherals::RADIO_NS.MODE = (uint)DAT_21004a9c;
  switch((uint)DAT_21004a9c) {
  case 0:
  case 3:
    DAT_210049a4 = 300;
    break;
  case 1:
  case 4:
    DAT_210049a4 = 0xa0;
    break;
  default:
    return 0;
  }
  return 1;
}


