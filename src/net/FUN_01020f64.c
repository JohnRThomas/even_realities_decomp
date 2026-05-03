/*
 * Function: FUN_01020f64
 * Entry:    01020f64
 * Prototype: undefined __stdcall FUN_01020f64(uint param_1)
 */


/* WARNING: Removing unreachable block (ram,0x01020fd6) */
/* WARNING: Removing unreachable block (ram,0x01020fea) */
/* WARNING: Removing unreachable block (ram,0x01020ff4) */
/* WARNING: Removing unreachable block (ram,0x01020ff6) */
/* WARNING: Removing unreachable block (ram,0x01020ff8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020f64(uint param_1)

{
  uint uVar1;
  bool bVar2;
  short *psVar3;
  undefined2 *puVar4;
  int iVar5;
  uint uVar6;
  uint extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  int unaff_r6;
  undefined8 uVar7;
  
  uVar6 = (uint)DAT_21001625;
  Peripherals::RADIO_NS.PACKETPTR = param_1;
  DAT_21001625 = DAT_21001625 | 1;
  uVar7 = CONCAT44(&Peripherals::RADIO_NS,uVar6 << 0x1e);
  DAT_21001620 = param_1;
  if ((int)(uVar6 << 0x1e) < 0) {
    uVar1 = Peripherals::RADIO_NS.SHORTS;
    Peripherals::RADIO_NS.SHORTS = uVar1 | 1;
    uVar1 = Peripherals::RADIO_NS.STATE;
    if ((uVar1 & 0xf6) != 2) {
      _MasterStackPointer = 0xb83d;
      return;
    }
    uVar7 = FUN_01009500(0x3e,0x5a7,uVar6,2);
    uVar6 = extraout_r2;
  }
  iVar5 = (int)((ulonglong)uVar7 >> 0x20);
  if ((int)(uVar6 << 0x1d) < 0) {
    *(undefined1 **)(iVar5 + 0x88) = &DAT_80000008;
    bVar2 = FUN_010242c4((int)uVar7,iVar5,uVar6,&DAT_80000008);
    if (bVar2) {
      FUN_01009500(0x3e,0x5af,extraout_r2_00,extraout_r3);
      psVar3 = (short *)(unaff_r6 >> 0x17);
      *psVar3 = (short)(unaff_r6 >> 0x17);
                    /* WARNING: Read-only address (ram,0x00000000) is written */
      _MasterStackPointer = 0;
      FUN_01009500(0x3e,0x8d1,&DAT_210015f0,DAT_21001614);
      puVar4 = (undefined2 *)((int)psVar3 >> ((uint)psVar3 & 0xff));
      *puVar4 = (short)puVar4;
      DAT_210015fc = 2;
      if (DAT_21001619 == '\x01') {
        DAT_21001600 = FUN_01021e54((uint)DAT_2100160c,(uint)DAT_21001618,(uint)DAT_21001608,
                                    (int)puVar4);
      }
      else {
        DAT_21001600 = FUN_01021e94((uint)DAT_2100160c,(uint)DAT_21001618,(uint)DAT_21001608);
      }
      Peripherals::TIMER0_NS.EVENTS_COMPARE_1_ = 0;
      Peripherals::TIMER0_NS.CC_1_ = DAT_21001614 + DAT_21001600;
      return;
    }
  }
                    /* WARNING: Read-only address (ram,0x00000000) is written */
  return;
}


