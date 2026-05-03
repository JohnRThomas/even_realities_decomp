/*
 * Function: FUN_01027a2c
 * Entry:    01027a2c
 * Prototype: bool __stdcall FUN_01027a2c(int param_1, short param_2)
 */


bool FUN_01027a2c(int param_1,short param_2)

{
  return (ushort)(param_2 + 8U) <= *(ushort *)(param_1 + 4);
}


