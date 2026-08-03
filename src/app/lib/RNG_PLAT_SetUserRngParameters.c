/*
 * Function: RNG_PLAT_SetUserRngParameters
 * Entry:    0007e220
 * Prototype: CCError_t __stdcall RNG_PLAT_SetUserRngParameters(CCRndParams_t * pTrngParams)
 */


/* exclude_from_export */

CCError_t RNG_PLAT_SetUserRngParameters(CCRndParams_t *pTrngParams)

{
  undefined *puVar1;
  uint uVar2;
  size_t local_14;
  
  local_14 = 0x1c;
  puVar1 = (undefined *)CC_PalTrngParamGet((CC_PalTrngParams_t *)pTrngParams,&local_14);
  if (puVar1 == (undefined *)0x0) {
    if (local_14 == 0x1c) {
      uVar2 = (uint)(pTrngParams[2] != 0) << 2 | (uint)(pTrngParams[1] != 0) << 1;
      if (*pTrngParams != 0) {
        uVar2 = uVar2 | 1;
      }
      pTrngParams[7] = 1;
      if (pTrngParams[3] != 0) {
        pTrngParams[8] = uVar2 | 8;
        pTrngParams[9] = 0;
        return 0;
      }
      pTrngParams[8] = uVar2;
      pTrngParams[9] = 0;
      if (uVar2 != 0) {
        return 0;
      }
      puVar1 = &DAT_00f00c0e;
    }
    else {
      puVar1 = &DAT_00f00c37;
    }
    CC_HalWriteRegister(pTrngParams,0x1c);
  }
  return (CCError_t)puVar1;
}


