/*
 * Function: CC_PalTrngParamGet
 * Entry:    0007e294
 * Prototype: CCError_t __stdcall CC_PalTrngParamGet(CC_PalTrngParams_t * pTrngParams, size_t * pParamsSize)
 */


/* exclude_from_export */

CCError_t CC_PalTrngParamGet(CC_PalTrngParams_t *pTrngParams,size_t *pParamsSize)

{
  uint uVar1;
  
  if (((pTrngParams != (CC_PalTrngParams_t *)0x0) && (pParamsSize != (size_t *)0x0)) &&
     (*pParamsSize == 0x1c)) {
    uVar1 = Peripherals::FICR_S.TRNG90B_ROSC1;
    if (uVar1 == 0xffffffff) {
      uVar1 = 0x5dc;
    }
    else {
      uVar1 = Peripherals::FICR_S.TRNG90B_ROSC1;
    }
    *(uint *)pTrngParams->opaque = uVar1;
    uVar1 = Peripherals::FICR_S.TRNG90B_ROSC2;
    if (uVar1 == 0xffffffff) {
      uVar1 = 0x5dc;
    }
    else {
      uVar1 = Peripherals::FICR_S.TRNG90B_ROSC2;
    }
    *(uint *)pTrngParams[1].opaque = uVar1;
    uVar1 = Peripherals::FICR_S.TRNG90B_ROSC3;
    if (uVar1 == 0xffffffff) {
      uVar1 = 0x834;
    }
    else {
      uVar1 = Peripherals::FICR_S.TRNG90B_ROSC3;
    }
    *(uint *)pTrngParams[2].opaque = uVar1;
    uVar1 = Peripherals::FICR_S.TRNG90B_ROSC4;
    if (uVar1 == 0xffffffff) {
      uVar1 = 0x834;
    }
    else {
      uVar1 = Peripherals::FICR_S.TRNG90B_ROSC4;
    }
    *(uint *)pTrngParams[3].opaque = uVar1;
    uVar1 = Peripherals::FICR_S.TRNG90B_BYTES;
    if (uVar1 == 0xffffffff) {
      uVar1 = 0x90;
    }
    else {
      uVar1 = Peripherals::FICR_S.TRNG90B_BYTES;
    }
    *(uint *)pTrngParams[4].opaque = uVar1;
    uVar1 = Peripherals::FICR_S.TRNG90B_RCCUTOFF;
    if (uVar1 == 0xffffffff) {
      uVar1 = 0x51;
    }
    else {
      uVar1 = Peripherals::FICR_S.TRNG90B_RCCUTOFF;
    }
    *(uint *)pTrngParams[5].opaque = uVar1;
    uVar1 = Peripherals::FICR_S.TRNG90B_APCUTOFF;
    if (uVar1 == 0xffffffff) {
      uVar1 = 0x337;
    }
    else {
      uVar1 = Peripherals::FICR_S.TRNG90B_APCUTOFF;
    }
    *(uint *)pTrngParams[6].opaque = uVar1;
    return 0;
  }
  return 1;
}


