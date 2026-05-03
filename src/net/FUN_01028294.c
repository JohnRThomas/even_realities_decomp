/*
 * Function: FUN_01028294
 * Entry:    01028294
 * Prototype: undefined __stdcall FUN_01028294(undefined4 * param_1, undefined4 * param_2)
 */


void FUN_01028294(undefined4 *param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  *param_2 = *param_1;
  *param_1 = param_2;
  if (iVar2 == 0) {
    enableIRQinterrupts();
  }
  return;
}


