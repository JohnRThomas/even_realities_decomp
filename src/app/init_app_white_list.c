/*
 * Function: ?_init_app_white_list
 * Entry:    00036de0
 * Prototype: undefined __stdcall ?_init_app_white_list(void)
 */


void __init_app_white_list(void)

{
  int iVar1;
  
  memset(&DAT_2001aefb,0,0x15e2);
  printk("MAX_WHITE_LIST_BUF_LEN is %d \n",0x15e3);
  iVar1 = load_whitelist();
  if (iVar1 == 0) {
    dump_whitelist();
    return;
  }
  return;
}


