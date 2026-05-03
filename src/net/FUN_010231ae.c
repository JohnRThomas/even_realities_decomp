/*
 * Function: FUN_010231ae
 * Entry:    010231ae
 * Prototype: undefined __stdcall FUN_010231ae(int param_1, undefined4 param_2, undefined2 param_3)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010231ae(int param_1,undefined4 param_2,undefined2 param_3)

{
  undefined1 uVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  
  DAT_21001722 = 0x20;
  uVar1 = (undefined1)param_1;
  DAT_2100173a = 0x20;
  DAT_210016f8 = 0xffffffff;
  DAT_210016fc = 0xffffffff;
  DAT_2100173b = 0x20;
  _DAT_21001718 = (undefined2)param_1;
  DAT_21001730 = 0xffffffff;
  DAT_21001734 = 0xffffffff;
  DAT_210016f0 = param_1;
  DAT_2100171a = uVar1;
  DAT_21001720 = param_3;
  DAT_21001726 = uVar1;
  DAT_21001727 = uVar1;
  DAT_21001738 = uVar1;
  DAT_21001739 = uVar1;
  do {
    (&DAT_21001740)[param_1 * 2] = uVar1;
    param_1 = param_1 + 1;
  } while (param_1 != 0x20);
  FUN_01024e34();
  DAT_21001728 = 1;
  DAT_21001bc8 = 0xff;
  DAT_21001bc9 = FUN_01025fe4(0x10224ed,extraout_r1,extraout_r2,0xff);
  DAT_21001bc4 = FUN_010260c4();
  FUN_01025344();
  DAT_2100173c = 1;
  return;
}


