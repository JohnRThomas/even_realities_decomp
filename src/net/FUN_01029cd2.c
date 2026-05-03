/*
 * Function: FUN_01029cd2
 * Entry:    01029cd2
 * Prototype: undefined __stdcall FUN_01029cd2(int * param_1, int param_2)
 */


void FUN_01029cd2(int *param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = *param_1;
  if (*param_1 == 0) {
    *param_1 = param_2;
    return;
  }
  do {
    if (*(int *)(iVar1 + 4) == 0) {
      if (iVar1 != param_2) {
        *(int *)(iVar1 + 4) = param_2;
      }
      return;
    }
    bVar2 = iVar1 != param_2;
    iVar1 = *(int *)(iVar1 + 4);
  } while (bVar2);
  return;
}


