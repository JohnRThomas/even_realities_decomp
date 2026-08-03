/*
 * Function: _malloc_usable_size_r
 * Entry:    0008b146
 * Prototype: int __stdcall _malloc_usable_size_r(undefined4 param_1, int param_2)
 */


/* exclude_from_export_ai */

int _malloc_usable_size_r(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + -4) + -4;
  if (*(int *)(param_2 + -4) < 0) {
    iVar1 = iVar1 + *(int *)(param_2 + iVar1);
  }
  return iVar1;
}


