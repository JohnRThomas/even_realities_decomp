/*
 * Function: FUN_01020f38
 * Entry:    01020f38
 * Prototype: undefined __stdcall FUN_01020f38(undefined4 * param_1)
 */


/* WARNING: Removing unreachable block (ram,0x01020fd6) */
/* WARNING: Removing unreachable block (ram,0x01020fea) */
/* WARNING: Removing unreachable block (ram,0x01020ff4) */
/* WARNING: Removing unreachable block (ram,0x01020ff6) */
/* WARNING: Removing unreachable block (ram,0x01020ff8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020f38(undefined4 *param_1)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  short *psVar4;
  undefined2 *puVar5;
  undefined4 extraout_r2;
  uint uVar6;
  uint extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  int unaff_r6;
  undefined8 uVar7;
  
  iVar3 = FUN_010263d4();
  if (iVar3 == 0) {
    DAT_2100163c = *param_1;
    DAT_21001640 = param_1[1];
    DAT_21001644 = param_1[2];
    DAT_21001648 = param_1[3];
    return;
  }
  DAT_21001620 = FUN_01009500(0x3e,0x8c0,extraout_r2,extraout_r3);
  uVar6 = (uint)DAT_21001625;
  Peripherals::RADIO_NS.PACKETPTR = DAT_21001620;
  DAT_21001625 = DAT_21001625 | 1;
  uVar7 = CONCAT44(&Peripherals::RADIO_NS,uVar6 << 0x1e);
  if ((int)(uVar6 << 0x1e) < 0) {
    uVar1 = Peripherals::RADIO_NS.SHORTS;
    Peripherals::RADIO_NS.SHORTS = uVar1 | 1;
    uVar1 = Peripherals::RADIO_NS.STATE;
    if ((uVar1 & 0xf6) != 2) {
      return;
    }
    uVar7 = FUN_01009500(0x3e,0x5a7,uVar6,2);
    uVar6 = extraout_r2_00;
  }
  iVar3 = (int)((ulonglong)uVar7 >> 0x20);
  if ((int)(uVar6 << 0x1d) < 0) {
    *(undefined1 **)(iVar3 + 0x88) = &DAT_80000008;
    bVar2 = FUN_010242c4((int)uVar7,iVar3,uVar6,&DAT_80000008);
    if (bVar2) {
      FUN_01009500(0x3e,0x5af,extraout_r2_01,extraout_r3_00);
      psVar4 = (short *)(unaff_r6 >> 0x17);
      *psVar4 = (short)(unaff_r6 >> 0x17);
                    /* WARNING: Read-only address (ram,0x00000000) is written */
      _MasterStackPointer = 0;
      FUN_01009500(0x3e,0x8d1,&DAT_210015f0,DAT_21001614);
      puVar5 = (undefined2 *)((int)psVar4 >> ((uint)psVar4 & 0xff));
      *puVar5 = (short)puVar5;
      DAT_210015fc = 2;
      if (DAT_21001619 == '\x01') {
        DAT_21001600 = FUN_01021e54((uint)DAT_2100160c,(uint)DAT_21001618,(uint)DAT_21001608,
                                    (int)puVar5);
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


