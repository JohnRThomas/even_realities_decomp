/*
 * Function: FUN_0102aa08
 * Entry:    0102aa08
 * Prototype: undefined4 __stdcall FUN_0102aa08(undefined1 * param_1)
 */


undefined4 FUN_0102aa08(undefined1 *param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  *param_1 = 0;
  if (iVar2 == 0) {
    enableIRQinterrupts();
  }
  return 0;
}


