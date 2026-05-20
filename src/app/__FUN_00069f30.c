/*
 * Function: $_FUN_00069f30
 * Entry:    00069f30
 * Prototype: undefined __stdcall $_FUN_00069f30(void)
 */


void __FUN_00069f30(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = Peripherals::QSPI_S.EVENTS_READY;
  if (uVar1 == 0) {
    return;
  }
  Peripherals::QSPI_S.EVENTS_READY = 0;
  if (DAT_2000bd68 == '\0') {
    if (DAT_2000bd60 == '\x03') {
      Peripherals::QSPI_S.TASKS_READSTART = 1;
      DAT_2000bd68 = 1;
      return;
    }
    if (DAT_2000bd60 != '\x04') {
      if (DAT_2000bd60 != '\x02') {
        DAT_2000bd68 = 1;
        return;
      }
      Peripherals::QSPI_S.TASKS_WRITESTART = 1;
      DAT_2000bd68 = 1;
      return;
    }
    Peripherals::QSPI_S.TASKS_ERASESTART = 1;
    DAT_2000bd68 = 1;
    return;
  }
  if (DAT_2000bd60 == '\x03') {
    DAT_2000bd50 = 2;
  }
  else {
    if (DAT_2000bd60 == '\x04') {
      DAT_2000bd50 = 3;
      DAT_2000bd54 = Peripherals::QSPI_S._1308_4_;
      uVar2 = Peripherals::QSPI_S._1312_4_;
      DAT_2000bd58._0_1_ = (undefined1)uVar2;
      goto LAB_00069f80;
    }
    if (DAT_2000bd60 != '\x02') goto LAB_00069f80;
    DAT_2000bd50 = 1;
  }
  FUN_000698ec();
LAB_00069f80:
  if (DAT_2000bd38 == 0) {
    DAT_2000bd60 = '\x01';
  }
  if (DAT_2000bd69 == '\0') {
    (*DAT_2000bd30)(0,DAT_2000bd34);
  }
  DAT_2000bd50 = 0;
  return;
}


