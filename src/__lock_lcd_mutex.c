/*
 * Function: ?_lock_lcd_mutex
 * Entry:    0004af50
 * Prototype: void __stdcall ?_lock_lcd_mutex(int64_t timeout)
 */


void __lock_lcd_mutex(int64_t timeout)

{
  k_timeout_t timeout_00;
  
  timeout_00.ticks._0_4_ = (undefined4)((ulonglong)timeout >> 0x20);
  timeout_00.ticks._4_4_ = (int)timeout;
  z_impl_k_mutex_lock(&lcd_mutex,timeout_00);
  return;
}


