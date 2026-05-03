/*
 * Function: FUN_0100b434
 * Entry:    0100b434
 * Prototype: undefined __stdcall FUN_0100b434(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0100b434(void)

{
  FUN_01020d00();
  FUN_0102074c();
  (*DAT_21000c7c)(DAT_21000c78,0);
  if (DAT_21000c60 != '\0') {
    DAT_21000c54 = DAT_21000c48;
    DAT_21000c58 = _DAT_21000c4c;
    DAT_21000c5c = ram0x21000c50;
    FUN_0100f7c8((undefined4 *)&DAT_21000c61,0x100b381,2);
  }
  (*DAT_21000c88)(DAT_21000c86,DAT_21000c85);
  DAT_21000c8c = 0;
  return;
}


