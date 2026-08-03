/*
 * Function: LLF_RND_RepetitionCounterTest
 * Entry:    0007d8e4
 * Prototype: CCError_t __stdcall LLF_RND_RepetitionCounterTest(uint32_t * pData, uint32_t sizeInBytes, uint32_t C)
 */


/* exclude_from_export */

CCError_t LLF_RND_RepetitionCounterTest(uint32_t *pData,uint32_t sizeInBytes,uint32_t C)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((pData != (uint32_t *)0x0) && (sizeInBytes - 1 < 0x210)) {
    uVar1 = 0;
    uVar3 = 0;
    uVar4 = 0;
    do {
      while ((uVar2 = pData[uVar1 >> 5] >> (uVar1 & 0x1f), (uVar1 & 0x1f) != 0x1f &&
             (uVar2 = uVar2 & 1, uVar1 == 0))) {
        uVar1 = 1;
        uVar3 = uVar2;
        uVar4 = uVar1;
      }
      uVar1 = uVar1 + 1;
      if (uVar3 == uVar2) {
        uVar4 = uVar4 + 1;
        if (uVar4 == C) {
          return 0xf10c36;
        }
      }
      else {
        uVar4 = 1;
        uVar3 = uVar2;
      }
    } while (uVar1 != sizeInBytes * 8);
    return 0;
  }
  return 0xf10c36;
}


