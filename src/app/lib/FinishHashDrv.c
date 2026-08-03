/*
 * Function: FinishHashDrv
 * Entry:    0007e69c
 * Prototype: drvError_t __stdcall FinishHashDrv(void * pCtx)
 */


/* exclude_from_export */

drvError_t FinishHashDrv(void *pCtx)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (pCtx != (void *)0x0) {
    uVar5 = *(uint *)((int)pCtx + 8);
    uVar1 = *(uint *)((int)pCtx + 0xc);
    uVar2 = *(uint *)((int)pCtx + 0x10);
    uVar3 = *(uint *)((int)pCtx + 0x14);
    *(uint *)((int)pCtx + 0x10) =
         uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18;
    *(uint *)((int)pCtx + 0x14) =
         uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
    uVar3 = *(uint *)((int)pCtx + 0x18);
    uVar4 = *(uint *)((int)pCtx + 0x1c);
    uVar2 = *(uint *)((int)pCtx + 0x28);
    *(uint *)((int)pCtx + 8) =
         uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 | uVar5 >> 0x18;
    *(uint *)((int)pCtx + 0xc) =
         uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
    *(uint *)((int)pCtx + 0x18) =
         uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
    uVar3 = *(uint *)((int)pCtx + 0x20);
    uVar1 = *(uint *)((int)pCtx + 0x24);
    *(uint *)((int)pCtx + 0x1c) =
         uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18;
    *(uint *)((int)pCtx + 0x20) =
         uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
    uVar3 = *(uint *)((int)pCtx + 0x2c);
    uVar4 = *(uint *)((int)pCtx + 0x30);
    *(uint *)((int)pCtx + 0x24) =
         uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
    *(uint *)((int)pCtx + 0x28) =
         uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18;
    uVar1 = *(uint *)((int)pCtx + 0x3c);
    *(uint *)((int)pCtx + 0x2c) =
         uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
    uVar3 = *(uint *)((int)pCtx + 0x34);
    uVar2 = *(uint *)((int)pCtx + 0x38);
    *(uint *)((int)pCtx + 0x30) =
         uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18;
    *(uint *)((int)pCtx + 0x34) =
         uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
    uVar3 = *(uint *)((int)pCtx + 0x40);
    uVar4 = *(uint *)((int)pCtx + 0x44);
    *(uint *)((int)pCtx + 0x38) =
         uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18;
    *(uint *)((int)pCtx + 0x3c) =
         uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
    *(uint *)((int)pCtx + 0x40) =
         uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
    *(uint *)((int)pCtx + 0x44) =
         uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 | uVar4 >> 0x18;
    return 0;
  }
  return 0xf30000;
}


