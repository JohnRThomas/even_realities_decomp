/*
 * Function: FUN_01020968
 * Entry:    01020968
 * Prototype: undefined __stdcall FUN_01020968(int param_1, undefined4 param_2, undefined4 param_3)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020968(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  int iVar3;
  undefined4 extraout_r3;
  int extraout_r3_00;
  int unaff_r6;
  int unaff_r7;
  char local_14 [8];
  
  iVar3 = param_1 + -1;
  DAT_21001608 = (undefined1)param_1;
  switch(param_1) {
  case 1:
    Peripherals::RADIO_NS.MODE = 3;
    break;
  case 2:
    Peripherals::RADIO_NS.MODE = 4;
    uVar1 = Peripherals::FICR_NS._132_4_;
    Peripherals::RADIO_NS._1416_4_ = uVar1;
    goto LAB_01020994;
  default:
    goto switchD_01020976_caseD_3;
  case 4:
    Peripherals::RADIO_NS.MODE = 6;
    break;
  case 8:
    Peripherals::RADIO_NS.MODE = 5;
  }
  uVar1 = Peripherals::FICR_NS._128_4_;
  Peripherals::RADIO_NS._1416_4_ = uVar1;
LAB_01020994:
  uVar2 = (uint)DAT_2100160a;
  Peripherals::RADIO_NS.FREQUENCY = (uint)(byte)(&DAT_0103c490)[uVar2];
  Peripherals::RADIO_NS.DATAWHITEIV = uVar2 & 0x7f;
  if (DAT_210015f7._1_1_ == '\x01') {
    FUN_01021ed4((uint)DAT_210015fa,uVar2,(int)DAT_21001609,(undefined2 *)local_14);
    FUN_01021da8((int)local_14[0]);
    iVar3 = FUN_010220fc();
    if (iVar3 != 0) {
      FUN_01009500(0x3e,0x57e,extraout_r2,extraout_r3);
      param_3 = extraout_r2_00;
      iVar3 = extraout_r3_00;
switchD_01020976_caseD_3:
      FUN_01009500(0x3e,0xd35,param_3,iVar3);
      *(short *)(unaff_r6 >> 0x17) = (short)(unaff_r6 >> 0x17);
      _DAT_210015f4 = unaff_r7 << 7;
      DAT_210015f0 = &DAT_210015f0;
      FUN_01026284(&DAT_210015f0,0,0x48);
      DAT_41000e00 = 0x1111;
      _DAT_41007e40 = 0;
      _DAT_41007e44 = 0;
      _DAT_41007e00 = 0xaa;
      return;
    }
  }
  uVar2 = Peripherals::RADIO_NS.SHORTS;
  Peripherals::RADIO_NS.SHORTS = uVar2 | 0x110;
  uVar2 = Peripherals::RADIO_NS._1384_4_;
  Peripherals::RADIO_NS._1384_4_ = uVar2 | 0x60000;
  return;
}


