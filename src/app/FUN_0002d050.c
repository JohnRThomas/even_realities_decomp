/*
 * Function: FUN_0002d050
 * Entry:    0002d050
 * Prototype: int __stdcall FUN_0002d050(void)
 */


int FUN_0002d050(void)

{
  int iVar1;
  int iVar2;
  
  if (DAT_20008530 < 0) {
LAB_0002d082:
    iVar1 = 0;
  }
  else {
    iVar2 = 5;
    do {
      iVar1 = FUN_00088444(0x8b478);
      if (iVar1 == 0) {
        DAT_20008530 = -0x10;
        goto LAB_0002d082;
      }
      z_impl_k_sleep((k_timeout_t)0x667);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return iVar1;
}


