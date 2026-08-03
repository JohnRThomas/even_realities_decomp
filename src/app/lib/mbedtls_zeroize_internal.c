/*
 * Function: mbedtls_zeroize_internal
 * Entry:    0007ca9c
 * Prototype: void __stdcall mbedtls_zeroize_internal(void * v, size_t n)
 */


/* exclude_from_export */

void mbedtls_zeroize_internal(void *v,size_t n)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if ((v != (void *)0x0) && (n != 0)) {
    puVar1 = v;
    do {
      puVar2 = puVar1 + 1;
      *puVar1 = 0;
      puVar1 = puVar2;
    } while ((undefined1 *)(n + (int)v) != puVar2);
  }
  return;
}


