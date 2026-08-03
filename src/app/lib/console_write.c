/*
 * Function: console_write
 * Entry:    0004e2bc
 * Prototype: int __stdcall console_write(uint param_1)
 */


/* exclude_from_export_ai */

int console_write(uint param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((param_1 < 16) && (*(int *)(&DAT_20002570 + param_1 * 40) != 0)) {
    iVar2 = 0;
  }
  else {
    piVar1 = __errno();
    *piVar1 = 9;
    iVar2 = -1;
  }
  return iVar2;
}


