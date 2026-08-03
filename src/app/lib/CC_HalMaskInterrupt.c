/*
 * Function: CC_HalMaskInterrupt
 * Entry:    0007d554
 * Prototype: void __stdcall CC_HalMaskInterrupt(uint32_t data)
 */


/* exclude_from_export */

void CC_HalMaskInterrupt(uint32_t data)

{
  DAT_50845a04 = data;
  return;
}


