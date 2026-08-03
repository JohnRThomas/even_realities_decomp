/*
 * Function: any_on
 * Entry:    0008ae3e
 * Prototype: undefined4 __stdcall any_on(int param_1, uint param_2)
 */


/* exclude_from_export_ai */

undefined4 any_on(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  piVar4 = (int *)(param_1 + 0x14);
  iVar5 = (int)param_2 >> 5;
  iVar2 = *(int *)(param_1 + 0x10);
  if ((((iVar2 < iVar5) || (bVar1 = iVar2 <= iVar5, iVar2 = iVar5, bVar1)) ||
      (uVar3 = param_2 & 0x1f, uVar3 == 0)) ||
     (piVar4[iVar5] == ((uint)piVar4[iVar5] >> uVar3) << uVar3)) {
    piVar6 = piVar4 + iVar2;
    do {
      if (piVar6 <= piVar4) {
        return 0;
      }
      piVar6 = piVar6 + -1;
    } while (*piVar6 == 0);
  }
  return 1;
}


