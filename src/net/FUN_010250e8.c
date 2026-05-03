/*
 * Function: FUN_010250e8
 * Entry:    010250e8
 * Prototype: undefined4 __stdcall FUN_010250e8(byte * param_1)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_010250e8(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  CLOCK_NS *pCVar5;
  uint uVar6;
  
  if ((param_1 == (byte *)0x0) || (2 < *param_1)) {
    return 0xffffffea;
  }
  if (*param_1 == 0) {
    if (0x1f < param_1[1] - 1) {
      return 0xffffffea;
    }
    if (0x21 < param_1[2]) {
      return 0xffffffea;
    }
  }
  else {
    if (param_1[1] != 0) {
      return 0xffffffea;
    }
    if (param_1[2] != 0) {
      return 0xffffffea;
    }
  }
  _DAT_e000e180 = 0x20;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  _DAT_e000e280 = 0x20;
  Peripherals::CLOCK_NS.INTENCLR = 0xffffffff;
  Peripherals::CLOCK_NS.EVENTS_HFCLKSTARTED = 0;
  Peripherals::CLOCK_NS.EVENTS_LFCLKSTARTED = 0;
  Peripherals::CLOCK_NS.EVENTS_DONE = 0;
  DAT_21001bd6 = 0;
  DAT_21001bd4 = *(undefined2 *)(param_1 + 4);
  uVar2 = FUN_010252f0();
  if (uVar2 != 0) {
    DAT_21001bd0 = 1;
    DAT_21001bd6 = 1;
  }
  uVar2 = Peripherals::CLOCK_NS.HFCLKSTAT;
  uVar6 = Peripherals::CLOCK_NS.HFCLKSTAT;
  if (((int)(uVar2 << 0xf) < 0) && ((int)(uVar6 << 0x1f) < 0)) {
    FUN_010252c4();
  }
  DAT_21001be0 = param_1[2];
  DAT_21001bd2 = 0x5f5;
  iVar4 = 0;
  DAT_21001bf0 = 1;
  DAT_21001bec = *param_1;
  pCVar5 = (CLOCK_NS *)(uint)DAT_21001bec;
  DAT_21001bde = 0;
  if (pCVar5 == (CLOCK_NS *)0x1) {
    DAT_21001bf0 = 2;
LAB_0102518a:
    uVar2 = FUN_01025300();
    if ((uVar2 == 0) || (uVar2 = FUN_01025310(), uVar2 != (DAT_21001bf0 & 3))) {
      pCVar5 = &Peripherals::CLOCK_NS;
      Peripherals::CLOCK_NS.TASKS_LFCLKSTOP = 1;
      Peripherals::CLOCK_NS.EVENTS_LFCLKSTARTED = 0;
      Peripherals::CLOCK_NS.LFCLKSRC = DAT_21001bf0 & 0xff;
      Peripherals::CLOCK_NS.TASKS_LFCLKSTART = 1;
      Peripherals::CLOCK_NS.INTENSET = 2;
      if (param_1[6] != 0) goto LAB_010251a8;
      uVar2 = Peripherals::CLOCK_NS.INTENSET;
      iVar4 = uVar2 << 0x1e;
      if (iVar4 < 0) {
        uVar6 = _DAT_e000ed10 & 0x10;
        _DAT_e000ed10 = _DAT_e000ed10 | 0x10;
        uVar2 = Peripherals::CLOCK_NS.EVENTS_LFCLKSTARTED;
        if (uVar2 == 0) {
          FUN_0102aa20();
        }
        while (uVar2 = Peripherals::CLOCK_NS.EVENTS_LFCLKSTARTED, uVar2 == 0) {
          FUN_0102aa1e();
        }
        FUN_010250d0();
        if (uVar6 == 0) {
          _DAT_e000ed10 = _DAT_e000ed10 & 0xffffffef;
        }
        Peripherals::CLOCK_NS.INTENCLR = 2;
        Peripherals::CLOCK_NS.EVENTS_LFCLKSTARTED = 0;
        goto LAB_010251a8;
      }
      uVar3 = 0x2d5;
      goto LAB_01025200;
    }
    if (param_1[6] == 0) {
      FUN_010250d0();
      goto LAB_010251a8;
    }
  }
  else {
    if (pCVar5 == (CLOCK_NS *)0x2) {
      FUN_01024ee4();
      do {
        do {
          uVar2 = Peripherals::CLOCK_NS.HFCLKSTAT;
          uVar6 = Peripherals::CLOCK_NS.HFCLKSTAT;
        } while (-1 < (int)(uVar2 << 0xf));
      } while (-1 < (int)(uVar6 << 0x1f));
      DAT_21001bf0 = 3;
      goto LAB_0102518a;
    }
    if (pCVar5 == (CLOCK_NS *)0x0) goto LAB_0102518a;
    uVar3 = 0x31e;
LAB_01025200:
    FUN_01025edc(0x6d,uVar3,iVar4,pCVar5);
  }
  Peripherals::CLOCK_NS.INTENSET = 2;
LAB_010251a8:
  if ((DAT_21001be0 != 0) && (*param_1 == 0)) {
    bVar1 = FUN_010252d0();
    uVar2 = FUN_01025f68();
    if (bVar1 == 0) {
      DAT_21001be4 = 0x7fffffff;
      DAT_21001be8 = uVar2;
    }
    else {
      DAT_21001be8 = 0x7fffffff;
      DAT_21001be4 = uVar2;
    }
  }
  DAT_21001bdd = 0;
  DAT_21001bf5 = 1;
  _DAT_e000e100 = 0x20;
  _DAT_e000e280 = 0x20;
  return 0;
}


