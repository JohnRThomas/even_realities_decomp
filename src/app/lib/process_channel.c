/*
 * Function: process_channel
 * Entry:    00012760
 * Prototype: void __stdcall process_channel(int32_t chan)
 */


/* exclude_from_export_ai */

void process_channel(int32_t chan)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  code *extraout_r1;
  undefined4 uVar4;
  int chan_00;
  undefined4 *puVar5;
  uint64_t uVar6;
  
  uVar3 = Peripherals::RTC1_S.INTENSET;
  if (((int)(uVar3 << 0x1e) < 0) && (uVar3 = Peripherals::RTC1_S.EVENTS_OVRFLW, uVar3 != 0)) {
    Peripherals::RTC1_S.EVENTS_OVRFLW = 0;
    uVar3 = Peripherals::RTC1_S.EVENTS_OVRFLW;
    DAT_2000bcc4 = DAT_2000bcc4 + 1;
  }
  puVar5 = &DAT_20006870;
  chan_00 = 0;
  while( true ) {
    uVar3 = Peripherals::RTC1_S.INTENSET;
    if (((0x10000 << chan_00 & uVar3) != 0) &&
       ((uVar3 = DAT_2000bcb8 & ~(1 << chan_00), (int)((DAT_2000bcb8 >> chan_00) << 0x1f) < 0 ||
        (DAT_2000bcb8 = uVar3, (&Peripherals::RTC1_S.EVENTS_COMPARE_0_)[chan_00] != 0)))) {
      DAT_2000bcb8 = uVar3;
      event_clear(chan_00);
      uVar6 = z_nrf_rtc_timer_read();
      uVar3 = (uint)(uVar6 >> 0x20);
      uVar4 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar4 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      if ((uint)(&DAT_2000687c)[chan_00 * 4] < uVar3 ||
          uVar3 - (&DAT_2000687c)[chan_00 * 4] <
          (uint)((uint)(&DAT_20006878)[chan_00 * 4] <= (uint)uVar6)) {
        *puVar5 = 0;
        *(undefined8 *)(&DAT_20006878 + chan_00 * 4) = 0xffffffffffffffff;
        Peripherals::RTC1_S.EVTENCLR = 0x10000 << chan_00;
        event_clear(chan_00);
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar4);
        }
        InstructionSynchronizationBarrier(0xf);
        if (extraout_r1 != (code *)0x0) {
          (*extraout_r1)();
        }
      }
      else {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar4);
        }
        InstructionSynchronizationBarrier(0xf);
      }
    }
    puVar5 = puVar5 + 4;
    if (chan_00 != 0) break;
    chan_00 = 1;
  }
  return;
}


