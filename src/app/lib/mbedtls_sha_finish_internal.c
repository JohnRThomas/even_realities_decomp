/*
 * Function: mbedtls_sha_finish_internal
 * Entry:    0007df88
 * Prototype: int __stdcall mbedtls_sha_finish_internal(void * ctx)
 */


/* exclude_from_export */

int mbedtls_sha_finish_internal(void *ctx)

{
  drvError_t dVar1;
  size_t n;
  size_t dataInSize;
  CCBuffInfo_t apuStack_a0 [2];
  uint8_t auStack_98 [132];
  
  n = *(uint *)((int)ctx + 0x60);
  dataInSize = 0;
  if (n != 0) {
    if (0x7f < n) {
      n = 0x80;
    }
    memmove(auStack_98,(void *)((int)ctx + 100),n);
    dataInSize = *(size_t *)((int)ctx + 0x60);
  }
  *(undefined4 *)((int)ctx + 4) = 1;
  dVar1 = SetDataBuffersInfo(auStack_98,dataInSize,apuStack_a0,(uint8_t *)0x0,0,(CCBuffInfo_t *)0x0)
  ;
  if (((dVar1 == 0) && (dVar1 = ProcessHashDrv(ctx,apuStack_a0,dataInSize), dVar1 == 0)) &&
     (dVar1 = FinishHashDrv(ctx), dVar1 == 0)) {
    *(undefined4 *)((int)ctx + 0x60) = 0;
    return 0;
  }
  return 1;
}


