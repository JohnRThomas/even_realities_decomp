/*
 * Function: FUN_00026618
 * Entry:    00026618
 * Prototype: int __stdcall FUN_00026618(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


int FUN_00026618(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  iVar1 = 0;
  uStack_18 = param_1;
  uStack_14 = param_2;
  uStack_10 = param_3;
  for (iVar2 = DAT_20003b24; 0 < iVar2; iVar2 = iVar2 + -1) {
    iVar1 = z_impl_k_msgq_get((k_msgq *)&DAT_20003b00,&uStack_18,(k_timeout_t)0x0);
  }
  return iVar1;
}


