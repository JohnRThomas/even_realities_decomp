/*
 * Function: mutex_init
 * Entry:    0007ca08
 * Prototype: void __stdcall mutex_init(mbedtls_threading_mutex_t * p_mutex)
 */


/* exclude_from_export */

void mutex_init(mbedtls_threading_mutex_t *p_mutex)

{
  if (p_mutex == (mbedtls_threading_mutex_t *)0x0) {
    CC_PalAbort("Can\'t initialize mutex, was NULL\r\n");
  }
  *p_mutex = 0;
  p_mutex[1] = (mbedtls_threading_mutex_t)&DAT_3a00003a;
  return;
}


