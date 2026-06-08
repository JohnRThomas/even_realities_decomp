/*
 * Function: load_app_white_list_from_flash
 * Entry:    00036de0
 * Prototype: undefined __stdcall load_app_white_list_from_flash(void)
 */


void load_app_white_list_from_flash(void)

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


