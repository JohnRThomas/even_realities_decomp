/*
 * Function: FUN_010194ac
 * Entry:    010194ac
 * Prototype: undefined4 __stdcall FUN_010194ac(undefined1 param_1)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_010194ac(undefined1 param_1)

{
  if ((DAT_21001000 != '\x01') && (DAT_21001000 != '\0')) {
    return 0xc;
  }
  FUN_0100ad78();
  FUN_01019d88();
  if (DAT_2100100c != '\0') {
    FUN_010210b0();
    FUN_010204a8();
    DAT_2100100c = '\0';
  }
  FUN_01026284((undefined4 *)&DAT_21000f90,0,0x42);
  DAT_21000fe9 = param_1;
  DAT_2100100a = 0;
  DAT_21001038 = 0;
  DAT_21000ff8 = 0;
  DAT_21000ff4 = 0;
  DAT_21000ff9 = 0;
  DAT_2100103b = 0;
  DAT_2100104d = 1;
  DAT_2100103c = 0;
  DAT_21000fd4 = 0;
  _DAT_21000fe4 = 0x201;
  _DAT_21000fdc = 0x107;
  DAT_21000fe7 = 0;
  return 0;
}


