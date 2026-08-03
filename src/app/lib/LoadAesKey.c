/*
 * Function: LoadAesKey
 * Entry:    0007e7d8
 * Prototype: drvError_t __stdcall LoadAesKey(AesContext_t * aesCtx)
 */


/* exclude_from_export */

drvError_t LoadAesKey(AesContext_t *aesCtx)

{
  drvError_t dVar1;
  
  if (aesCtx == (AesContext_t *)0x0) {
    return 0xf10000;
  }
  if ((char)aesCtx[0xf] == '\0') {
    Peripherals::CC_AES_S.AES_KEY_0_0_ = aesCtx[4];
    Peripherals::CC_AES_S.AES_KEY_0_1_ = aesCtx[5];
    Peripherals::CC_AES_S.AES_KEY_0_2_ = aesCtx[6];
    Peripherals::CC_AES_S.AES_KEY_0_3_ = aesCtx[7];
    if (aesCtx[0xc] - 1 < 2) {
      Peripherals::CC_AES_S.AES_KEY_0_4_ = aesCtx[8];
      Peripherals::CC_AES_S.AES_KEY_0_5_ = aesCtx[9];
      if (aesCtx[0xc] == 2) {
        Peripherals::CC_AES_S.AES_KEY_0_6_ = aesCtx[10];
        Peripherals::CC_AES_S.AES_KEY_0_7_ = aesCtx[0xb];
      }
    }
    return 0;
  }
  if ((char)aesCtx[0xf] == '\x02') {
    dVar1 = kmu_validate_slot_and_size_no_kdr(aesCtx[0x10],aesCtx[0xc]);
    if (dVar1 == 0) {
      Peripherals::CC_AES_S.AES_KEY_0_0_ = *DAT_20002f5c;
      Peripherals::CC_AES_S.AES_KEY_0_1_ = DAT_20002f5c[1];
      Peripherals::CC_AES_S.AES_KEY_0_2_ = DAT_20002f5c[2];
      Peripherals::CC_AES_S.AES_KEY_0_3_ = DAT_20002f5c[3];
      Peripherals::CC_AES_S.AES_KEY_0_4_ = DAT_20002f5c[4];
      Peripherals::CC_AES_S.AES_KEY_0_5_ = DAT_20002f5c[5];
      Peripherals::CC_AES_S.AES_KEY_0_6_ = DAT_20002f5c[6];
      Peripherals::CC_AES_S.AES_KEY_0_7_ = DAT_20002f5c[7];
      dVar1 = kmu_load_key_aes(aesCtx[0x10],aesCtx[0xc]);
      if (dVar1 == 0) {
        return 0;
      }
    }
  }
  else {
    dVar1 = 0xf10009;
  }
  Peripherals::CC_AES_S.AES_KEY_0_0_ = *DAT_20002f5c;
  Peripherals::CC_AES_S.AES_KEY_0_1_ = DAT_20002f5c[1];
  Peripherals::CC_AES_S.AES_KEY_0_2_ = DAT_20002f5c[2];
  Peripherals::CC_AES_S.AES_KEY_0_3_ = DAT_20002f5c[3];
  Peripherals::CC_AES_S.AES_KEY_0_4_ = DAT_20002f5c[4];
  Peripherals::CC_AES_S.AES_KEY_0_5_ = DAT_20002f5c[5];
  Peripherals::CC_AES_S.AES_KEY_0_6_ = DAT_20002f5c[6];
  Peripherals::CC_AES_S.AES_KEY_0_7_ = DAT_20002f5c[7];
  return dVar1;
}


