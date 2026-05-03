/*
 * Function: FUN_0102f17c
 * Entry:    0102f17c
 * Prototype: undefined8 __stdcall FUN_0102f17c(void)
 */


ulonglong FUN_0102f17c(void)

{
  bool bVar1;
  ulonglong uVar2;
  
  FUN_0102d884();
  disableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar2 = FUN_0102d980();
  if ((int)uVar2 != 0) {
    DataSynchronizationBarrier(0xf);
    WaitForInterrupt();
  }
  enableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  return uVar2 & 0xffffffff00000000;
}


