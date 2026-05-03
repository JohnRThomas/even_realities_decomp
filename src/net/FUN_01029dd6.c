/*
 * Function: FUN_01029dd6
 * Entry:    01029dd6
 * Prototype: undefined __stdcall FUN_01029dd6(ushort * param_1, int param_2)
 */


void FUN_01029dd6(ushort *param_1,int param_2)

{
  uint uVar1;
  ushort uVar2;
  
  if (param_2 == 0) {
    if (*(char *)((int)param_1 + 3) != '\0') goto LAB_01029dfa;
    if (*param_1 < 0xff) {
      uVar2 = *param_1 * 2;
      if (0xff < uVar2) {
        uVar2 = 0xff;
      }
      goto LAB_01029de8;
    }
  }
  else {
    if (*(char *)((int)param_1 + 3) != '\0') goto LAB_01029dfa;
    if (1 < *param_1) {
      uVar2 = *param_1 >> 1;
LAB_01029de8:
      *param_1 = uVar2;
    }
  }
  uVar1 = FUN_0100fe3c();
  *(char *)(param_1 + 1) = (char)uVar1 - (char)(uVar1 / *param_1) * (char)*param_1;
LAB_01029dfa:
  *(byte *)((int)param_1 + 3) = *(byte *)((int)param_1 + 3) ^ 1;
  return;
}


