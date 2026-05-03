/*
 * Function: FUN_0103b4da
 * Entry:    0103b4da
 * Prototype: undefined4 __stdcall FUN_0103b4da(int param_1)
 */


undefined4 FUN_0103b4da(int param_1)

{
  if ((uint)*(ushort *)(*(int *)(param_1 + 0x1c) + 2) != (uint)*(ushort *)(param_1 + 0x30)) {
    return *(undefined4 *)
            (*(int *)(param_1 + 0x18) +
             (uint)*(ushort *)
                    (*(int *)(param_1 + 0x1c) +
                     ((uint)*(ushort *)(param_1 + 0x30) & *(ushort *)(param_1 + 10) - 1) * 2 + 4) *
             0x10 + 8);
  }
  return 0;
}


