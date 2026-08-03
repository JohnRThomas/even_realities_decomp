/*
 * Function: nrf_cc3xx_platform_ctr_drbg_get
 * Entry:    0007c910
 * Prototype: int __stdcall nrf_cc3xx_platform_ctr_drbg_get(nrf_cc3xx_platform_ctr_drbg_context_t * context, uint8_t * buffer, size_t length, size_t * olen)
 */


/* exclude_from_export */

int nrf_cc3xx_platform_ctr_drbg_get
              (nrf_cc3xx_platform_ctr_drbg_context_t *context,uint8_t *buffer,size_t length,
              size_t *olen)

{
  int iVar1;
  
  if (context == (nrf_cc3xx_platform_ctr_drbg_context_t *)0x0) {
    context = (nrf_cc3xx_platform_ctr_drbg_context_t *)&DAT_2000d618;
  }
  if (*(int *)context->opaque == 0x5ac9bca5) {
    iVar1 = mbedtls_ctr_drbg_random_with_add(context + 0x47,buffer,length,(uchar *)0x0,0);
    if (iVar1 != 0) {
      length = 0;
    }
    *olen = length;
  }
  else {
    iVar1 = -0x7018;
  }
  return iVar1;
}


