/*
 * Function: InitAes
 * Entry:    0007e710
 * Prototype: drvError_t __stdcall InitAes(AesContext_t * aesCtx)
 */


/* exclude_from_export */

drvError_t InitAes(AesContext_t *aesCtx)

{
  int iVar1;
  uint extraout_r1;
  uint uVar2;
  AesContext_t AVar3;
  drvError_t dVar4;
  bool bVar5;
  
  if (aesCtx == (AesContext_t *)0x0) {
    return 0xf10000;
  }
  AVar3 = aesCtx[0xd];
  if ((int)AVar3 < 4) {
    if ((int)AVar3 < 0) {
      return 0xf10001;
    }
  }
  else if (1 < AVar3 - 6) {
    return 0xf10001;
  }
  if (aesCtx[0xe] < 2) {
    if (1 < aesCtx[0x17]) {
      return 0xf10003;
    }
    if (aesCtx[0x18] < 2) {
      do {
        iVar1 = DAT_50845910;
      } while (iVar1 != 0);
      CC_HalClearInterruptBit(0xffffffff);
      uVar2 = DAT_50845a04;
      CC_HalMaskInterrupt(uVar2 & 0xfffff7ff);
      DAT_50845900 = 1;
      Peripherals::CC_AES_S.AES_REMAINING_BYTES = 0;
      bVar5 = (aesCtx[0xd] & 0xfffffffb) != 3;
      uVar2 = extraout_r1;
      if (bVar5) {
        uVar2 = aesCtx[0xe];
      }
      if (bVar5) {
        uVar2 = uVar2 & 1;
      }
      else {
        uVar2 = 0;
      }
      if (aesCtx[0xc] < 3) {
        Peripherals::CC_AES_S.AES_CONTROL = (aesCtx[0xd] & 7) << 2 | aesCtx[0xc] << 0xc | uVar2;
        dVar4 = 0;
        if (aesCtx[0xd] == 7) {
          Peripherals::CC_AES_S.AES_CMAC_INIT = 1;
        }
      }
      else {
        dVar4 = 0xf10006;
      }
    }
    else {
      dVar4 = 0xf10004;
    }
    return dVar4;
  }
  return 0xf10002;
}


