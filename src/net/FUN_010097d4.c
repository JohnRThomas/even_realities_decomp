/*
 * Function: FUN_010097d4
 * Entry:    010097d4
 * Prototype: undefined4 __stdcall FUN_010097d4(int param_1, uint param_2)
 */


undefined4 FUN_010097d4(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  int extraout_r3;
  undefined4 extraout_r3_00;
  undefined8 uVar3;
  
  if (((param_1 == 0) || (param_2 == 0)) || ((param_2 & 7) != 0)) {
    uVar2 = 0xffffffea;
  }
  else {
    iVar1 = FUN_01009a10();
    if (iVar1 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      DAT_21000a5e = FUN_01025fe4(param_1,extraout_r1,extraout_r2,extraout_r3);
      FUN_01009258(param_2,0);
      FUN_01020414();
      uVar3 = FUN_01020018(DAT_21000a5e,DAT_21000a54);
      FUN_0100957c((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),extraout_r2_00,extraout_r3_00);
      DAT_21000a5c = 1;
      uVar2 = 0;
    }
  }
  return uVar2;
}


