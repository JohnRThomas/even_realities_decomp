/*
 * Function: FUN_0102bf18
 * Entry:    0102bf18
 * Prototype: int __stdcall FUN_0102bf18(int param_1)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0102bf18(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    if (DAT_210005b4 != 3) {
      Peripherals::P0_NS.OUTSET = 0x80000000;
      Peripherals::P0_NS.OUTSET = 0x20000000;
      iVar3 = FUN_0102badc((uint)DAT_21004fa2);
      DAT_21004fa1 = 1;
      DAT_21004fa3 = 1;
      FUN_0102bbb0(1);
      Peripherals::P0_NS.OUTCLR = 0x20000000;
      return iVar3;
    }
  }
  else {
    if (param_1 != 1) {
      return param_1;
    }
    if (DAT_21004fa1 != '\0') {
      Peripherals::P0_NS.OUTCLR = 0x80000000;
      DAT_21004fa1 = 0;
      Peripherals::P0_NS.OUTSET = 0x20000000;
      if (DAT_21004fa2 == 0) {
        uVar4 = 0;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          uVar4 = getBasePriority();
        }
        bVar1 = (bool)isCurrentModePrivileged();
        if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
          setBasePriority(0x40);
        }
        InstructionSynchronizationBarrier(0xf);
        FUN_0102f308('\b');
        _DAT_e000e180 = 0x100;
        DataSynchronizationBarrier(0xf);
        InstructionSynchronizationBarrier(0xf);
        Peripherals::RADIO_NS.SHORTS = 0;
        Peripherals::RADIO_NS.EVENTS_DISABLED = 0;
        Peripherals::RADIO_NS.TASKS_DISABLE = 1;
        do {
          uVar2 = Peripherals::RADIO_NS.EVENTS_DISABLED;
        } while (uVar2 == 0);
        Peripherals::TIMER2_NS.TASKS_STOP = 1;
        Peripherals::RADIO_NS.INTENCLR = 0xffffffff;
        FUN_01033b14();
        _DAT_e000e280 = 0x100;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar4);
        }
        InstructionSynchronizationBarrier(0xf);
      }
      else if (DAT_21004fa2 == 1) {
        FUN_01034128();
      }
      Peripherals::P0_NS.OUTCLR = 0x20000000;
      Peripherals::VREQCTRL_NS.VREGRADIO_VREQH = 1;
      return 0;
    }
  }
  return param_1;
}


