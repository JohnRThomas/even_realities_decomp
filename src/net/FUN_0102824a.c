/*
 * Function: FUN_0102824a
 * Entry:    0102824a
 * Prototype: undefined4 * __stdcall FUN_0102824a(undefined4 * param_1)
 */


undefined4 * FUN_0102824a(undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  puVar3 = (undefined4 *)*param_1;
  if (puVar3 != (undefined4 *)0x0) {
    *param_1 = *puVar3;
    *puVar3 = 0;
  }
  if (iVar2 == 0) {
    enableIRQinterrupts();
  }
  return puVar3;
}


