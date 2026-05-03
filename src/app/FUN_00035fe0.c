/*
 * Function: FUN_00035fe0
 * Entry:    00035fe0
 * Prototype: undefined __stdcall FUN_00035fe0(void)
 */


void FUN_00035fe0(void)

{
  APP_WHITE_LIST_BUF = 10;
  DAT_2001aef9 = 0;
  DAT_2001aef8 = 0;
  FUN_00035a84();
  memset(&DAT_2000878c,0,0x2210);
  __init_app_white_list();
  return;
}


