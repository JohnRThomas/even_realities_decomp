/*
 * Function: FUN_01012eb0
 * Entry:    01012eb0
 * Prototype: ushort __stdcall FUN_01012eb0(int param_1)
 */


ushort FUN_01012eb0(int param_1)

{
  return *(ushort *)(param_1 + 2) & 1;
}


