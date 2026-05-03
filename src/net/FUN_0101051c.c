/*
 * Function: FUN_0101051c
 * Entry:    0101051c
 * Prototype: undefined4 __stdcall FUN_0101051c(int param_1, int param_2)
 */


undefined4 FUN_0101051c(int param_1,int param_2)

{
  if (*(char *)(*(int *)(param_1 + 4) + 0xc5) != '\x15') {
    return 2;
  }
  FUN_0100ef90(param_2,(undefined4 *)(*(int *)(param_1 + 4) + 0x353));
  FUN_0100efa4(param_2,(undefined4 *)(*(int *)(param_1 + 4) + 0x144));
  *(undefined1 *)(*(int *)(param_1 + 4) + 0xc5) = 0x18;
  return 0;
}


