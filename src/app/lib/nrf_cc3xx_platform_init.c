/*
 * Function: nrf_cc3xx_platform_init
 * Entry:    0007c7f4
 * Prototype: int __stdcall nrf_cc3xx_platform_init(void)
 */


/* exclude_from_export_ai */

int nrf_cc3xx_platform_init(void)

{
  CCRndContext_t *in_r0;
  CClibRetCode_t CVar1;
  CCRndWorkBuff_t *in_r1;
  
  if ((DAT_2000d614 == 0) || (DAT_2000d610 == 0)) {
    CVar1 = CC_LibInit(in_r0,in_r1);
    if (CVar1 != CC_LIB_RET_OK) {
      if (7 < CVar1 - CC_LIB_RET_EINVAL_CTX_PTR) {
        return -0x7002;
      }
      return *(int *)(&DAT_0009c310 + (CVar1 - CC_LIB_RET_EINVAL_CTX_PTR) * 4);
    }
    DAT_2000d610 = 1;
  }
  DAT_2000d614 = 1;
  return 0;
}


