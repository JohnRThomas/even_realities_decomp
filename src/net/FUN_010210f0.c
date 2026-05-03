/*
 * Function: FUN_010210f0
 * Entry:    010210f0
 * Prototype: int __stdcall FUN_010210f0(undefined1 param_1, int param_2, uint param_3)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_010210f0(undefined1 param_1,int param_2,uint param_3)

{
  int iVar1;
  short *psVar2;
  uint uVar3;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 unaff_r7;
  char local_24;
  undefined1 local_23;
  int local_20;
  
  _DAT_210015f4 = CONCAT13(param_1,_DAT_210015f4);
  DAT_210015fa = (undefined1)param_3;
  if (param_2 == 0) {
    DAT_210015f7._1_1_ = 1;
    if (DAT_210015f9 == '\x02') {
      FUN_01021ed4(param_3,(uint)DAT_2100160a,(int)DAT_21001609,(undefined2 *)&local_24);
      FUN_01021da8((int)local_24);
      iVar1 = FUN_010220fc();
      if (iVar1 != 0) {
        FUN_01009500(0x3e,0x57e,extraout_r2,extraout_r3);
        psVar2 = (short *)((int)&local_24 >> 0x17);
        DAT_210015f0 = &DAT_210015f0;
        _DAT_210015f4 = unaff_r7;
        *psVar2 = (short)((int)&local_24 >> 0x17);
        Peripherals::TIMER0_NS.CC_0_ = 0;
        return (int)psVar2 >> ((uint)psVar2 & 0xff);
      }
      uVar3 = Peripherals::RADIO_NS.SHORTS;
      Peripherals::RADIO_NS.SHORTS = uVar3 | 0x110;
      goto LAB_01021148;
    }
    uVar3 = (uint)DAT_21001608;
  }
  else {
    DAT_210015f7._1_1_ = 2;
LAB_01021148:
    uVar3 = (uint)DAT_21001608;
    if (DAT_210015f9 == '\x02') {
      local_20 = (uint)DAT_2100160c - (*(int *)(&DAT_0103c500 + uVar3 * 4) + 999U) / 1000;
      goto LAB_01021126;
    }
  }
  local_20 = (uint)DAT_2100160c + (*(ushort *)(&DAT_0103c524 + uVar3 * 2) + 999) / 1000;
LAB_01021126:
  local_23 = param_2 == 0;
  local_24 = '\x01';
  iVar1 = FUN_0102649c((int)&local_24,(uint)(byte)local_23,local_20,1);
  return iVar1;
}


