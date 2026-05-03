/*
 * Function: ?_panel_something
 * Entry:    00080b9e
 * Prototype: undefined __stdcall ?_panel_something(int param_1)
 */


void __panel_something(int param_1)

{
  if (*(int *)(param_1 + 0x35c) != 0) {
    FUN_00080dd2((ushort)*(undefined4 *)(param_1 + 0x348),(ushort)*(undefined4 *)(param_1 + 0x34c),
                 *(undefined4 *)(param_1 + 0x24),*(uint *)(param_1 + 0x350));
    return;
  }
  return;
}


