/*
 * Function: FUN_0100fb00
 * Entry:    0100fb00
 * Prototype: undefined __stdcall FUN_0100fb00(undefined2 param_1, int param_2, undefined4 * param_3)
 */


void FUN_0100fb00(undefined2 param_1,int param_2,undefined4 *param_3)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar9;
  
  sVar4 = *(short *)(param_2 + 0xc);
  sVar5 = *(short *)(param_2 + 8);
  sVar1 = *(short *)(param_2 + 0x2e);
  *(undefined2 *)((int)param_3 + 9) = param_1;
  sVar2 = *(short *)(param_2 + 10);
  sVar3 = *(short *)(param_2 + 0xe);
  *(short *)((int)param_3 + 0xb) = sVar5;
  *(short *)((int)param_3 + 0xd) = sVar4;
  *(short *)((int)param_3 + 0xf) = sVar2;
  *(short *)((int)param_3 + 0x11) = sVar3;
  if (((sVar1 == sVar3) && (*(short *)(param_2 + 0x2a) == sVar2)) &&
     (*(short *)(param_2 + 0x30) == sVar4)) {
    bVar9 = *(short *)(param_2 + 0x2c) != sVar5;
  }
  else {
    bVar9 = true;
  }
  *(byte *)((int)param_3 + 0x13) = *(byte *)((int)param_3 + 0x13) & 0xfe | bVar9;
  *(short *)(param_2 + 0x2a) = sVar2;
  *(short *)(param_2 + 0x2e) = sVar3;
  *(short *)(param_2 + 0x2c) = sVar5;
  *(short *)(param_2 + 0x30) = sVar4;
  if (*(char *)(param_3 + 2) == '\0') {
    param_3[1] = 0x100f8a5;
    *(undefined1 *)(param_3 + 2) = 3;
    iVar8 = 0;
    bVar9 = (bool)isCurrentModePrivileged();
    if (bVar9) {
      iVar8 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    *param_3 = &DAT_21000ed0;
    uVar6 = 0;
    if ((DAT_21000ed0 == 0) ||
       (uVar6 = (uint)*(byte *)(DAT_21000ed0 + 8), puVar7 = &DAT_21000ed0, uVar6 != 1)) {
      puVar7 = DAT_21000ecc;
    }
    *puVar7 = param_3;
    if (iVar8 == 0) {
      enableIRQinterrupts();
    }
    DAT_21000ecc = param_3;
    FUN_0102603c((uint)DAT_21000ec8,uVar6,puVar7,0x21000ec8);
    return;
  }
  *(undefined1 *)(param_3 + 2) = 3;
                    /* WARNING: Could not recover jumptable at 0x0100f710. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


