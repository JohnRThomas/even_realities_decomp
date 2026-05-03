/*
 * Function: FUN_01020094
 * Entry:    01020094
 * Prototype: undefined __stdcall FUN_01020094(uint param_1)
 */


void FUN_01020094(uint param_1)

{
  *(byte *)((int)&DAT_21000020 + (param_1 >> 3)) =
       (byte)(1 << (param_1 & 7)) | *(byte *)((int)&DAT_21000020 + (param_1 >> 3));
  return;
}


