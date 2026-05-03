/*
 * Function: FUN_01020afc
 * Entry:    01020afc
 * Prototype: undefined __stdcall FUN_01020afc(uint param_1, undefined4 param_2, undefined4 param_3)
 */


/* WARNING: Removing unreachable block (ram,0x01020b90) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020afc(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint extraout_r2;
  byte *extraout_r2_00;
  uint uVar5;
  uint extraout_r3;
  int iVar6;
  int iVar7;
  
  DAT_21001624 = (undefined1)param_1;
  switch(param_2) {
  case 1:
    puVar3 = &DAT_00100108;
    break;
  case 2:
    puVar3 = &DAT_01100108;
    break;
  default:
    FUN_01009500(0x3e,0x2dc,param_3,&DAT_210015f0);
    uVar4 = extraout_r2;
    uVar5 = extraout_r3;
    goto LAB_01020b46;
  case 4:
  case 8:
    puVar3 = &DAT_63900108;
  }
  uVar4 = param_1 | 0x2030000;
  Peripherals::RADIO_NS.PCNF0 = (uint)puVar3;
  Peripherals::RADIO_NS.PCNF1 = uVar4;
  uVar5 = Peripherals::RADIO_NS.STATE;
  uVar5 = uVar5 & 0xf7;
  if (uVar5 != 3) {
    _MasterStackPointer = 0xb83d;
    return;
  }
LAB_01020b46:
  FUN_01009500(0x3e,0x2f4,uVar4,uVar5);
  extraout_r2_00[0x38] = 0;
  extraout_r2_00[0x39] = 0;
  extraout_r2_00[0x3a] = 0;
  extraout_r2_00[0x3b] = 0;
                    /* WARNING (jumptable): Read-only address (ram,0x00000000) is written */
                    /* WARNING: Read-only address (ram,0x00000000) is written */
  _MasterStackPointer = 0;
  Peripherals::RADIO_NS._428_4_ = 0x80000006;
  if (*extraout_r2_00 == 3) {
    uVar5 = Peripherals::RADIO_NS.PCNF0;
    Peripherals::RADIO_NS.PCNF0 = uVar5 & 0xfff0ffff;
    Peripherals::RADIO_NS.DFEMODE = DAT_21001604 | 3;
    Peripherals::RADIO_NS.DFECTRL1 = extraout_r2_00[1] & 0x3f | 0x23280;
    DAT_21001604 = DAT_21001604 | 3;
    DAT_21001634 = 1;
    return;
  }
  puVar2 = (undefined2 *)FUN_01009500(0x3e,0x349,(uint)*extraout_r2_00,&Peripherals::RADIO_NS);
  *puVar2 = (short)puVar2;
  *puVar2 = (short)puVar2;
  _DAT_e000e180 = 0x100;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  Peripherals::RADIO_NS.POWER = 0;
  Peripherals::RADIO_NS.POWER = 1;
  iVar6 = 0;
  do {
    iVar7 = iVar6 + 1;
    if ((RADIO_NS *)((&Peripherals::FICR_NS.TRIMCNF_0__ADDR)[iVar6 * 2] & 0xfffff000) ==
        &Peripherals::RADIO_NS) {
      *(uint *)(&Peripherals::FICR_NS.TRIMCNF_0__ADDR)[iVar6 * 2] =
           (&Peripherals::FICR_NS.TRIMCNF_0__DATA)[iVar6 * 2];
    }
    iVar6 = iVar7;
  } while (iVar7 != 0x20);
  Peripherals::RADIO_NS.CRCCNF = 0x103;
  Peripherals::RADIO_NS.CRCPOLY = 0x65b;
  Peripherals::RADIO_NS.RXADDRESSES = 1;
  Peripherals::RADIO_NS.MODE = 3;
  DAT_21001608 = 1;
  uVar1 = Peripherals::FICR_NS._128_4_;
  Peripherals::RADIO_NS._1416_4_ = uVar1;
  Peripherals::RADIO_NS.MODECNF0 = 0x201;
  Peripherals::RADIO_NS.SHORTS = 0x100000;
  FUN_0102635c();
  Peripherals::TIMER0_NS.PUBLISH_COMPARE_0_ = 0x8000000a;
  Peripherals::RADIO_NS.PUBLISH_BCMATCH = 0x80000003;
  Peripherals::TIMER0_NS.SUBSCRIBE_CAPTURE_2_ = 0x80000006;
  Peripherals::TIMER0_NS.SUBSCRIBE_CAPTURE_1_ = 0x80000005;
  Peripherals::DPPIC_NS.CHENSET = 0x1df8;
  DAT_21001604 = Peripherals::RADIO_NS.DFEMODE;
  DAT_2100160c = 0x96;
  _DAT_21001618 = 0;
  DAT_21001614 = 0;
  DAT_21001625 = 0;
  DAT_21001634 = 0;
  _DAT_e000e280 = 0x100;
  Peripherals::RADIO_NS.INTENSET = 0x10;
  _DAT_e000e100 = 0x100;
  if (DAT_21001638 == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x01020cac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_21001638)();
  return;
}


