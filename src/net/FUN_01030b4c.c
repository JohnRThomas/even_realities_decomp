/*
 * Function: FUN_01030b4c
 * Entry:    01030b4c
 * Prototype: undefined __stdcall FUN_01030b4c(int param_1)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01030b4c(int param_1)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  undefined4 extraout_r3;
  undefined4 uVar5;
  
  iVar2 = DAT_21004810;
  DAT_21004810 = 1;
  if (iVar2 != 0) goto LAB_01030b8c;
  DAT_21004804 = iVar2;
  DAT_2100480c = iVar2;
  DAT_21004808 = 1;
  uVar4 = FUN_0102d240((int *)&DAT_21004834,(undefined4 *)&DAT_21004800);
  if (-1 < (int)uVar4) goto LAB_01030b8c;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
               "WEST_TOPDIR/zephyr/drivers/clock_control/clock_control_nrf.c",0x230,extraout_r3);
  while( true ) {
    FUN_0103a370();
LAB_01030b8c:
    if (param_1 == 0) break;
    if (param_1 - 1U < 2) {
      if ((param_1 != 1) || (uVar4 = Peripherals::CLOCK_NS.LFCLKSRCCOPY, (uVar4 & 3) != 2)) {
        bVar3 = FUN_0103b90a();
        if ((bVar3) || (DAT_21006461 == '\0')) {
          uVar5 = 0;
          bVar3 = (bool)isCurrentModePrivileged();
          if (bVar3) {
            uVar5 = getBasePriority();
          }
          bVar3 = (bool)isCurrentModePrivileged();
          if ((bVar3) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x40 < uVar4)) {
            setBasePriority(0x40);
          }
          InstructionSynchronizationBarrier(0xf);
          bVar3 = true;
        }
        else {
          Peripherals::CLOCK_NS.INTENCLR = 2;
          bVar3 = false;
          uVar5 = 0;
        }
        while( true ) {
          uVar4 = Peripherals::CLOCK_NS.LFCLKSTAT;
          uVar1 = Peripherals::CLOCK_NS.LFCLKSTAT;
          if (((int)(uVar4 << 0xf) < 0) && (((uVar1 & 3) == 2 || (param_1 == 1)))) break;
          if (bVar3) {
            FUN_0102f1c0(uVar5);
          }
          else {
            FUN_01038424(0x21,0);
          }
          uVar4 = Peripherals::CLOCK_NS.LFCLKSRC;
          if (((uVar4 & 0xff) == 1) &&
             (uVar4 = Peripherals::CLOCK_NS.EVENTS_LFCLKSTARTED, uVar4 != 0)) {
            Peripherals::CLOCK_NS.EVENTS_LFCLKSTARTED = 0;
            uVar4 = Peripherals::CLOCK_NS.EVENTS_LFCLKSTARTED;
            Peripherals::CLOCK_NS.LFCLKSRC = 2;
            _DAT_e000e280 = 0x20;
            Peripherals::CLOCK_NS.TASKS_LFCLKSTART = 1;
          }
        }
        if (bVar3) {
          bVar3 = (bool)isCurrentModePrivileged();
          if (bVar3) {
            setBasePriority(uVar5);
          }
          InstructionSynchronizationBarrier(0xf);
        }
        else {
          Peripherals::CLOCK_NS.INTENSET = 2;
        }
      }
      return;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/zephyr/drivers/clock_control/clock_control_nrf.c",0x242,param_1 - 1U);
  }
  return;
}


