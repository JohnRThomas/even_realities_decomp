/*
 * Function: CC_LibInit
 * Entry:    0007d4c0
 * Prototype: CClibRetCode_t __stdcall CC_LibInit(CCRndContext_t * rndContext_ptr, CCRndWorkBuff_t * rndWorkBuff_ptr)
 */


/* exclude_from_export */

CClibRetCode_t CC_LibInit(CCRndContext_t *rndContext_ptr,CCRndWorkBuff_t *rndWorkBuff_ptr)

{
  int iVar1;
  CCError_t CVar2;
  size_t asStack_14 [2];
  
  iVar1 = CC_HalInit();
  if (iVar1 != 0) {
    CC_PalTerminate();
    return CC_LIB_RET_HAL;
  }
  iVar1 = CC_PalInit();
  if (iVar1 != 0) {
    return CC_LIB_RET_PAL;
  }
  DAT_50845a0c = 0;
  CVar2 = RndStartupTest((CCRndWorkBuff_t *)0x0);
  if (CVar2 == 0) {
    if (DAT_2000dd28 != 0) {
      return CC_LIB_RET_OK;
    }
    iVar1 = CC_LibFini((int *)0x0,(void *)0x0,0);
    if ((iVar1 == 0) &&
       (iVar1 = nrf_cc3xx_platform_ctr_drbg_get
                          ((nrf_cc3xx_platform_ctr_drbg_context_t *)0x0,&DAT_2000dd2c,0x68,
                           asStack_14), iVar1 == 0)) {
      DAT_2000dd28 = 0x5a5aea5a;
      return CC_LIB_RET_OK;
    }
  }
  return CC_LIB_RET_RND_INST_ERR;
}


