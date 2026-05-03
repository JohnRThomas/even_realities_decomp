/*
 * Function: FUN_00019e04
 * Entry:    00019e04
 * Prototype: int __stdcall FUN_00019e04(void * param_1)
 */


int FUN_00019e04(void *param_1)

{
  int iVar1;
  undefined1 auStack_d8 [204];
  
  iVar1 = z_impl_k_msgq_get((k_msgq *)&DAT_20007ef8,auStack_d8,(k_timeout_t)0x0);
  if (iVar1 == 0) {
    memcpy(param_1,auStack_d8,200);
  }
  return iVar1;
}


