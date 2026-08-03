/*
 * Function: entropy_cc3xx_rng_get_entropy
 * Entry:    00063bb8
 * Prototype: int __stdcall entropy_cc3xx_rng_get_entropy(device * dev, uint8_t * buffer, uint16_t length)
 */


/* WARNING: Type propagation algorithm not settling */
/* exclude_from_export */

int entropy_cc3xx_rng_get_entropy(device *dev,uint8_t *buffer,uint16_t length)

{
  int iVar1;
  uint8_t *puVar2;
  uint8_t *puVar3;
  uint8_t *length_00;
  uint8_t *local_1c;
  uint8_t *puStack_18;
  
  puVar2 = (uint8_t *)(uint)length;
  local_1c = buffer;
  puStack_18 = puVar2;
  if (dev == (device *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","dev != ((void *)0)",
            "WEST_TOPDIR/nrf/drivers/entropy/entropy_cc3xx.c",0x18);
  }
  else {
    if (buffer != (uint8_t *)0x0) {
      length_00 = &DAT_00000400;
      puVar3 = (uint8_t *)0x0;
      while( true ) {
        if (puVar2 <= puVar3) {
          if (puVar2 == puVar3) {
            iVar1 = 0;
          }
          else {
            iVar1 = 0x16;
          }
          return iVar1;
        }
        if (puVar2 + -(int)puVar3 < &DAT_00000400) {
          length_00 = puVar2 + -(int)puVar3;
        }
        iVar1 = nrf_cc3xx_platform_ctr_drbg_get
                          ((nrf_cc3xx_platform_ctr_drbg_context_t *)0x0,buffer + (int)puVar3,
                           (size_t)length_00,(size_t *)&local_1c);
        if ((iVar1 != 0) || (local_1c != length_00)) break;
        puVar3 = puVar3 + (int)length_00;
      }
      return -0x16;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","buffer != ((void *)0)",
            "WEST_TOPDIR/nrf/drivers/entropy/entropy_cc3xx.c",25);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


