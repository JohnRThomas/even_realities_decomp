/*
 * Function: stream_flash_buffered_write
 * Entry:    00082820
 * Prototype: int __stdcall stream_flash_buffered_write(stream_flash_ctx * ctx, uint8_t * data, size_t len, bool flush)
 */


/* exclude_from_export_ai */

int stream_flash_buffered_write(stream_flash_ctx *ctx,uint8_t *data,size_t len,bool flush)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint n;
  uint n_00;
  
  if (ctx == (stream_flash_ctx *)0x0) {
    iVar2 = -0xe;
  }
  else if (ctx->available < ctx->bytes_written + ctx->buf_bytes + len) {
    iVar2 = -0xc;
  }
  else {
    uVar3 = 0;
    while( true ) {
      uVar1 = ctx->buf_bytes;
      n_00 = len - uVar3;
      n = ctx->buf_len - uVar1;
      if (n_00 < n) break;
      memcpy(ctx->buf + uVar1,data + uVar3,n);
      ctx->buf_bytes = ctx->buf_len;
      iVar2 = flash_sync(ctx);
      if (iVar2 != 0) {
        return iVar2;
      }
      uVar3 = uVar3 + n;
    }
    if (uVar3 < len) {
      memcpy(ctx->buf + uVar1,data + uVar3,n_00);
      ctx->buf_bytes = ctx->buf_bytes + n_00;
    }
    if (flush) {
      iVar2 = 0;
      if (ctx->buf_bytes != 0) {
        iVar2 = flash_sync(ctx);
        return iVar2;
      }
    }
    else {
      iVar2 = 0;
    }
  }
  return iVar2;
}


