/*
 * Function: FUN_00025bd0
 * Entry:    00025bd0
 * Prototype: int __stdcall FUN_00025bd0(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


int FUN_00025bd0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  iVar1 = 0;
  uStack_18 = param_1;
  uStack_14 = param_2;
  uStack_10 = param_3;
  for (; 0 < param_4; param_4 = param_4 + -1) {
    iVar1 = z_impl_k_msgq_get((k_msgq *)&DAT_20003b34,&uStack_18,(k_timeout_t)0x0);
  }
  return iVar1;
}


