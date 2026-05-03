/*
 * Function: FUN_01035c7c
 * Entry:    01035c7c
 * Prototype: uint __stdcall FUN_01035c7c(char * param_1, int param_2, char * param_3, uint param_4, undefined4 param_5, int param_6, undefined4 param_7)
 */


uint FUN_01035c7c(char *param_1,int param_2,char *param_3,uint param_4,undefined4 param_5,
                 int param_6,undefined4 param_7)

{
  undefined4 extraout_r1;
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  
  if (((param_1 == (char *)0x0) || (param_2 == 0)) || (param_6 == 0)) {
    return 0xfffff82d;
  }
  piVar4 = (int *)(param_2 + 0x58);
  FUN_0103b50a(piVar4,param_2);
  if (param_4 == 0xffffffff) {
    iVar1 = param_2 + 0x48;
    uVar2 = 0;
    if ((*(uint *)(param_2 + 0x48) & 1) != 0) {
      uVar2 = 0;
      do {
        uVar2 = uVar2 + 1;
        if (uVar2 == 0x80) goto LAB_01035d66;
      } while ((int)((*(uint *)(iVar1 + (uVar2 >> 5) * 4) >> (uVar2 & 0x1f)) << 0x1f) < 0);
    }
    param_4 = uVar2 + 0x400;
    *(uint *)(iVar1 + (uVar2 >> 5) * 4) = *(uint *)(iVar1 + (uVar2 >> 5) * 4) | 1 << (uVar2 & 0x1f);
  }
  else if (0x3ff < param_4) {
    uVar2 = param_4 - 0x400;
    if (uVar2 < 0x80) {
      uVar3 = *(uint *)(param_2 + 0x48 + (uVar2 >> 5) * 4);
      if (-1 < (int)((uVar3 >> (uVar2 & 0x1f)) << 0x1f)) {
        *(uint *)(param_2 + 0x48 + (uVar2 >> 5) * 4) = 1 << (uVar2 & 0x1f) | uVar3;
        goto LAB_01035ce4;
      }
LAB_01035d66:
      uVar2 = 0xfffff829;
    }
    else {
      uVar2 = 0xfffff82d;
    }
    FUN_01036fe4(piVar4);
    return uVar2;
  }
LAB_01035ce4:
  FUN_01035c3c(param_2,param_1,param_3,param_4,param_5,param_6,param_7);
  FUN_01036fe4(piVar4);
  uVar2 = 0;
  if ((*param_1 != '\0') && (uVar2 = 0, *(char *)(param_2 + 0x90) != '\0')) {
    if (*(int *)(param_1 + 0x28) == -1) {
      uVar2 = FUN_0103b568((int)param_1,0);
      if (uVar2 != 0) {
        FUN_0103b516((int)param_1,extraout_r1);
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


