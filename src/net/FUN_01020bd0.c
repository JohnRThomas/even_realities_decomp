/*
 * Function: FUN_01020bd0
 * Entry:    01020bd0
 * Prototype: undefined __stdcall FUN_01020bd0(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020bd0(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  _DAT_e000e180 = 0x100;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  Peripherals::RADIO_NS.POWER = 0;
  Peripherals::RADIO_NS.POWER = 1;
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 1;
    if ((RADIO_NS *)((&Peripherals::FICR_NS.TRIMCNF_0__ADDR)[iVar2 * 2] & 0xfffff000) ==
        &Peripherals::RADIO_NS) {
      *(uint *)(&Peripherals::FICR_NS.TRIMCNF_0__ADDR)[iVar2 * 2] =
           (&Peripherals::FICR_NS.TRIMCNF_0__DATA)[iVar2 * 2];
    }
    iVar2 = iVar3;
  } while (iVar3 != 0x20);
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
  if (DAT_21001638 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x01020cac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_21001638)();
    return;
  }
  return;
}


