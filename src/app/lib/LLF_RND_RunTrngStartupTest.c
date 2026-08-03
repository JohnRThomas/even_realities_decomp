/*
 * Function: LLF_RND_RunTrngStartupTest
 * Entry:    0007dc88
 * Prototype: CCError_t __stdcall LLF_RND_RunTrngStartupTest(CCRndState_t * rndState_ptr, CCRndParams_t * trngParams_ptr, uint32_t * rndWorkBuff_ptr)
 */


/* exclude_from_export */

CCError_t LLF_RND_RunTrngStartupTest
                    (CCRndState_t *rndState_ptr,CCRndParams_t *trngParams_ptr,
                    uint32_t *rndWorkBuff_ptr)

{
  CCError_t CVar1;
  uint32_t *puStack_18;
  uint32_t auStack_14 [2];
  
  CVar1 = getTrngSource(rndState_ptr,trngParams_ptr,0,&puStack_18,auStack_14,rndWorkBuff_ptr,1);
  return CVar1;
}


