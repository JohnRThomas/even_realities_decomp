/*
 * Function: FUN_00080d5e
 * Entry:    00080d5e
 * Prototype: undefined __stdcall FUN_00080d5e(uint param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_00080d5e(uint param_1,undefined4 param_2,undefined4 param_3)

{
  ushort local_c;
  undefined2 uStack_a;
  undefined4 uStack_8;
  
  _local_c = CONCAT22((short)((uint)param_2 >> 0x10),
                      (ushort)((param_1 & 0xff) << 8) | (ushort)(param_1 >> 8) & 0xff);
  uStack_8 = param_3;
  FUN_00080f80(0x36,&local_c,2);
  return;
}


