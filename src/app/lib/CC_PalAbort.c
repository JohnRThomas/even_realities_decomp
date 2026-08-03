/*
 * Function: CC_PalAbort
 * Entry:    0007c85c
 * Prototype: void __stdcall CC_PalAbort(char * exp)
 */


/* exclude_from_export */

void CC_PalAbort(char *exp)

{
  Peripherals::CC_AES_S.AES_KEY_0_0_ = 0xfefefefe;
  Peripherals::CC_AES_S.AES_KEY_0_1_ = 0xfefefefe;
  Peripherals::CC_AES_S.AES_KEY_0_2_ = 0xfefefefe;
  Peripherals::CC_AES_S.AES_KEY_0_3_ = 0xfefefefe;
  Peripherals::CC_AES_S.AES_KEY_0_4_ = 0xfefefefe;
  Peripherals::CC_AES_S.AES_KEY_0_5_ = 0xfefefefe;
  Peripherals::CC_AES_S.AES_KEY_0_6_ = 0xfefefefe;
  Peripherals::CC_AES_S.AES_KEY_0_7_ = 0xfefefefe;
  Peripherals::CRYPTOCELL_S.ENABLE = 0;
                    /* WARNING: Could not recover jumptable at 0x0007c892. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*nrf_cc3xx_platform_abort_apis_t_20002f10.abort_fn)(exp);
  return;
}


