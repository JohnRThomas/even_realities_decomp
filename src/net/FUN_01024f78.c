/*
 * Function: FUN_01024f78
 * Entry:    01024f78
 * Prototype: undefined __stdcall FUN_01024f78(void)
 */


void FUN_01024f78(void)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined1 *extraout_r3;
  int iVar3;
  
  iVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  puVar2 = &DAT_21001bd0;
  if (DAT_21001bd6 == '\0') {
    FUN_01025edc(0x6d,300,0,&DAT_21001bd0);
    puVar2 = extraout_r3;
  }
  puVar2[6] = puVar2[6] + -1;
  if ((puVar2[6] == '\0') && (puVar2[0xf] == '\0')) {
    FUN_010252a8();
  }
  if (iVar3 == 0) {
    enableIRQinterrupts();
  }
  return;
}


