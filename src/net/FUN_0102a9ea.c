/*
 * Function: FUN_0102a9ea
 * Entry:    0102a9ea
 * Prototype: undefined4 __stdcall FUN_0102a9ea(char * param_1)
 */


undefined4 FUN_0102a9ea(char *param_1)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    iVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  cVar1 = *param_1;
  *param_1 = '\x01';
  if (iVar4 == 0) {
    enableIRQinterrupts();
  }
  if (cVar1 == '\x01') {
    uVar3 = 0xffffffdd;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


