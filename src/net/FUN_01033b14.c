/*
 * Function: FUN_01033b14
 * Entry:    01033b14
 * Prototype: undefined __stdcall FUN_01033b14(void)
 */


void FUN_01033b14(void)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 extraout_r1;
  
  FUN_010346a4();
  FUN_010330c8();
  FUN_01035828(&DAT_21000698);
  FUN_010346f8();
  uVar1 = Peripherals::RADIO_NS.MODECNF0;
  Peripherals::RADIO_NS.MODECNF0 = uVar1 & 0x300;
  DAT_21006458 = 0;
  DAT_21006459 = 0;
  puVar2 = (undefined1 *)FUN_01032f60();
  FUN_0103bdee(puVar2,extraout_r1,0x20);
  DAT_21006256 = 0;
  DAT_2100625a = 0;
  FUN_0103affe();
  return;
}


