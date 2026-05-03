/*
 * Function: FUN_010183a4
 * Entry:    010183a4
 * Prototype: undefined __stdcall FUN_010183a4(void)
 */


void FUN_010183a4(void)

{
  undefined *puVar1;
  
  puVar1 = FUN_0101b95c(3);
  if (puVar1 != (undefined *)0x0) {
    FUN_01016ae0(3);
    FUN_010210f0(0,1,1);
    DAT_21001000 = 0xb;
    return;
  }
  puVar1 = (undefined *)0x0;
  if (DAT_2100100c != '\0') {
    FUN_010210b0();
    puVar1 = (undefined *)FUN_010204a8();
    DAT_2100100c = '\0';
  }
  DAT_2100104a = 0;
  DAT_21001000 = 1;
  DAT_2100104c = 0;
  FUN_0101bcf4(puVar1);
  return;
}


