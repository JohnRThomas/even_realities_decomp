/*
 * Function: FUN_01033e20
 * Entry:    01033e20
 * Prototype: undefined4 __stdcall FUN_01033e20(byte * param_1)
 */


undefined4 FUN_01033e20(byte *param_1)

{
  bool bVar1;
  uint uVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  if (DAT_21006459 == '\0') {
    return 0xfffffff3;
  }
  if (param_1 != (byte *)0x0) {
    if ((0xfa < (byte)(*param_1 - 1)) || ((DAT_21004a94 == '\0' && (DAT_21004aa5 < *param_1)))) {
      return 0xffffff86;
    }
    if (7 < DAT_21004a88) {
      return 0xfffffff4;
    }
    if (param_1[1] < 8) {
      uVar6 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar6 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      if (DAT_21004a95 == '\0') {
        iVar7 = *(int *)(&DAT_21004a60 + DAT_21004a80 * 4);
        puVar3 = (undefined1 *)FUN_0103bdd4(iVar7,param_1,0x100);
        *(byte *)((int)&DAT_21006256 + (uint)param_1[1]) =
             *(char *)((int)&DAT_21006256 + (uint)param_1[1]) + 1U & 3;
        *(undefined1 *)(iVar7 + 4) = *(undefined1 *)((int)&DAT_21006256 + (uint)param_1[1]);
        DAT_21004a80 = DAT_21004a80 + 1;
        if (7 < DAT_21004a80) {
          DAT_21004a80 = 0;
        }
LAB_01033ea2:
        DAT_21004a88 = DAT_21004a88 + 1;
      }
      else {
        puVar4 = &DAT_210049d4;
        iVar7 = 0;
        do {
          puVar3 = (undefined1 *)(uint)*(byte *)(puVar4 + 1);
          if (puVar3 == (undefined1 *)0x0) {
            iVar8 = (&DAT_210049d4)[iVar7 * 3];
            (&DAT_210049d8)[iVar7 * 0xc] = 1;
            (&DAT_210049dc)[iVar7 * 3] = 0;
            puVar3 = (undefined1 *)FUN_0103bdd4(iVar8,param_1,0x100);
            *(byte *)((int)&DAT_21006256 + (uint)param_1[1]) =
                 *(char *)((int)&DAT_21006256 + (uint)param_1[1]) + 1U & 3;
            *(undefined1 *)(iVar8 + 4) = *(undefined1 *)((int)&DAT_21006256 + (uint)param_1[1]);
            iVar8 = *(int *)(&DAT_210049b4 + (uint)param_1[1] * 4);
            if (*(int *)(&DAT_210049b4 + (uint)param_1[1] * 4) == 0) {
              *(undefined4 **)(&DAT_210049b4 + (uint)param_1[1] * 4) = &DAT_210049d4 + iVar7 * 3;
            }
            else {
              do {
                iVar5 = iVar8;
                iVar8 = *(int *)(iVar5 + 8);
              } while (iVar8 != 0);
              *(undefined4 **)(iVar5 + 8) = &DAT_210049d4 + iVar7 * 3;
            }
            goto LAB_01033ea2;
          }
          iVar7 = iVar7 + 1;
          puVar4 = puVar4 + 3;
        } while (iVar7 != 8);
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar6);
      }
      InstructionSynchronizationBarrier(0xf);
      if ((DAT_21004a95 == '\0' && DAT_21004aa4 == '\0') && (DAT_21006458 == '\0')) {
        FUN_010333e8(puVar3);
      }
      return 0;
    }
  }
  return 0xffffffea;
}


