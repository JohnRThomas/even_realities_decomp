/*
 * Function: LLF_RND_TurnOffTrng
 * Entry:    0007e3b4
 * Prototype: void __stdcall LLF_RND_TurnOffTrng(void)
 */


/* exclude_from_export */

void LLF_RND_TurnOffTrng(void)

{
  Peripherals::CC_AES_S._300_4_ = 0;
  Peripherals::CC_AES_S._452_4_ = 0;
  CC_HalClearInterruptBit(0x400);
  Peripherals::CC_AES_S._264_4_ = 0xffffffff;
  return;
}


