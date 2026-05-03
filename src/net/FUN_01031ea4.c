/*
 * Function: FUN_01031ea4
 * Entry:    01031ea4
 * Prototype: uint __stdcall FUN_01031ea4(void)
 */


uint FUN_01031ea4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  do {
    if (DAT_21004968 == 0) {
      return 0xfffffff4;
    }
    uVar1 = 0x1f - LZCOUNT(DAT_21004968);
    uVar3 = DAT_21004968 & ~(1 << (uVar1 & 0xff));
    uVar2 = DAT_21004968 >> (uVar1 & 0xff);
    DAT_21004968 = uVar3;
  } while (-1 < (int)(uVar2 << 0x1f));
  return uVar1;
}


