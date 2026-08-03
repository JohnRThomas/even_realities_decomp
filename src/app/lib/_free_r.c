/*
 * Function: _free_r
 * Entry:    0007a034
 * Prototype: undefined __stdcall _free_r(undefined4 * param_1, int param_2)
 */


/* exclude_from_export_ai */

void _free_r(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  bool bVar7;
  
  if (param_2 == 0) {
    return;
  }
  piVar6 = (int *)(param_2 + -4);
  if (*(int *)(param_2 + -4) < 0) {
    piVar6 = (int *)((int)piVar6 + *(int *)(param_2 + -4));
  }
  __lock_acquire_recursive();
  if (DAT_2000d608 != (int *)0x0) {
    piVar5 = DAT_2000d608;
    if (DAT_2000d608 <= piVar6) {
      do {
        piVar4 = piVar5;
        piVar5 = (int *)piVar4[1];
        if (piVar5 == (int *)0x0) break;
      } while (piVar5 <= piVar6);
      piVar1 = (int *)((int)piVar4 + *piVar4);
      if (piVar1 == piVar6) {
        iVar3 = *piVar4 + *piVar6;
        *piVar4 = iVar3;
        if (piVar5 == (int *)((int)piVar4 + iVar3)) {
          iVar2 = *piVar5;
          piVar4[1] = piVar5[1];
          *piVar4 = iVar2 + iVar3;
        }
      }
      else if (piVar6 < piVar1) {
        *param_1 = 0xc;
      }
      else {
        piVar1 = (int *)((int)piVar6 + *piVar6);
        bVar7 = piVar5 == piVar1;
        if (bVar7) {
          iVar3 = *piVar5;
          piVar5 = (int *)piVar5[1];
          piVar1 = (int *)(iVar3 + *piVar6);
        }
        piVar6[1] = (int)piVar5;
        if (bVar7) {
          *piVar6 = (int)piVar1;
        }
        piVar4[1] = (int)piVar6;
      }
      goto LAB_0007a056;
    }
    if (DAT_2000d608 == (int *)((int)piVar6 + *piVar6)) {
      iVar3 = *DAT_2000d608;
      DAT_2000d608 = (int *)DAT_2000d608[1];
      *piVar6 = iVar3 + *piVar6;
    }
  }
  piVar6[1] = (int)DAT_2000d608;
  DAT_2000d608 = piVar6;
LAB_0007a056:
  __lock_release_recursive();
  return;
}


