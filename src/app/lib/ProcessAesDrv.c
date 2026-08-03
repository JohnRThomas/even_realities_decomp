/*
 * Function: ProcessAesDrv
 * Entry:    0007e93c
 * Prototype: drvError_t __stdcall ProcessAesDrv(AesContext_t * aesCtx, CCBuffInfo_t * pInputBuffInfo, CCBuffInfo_t * pOutputBuffInfo, uint32_t blockSize)
 */


/* exclude_from_export */

drvError_t
ProcessAesDrv(AesContext_t *aesCtx,CCBuffInfo_t *pInputBuffInfo,CCBuffInfo_t *pOutputBuffInfo,
             uint32_t blockSize)

{
  bool bVar1;
  CCError_t CVar2;
  CCError_t CVar3;
  int iVar4;
  drvError_t dVar5;
  uint uVar6;
  size_t sVar7;
  
  if ((pInputBuffInfo == (CCBuffInfo_t *)0x0) || (pOutputBuffInfo == (CCBuffInfo_t *)0x0)) {
    return 0xf1000b;
  }
  if (aesCtx == (AesContext_t *)0x0) {
    return 0xf10000;
  }
  if (aesCtx[0x17] == 0) {
    if (0xfff < blockSize) {
      return 0xf10005;
    }
  }
  else if ((aesCtx[0x17] == 1) && (0xffff < blockSize)) {
    return 0xf10005;
  }
  if ((char)aesCtx[0xf] == '\x04') {
    iVar4 = kmu_validate_slot_and_size(aesCtx[0x10],aesCtx[0xc]);
    if (iVar4 == 0) {
      Peripherals::CC_AES_S.AES_KEY_0_0_ = *DAT_20002f5c;
      Peripherals::CC_AES_S.AES_KEY_0_1_ = DAT_20002f5c[1];
      Peripherals::CC_AES_S.AES_KEY_0_2_ = DAT_20002f5c[2];
      Peripherals::CC_AES_S.AES_KEY_0_3_ = DAT_20002f5c[3];
      Peripherals::CC_AES_S.AES_KEY_0_4_ = DAT_20002f5c[4];
      Peripherals::CC_AES_S.AES_KEY_0_5_ = DAT_20002f5c[5];
      Peripherals::CC_AES_S.AES_KEY_0_6_ = DAT_20002f5c[6];
      Peripherals::CC_AES_S.AES_KEY_0_7_ = DAT_20002f5c[7];
      uVar6 = aesCtx[0xc];
      if (uVar6 < 3) {
        sVar7 = uVar6 * 8 + 0x10;
        dVar5 = kmu_derive_cmac(aesCtx[0x10],uVar6,(uint8_t *)aesCtx[0x11],aesCtx[0x12],
                                (uint8_t *)aesCtx[0x13],aesCtx[0x14],(int)(aesCtx + 4),sVar7);
        if (dVar5 != 0) {
          Peripherals::CC_AES_S.AES_KEY_0_0_ = *DAT_20002f5c;
          Peripherals::CC_AES_S.AES_KEY_0_1_ = DAT_20002f5c[1];
          Peripherals::CC_AES_S.AES_KEY_0_2_ = DAT_20002f5c[2];
          Peripherals::CC_AES_S.AES_KEY_0_3_ = DAT_20002f5c[3];
          Peripherals::CC_AES_S.AES_KEY_0_4_ = DAT_20002f5c[4];
          Peripherals::CC_AES_S.AES_KEY_0_5_ = DAT_20002f5c[5];
          Peripherals::CC_AES_S.AES_KEY_0_6_ = DAT_20002f5c[6];
          Peripherals::CC_AES_S.AES_KEY_0_7_ = DAT_20002f5c[7];
          CC_HalWriteRegister(aesCtx + 4,sVar7);
        }
        *(undefined1 *)(aesCtx + 0xf) = 0;
      }
    }
    bVar1 = true;
  }
  else {
    bVar1 = false;
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
  if ((CVar2 != 0) || (CVar2 = LoadAesKey(aesCtx), CVar2 != 0)) goto joined_r0x0007e9b6;
  if (aesCtx[0xd] < 8) {
    uVar6 = 1 << (aesCtx[0xd] & 0xff);
    if ((uVar6 & 0x8a) == 0) {
      if ((uVar6 & 0x44) == 0) {
        if ((uVar6 & 1) == 0) goto LAB_0007eb9e;
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
    DAT_50845b0c = (*(byte *)(pInputBuffInfo + 1) & 1) << 1 | *(byte *)(pOutputBuffInfo + 1) & 1;
    if ((aesCtx[0xd] & 0xfffffffb) != 3) {
      if (aesCtx[0x18] == 1) {
        DAT_50845d28 = *pOutputBuffInfo;
        DAT_50845d2c = blockSize;
      }
      else {
        DAT_50845d30 = *pOutputBuffInfo;
        DAT_50845d34 = blockSize;
      }
    }
    if (aesCtx[0x17] == 1) {
      DAT_50845c28 = *pInputBuffInfo;
      DAT_50845c2c = blockSize;
    }
    else {
      DAT_50845c30 = *pInputBuffInfo;
      DAT_50845c34 = blockSize;
    }
    CVar2 = CC_PalWaitInterrupt(0x800);
    if (CVar2 == 0) {
      if (aesCtx[0xd] < 8) {
        uVar6 = 1 << (aesCtx[0xd] & 0xff);
        if ((uVar6 & 0x8a) == 0) {
          if ((uVar6 & 0x44) != 0) {
            uVar6 = Peripherals::CC_AES_S.AES_CTR_0_;
            *aesCtx = uVar6;
            uVar6 = Peripherals::CC_AES_S.AES_CTR_1_;
            aesCtx[1] = uVar6;
            uVar6 = Peripherals::CC_AES_S.AES_CTR_2_;
            aesCtx[2] = uVar6;
            uVar6 = Peripherals::CC_AES_S.AES_CTR_3_;
            aesCtx[3] = uVar6;
          }
        }
        else {
          uVar6 = Peripherals::CC_AES_S.AES_IV_0_0_;
          *aesCtx = uVar6;
          uVar6 = Peripherals::CC_AES_S.AES_IV_0_1_;
          aesCtx[1] = uVar6;
          uVar6 = Peripherals::CC_AES_S.AES_IV_0_2_;
          aesCtx[2] = uVar6;
          uVar6 = Peripherals::CC_AES_S.AES_IV_0_3_;
          aesCtx[3] = uVar6;
        }
      }
      aesCtx[0x16] = 1;
    }
  }
  else {
LAB_0007eb9e:
    CVar2 = 0xf10001;
  }
joined_r0x0007e9b6:
  if (bVar1) {
    *(undefined1 *)(aesCtx + 0xf) = 4;
    CC_HalWriteRegister(aesCtx + 4,0x20);
  }
  DAT_50845810 = 0;
  DAT_50845820 = 0;
  CVar3 = CC_PalPowerSaveModeSelect(1);
  if (CVar3 != 0) {
    CC_PalAbort("Fail to decrease PM counter\n");
  }
  CVar3 = CC_PalMutexUnlock((CC_PalMutex *)&DAT_20002f70);
  if (CVar3 == 0) {
    return CVar2;
  }
  CC_PalAbort("Fail to release mutex\n");
  return CVar2;
}


