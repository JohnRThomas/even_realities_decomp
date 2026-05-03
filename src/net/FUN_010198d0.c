/*
 * Function: FUN_010198d0
 * Entry:    010198d0
 * Prototype: undefined __stdcall FUN_010198d0(void)
 */


void FUN_010198d0(void)

{
  undefined4 in_r3;
  
  if ((DAT_21000ff9 == '\0') && (DAT_21000ff4 != (uint *)0x0)) {
    FUN_01023250((uint)DAT_21000ff8,DAT_21000ff4,0,in_r3);
  }
  if (DAT_2100100c != '\0') {
    FUN_010210b0();
    FUN_010204a8();
    DAT_2100100c = '\0';
  }
  DAT_2100104a = 0;
  DAT_21001000 = 0;
  DAT_2100104c = 0;
  return;
}


