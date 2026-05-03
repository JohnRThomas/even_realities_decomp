/*
 * Function: FUN_00080ece
 * Entry:    00080ece
 * Prototype: undefined __stdcall FUN_00080ece(undefined1 param_1)
 */


void FUN_00080ece(undefined1 param_1)

{
  undefined1 *puVar1;
  undefined1 local_11 [5];
  undefined1 local_c [4];
  
  local_c[0] = 0;
  local_11[0] = param_1;
  puVar1 = __get_something_from_glasses_state();
  __lock_lcd_mutex(-1);
  (**(code **)(*(int *)(puVar1 + 0x378) + 8))(*(int *)(puVar1 + 0x378),local_11,1,local_c,1);
  __unlock_lcd_mutex();
  return;
}


