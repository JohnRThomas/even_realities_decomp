/*
 * Function: write_invalid_key
 * Entry:    0007e8ec
 * Prototype: undefined __stdcall write_invalid_key(void)
 */


/* exclude_from_export */

void write_invalid_key(void)

{
  Peripherals::CC_AES_S.AES_KEY_0_0_ = *DAT_20002f5c;
  Peripherals::CC_AES_S.AES_KEY_0_1_ = DAT_20002f5c[1];
  Peripherals::CC_AES_S.AES_KEY_0_2_ = DAT_20002f5c[2];
  Peripherals::CC_AES_S.AES_KEY_0_3_ = DAT_20002f5c[3];
  Peripherals::CC_AES_S.AES_KEY_0_4_ = DAT_20002f5c[4];
  Peripherals::CC_AES_S.AES_KEY_0_5_ = DAT_20002f5c[5];
  Peripherals::CC_AES_S.AES_KEY_0_6_ = DAT_20002f5c[6];
  Peripherals::CC_AES_S.AES_KEY_0_7_ = DAT_20002f5c[7];
  return;
}


