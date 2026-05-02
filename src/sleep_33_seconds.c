/*
 * Function: sleep_33_seconds
 * Entry:    000802b0
 * Prototype: undefined __stdcall sleep_33_seconds(void)
 */


void sleep_33_seconds(void)

{
  z_impl_k_sleep((k_timeout_t)33);
  return;
}


