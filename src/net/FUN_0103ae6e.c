/*
 * Function: FUN_0103ae6e
 * Entry:    0103ae6e
 * Prototype: undefined __stdcall FUN_0103ae6e(short param_1)
 */


void FUN_0103ae6e(short param_1)

{
  *(undefined4 *)((int)&Peripherals::RTC1_NS.TASKS_START + (uint)(ushort)((param_1 + 0x50) * 4)) = 0
  ;
  return;
}


