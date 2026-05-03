/*
 * Function: FUN_0102a43a
 * Entry:    0102a43a
 * Prototype: undefined __stdcall FUN_0102a43a(int param_1)
 */


void FUN_0102a43a(int param_1)

{
  undefined4 *puVar1;
  
  while (puVar1 = (undefined4 *)FUN_0102a422((int *)(param_1 + 0x30)), puVar1 != (undefined4 *)0x0)
  {
    FUN_01028294(*(undefined4 **)(param_1 + 0x84),puVar1);
  }
  if (*(undefined4 **)(param_1 + 0x88) != (undefined4 *)0x0) {
    FUN_01028294(*(undefined4 **)(param_1 + 0x84),*(undefined4 **)(param_1 + 0x88));
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  return;
}


