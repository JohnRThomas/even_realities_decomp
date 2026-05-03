/*
 * Function: FUN_01030cc8
 * Entry:    01030cc8
 * Prototype: uint __stdcall FUN_01030cc8(void)
 */


uint FUN_01030cc8(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar3 = Peripherals::RNG_NS.EVENTS_VALRDY;
  if (uVar3 == 0) {
    uVar3 = 0xfffffff5;
  }
  else {
    uVar3 = Peripherals::RNG_NS.VALUE;
    Peripherals::RNG_NS.EVENTS_VALRDY = 0;
    uVar2 = Peripherals::RNG_NS.EVENTS_VALRDY;
    uVar3 = uVar3 & 0xff;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
}


