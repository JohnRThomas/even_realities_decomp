/*
 * Function: FUN_0100fad0
 * Entry:    0100fad0
 * Prototype: undefined __stdcall FUN_0100fad0(undefined2 param_1, int param_2, undefined4 * param_3)
 */


void FUN_0100fad0(undefined2 param_1,int param_2,undefined4 *param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  bool bVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint extraout_r1;
  undefined4 *puVar7;
  int iVar8;
  
  uVar2 = *(undefined2 *)(param_2 + 0x14);
  *(undefined2 *)((int)param_3 + 9) = param_1;
  uVar1 = *(undefined2 *)(param_2 + 0x16);
  *(undefined2 *)((int)param_3 + 0xb) = uVar2;
  uVar3 = *(undefined2 *)(param_2 + 0x18);
  uVar2 = *(undefined2 *)(param_2 + 0x1a);
  *(undefined2 *)((int)param_3 + 0xd) = uVar1;
  *(undefined2 *)((int)param_3 + 0xf) = uVar3;
  *(undefined2 *)((int)param_3 + 0x11) = uVar2;
  if (*(byte *)(param_3 + 2) != 0) {
    FUN_0100f3b8(param_3,0x100f805,param_3,(uint)*(byte *)(param_3 + 2));
    uVar6 = extraout_r1;
    while( true ) {
      puVar5 = (undefined4 *)(uVar6 >> 0x1b);
      uVar6 = 0;
      if (*(char *)(puVar5 + 2) == '\0') break;
      *(undefined1 *)(puVar5 + 2) = 3;
    }
    puVar5[1] = 0;
    *(undefined1 *)(puVar5 + 2) = 3;
    iVar8 = 0;
    bVar4 = (bool)isCurrentModePrivileged();
    if (bVar4) {
      iVar8 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    *puVar5 = &DAT_21000ed0;
    uVar6 = 0;
    if ((DAT_21000ed0 == 0) ||
       (uVar6 = (uint)*(byte *)(DAT_21000ed0 + 8), puVar7 = &DAT_21000ed0, uVar6 != 1)) {
      puVar7 = DAT_21000ecc;
    }
    *puVar7 = puVar5;
    if (iVar8 == 0) {
      enableIRQinterrupts();
    }
    DAT_21000ecc = puVar5;
    FUN_0102603c((uint)DAT_21000ec8,uVar6,puVar7,0x21000ec8);
    return;
  }
  param_3[1] = 0x100f805;
  *(undefined1 *)(param_3 + 2) = 3;
  iVar8 = 0;
  bVar4 = (bool)isCurrentModePrivileged();
  if (bVar4) {
    iVar8 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  *param_3 = &DAT_21000ed0;
  uVar6 = 0;
  if ((DAT_21000ed0 == 0) ||
     (uVar6 = (uint)*(byte *)(DAT_21000ed0 + 8), puVar5 = &DAT_21000ed0, uVar6 != 1)) {
    puVar5 = DAT_21000ecc;
  }
  *puVar5 = param_3;
  if (iVar8 == 0) {
    enableIRQinterrupts();
  }
  DAT_21000ecc = param_3;
  FUN_0102603c((uint)DAT_21000ec8,uVar6,puVar5,0x21000ec8);
  return;
}


