/*
 * Function: ProcessHashDrv
 * Entry:    0007e48c
 * Prototype: drvError_t __stdcall ProcessHashDrv(void * pCtx, CCBuffInfo_t * pInputBuffInfo, uint32_t dataInSize)
 */


/* exclude_from_export */

drvError_t ProcessHashDrv(void *pCtx,CCBuffInfo_t *pInputBuffInfo,uint32_t dataInSize)

{
  int iVar1;
  uint uVar2;
  CCError_t CVar3;
  CCError_t CVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (pInputBuffInfo == (CCBuffInfo_t *)0x0) {
    return 0xf30003;
  }
  if (pCtx == (void *)0x0) {
    return 0xf30000;
  }
  if (*(int *)pCtx == 0) {
    uVar6 = 1;
    uVar5 = 1;
    CVar3 = CC_PalMutexLock((CC_PalMutex *)&DAT_20002f70,0xffffffff);
    if (CVar3 != 0) goto LAB_0007e628;
LAB_0007e4c6:
    CVar3 = CC_PalPowerSaveModeSelect(0);
    uVar5 = uVar6;
  }
  else {
    if (1 < *(int *)pCtx - 1U) {
      return 0xf30001;
    }
    uVar5 = 2;
    CVar3 = CC_PalMutexLock((CC_PalMutex *)&DAT_20002f70,0xffffffff);
    uVar6 = uVar5;
    if (CVar3 == 0) goto LAB_0007e4c6;
LAB_0007e628:
    CC_PalAbort("Fail to acquire mutex\n");
    CVar3 = CC_PalPowerSaveModeSelect(0);
  }
  if (CVar3 != 0) {
    CC_PalAbort("Fail to increase PM counter\n");
  }
  do {
    iVar1 = DAT_50845910;
  } while (iVar1 != 0);
  CC_HalClearInterruptBit(0xffffffff);
  uVar2 = DAT_50845a04;
  CC_HalMaskInterrupt(uVar2 & 0xfffff7ff);
  DAT_50845818 = 1;
  DAT_50845820 = 1;
  DAT_50845900 = 7;
  DAT_508457c4 = 1;
  DAT_508456a4 = 0;
  DAT_508457cc = *(undefined4 *)((int)pCtx + 0x48);
  DAT_508457d0 = *(undefined4 *)((int)pCtx + 0x4c);
  DAT_508457c0 = uVar5;
  if (*(int *)pCtx == 0) {
LAB_0007e536:
    DAT_50845650 = *(undefined4 *)((int)pCtx + 0x18);
    DAT_5084564c = *(undefined4 *)((int)pCtx + 0x14);
    DAT_50845648 = *(undefined4 *)((int)pCtx + 0x10);
    DAT_50845644 = *(undefined4 *)((int)pCtx + 0xc);
    DAT_50845640 = *(undefined4 *)((int)pCtx + 8);
  }
  else if (*(int *)pCtx - 1U < 2) {
    DAT_5084565c = *(undefined4 *)((int)pCtx + 0x24);
    DAT_50845658 = *(undefined4 *)((int)pCtx + 0x20);
    DAT_50845654 = *(undefined4 *)((int)pCtx + 0x1c);
    goto LAB_0007e536;
  }
  if (dataInSize == 0) {
    DAT_508457c8 = 4;
  }
  else {
    if (*(int *)((int)pCtx + 4) == 1) {
      DAT_50845684 = 1;
    }
    DAT_50845b0c = (*(byte *)(pInputBuffInfo + 1) & 1) << 1;
    DAT_50845c28 = *pInputBuffInfo;
    DAT_50845c2c = dataInSize;
    CVar3 = CC_PalWaitInterrupt(0x800);
  }
  if (*(int *)pCtx != 0) {
    if (1 < *(int *)pCtx - 1U) goto LAB_0007e5cc;
    uVar6 = DAT_5084565c;
    *(undefined4 *)((int)pCtx + 0x24) = uVar6;
    uVar6 = DAT_50845658;
    *(undefined4 *)((int)pCtx + 0x20) = uVar6;
    uVar6 = DAT_50845654;
    *(undefined4 *)((int)pCtx + 0x1c) = uVar6;
  }
  uVar6 = DAT_50845650;
  *(undefined4 *)((int)pCtx + 0x18) = uVar6;
  uVar6 = DAT_5084564c;
  *(undefined4 *)((int)pCtx + 0x14) = uVar6;
  uVar6 = DAT_50845648;
  *(undefined4 *)((int)pCtx + 0x10) = uVar6;
  uVar6 = DAT_50845644;
  *(undefined4 *)((int)pCtx + 0xc) = uVar6;
  uVar6 = DAT_50845640;
  *(undefined4 *)((int)pCtx + 8) = uVar6;
LAB_0007e5cc:
  uVar6 = DAT_508457cc;
  *(undefined4 *)((int)pCtx + 0x48) = uVar6;
  uVar6 = DAT_508457d0;
  *(undefined4 *)((int)pCtx + 0x4c) = uVar6;
  DAT_508457c4 = 1;
  DAT_50845684 = 0;
  DAT_508457c8 = 0;
  DAT_50845818 = 0;
  DAT_50845820 = 0;
  if (CVar3 != 0) {
    CC_HalWriteRegister((void *)((int)pCtx + 8),0x10);
  }
  CVar4 = CC_PalPowerSaveModeSelect(1);
  if (CVar4 != 0) {
    CC_PalAbort("Fail to decrease PM counter\n");
  }
  CVar4 = CC_PalMutexUnlock((CC_PalMutex *)&DAT_20002f70);
  if (CVar4 == 0) {
    return CVar3;
  }
  CC_PalAbort("Fail to release mutex\n");
  return CVar3;
}


