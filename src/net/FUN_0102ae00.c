/*
 * Function: FUN_0102ae00
 * Entry:    0102ae00
 * Prototype: undefined4 __stdcall FUN_0102ae00(void)
 */


undefined4 FUN_0102ae00(void)

{
  int iVar1;
  
  if (DAT_2100057c == -0x10) {
    iVar1 = FUN_0102dd08();
    if (iVar1 == -0x10) {
      return 1;
    }
    DAT_20070000 = 0xa5a5a5a5;
    DAT_2100057c = iVar1;
    if (1 < DAT_21000580) {
      FUN_01039ee2((byte *)"SYNC, offset %d\n",iVar1,0xa5a5a5a5,DAT_21000580);
    }
  }
  return 0;
}


