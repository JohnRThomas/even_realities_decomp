/*
 * Function: FUN_0102d980
 * Entry:    0102d980
 * Prototype: undefined8 __stdcall FUN_0102d980(void)
 */


undefined8 FUN_0102d980(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  puVar4 = &DAT_21004fab;
  bVar1 = (bool)hasExclusiveAccess(0x21004fab);
  if (bVar1) {
    DAT_21004fab = 0;
    uVar6 = (uint)DAT_21004faa;
    if (uVar6 != 0) {
      uVar5 = (DAT_21004fa8 + 1) % 5;
      uVar7 = FUN_0103ae86();
      puVar4 = (undefined1 *)((ulonglong)uVar7 >> 0x20);
      if ((DAT_21004fa7 == '\0') || (7 < (uint)((int)uVar7 - *(int *)(&DAT_21004640 + uVar5 * 4))))
      {
        iVar2 = Peripherals::CLOCK_NS._276_4_;
        if (iVar2 != 0) {
          Peripherals::CLOCK_NS._276_4_ = 0;
          uVar3 = Peripherals::CLOCK_NS._276_4_;
          DAT_21004fa8 = (byte)uVar5;
          if (uVar5 == 0) {
            DAT_21004fa7 = '\x01';
          }
        }
        uVar5 = (uint)DAT_21004fa8;
        uVar7 = FUN_0103ae86();
        puVar4 = (undefined1 *)((ulonglong)uVar7 >> 0x20);
        *(int *)(&DAT_21004640 + uVar5 * 4) = (int)uVar7;
        goto LAB_0102d9de;
      }
    }
  }
  uVar6 = 0;
  uVar5 = Peripherals::IPC_NS.PUBLISH_RECEIVE_11_;
  Peripherals::IPC_NS.PUBLISH_RECEIVE_11_ = uVar5 & 0x7fffffff;
  Peripherals::WDT_NS.TASKS_STOP = 1;
LAB_0102d9de:
  return CONCAT44(puVar4,uVar6);
}


