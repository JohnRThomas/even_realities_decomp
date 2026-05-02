/*
 * Function: ?_panel_related
 * Entry:    00036e10
 * Prototype: undefined4 __stdcall ?_panel_related(int param_1, int param_2, undefined4 param_3)
 */


undefined4 __panel_related(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x47f) == '\0') {
    uVar2 = 0xffffffff;
  }
  else {
    *(undefined4 *)(param_1 + 0x348) = 0;
    *(undefined4 *)(param_1 + 0x34c) = 0xb0;
    if ((param_2 == 7) || ((**(code **)(param_1 + 0x1c))(), param_2 - 1U < 0x14)) {
      iVar1 = (param_2 + 0xfffffff) * 0x10;
      if ((*(int *)(&DAT_20002434 + iVar1) != 0) &&
         (*(code **)(&DAT_2000243c + iVar1) != (code *)0x0)) {
        (**(code **)(&DAT_2000243c + iVar1))(param_3);
      }
      (**(code **)(&DAT_20002438 + iVar1))(param_1,param_3);
    }
    if (*(int *)(param_1 + 0x35c) != 0) {
      (**(code **)(param_1 + 0x18))(param_1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


