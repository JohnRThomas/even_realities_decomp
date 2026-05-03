/*
 * Function: FUN_010345b0
 * Entry:    010345b0
 * Prototype: undefined4 __stdcall FUN_010345b0(void)
 */


undefined4 FUN_010345b0(void)

{
  byte local_28 [4];
  char *local_24;
  undefined1 *puStack_20;
  
  puStack_20 = (undefined1 *)FUN_01034c18(&DAT_21006460);
  if ((((puStack_20 == &DAT_0bad0000) &&
       (puStack_20 = (undefined1 *)FUN_01034c18(&DAT_2100645f), puStack_20 == &DAT_0bad0000)) &&
      (puStack_20 = (undefined1 *)FUN_01034c18(&DAT_2100645e), puStack_20 == &DAT_0bad0000)) &&
     (((puStack_20 = (undefined1 *)FUN_01034c18(&DAT_2100645d), puStack_20 == &DAT_0bad0000 &&
       (puStack_20 = (undefined1 *)FUN_01034c18(&DAT_2100645c), puStack_20 == &DAT_0bad0000)) &&
      (puStack_20 = (undefined1 *)FUN_01034c18(&DAT_2100645b), puStack_20 == &DAT_0bad0000)))) {
    puStack_20 = (undefined1 *)FUN_01034c40(&DAT_2100645a);
    if (puStack_20 == &DAT_0bad0000) {
      Peripherals::RADIO_NS.PUBLISH_DISABLED = DAT_2100645d | 0x80000000;
      Peripherals::DPPIC_NS.CHENSET = 1 << (uint)DAT_2100645d;
      return 0;
    }
    local_24 = "gppi_group_alloc failed with: %d\n";
    local_28[0] = 3;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    FUN_0102ea44(0x103c01c,0x1840,local_28,(undefined1 *)0x0);
  }
  else {
    local_24 = "gppi_channel_alloc failed with: %d\n";
    local_28[0] = 3;
    local_28[1] = 0;
    local_28[2] = 0;
    local_28[3] = 0;
    FUN_0102ea44(0x103c01c,0x1840,local_28,(undefined1 *)0x0);
  }
  return 0xffffffed;
}


