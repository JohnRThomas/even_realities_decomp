/*
 * Function: FUN_0100f788
 * Entry:    0100f788
 * Prototype: undefined __stdcall FUN_0100f788(undefined4 * param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_0100f788(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint extraout_r1;
  undefined1 extraout_r2;
  undefined4 *puVar4;
  int iVar5;
  
  if (*(byte *)(param_1 + 2) == 0) {
    param_1[1] = param_2;
    *(char *)(param_1 + 2) = (char)param_3;
    iVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      iVar5 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    *param_1 = &DAT_21000ed0;
    uVar3 = 0;
    if ((DAT_21000ed0 == 0) ||
       (uVar3 = (uint)*(byte *)(DAT_21000ed0 + 8), puVar2 = &DAT_21000ed0, uVar3 != 1)) {
      puVar2 = DAT_21000ecc;
    }
    *puVar2 = param_1;
    if (iVar5 == 0) {
      enableIRQinterrupts();
    }
    DAT_21000ecc = param_1;
    FUN_0102603c((uint)DAT_21000ec8,uVar3,puVar2,0x21000ec8);
    return;
  }
  FUN_0100f3b8(param_1,param_2,param_3,(uint)*(byte *)(param_1 + 2));
  puVar2 = (undefined4 *)(extraout_r1 >> 0x1b);
  if (*(char *)(puVar2 + 2) != '\0') {
    *(undefined1 *)(puVar2 + 2) = extraout_r2;
    return;
  }
  puVar2[1] = 0;
  *(undefined1 *)(puVar2 + 2) = extraout_r2;
  iVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar5 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  *puVar2 = &DAT_21000ed0;
  uVar3 = 0;
  if ((DAT_21000ed0 == 0) ||
     (uVar3 = (uint)*(byte *)(DAT_21000ed0 + 8), puVar4 = &DAT_21000ed0, uVar3 != 1)) {
    puVar4 = DAT_21000ecc;
  }
  *puVar4 = puVar2;
  if (iVar5 == 0) {
    enableIRQinterrupts();
  }
  DAT_21000ecc = puVar2;
  FUN_0102603c((uint)DAT_21000ec8,uVar3,puVar4,0x21000ec8);
  return;
}


