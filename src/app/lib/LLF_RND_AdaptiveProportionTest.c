/*
 * Function: LLF_RND_AdaptiveProportionTest
 * Entry:    0007d948
 * Prototype: CCError_t __stdcall LLF_RND_AdaptiveProportionTest(uint32_t * pData, uint32_t sizeInBytes, uint32_t C, uint32_t W)
 */


/* exclude_from_export */

CCError_t LLF_RND_AdaptiveProportionTest(uint32_t *pData,uint32_t sizeInBytes,uint32_t C,uint32_t W)

{
  uint uVar1;
  uint32_t uVar2;
  uint32_t uVar3;
  uint uVar4;
  uint uVar5;
  
  if (pData == (uint32_t *)0x0) {
    return 0xf10c37;
  }
  if (((sizeInBytes - 1 < 0x210) && (W != 0)) && (C != 0)) {
    uVar1 = 0;
    uVar2 = 0;
    uVar3 = 0;
    uVar4 = 0;
    do {
      while ((uVar5 = pData[uVar1 >> 5] >> (uVar1 & 0x1f), (uVar1 & 0x1f) != 0x1f &&
             (uVar5 = uVar5 & 1, uVar1 == 0))) {
        uVar1 = 1;
        uVar2 = uVar1;
        uVar3 = uVar1;
        uVar4 = uVar5;
      }
      if (W == uVar2) {
        uVar3 = 1;
        uVar2 = uVar3;
        uVar4 = uVar5;
      }
      else {
        if (uVar5 == uVar4) {
          uVar3 = uVar3 + 1;
        }
        if (W - 1 == uVar2) {
          uVar2 = W;
          if (C < uVar3) {
            return 0xf10c37;
          }
        }
        else {
          uVar2 = uVar2 + 1;
        }
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 != sizeInBytes * 8);
    return 0;
  }
  return 0xf10c37;
}


