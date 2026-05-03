/*
 * Function: FUN_0100f440
 * Entry:    0100f440
 * Prototype: undefined __stdcall FUN_0100f440(void)
 */


void FUN_0100f440(void)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((char)DAT_21000ee8 != '\0') {
    return;
  }
  DAT_21000ee4 = 0x100f2e5;
  DAT_21000ee8._0_1_ = 2;
  iVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  DAT_21000ee0 = &DAT_21000ed0;
  if ((DAT_21000ed0 == 0) || (puVar3 = &DAT_21000ed0, *(char *)(DAT_21000ed0 + 8) != '\x01')) {
    puVar3 = DAT_21000ecc;
  }
  *puVar3 = &DAT_21000ee0;
  DAT_21000ecc = &DAT_21000ee0;
  if (iVar2 == 0) {
    enableIRQinterrupts();
  }
  FUN_0102603c((uint)DAT_21000ec8,&DAT_21000ee0,puVar3,0x21000ec8);
  return;
}


