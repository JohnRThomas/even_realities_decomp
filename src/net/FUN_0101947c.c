/*
 * Function: FUN_0101947c
 * Entry:    0101947c
 * Prototype: undefined4 __stdcall FUN_0101947c(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0101947c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  byte extraout_var;
  
  if (DAT_21000fe0 != (undefined2 *)0x0) {
    DAT_21000f99 = 2;
    DAT_21000f9a = *DAT_21000fe0;
    uVar1 = FUN_0100f788((undefined4 *)&DAT_21000f90,0x10175c9,2);
    DAT_21000fe0 = (undefined2 *)0x0;
    return uVar1;
  }
  FUN_01009500(0x32,0x423,param_3,0);
                    /* WARNING: Read-only address (ram,0x00000017) is written */
  uRam00000017 = 0;
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
  DAT_21000fe9 = extraout_var >> 6;
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


