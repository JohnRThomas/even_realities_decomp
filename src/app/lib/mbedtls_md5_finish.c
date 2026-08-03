/*
 * Function: mbedtls_md5_finish
 * Entry:    0004d194
 * Prototype: int __stdcall mbedtls_md5_finish(mbedtls_md5_context * ctx, uchar * output)
 */


/* exclude_from_export_ai */

int mbedtls_md5_finish(mbedtls_md5_context *ctx,uchar *output)

{
  int iVar1;
  uint uVar2;
  size_t ilen;
  mbedtls_md5_context *pmStack_18;
  uchar *puStack_14;
  
  uVar2 = (*ctx & 0x1ff) >> 3;
  if (uVar2 < 0x38) {
    ilen = 0x38 - uVar2;
  }
  else {
    ilen = 0x78 - uVar2;
  }
  pmStack_18 = ctx;
  puStack_14 = output;
  FUN_00080fea((undefined1 *)&pmStack_18,(int)ctx,8);
  mbedtls_md5_update(ctx,&DAT_20003699,ilen);
  mbedtls_md5_update(ctx,(uchar *)&pmStack_18,8);
  iVar1 = FUN_00080fea(output,(int)(ctx + 2),0x10);
  return iVar1;
}


