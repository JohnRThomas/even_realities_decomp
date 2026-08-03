/*
 * Function: mbedtls_hardware_poll
 * Entry:    0007dca4
 * Prototype: int __stdcall mbedtls_hardware_poll(void * data, uchar * output, size_t len, size_t * olen)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

int mbedtls_hardware_poll(void *data,uchar *output,size_t len,size_t *olen)

{
  CCError_t CVar1;
  int iVar2;
  int local_20;
  uint local_1c;
  
  if (((output == (uchar *)0x0) || (olen == (size_t *)0x0)) || (len == 0)) {
    return -1;
  }
  CVar1 = CC_PalMutexLock(DAT_20002f60,0xffffffff);
  if (CVar1 != 0) {
    CC_PalAbort("Fail to acquire mutex\n");
  }
  if ((_DAT_50846e34 & 1) == 0) {
    CVar1 = CC_PalPowerSaveModeSelect(0);
    if (CVar1 != 0) {
      CC_PalAbort("Fail to increase PM counter\n");
    }
    CVar1 = RNG_PLAT_SetUserRngParameters((CCRndParams_t *)&DAT_2000dd9c);
    if ((CVar1 == 0) &&
       (iVar2 = nrf_cc3xx_platform_entropy_get(&DAT_2000dd98,0x2000dd9c,(size_t *)0x0), iVar2 == 0))
    {
      if (local_1c <= len) {
        len = local_1c;
      }
      *olen = len;
      memmove(output,(void *)(local_20 + 8),len);
      iVar2 = 0;
    }
    else {
      iVar2 = -1;
    }
    CVar1 = CC_PalPowerSaveModeSelect(1);
    if (CVar1 != 0) {
      CC_PalAbort("Fail to decrease PM counter\n");
    }
  }
  else {
    iVar2 = -1;
  }
  mbedtls_zeroize_internal(&DAT_2000ddc4,0x220);
  mbedtls_zeroize_internal(&DAT_2000dd98,4);
  mbedtls_zeroize_internal(&DAT_2000dd9c,0x28);
  CVar1 = CC_PalMutexUnlock(DAT_20002f60);
  if (CVar1 == 0) {
    return iVar2;
  }
  CC_PalAbort("Fail to unlock mutex\n");
  return iVar2;
}


