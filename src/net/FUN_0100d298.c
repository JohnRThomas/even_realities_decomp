/*
 * Function: FUN_0100d298
 * Entry:    0100d298
 * Prototype: undefined4 __stdcall FUN_0100d298(uint param_1, undefined1 * param_2, undefined4 * param_3)
 */


undefined4 FUN_0100d298(uint param_1,undefined1 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (DAT_21000d19 <= param_1) {
    return 0;
  }
  iVar1 = (uint)(byte)(&DAT_21000e1a)[param_1] * 7;
  *param_2 = (&DAT_21000e6a)[iVar1];
  *param_3 = *(undefined4 *)(&DAT_21000e6b + iVar1);
  *(undefined2 *)(param_3 + 1) = *(undefined2 *)(&DAT_21000e6f + iVar1);
  return 1;
}


