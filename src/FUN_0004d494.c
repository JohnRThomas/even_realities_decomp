/*
 * Function: FUN_0004d494
 * Entry:    0004d494
 * Prototype: undefined __stdcall FUN_0004d494(int * param_1, int param_2, int param_3)
 */


void FUN_0004d494(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  
  if (param_3 == 0) {
    uVar4 = get_bootSeconds();
    iVar2 = *(int *)(&DAT_2000aa80 + param_2 * 4);
    if (iVar2 == 0) {
      *(int *)(&DAT_2000aa80 + param_2 * 4) = (int)uVar4;
    }
    else {
      uVar3 = (int)uVar4 - iVar2;
      if (999 < uVar3) {
        uVar3 = uVar3 / 1000;
        iVar1 = *param_1;
        *(uint *)(&DAT_2000aa80 + param_2 * 4) = uVar3 * 1000 + iVar2;
        *param_1 = iVar1 + uVar3;
      }
    }
  }
  else {
    uVar4 = get_bootSeconds();
    *(int *)(&DAT_2000aa80 + param_2 * 4) = (int)uVar4;
  }
  return;
}


