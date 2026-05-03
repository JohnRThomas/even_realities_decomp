/*
 * Function: FUN_0102d884
 * Entry:    0102d884
 * Prototype: undefined __stdcall FUN_0102d884(void)
 */


void FUN_0102d884(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined8 uVar7;
  uint local_18;
  uint local_14;
  
  ExclusiveAccess(0x21004fab);
  local_18 = 0;
  local_14 = 0;
  do {
    uVar6 = Peripherals::RTC1_NS.COUNTER;
    DataMemoryBarrier(0x1f);
    uVar1 = Peripherals::RTC0_NS.COUNTER;
    DataMemoryBarrier(0x1f);
    uVar2 = Peripherals::RTC1_NS.COUNTER;
  } while (uVar6 != uVar2);
  iVar3 = FUN_0103a5ac(0x41016000,3,uVar6,&local_18);
  iVar4 = FUN_0103a5ac(0x41011000,0xf,uVar1,&local_14);
  if (iVar4 == 0) {
    if (iVar3 == 0) goto LAB_0102d908;
  }
  else if ((iVar3 == 0) || (local_14 < local_18)) {
    local_18 = local_14;
  }
  uVar1 = Peripherals::RTC1_NS.CC_3_;
  uVar6 = (uVar6 + local_18) - 1 & 0xffffff;
  if (uVar6 == uVar1) {
    if (DAT_21004fa9 == '\0') {
      DAT_21004faa = 0;
      return;
    }
  }
  else {
    uVar7 = FUN_0102d7ac();
    puVar5 = (undefined1 *)((ulonglong)uVar7 >> 0x20);
    *(uint *)((int)uVar7 + 0x54c) = uVar6;
    if ((local_18 < 0x7fffff) &&
       (DataMemoryBarrier(0x1f), 0x7ffffb < (uVar6 - *(int *)((int)uVar7 + 0x504) & 0xffffff) - 3))
    {
      *puVar5 = 0;
      DAT_21004faa = 0;
      return;
    }
    *puVar5 = 1;
  }
LAB_0102d908:
  uVar1 = Peripherals::IPC_NS.PUBLISH_RECEIVE_11_;
  Peripherals::IPC_NS.PUBLISH_RECEIVE_11_ = uVar1 | 0x80000000;
  uVar1 = Peripherals::RTC1_NS.EVENTS_COMPARE_3_;
  if (uVar1 == 0) {
    Peripherals::WDT_NS.TASKS_STOP = 1;
    uVar1 = Peripherals::RTC1_NS.EVENTS_COMPARE_3_;
    if (uVar1 != 0) {
      Peripherals::WDT_NS.TASKS_START = 1;
    }
  }
  DAT_21004faa = 1;
  return;
}


