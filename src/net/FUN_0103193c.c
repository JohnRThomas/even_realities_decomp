/*
 * Function: FUN_0103193c
 * Entry:    0103193c
 * Prototype: undefined4 __stdcall FUN_0103193c(int param_1, undefined1 param_2)
 */


undefined4 FUN_0103193c(int param_1,undefined1 param_2)

{
  uint uVar1;
  bool bVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_1 + 0x10);
  bVar2 = FUN_0103b90a();
  if ((bVar2) || (DAT_21006461 == '\0')) {
    while( true ) {
      uVar6 = 0;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        uVar6 = getBasePriority();
      }
      bVar2 = (bool)isCurrentModePrivileged();
      if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      bVar2 = FUN_0103addc(*(int **)(param_1 + 4));
      uVar3 = extraout_r1;
      if (bVar2) break;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(uVar6);
      }
      InstructionSynchronizationBarrier(0xf);
    }
LAB_010319b8:
    **(undefined1 **)(iVar7 + 0x10) = param_2;
    piVar4 = *(int **)(param_1 + 4);
    iVar5 = *piVar4;
    *(undefined4 *)(iVar5 + 0x544) = *(undefined4 *)(iVar7 + 0x10);
    *(undefined4 *)(iVar5 + 0x548) = 1;
    *(undefined4 *)(iVar5 + 0x120) = 0;
    *(undefined4 *)(iVar5 + 0x158) = 0;
    uVar6 = *(undefined4 *)(iVar5 + 0x158);
    if (piVar4[1] << 0x1b < 0) {
      uVar6 = 8;
      *(undefined4 *)(**(int **)(param_1 + 4) + 0x500) = 8;
      *(undefined4 *)(iVar5 + 0x304) = 0x400000;
    }
    *(undefined4 *)(iVar5 + 8) = 1;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar3);
    }
    InstructionSynchronizationBarrier(0xf);
    return uVar6;
  }
  do {
    iVar5 = 100;
    do {
      bVar2 = FUN_0103addc(*(int **)(param_1 + 4));
      if (bVar2) {
        uVar6 = 0;
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          uVar6 = getBasePriority();
        }
        bVar2 = (bool)isCurrentModePrivileged();
        if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
          setBasePriority(0x40);
        }
        InstructionSynchronizationBarrier(0xf);
        bVar2 = FUN_0103addc(*(int **)(param_1 + 4));
        uVar3 = extraout_r1_00;
        if (bVar2) goto LAB_010319b8;
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(uVar6);
        }
        InstructionSynchronizationBarrier(0xf);
        break;
      }
      src/*FUN_0103b8a8(1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    FUN_01038424(0x21,0);
  } while( true );
}


