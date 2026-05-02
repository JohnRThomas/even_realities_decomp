/*
 * Function: FUN_0004b194
 * Entry:    0004b194
 * Prototype: undefined __stdcall FUN_0004b194(int param_1, int param_2, int param_3)
 */


void FUN_0004b194(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
    *(undefined4 *)(param_3 + iVar1 * 4) =
         *(undefined4 *)(&DAT_000db766 + (uint)*(byte *)(param_1 + iVar1) * 4);
  }
  return;
}


