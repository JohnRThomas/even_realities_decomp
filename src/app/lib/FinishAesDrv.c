/*
 * Function: FinishAesDrv
 * Entry:    0007ec74
 * Prototype: drvError_t __stdcall FinishAesDrv(AesContext_t * aesCtx, CCBuffInfo_t * pInputBuffInfo, CCBuffInfo_t * pOutputBuffInfo, uint32_t blockSize)
 */


/* exclude_from_export */

drvError_t
FinishAesDrv(AesContext_t *aesCtx,CCBuffInfo_t *pInputBuffInfo,CCBuffInfo_t *pOutputBuffInfo,
            uint32_t blockSize)

{
  drvError_t dVar1;
  CCError_t CVar2;
  CCError_t CVar3;
  uint uVar4;
  
  if ((pInputBuffInfo == (CCBuffInfo_t *)0x0) || (pOutputBuffInfo == (CCBuffInfo_t *)0x0)) {
    return 0xf1000b;
  }
  if (aesCtx == (AesContext_t *)0x0) {
    return 0xf10000;
  }
  if (aesCtx[0xd] != 7) {
    if (blockSize == 0) {
      if ((aesCtx[0xd] != 3) || (aesCtx[0x16] != 0)) {
        return 0;
      }
      aesCtx[0x19] = 0;
      aesCtx[0x1a] = 0;
      aesCtx[0x1b] = 0;
      aesCtx[0x1c] = 0;
      blockSize = 0x10;
      *pInputBuffInfo = (CCBuffInfo_t)(aesCtx + 0x19);
    }
    dVar1 = ProcessAesDrv(aesCtx,pInputBuffInfo,pOutputBuffInfo,blockSize);
    return dVar1;
  }
  if (aesCtx[0x17] == 0) {
    if (0xfff < blockSize) {
      return 0xf10005;
    }
  }
  else if ((aesCtx[0x17] == 1) && (0xffff < blockSize)) {
    return 0xf10005;
  }
  if ((blockSize == 0) && (aesCtx[0x16] != 0)) {
    return 0xf10005;
  }
  CVar2 = CC_PalMutexLock((CC_PalMutex *)&DAT_20002f70,0xffffffff);
  if (CVar2 != 0) {
    CC_PalAbort("Fail to acquire mutex\n");
  }
  CVar2 = CC_PalPowerSaveModeSelect(0);
  if (CVar2 != 0) {
    CC_PalAbort("Fail to increase PM counter\n");
  }
  DAT_50845810 = 1;
  DAT_50845820 = 1;
  CVar2 = InitAes(aesCtx);
  if ((CVar2 != 0) || (CVar3 = LoadAesKey(aesCtx), CVar2 = CVar3, CVar3 != 0)) goto LAB_0007ed06;
  if (aesCtx[0xd] < 8) {
    uVar4 = 1 << (aesCtx[0xd] & 0xff);
    if ((uVar4 & 0x8a) == 0) {
      if ((uVar4 & 0x44) == 0) {
        if ((uVar4 & 1) == 0) goto LAB_0007ed68;
      }
      else {
        Peripherals::CC_AES_S.AES_CTR_0_ = *aesCtx;
        Peripherals::CC_AES_S.AES_CTR_1_ = aesCtx[1];
        Peripherals::CC_AES_S.AES_CTR_2_ = aesCtx[2];
        Peripherals::CC_AES_S.AES_CTR_3_ = aesCtx[3];
      }
    }
    else {
      Peripherals::CC_AES_S.AES_IV_0_0_ = *aesCtx;
      Peripherals::CC_AES_S.AES_IV_0_1_ = aesCtx[1];
      Peripherals::CC_AES_S.AES_IV_0_2_ = aesCtx[2];
      Peripherals::CC_AES_S.AES_IV_0_3_ = aesCtx[3];
    }
    Peripherals::CC_AES_S.AES_CMAC_INIT = 1;
    Peripherals::CC_AES_S.AES_REMAINING_BYTES = blockSize;
    DAT_50845b0c = (*(byte *)(pInputBuffInfo + 1) & 1) << 1;
    if (blockSize == 0) {
      if (aesCtx[0x16] == 0) {
        Peripherals::CC_AES_S.AES_CMAC_SIZE0_KICK = 1;
      }
    }
    else {
      if (aesCtx[0x17] == 1) {
        DAT_50845c28 = *pInputBuffInfo;
        DAT_50845c2c = blockSize;
      }
      else {
        DAT_50845c30 = *pInputBuffInfo;
        DAT_50845c34 = blockSize;
      }
      CVar2 = CC_PalWaitInterrupt(0x800);
      if (CVar2 != 0) goto LAB_0007ed06;
    }
    CVar2 = CVar3;
    if (aesCtx[0xd] < 8) {
      uVar4 = 1 << (aesCtx[0xd] & 0xff);
      if ((uVar4 & 0x8a) == 0) {
        if ((uVar4 & 0x44) != 0) {
          uVar4 = Peripherals::CC_AES_S.AES_CTR_0_;
          *aesCtx = uVar4;
          uVar4 = Peripherals::CC_AES_S.AES_CTR_1_;
          aesCtx[1] = uVar4;
          uVar4 = Peripherals::CC_AES_S.AES_CTR_2_;
          aesCtx[2] = uVar4;
          uVar4 = Peripherals::CC_AES_S.AES_CTR_3_;
          aesCtx[3] = uVar4;
        }
      }
      else {
        uVar4 = Peripherals::CC_AES_S.AES_IV_0_0_;
        *aesCtx = uVar4;
        uVar4 = Peripherals::CC_AES_S.AES_IV_0_1_;
        aesCtx[1] = uVar4;
        uVar4 = Peripherals::CC_AES_S.AES_IV_0_2_;
        aesCtx[2] = uVar4;
        uVar4 = Peripherals::CC_AES_S.AES_IV_0_3_;
        aesCtx[3] = uVar4;
      }
    }
  }
  else {
LAB_0007ed68:
    CVar2 = 0xf10001;
  }
LAB_0007ed06:
  DAT_50845810 = 0;
  DAT_50845820 = 0;
  CVar3 = CC_PalPowerSaveModeSelect(1);
  if (CVar3 != 0) {
    CC_PalAbort("Fail to decrease PM counter\n");
  }
  CVar3 = CC_PalMutexUnlock((CC_PalMutex *)&DAT_20002f70);
  if (CVar3 != 0) {
    CC_PalAbort("Fail to release mutex\n");
    return CVar2;
  }
  return CVar2;
}


