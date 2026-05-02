/*
 * Function: ?_init_nfc_comm
 * Entry:    00027818
 * Prototype: int __stdcall ?_init_nfc_comm(void)
 */


int __init_nfc_comm(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_000346b4((int)global_st25dv_context_ptr);
  if (iVar1 == 0) {
    iVar2 = process_pt_data(0);
    iVar1 = 0;
    if (iVar2 != 0) {
      iVar1 = -2;
    }
  }
  else {
    printk("init_nfc_comm is failed\n");
    iVar1 = -1;
  }
  return iVar1;
}


