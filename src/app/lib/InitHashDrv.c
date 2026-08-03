/*
 * Function: InitHashDrv
 * Entry:    0007e43c
 * Prototype: drvError_t __stdcall InitHashDrv(void * pCtx)
 */


/* exclude_from_export_ai */

drvError_t InitHashDrv(void *pCtx)

{
  int iVar1;
  
  if (pCtx == (void *)0x0) {
    return 0xf30000;
  }
  iVar1 = *(int *)pCtx;
  if (iVar1 == 1) {
    memmove((void *)((int)pCtx + 8),&DAT_0009c448,0x20);
  }
  else if (iVar1 == 2) {
    memmove((void *)((int)pCtx + 8),&DAT_0009c468,0x20);
  }
  else {
    if (iVar1 != 0) {
      return 0xf30001;
    }
    memmove((void *)((int)pCtx + 8),&DAT_0009c488,0x14);
  }
  return 0;
}


