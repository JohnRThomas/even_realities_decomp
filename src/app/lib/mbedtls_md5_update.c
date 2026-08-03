/*
 * Function: mbedtls_md5_update
 * Entry:    0008104a
 * Prototype: int __stdcall mbedtls_md5_update(mbedtls_md5_context * ctx, uchar * input, size_t ilen)
 */


/* exclude_from_export_ai */

int mbedtls_md5_update(mbedtls_md5_context *ctx,uchar *input,size_t ilen)

{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  mbedtls_md5_context mVar5;
  uint n;
  
  uVar4 = *ctx;
  uVar3 = ilen * 8;
  uVar1 = (uVar4 & 0x1ff) >> 3;
  mVar5 = uVar4 + uVar3;
  *ctx = mVar5;
  if (CARRY4(uVar4,uVar3)) {
    mVar5 = ctx[1];
  }
  n = 0x40 - uVar1;
  if (CARRY4(uVar4,uVar3)) {
    ctx[1] = mVar5 + 1;
  }
  ctx[1] = ctx[1] + (ilen >> 0x1d);
  if (ilen < n) {
    n = 0;
  }
  else {
    memcpy((void *)(uVar1 + 0x18 + (int)ctx),input,n);
    mbedtls_internal_md5_process(ctx + 2,(uchar *)(ctx + 6));
    while( true ) {
      if (ilen < n + 0x40) break;
      mbedtls_internal_md5_process(ctx + 2,input + n);
      n = n + 0x40;
    }
    uVar1 = 0;
  }
  pvVar2 = memcpy((void *)(uVar1 + 0x18 + (int)ctx),input + n,ilen - n);
  return (int)pvVar2;
}


