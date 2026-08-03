/*
 * Function: CC_PalInit
 * Entry:    0007d578
 * Prototype: int __stdcall CC_PalInit(void)
 */


/* exclude_from_export_ai */

int CC_PalInit(void)

{
  CCError_t CVar1;
  int iVar2;
  
  CVar1 = CC_PalMutexCreate((CC_PalMutex *)&DAT_20002f70);
  if (((CVar1 == 0) && (CVar1 = CC_PalMutexCreate((CC_PalMutex *)&DAT_20002f6c), CVar1 == 0)) &&
     (CVar1 = CC_PalMutexCreate((CC_PalMutex *)&DAT_20002f68), CVar1 == 0)) {
    DAT_20002f60 = &DAT_20002f68;
    CVar1 = CC_PalMutexCreate((CC_PalMutex *)&DAT_20002f64);
    if (CVar1 == 0) {
      iVar2 = CC_PalDmaInit();
      if (iVar2 == 0) {
        CC_PalInterruptInit();
      }
      return iVar2;
    }
  }
  return CVar1;
}


