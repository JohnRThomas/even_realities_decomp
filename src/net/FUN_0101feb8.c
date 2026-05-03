/*
 * Function: FUN_0101feb8
 * Entry:    0101feb8
 * Prototype: uint __stdcall FUN_0101feb8(void)
 */


uint FUN_0101feb8(void)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar2;
  uint extraout_r2_01;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar3;
  
  FUN_0101e4c8();
  FUN_0101b69c();
  FUN_0101c398();
  iVar1 = FUN_0101f160();
  DAT_21001050 = &DAT_21001230;
  if (DAT_21001054 == (undefined *)0x0) {
    FUN_01009500(0x32,0x9a9,0,&DAT_21000f90);
    uVar2 = extraout_r2_00;
    uVar3 = extraout_r3_00;
  }
  else {
    DAT_2100104a = 0;
    DAT_2100104c = 0;
    DAT_21001000 = 0;
    FUN_01019d88();
    iVar1 = FUN_010194ac((char)iVar1);
    uVar2 = extraout_r2;
    uVar3 = extraout_r3;
    if (iVar1 == 0) {
      return 0;
    }
  }
  FUN_01009500(0x32,0x9af,uVar2,uVar3);
  DAT_21001054 = &DAT_21000328;
  return extraout_r2_01 >> 0x1e;
}


