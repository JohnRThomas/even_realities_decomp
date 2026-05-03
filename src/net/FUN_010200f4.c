/*
 * Function: FUN_010200f4
 * Entry:    010200f4
 * Prototype: undefined __stdcall FUN_010200f4(void)
 */


void FUN_010200f4(void)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = FUN_01024ecc();
  iVar2 = 0;
  do {
    if (uVar1 <= (ushort)(&DAT_0103c370)[iVar2 * 2]) {
      DAT_2100144a = (&DAT_0103c372)[iVar2 * 4];
      return;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0xc);
  DAT_2100144a = 0;
  return;
}


