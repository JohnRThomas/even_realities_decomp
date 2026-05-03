/*
 * Function: FUN_0102f1c0
 * Entry:    0102f1c0
 * Prototype: undefined4 __stdcall FUN_0102f1c0(undefined4 param_1)
 */


undefined4 FUN_0102f1c0(undefined4 param_1)

{
  bool bVar1;
  undefined8 uVar2;
  
  FUN_0102d884();
  disableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  uVar2 = FUN_0102d980();
  if ((int)uVar2 != 0) {
    DataSynchronizationBarrier(0xf);
    WaitForEvent();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(param_1);
  }
  enableIRQinterrupts();
  return param_1;
}


