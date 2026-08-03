/*
 * Function: RndStartupTest
 * Entry:    0007d414
 * Prototype: CCError_t __stdcall RndStartupTest(CCRndWorkBuff_t * workBuff_ptr)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

CCError_t RndStartupTest(CCRndWorkBuff_t *workBuff_ptr)

{
  CCError_t CVar1;
  CCError_t CVar2;
  CCRndState_t local_3c;
  CCRndParams_t aCStack_38 [11];
  
  local_3c.opaque[0] = 0;
  local_3c.opaque[1] = 0;
  local_3c.opaque[2] = 0;
  local_3c.opaque[3] = 0;
  memset(aCStack_38,0,0x28);
  CVar1 = RNG_PLAT_SetUserRngParameters(aCStack_38);
  if (CVar1 == 0) {
    CVar1 = CC_PalMutexLock(DAT_20002f60,0xffffffff);
    if (CVar1 != 0) {
      CC_PalAbort("Fail to acquire mutex\n");
    }
    if ((_DAT_50846e34 & 1) == 0) {
      CVar1 = CC_PalPowerSaveModeSelect(0);
      if (CVar1 != 0) {
        CC_PalAbort("Fail to increase PM counter\n");
      }
      CVar1 = LLF_RND_RunTrngStartupTest(&local_3c,aCStack_38,(uint32_t *)&DAT_2000db08);
      CVar2 = CC_PalPowerSaveModeSelect(1);
      if (CVar2 != 0) {
        CC_PalAbort("Fail to decrease PM counter\n");
      }
      CVar2 = CC_PalMutexUnlock(DAT_20002f60);
    }
    else {
      CVar1 = 5;
      CVar2 = CC_PalMutexUnlock(DAT_20002f60);
    }
    if (CVar2 != 0) {
      CC_PalAbort("Fail to release mutex\n");
      return CVar1;
    }
  }
  return CVar1;
}


