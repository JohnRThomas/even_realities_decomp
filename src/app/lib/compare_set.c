/*
 * Function: compare_set
 * Entry:    000668fc
 * Prototype: int __stdcall compare_set(int32_t chan, uint64_t target_time, z_nrf_rtc_timer_compare_handler_t handler, void * user_data, bool exact)
 */


/* exclude_from_export */

int compare_set(int32_t chan,uint64_t target_time,z_nrf_rtc_timer_compare_handler_t handler,
               void *user_data,bool exact)

{
  bool key;
  uint uVar1;
  int extraout_r1;
  int extraout_r1_00;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint64_t uVar7;
  
  uVar4 = (uint)(target_time >> 0x20);
  key = compare_int_lock(chan);
  uVar7 = z_nrf_rtc_timer_read();
  uVar1 = (uint)(uVar7 >> 0x20);
  if (uVar4 < uVar1 || uVar1 - uVar4 < (uint)((uint)target_time <= (uint)uVar7)) {
    if (!exact) {
      DAT_2000bcb8 = DAT_2000bcb8 | 1 << (chan & 0xffU);
      goto LAB_000669f2;
    }
  }
  else {
    uVar1 = (uint)(target_time - uVar7 >> 0x20);
    if (uVar1 == 0 && (0x800000 < (uint)(target_time - uVar7)) <= uVar1) {
      if (target_time != *(uint64_t *)(&DAT_20006878 + chan * 4)) {
        uVar4 = 0x10000 << (chan & 0xffU);
        uVar6 = (uint)target_time & 0xffffff;
        Peripherals::RTC1_S.EVTENCLR = uVar4;
        event_clear(chan);
        iVar5 = 3;
        uVar1 = uVar6;
        iVar3 = extraout_r1;
        while( true ) {
          *(uint *)(iVar3 + (chan + 0x150) * 4) = uVar1 & 0xffffff;
          *(uint *)(iVar3 + 0x344) = uVar4;
          iVar2 = *(int *)(iVar3 + 0x504);
          if (((uVar1 - iVar2) - 3 & 0xffffff) < 0x7ffffe) break;
          if (*(int *)((int)&Peripherals::RTC1_S.TASKS_START + ((chan + 0x50) * 4 & 0xffffU)) != 0)
          {
            iVar2 = *(int *)(iVar3 + 0x504);
            if ((iVar2 - uVar6 & 0xffffff) < 0x800001) break;
            event_clear(chan);
            iVar3 = extraout_r1_00;
          }
          if (exact) goto LAB_000669ca;
          uVar1 = iVar5 + iVar2;
          iVar5 = iVar5 + 1;
        }
      }
LAB_000669f2:
      (&DAT_20006870)[chan * 4] = handler;
      iVar3 = 0;
      *(uint64_t *)(&DAT_20006878 + chan * 4) = target_time;
      (&DAT_20006874)[chan * 4] = user_data;
      goto LAB_000669ce;
    }
  }
LAB_000669ca:
  iVar3 = -0x16;
LAB_000669ce:
  compare_int_unlock(chan,key);
  return iVar3;
}


