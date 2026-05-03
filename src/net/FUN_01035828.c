/*
 * Function: FUN_01035828
 * Entry:    01035828
 * Prototype: undefined __stdcall FUN_01035828(int * param_1)
 */


void FUN_01035828(int *param_1)

{
  FUN_0102f308((char)((uint)(*param_1 << 0xc) >> 0x18));
  *(undefined4 *)(*param_1 + 0x200) = 0;
  *(undefined4 *)(*param_1 + 0x308) = 0xffffffff;
  FUN_010357e8(param_1);
  (&DAT_21004b00)[(uint)*(byte *)(param_1 + 1) * 0xc] = 0;
  return;
}


