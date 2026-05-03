/*
 * Function: FUN_010346f8
 * Entry:    010346f8
 * Prototype: undefined __stdcall FUN_010346f8(void)
 */


void FUN_010346f8(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *extraout_r3;
  undefined1 *extraout_r3_00;
  undefined1 *extraout_r3_01;
  undefined1 *extraout_r3_02;
  undefined1 *extraout_r3_03;
  undefined1 *extraout_r3_04;
  
  Peripherals::DPPIC_NS.CHENCLR = 1 << DAT_2100645d;
  Peripherals::RADIO_NS.PUBLISH_DISABLED = 0;
  puVar1 = (undefined1 *)FUN_01034c24((uint)DAT_21006460);
  puVar4 = &DAT_0bad0000;
  if (puVar1 == &DAT_0bad0000) goto LAB_01034736;
  do {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/nrf/subsys/esb/esb_dppi.c",0x13b,
                 puVar4);
    FUN_0103a370();
LAB_01034736:
    puVar2 = (undefined1 *)FUN_01034c24((uint)DAT_2100645f);
    puVar4 = extraout_r3;
  } while ((((puVar2 != puVar1) ||
            (puVar1 = (undefined1 *)FUN_01034c24((uint)DAT_2100645e), puVar4 = extraout_r3_00,
            puVar1 != puVar2)) ||
           (puVar2 = (undefined1 *)FUN_01034c24((uint)DAT_2100645d), puVar4 = extraout_r3_01,
           puVar2 != puVar1)) ||
          (((puVar1 = (undefined1 *)FUN_01034c24((uint)DAT_2100645c), puVar4 = extraout_r3_02,
            puVar1 != puVar2 ||
            (puVar2 = (undefined1 *)FUN_01034c24((uint)DAT_2100645b), puVar4 = extraout_r3_03,
            puVar2 != puVar1)) ||
           (puVar3 = (undefined1 *)FUN_01034c4c((uint)DAT_2100645a), puVar4 = extraout_r3_04,
           puVar3 != puVar2))));
  return;
}


