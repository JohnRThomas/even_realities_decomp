/*
 * Function: FUN_00080d20
 * Entry:    00080d20
 * Prototype: undefined __stdcall FUN_00080d20(undefined1 param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_00080d20(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_c;
  undefined1 local_b;
  undefined2 uStack_a;
  undefined4 uStack_8;
  
  uStack_a = (undefined2)((uint)param_2 >> 0x10);
  _local_c = CONCAT11((char)param_2,param_1);
  uStack_8 = param_3;
  FUN_00080f80(0xc0,&local_c,2);
  FUN_00080ece(0x97);
  busy_wait_seconds(1);
  return;
}


