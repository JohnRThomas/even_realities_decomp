/*
 * Function: LLF_RND_GetRoscSampleCnt
 * Entry:    0007e360
 * Prototype: CCError_t __stdcall LLF_RND_GetRoscSampleCnt(uint32_t rosc, CCRndParams_t * pTrngParams)
 */


/* exclude_from_export */

CCError_t LLF_RND_GetRoscSampleCnt(uint32_t rosc,CCRndParams_t *pTrngParams)

{
  CCRndParams_t CVar1;
  
  switch(rosc) {
  case 1:
    CVar1 = *pTrngParams;
    break;
  case 2:
    CVar1 = pTrngParams[1];
    break;
  default:
    return 0xf10c31;
  case 4:
    pTrngParams[9] = pTrngParams[2];
    return 0;
  case 8:
    CVar1 = pTrngParams[3];
  }
  pTrngParams[9] = CVar1;
  return 0;
}


