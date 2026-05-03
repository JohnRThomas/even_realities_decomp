/*
 * Function: FUN_01024ee4
 * Entry:    01024ee4
 * Prototype: undefined __stdcall FUN_01024ee4(void)
 */


void FUN_01024ee4(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  DAT_21001bd6 = DAT_21001bd6 + '\x01';
  if (DAT_21001bd6 == '\x01') {
    FUN_0102529c();
  }
  if (iVar2 == 0) {
    enableIRQinterrupts();
  }
  return;
}


