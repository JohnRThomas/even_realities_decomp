/*
 * Function: FUN_00080fca
 * Entry:    00080fca
 * Prototype: undefined4 __stdcall FUN_00080fca(undefined1 param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 FUN_00080fca(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 local_c;
  undefined1 uStack_b;
  undefined2 uStack_a;
  undefined4 uStack_8;
  
  uStack_a = (undefined2)((uint)param_2 >> 0x10);
  _local_c = CONCAT11(param_1,1);
  uStack_8 = param_3;
  display_reflash(&local_c,2);
  z_impl_k_yield();
  return 0;
}


