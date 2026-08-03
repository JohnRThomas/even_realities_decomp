/*
 * Function: _close16
 * Entry:    0004e2e8
 * Prototype: undefined __stdcall _close16(int param_1)
 */


/* exclude_from_export_ai */

void _close16(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(&DAT_20002570 + param_1 * 40);
  do {
    iVar1 = *piVar2;
    if (iVar1 == 0) {
      return;
    }
  } while (*piVar2 != iVar1);
  *piVar2 = iVar1 + -1;
  if (iVar1 == 1) {
    *(undefined4 *)(&DAT_20002568 + param_1 * 40) = 0;
    *(undefined4 *)(&DAT_2000256c + param_1 * 40) = 0;
  }
  return;
}


