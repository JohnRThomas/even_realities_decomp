/*
 * Function: getTrngSource
 * Entry:    0007d9c8
 * Prototype: CCError_t __stdcall getTrngSource(CCRndState_t * rndState_ptr, CCRndParams_t * trngParams_ptr, CCBool_t isContinued, uint32_t * * sourceOut_ptr_ptr, uint32_t * sourceOutSize_ptr, uint32_t * rndWorkBuff_ptr, CCBool_t isStartup)
 */


/* exclude_from_export */

CCError_t getTrngSource(CCRndState_t *rndState_ptr,CCRndParams_t *trngParams_ptr,
                       CCBool_t isContinued,uint32_t **sourceOut_ptr_ptr,uint32_t *sourceOutSize_ptr
                       ,uint32_t *rndWorkBuff_ptr,CCBool_t isStartup)

{
  CCRndParams_t CVar1;
  int iVar2;
  CCError_t CVar3;
  uint32_t *pData;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint32_t *d;
  uint uVar7;
  int local_54;
  uint local_50;
  uint local_48;
  uint32_t local_44;
  undefined4 local_40 [7];
  
  if (isStartup == 0) {
    local_50 = trngParams_ptr[4];
  }
  else {
    uVar7 = Peripherals::FICR_S.TRNG90B_STARTUP;
    if (uVar7 == 0xffffffff) {
      local_50 = 0x210;
    }
    else {
      local_50 = Peripherals::FICR_S.TRNG90B_STARTUP;
    }
  }
  *sourceOut_ptr_ptr = rndWorkBuff_ptr;
  *sourceOutSize_ptr = 0;
  if (isContinued == 0) {
    CVar3 = startTrngHW(rndState_ptr,trngParams_ptr,1,&local_48,isStartup);
    if (CVar3 != 0) goto LAB_0007daaa;
  }
  else {
    iVar2 = Peripherals::CC_AES_S._312_4_;
    CVar1 = Peripherals::CC_AES_S._304_4_;
    if ((trngParams_ptr[9] != CVar1) || (iVar2 != 10)) {
      CVar3 = 0xf10c30;
      goto LAB_0007daaa;
    }
    local_48 = (uint)rndState_ptr->opaque[3];
  }
  pData = rndWorkBuff_ptr + 2;
  local_54 = 4;
  uVar7 = local_50 % 6;
  do {
    *sourceOutSize_ptr = local_50;
    if (local_50 == 0) {
LAB_0007dbfc:
      CVar3 = LLF_RND_RepetitionCounterTest(pData,local_50,trngParams_ptr[5]);
      if ((CVar3 == 0) &&
         (CVar3 = LLF_RND_AdaptiveProportionTest(pData,local_50,trngParams_ptr[6],0x400), CVar3 == 0
         )) break;
      *sourceOutSize_ptr = 0;
    }
    else {
      uVar6 = 0;
      LLF_RND_TurnOffTrng();
      d = pData;
      uVar5 = local_50;
      if (rndState_ptr != (CCRndState_t *)0x0) {
        while (trngParams_ptr != (CCRndParams_t *)0x0) {
          local_44 = 0;
          if (local_48 == 0) {
            CVar3 = 0xf10c31;
            goto LAB_0007da62;
          }
          CVar3 = LLF_RND_GetFastestRosc(trngParams_ptr,&local_48);
          if ((CVar3 != 0) ||
             (CVar3 = LLF_RND_GetRoscSampleCnt(local_48,trngParams_ptr), CVar3 != 0))
          goto LAB_0007da62;
          if (local_48 == 8) {
            uVar4 = 3;
          }
          else if (local_48 == 4) {
            uVar4 = 2;
          }
          else {
            uVar4 = (uint)(local_48 == 2);
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
          Peripherals::CC_AES_S._472_4_ =
               (trngParams_ptr[9] * (trngParams_ptr[4] / 0x18) * 3 & 0x1ffff) << 9;
          Peripherals::CC_AES_S._300_4_ = 1;
          *(uint *)rndState_ptr->opaque =
               local_48 << 8 | local_48 << 0x18 | *(uint *)rndState_ptr->opaque & 0xffffff;
          CVar3 = LLF_RND_WaitRngInterrupt(&local_44);
          if ((local_44 & 0x1a) != 0 || CVar3 != 0) goto LAB_0007da68;
          local_40[0] = Peripherals::CC_AES_S._276_4_;
          local_40[1] = Peripherals::CC_AES_S._280_4_;
          local_40[2] = Peripherals::CC_AES_S._284_4_;
          local_40[3] = Peripherals::CC_AES_S._288_4_;
          local_40[4] = Peripherals::CC_AES_S._292_4_;
          local_40[5] = Peripherals::CC_AES_S._296_4_;
          if ((uVar6 == uVar5 / 6) && (uVar7 != 0)) {
            uVar5 = uVar5 - uVar7;
            memmove(d,local_40,uVar7);
            d = (uint32_t *)((int)d + uVar7);
          }
          else {
            uVar5 = uVar5 - 0x18;
            memmove(d,local_40,0x18);
            d = d + 6;
          }
          if (uVar5 == 0) goto LAB_0007dbfc;
          uVar6 = uVar6 + 1;
          LLF_RND_TurnOffTrng();
        }
      }
      local_44 = 0;
      CVar3 = 0xf10c35;
    }
LAB_0007da62:
    if (CVar3 == 0xf10c02) goto LAB_0007daaa;
LAB_0007da68:
    if (local_48 == 8) {
LAB_0007dc30:
      CVar3 = 0xf10c32;
      goto LAB_0007daaa;
    }
    local_48 = local_48 << 1;
    CVar3 = startTrngHW(rndState_ptr,trngParams_ptr,0,&local_48,0);
    if (CVar3 == 0xf10c31) {
      if (trngParams_ptr[8] != 0) goto LAB_0007dc30;
      goto LAB_0007daaa;
    }
    if (CVar3 != 0) goto LAB_0007daaa;
    *(uint *)rndState_ptr->opaque =
         *(uint *)rndState_ptr->opaque >> 8 & 0xff0000 | *(uint *)rndState_ptr->opaque & 0xffffff;
    local_54 = local_54 + -1;
  } while (local_54 != 0);
  CVar3 = 0;
LAB_0007daaa:
  LLF_RND_TurnOffTrng();
  return CVar3;
}


