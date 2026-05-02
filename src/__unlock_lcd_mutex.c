/*
 * Function: ?_unlock_lcd_mutex
 * Entry:    0004af60
 * Prototype: undefined __stdcall ?_unlock_lcd_mutex(void)
 */


void __unlock_lcd_mutex(void)

{
  z_impl_k_mutex_unlock(&lcd_mutex);
  return;
}


