/*
 * Function: app_list_init
 * Entry:    00035fe0
 * Prototype: undefined __stdcall app_list_init(void)
 */


void app_list_init(void)

{
  APP_WHITE_LIST_BUF = 10;
  DAT_2001aef9 = 0;
  DAT_2001aef8 = 0;
  FUN_00035a84();
  memset(&DAT_2000878c,0,0x2210);
  load_app_white_list_from_flash();
  return;
}


