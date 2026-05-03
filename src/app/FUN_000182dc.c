/*
 * Function: FUN_000182dc
 * Entry:    000182dc
 * Prototype: int __stdcall FUN_000182dc(void * param_1)
 */


int FUN_000182dc(void *param_1)

{
  int iVar1;
  undefined1 auStack_114 [264];
  
  memset(auStack_114,0,257);
  iVar1 = z_impl_k_msgq_get((k_msgq *)&DAT_20003a98,auStack_114,(k_timeout_t)0x0);
  if (iVar1 == 0) {
    memcpy(param_1,auStack_114,257);
  }
  return iVar1;
}


