/*
 * Function: FUN_0102a47c
 * Entry:    0102a47c
 * Prototype: undefined __stdcall FUN_0102a47c(int param_1)
 */


void FUN_0102a47c(int param_1)

{
  if (*(char *)(param_1 + 0x20) != '\0') {
    FUN_0102a46c(param_1);
  }
  if (*(char *)(param_1 + 0x80) != '\0') {
    FUN_01022038(param_1);
  }
  if (*(int *)(param_1 + 0x84) != 0) {
    FUN_0102a43a(param_1);
    FUN_0100aef0(*(undefined4 **)(param_1 + 0x84));
    *(undefined4 *)(param_1 + 0x84) = 0;
  }
  return;
}


