/*
 * Function: FUN_010231a8
 * Entry:    010231a8
 * Prototype: undefined __stdcall FUN_010231a8(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010231a8(void)

{
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  int iVar1;
  
  DAT_21001722 = 0x20;
  DAT_210016f0 = 0;
  DAT_21001739 = 0;
  DAT_2100171a = 0;
  DAT_21001720 = 0x2020;
  DAT_21001726 = 0;
  DAT_2100173a = 0x20;
  DAT_210016f8 = 0xffffffff;
  DAT_210016fc = 0xffffffff;
  DAT_2100173b = 0x20;
  iVar1 = 0;
  DAT_21001727 = 0;
  _DAT_21001718 = 0;
  DAT_21001738 = 0;
  DAT_21001730 = 0xffffffff;
  DAT_21001734 = 0xffffffff;
  do {
    (&DAT_21001740)[iVar1 * 2] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0x20);
  FUN_01024e34();
  DAT_21001728 = 1;
  DAT_21001bc8 = 0xff;
  DAT_21001bc9 = FUN_01025fe4(0x10224ed,extraout_r1,extraout_r2,0xff);
  DAT_21001bc4 = FUN_010260c4();
  FUN_01025344();
  DAT_2100173c = 1;
  return;
}


