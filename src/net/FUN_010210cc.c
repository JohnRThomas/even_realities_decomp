/*
 * Function: FUN_010210cc
 * Entry:    010210cc
 * Prototype: undefined4 __stdcall FUN_010210cc(char * param_1)
 */


undefined4 FUN_010210cc(char *param_1)

{
  uint uVar1;
  
  uVar1 = Peripherals::RADIO_NS.RSSISAMPLE;
  *param_1 = -((byte)uVar1 & 0x7f);
  return 1;
}


