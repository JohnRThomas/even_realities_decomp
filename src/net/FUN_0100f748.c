/*
 * Function: FUN_0100f748
 * Entry:    0100f748
 * Prototype: undefined __stdcall FUN_0100f748(undefined4 * param_1, undefined4 param_2)
 */


void FUN_0100f748(undefined4 *param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if (*(char *)(param_1 + 2) != '\0') {
    *(undefined1 *)(param_1 + 2) = 4;
    return;
  }
  param_1[1] = param_2;
  *(undefined1 *)(param_1 + 2) = 4;
  iVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  *param_1 = &DAT_21000ed0;
  uVar2 = 0;
  if ((DAT_21000ed0 == 0) ||
     (uVar2 = (uint)*(byte *)(DAT_21000ed0 + 8), puVar3 = &DAT_21000ed0, uVar2 != 1)) {
    puVar3 = DAT_21000ecc;
  }
  *puVar3 = param_1;
  if (iVar4 == 0) {
    enableIRQinterrupts();
  }
  DAT_21000ecc = param_1;
  FUN_0102603c((uint)DAT_21000ec8,uVar2,puVar3,0x21000ec8);
  return;
}


