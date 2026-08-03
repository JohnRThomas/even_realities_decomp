/*
 * Function: CC_HalClearInterruptBit
 * Entry:    0007d538
 * Prototype: void __stdcall CC_HalClearInterruptBit(uint32_t data)
 */


/* exclude_from_export */

void CC_HalClearInterruptBit(uint32_t data)

{
  if ((int)(data << 0x15) < 0) {
    Peripherals::CC_AES_S._264_4_ = 0xffffffff;
  }
  DAT_50845a08 = data;
  return;
}


