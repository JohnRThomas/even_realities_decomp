/*
 * Function: entropy_get_entropy
 * Entry:    00055ea4
 * Prototype: int __stdcall entropy_get_entropy(device * dev, uint8_t * buffer, uint16_t length)
 */


/* WARNING: Removing unreachable block (ram,0x00055eb2) */
/* exclude_from_export */

int entropy_get_entropy(device *dev,uint8_t *buffer,uint16_t length)

{
  int iVar1;
  
  iVar1 = entropy_cc3xx_rng_get_entropy
                    ((device *)&PTR_s_crypto_50844000_0008b340,(uint8_t *)dev,(uint16_t)buffer);
  return iVar1;
}


