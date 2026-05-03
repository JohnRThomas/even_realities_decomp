/*
 * Function: FUN_0101834c
 * Entry:    0101834c
 * Prototype: undefined __stdcall FUN_0101834c(void)
 */


void FUN_0101834c(void)

{
  undefined *puVar1;
  
  puVar1 = FUN_0101b95c(5);
  if (puVar1 != (undefined *)0x0) {
    FUN_010210f0(0,1,(uint)DAT_21001049);
    DAT_21001000 = 0xd;
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


