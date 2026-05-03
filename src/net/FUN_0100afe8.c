/*
 * Function: FUN_0100afe8
 * Entry:    0100afe8
 * Prototype: undefined __stdcall FUN_0100afe8(uint param_1)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0100afe8(uint param_1)

{
  bool bVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  while( true ) {
    iVar4 = FUN_0102a9ea(&DAT_21000bf4);
    if (iVar4 != 0) {
      DAT_21000bf5 = -1;
    }
    do {
      Peripherals::ECB_NS.TASKS_STOPECB = 1;
      Peripherals::ECB_NS.EVENTS_ENDECB = 0;
      Peripherals::ECB_NS.EVENTS_ERRORECB = 0;
      Peripherals::ECB_NS.ECBDATAPTR = param_1;
      Peripherals::ECB_NS.TASKS_STARTECB = 1;
      while ((cVar3 = DAT_21000bf5, uVar2 = Peripherals::ECB_NS.EVENTS_ENDECB, uVar2 == 0 &&
             (uVar2 = Peripherals::ECB_NS.EVENTS_ERRORECB, uVar2 == 0))) {
        if (_DAT_e000ed10 << 0x1b < 0) {
          _DAT_e000e280 = 0x2000;
          iVar5 = 0;
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            iVar5 = isIRQinterruptsEnabled();
          }
          disableIRQinterrupts();
          Peripherals::ECB_NS.INTENSET = 3;
          uVar2 = Peripherals::ECB_NS.EVENTS_ENDECB;
          if ((uVar2 == 0) && (uVar2 = Peripherals::ECB_NS.EVENTS_ERRORECB, uVar2 == 0)) {
            FUN_0102aa1e();
          }
          if (iVar5 == 0) {
            enableIRQinterrupts();
          }
        }
      }
      uVar2 = Peripherals::ECB_NS.EVENTS_ERRORECB;
    } while (uVar2 != 0);
    if (iVar4 != 0) break;
    DAT_21000bf5 = '\0';
    Peripherals::ECB_NS.INTENCLR = 3;
    Peripherals::ECB_NS.EVENTS_ERRORECB = 0;
    Peripherals::ECB_NS.EVENTS_ENDECB = 0;
    _DAT_e000e280 = 0x2000;
    FUN_0102aa08(&DAT_21000bf4);
    if (cVar3 == '\0') {
      return;
    }
  }
  return;
}


