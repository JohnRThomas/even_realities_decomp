/*
 * Function: FUN_0101f168
 * Entry:    0101f168
 * Prototype: undefined8 __stdcall FUN_0101f168(undefined4 param_1, int param_2)
 */


undefined8 FUN_0101f168(undefined4 param_1,int param_2)

{
  *(undefined2 *)(param_2 >> 8) = DAT_21000eac._2_2_;
  *(undefined1 *)((undefined2 *)(param_2 >> 8) + 1) = (undefined1)DAT_21000eac;
  return 0;
}


