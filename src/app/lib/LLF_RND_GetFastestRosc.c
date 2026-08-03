/*
 * Function: LLF_RND_GetFastestRosc
 * Entry:    0007e394
 * Prototype: CCError_t __stdcall LLF_RND_GetFastestRosc(CCRndParams_t * trngParams_ptr, uint32_t * rosc_ptr)
 */


/* exclude_from_export */

CCError_t LLF_RND_GetFastestRosc(CCRndParams_t *trngParams_ptr,uint32_t *rosc_ptr)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *rosc_ptr;
  do {
    uVar1 = uVar2 & trngParams_ptr[8];
    uVar2 = uVar2 << 1;
    if (uVar1 != 0) {
      return 0;
    }
    *rosc_ptr = uVar2;
  } while (uVar2 < 9);
  return 0xf10c31;
}


