/*
 * Function: mbedtls_md5
 * Entry:    000810be
 * Prototype: int __stdcall mbedtls_md5(uchar * input, size_t ilen, uchar * output)
 */


/* exclude_from_export_ai */

int mbedtls_md5(uchar *input,size_t ilen,uchar *output)

{
  mbedtls_md5_context *ctx;
  mbedtls_md5_context mVar1;
  uchar *input_00;
  mbedtls_md5_context mVar2;
  size_t ilen_00;
  mbedtls_md5_context *pmVar3;
  mbedtls_md5_context local_78 [4];
  mbedtls_md5_context amStack_68 [22];
  
  pmVar3 = local_78;
  mbedtls_md5_starts(amStack_68);
  mbedtls_md5_update(ctx,input_00,ilen_00);
  mbedtls_md5_finish(amStack_68,(uchar *)local_78);
  do {
    mVar1 = *pmVar3;
    mVar2 = pmVar3[1];
    pmVar3 = pmVar3 + 2;
    *(mbedtls_md5_context *)output = mVar1;
    *(mbedtls_md5_context *)((int)output + 4) = mVar2;
    output = (uchar *)((int)output + 8);
  } while (pmVar3 != amStack_68);
  return 0;
}


