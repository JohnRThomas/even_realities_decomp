/*
 * Function: startTrngHW
 * Entry:    0007d7b4
 * Prototype: CCError_t __stdcall startTrngHW(CCRndState_t * rndState_ptr, CCRndParams_t * trngParams_ptr, CCBool_t isRestart, uint32_t * roscsToStart_ptr, CCBool_t isStartup)
 */


/* exclude_from_export */

CCError_t startTrngHW(CCRndState_t *rndState_ptr,CCRndParams_t *trngParams_ptr,CCBool_t isRestart,
                     uint32_t *roscsToStart_ptr,CCBool_t isStartup)

{
  CCRndParams_t CVar1;
  CCError_t CVar2;
  uint32_t uVar3;
  uint uVar4;
  
  if (((rndState_ptr != (CCRndState_t *)0x0) && (trngParams_ptr != (CCRndParams_t *)0x0)) &&
     (roscsToStart_ptr != (uint32_t *)0x0)) {
    if (isRestart != 0) {
      *roscsToStart_ptr = 1;
      *(undefined4 *)rndState_ptr->opaque = 0;
    }
    if (*roscsToStart_ptr == 0) {
      CVar2 = 0xf10c31;
    }
    else {
      CVar2 = LLF_RND_GetFastestRosc(trngParams_ptr,roscsToStart_ptr);
      if ((CVar2 == 0) &&
         (CVar2 = LLF_RND_GetRoscSampleCnt(*roscsToStart_ptr,trngParams_ptr), CVar2 == 0)) {
        uVar3 = *roscsToStart_ptr;
        if (uVar3 == 8) {
          uVar4 = 3;
        }
        else if (uVar3 == 4) {
          uVar4 = 2;
        }
        else {
          uVar4 = (uint)(uVar3 == 2);
        }
        Peripherals::CC_AES_S._452_4_ = 1;
        Peripherals::CC_AES_S._320_4_ = 1;
        do {
          Peripherals::CC_AES_S._452_4_ = 1;
          Peripherals::CC_AES_S._304_4_ = trngParams_ptr[9];
          CVar1 = Peripherals::CC_AES_S._304_4_;
        } while (trngParams_ptr[9] != CVar1);
        Peripherals::CC_AES_S._300_4_ = 0;
        Peripherals::CC_AES_S._264_4_ = 0xffffffff;
        Peripherals::CC_AES_S._256_4_ = 0xffffffe4;
        Peripherals::CC_AES_S._268_4_ = uVar4;
        uVar4 = DAT_50845a04;
        CC_HalMaskInterrupt(uVar4 | 0x400);
        Peripherals::CC_AES_S._312_4_ = 10;
        if (isStartup == 1) {
          uVar4 = Peripherals::FICR_S.TRNG90B_STARTUP;
          if (uVar4 == 0xffffffff) {
            uVar4 = 0x16;
          }
          else {
            uVar4 = Peripherals::FICR_S.TRNG90B_STARTUP;
            uVar4 = uVar4 / 0x18;
          }
        }
        else {
          uVar4 = trngParams_ptr[4] / 0x18;
        }
        Peripherals::CC_AES_S._472_4_ = (trngParams_ptr[9] * uVar4 * 3 & 0x1ffff) << 9;
        Peripherals::CC_AES_S._300_4_ = 1;
        uVar4 = *(uint *)rndState_ptr->opaque & 0xffffff | *roscsToStart_ptr << 0x18;
        *(uint *)rndState_ptr->opaque = uVar4;
        *(uint *)rndState_ptr->opaque = uVar4 | *roscsToStart_ptr << 8;
        return 0;
      }
    }
    return CVar2;
  }
  return 0xf10c35;
}


