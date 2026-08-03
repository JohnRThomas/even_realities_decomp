/*
 * Function: i2c_delay
 * Entry:    0007fbe2
 * Prototype: void __stdcall i2c_delay(uint cycles_to_wait)
 */


/* exclude_from_export_ai */

void i2c_delay(uint cycles_to_wait)

{
  z_impl_k_sleep((k_timeout_t)0x21);
  return;
}


