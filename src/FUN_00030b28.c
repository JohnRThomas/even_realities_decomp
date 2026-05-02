/*
 * Function: FUN_00030b28
 * Entry:    00030b28
 * Prototype: int __stdcall FUN_00030b28(void)
 */


int FUN_00030b28(void)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_dc [208];
  
  iVar1 = 0;
  for (iVar2 = DAT_20003a54; 0 < iVar2; iVar2 = iVar2 + -1) {
    iVar1 = z_impl_k_msgq_get((k_msgq *)&DAT_20003a30,auStack_dc,(k_timeout_t)0x0);
  }
  return iVar1;
}


