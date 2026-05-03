/*
 * Function: FUN_000352c4
 * Entry:    000352c4
 * Prototype: uint __stdcall FUN_000352c4(void)
 */


uint FUN_000352c4(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  uVar2 = 9;
  do {
    iVar1 = uVar2 * 0x1b4;
    if (((&DAT_2000879b)[iVar1] & 1) != 0) {
      uVar2 = uVar2 & 0xff;
      uVar3 = uVar2;
      goto LAB_000352de;
    }
    bVar4 = uVar2 != 0;
    uVar2 = uVar2 - 1;
  } while (bVar4);
  uVar2 = 0xff;
  uVar3 = (byte)(&DAT_2000879b)[iVar1] & 1;
LAB_000352de:
  DAT_2001aef9 = (char)uVar3;
  return uVar2;
}


