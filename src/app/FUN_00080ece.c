/*
 * Function: FUN_00080ece
 * Entry:    00080ece
 * Prototype: undefined __stdcall FUN_00080ece(undefined1 param_1)
 */


void FUN_00080ece(undefined1 param_1)

{
  jdb_panel_context *pjVar1;
  undefined1 local_11 [5];
  undefined1 local_c [4];
  
  local_c[0] = 0;
  local_11[0] = param_1;
  pjVar1 = get_jdb_panel_context();
  __lock_lcd_mutex(-1);
  (**(code **)(pjVar1->field849_0x378 + 8))(pjVar1->field849_0x378,local_11,1,local_c,1);
  __unlock_lcd_mutex();
  return;
}


