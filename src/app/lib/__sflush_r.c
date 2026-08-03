/*
 * Function: __sflush_r
 * Entry:    0008a1be
 * Prototype: undefined4 __stdcall __sflush_r(int * param_1, int * param_2)
 */


/* exclude_from_export_ai */

undefined4 __sflush_r(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  code *pcVar6;
  int iVar7;
  
  uVar3 = (uint)(short)param_2[3];
  if ((int)(uVar3 << 0x1c) < 0) {
    iVar1 = param_2[4];
    if (iVar1 == 0) {
      return 0;
    }
    iVar7 = *param_2;
    *param_2 = iVar1;
    if ((uVar3 & 3) == 0) {
      iVar4 = param_2[5];
    }
    else {
      iVar4 = 0;
    }
    iVar7 = iVar7 - iVar1;
    param_2[2] = iVar4;
    while( true ) {
      if (iVar7 < 1) {
        return 0;
      }
      iVar4 = (*(code *)param_2[10])(param_1,param_2[8],iVar1,iVar7);
      if (iVar4 < 1) break;
      iVar1 = iVar1 + iVar4;
      iVar7 = iVar7 - iVar4;
    }
LAB_0008a2aa:
    uVar5 = *(ushort *)(param_2 + 3);
LAB_0008a2ae:
    *(ushort *)(param_2 + 3) = uVar5 | 0x40;
    return 0xffffffff;
  }
  if ((param_2[1] < 1) && (param_2[0x10] < 1)) {
    return 0;
  }
  pcVar6 = (code *)param_2[0xb];
  if (pcVar6 == (code *)0x0) {
    return 0;
  }
  iVar7 = *param_1;
  iVar1 = param_2[8];
  *param_1 = 0;
  if ((uVar3 & 0x1000) == 0) {
    iVar1 = (*pcVar6)(param_1,iVar1,0,1);
    if ((iVar1 == -1) && (iVar4 = *param_1, iVar4 != 0)) {
      if ((iVar4 == 0x1d) || (iVar4 == 0x16)) {
        *param_1 = iVar7;
        return 0;
      }
      goto LAB_0008a2aa;
    }
  }
  else {
    iVar1 = param_2[0x15];
  }
  if (((int)((uint)*(ushort *)(param_2 + 3) << 0x1d) < 0) &&
     (iVar1 = iVar1 - param_2[1], param_2[0xd] != 0)) {
    iVar1 = iVar1 - param_2[0x10];
  }
  iVar1 = (*(code *)param_2[0xb])(param_1,param_2[8],iVar1,0);
  if (iVar1 == -1) {
    iVar4 = *param_1;
    uVar5 = *(ushort *)(param_2 + 3);
    uVar3 = (uint)(short)uVar5;
    if (iVar4 != 0) {
      if ((iVar4 != 0x1d) && (iVar4 != 0x16)) goto LAB_0008a2ae;
      param_2[1] = 0;
      *param_2 = param_2[4];
      goto LAB_0008a220;
    }
    param_2[1] = 0;
    *param_2 = param_2[4];
  }
  else {
    param_2[1] = 0;
    *param_2 = param_2[4];
    uVar3 = (uint)*(ushort *)(param_2 + 3);
  }
  if ((int)(uVar3 << 0x13) < 0) {
    param_2[0x15] = iVar1;
  }
LAB_0008a220:
  piVar2 = (int *)param_2[0xd];
  *param_1 = iVar7;
  if (piVar2 != (int *)0x0) {
    if (piVar2 != param_2 + 0x11) {
      _free_r(param_1,(int)piVar2);
    }
    param_2[0xd] = 0;
  }
  return 0;
}


