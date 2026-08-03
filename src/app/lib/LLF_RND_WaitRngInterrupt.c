/*
 * Function: LLF_RND_WaitRngInterrupt
 * Entry:    0007e340
 * Prototype: CCError_t __stdcall LLF_RND_WaitRngInterrupt(uint32_t * isr_ptr)
 */


/* exclude_from_export */

CCError_t LLF_RND_WaitRngInterrupt(uint32_t *isr_ptr)

{
  CCError_t CVar1;
  
  CVar1 = CC_HalWaitInterrupt(0x400);
  Peripherals::CC_AES_S._456_4_ = 0;
  Peripherals::CC_AES_S._300_4_ = 0;
  return CVar1;
}


