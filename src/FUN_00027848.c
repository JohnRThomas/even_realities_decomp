/*
 * Function: FUN_00027848
 * Entry:    00027848
 * Prototype: int __stdcall FUN_00027848(int param_1)
 */


int FUN_00027848(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 == 0) || (global_st25dv_context_ptr == (st25dv_context *)0x0)) {
    printk("input param valid \n");
    iVar1 = -1;
  }
  else {
    iVar2 = 10;
    do {
      iVar1 = FUN_0007fd80(global_st25dv_context_ptr,param_1);
      if (iVar1 == 0) {
        return 0;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return iVar1;
}


