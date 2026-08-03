/*
 * Function: flash_sync
 * Entry:    0005144c
 * Prototype: int __stdcall flash_sync(stream_flash_ctx * ctx)
 */


/* exclude_from_export_ai */

int flash_sync(stream_flash_ctx *ctx)

{
  log_msg_desc desc;
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  size_t n;
  uint uVar4;
  int iVar5;
  dword in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  void *in_stack_ffffffd0;
  undefined4 local_28;
  char *local_24;
  int iStack_20;
  int local_1c;
  
  if (ctx->buf_bytes == 0) {
    return 0;
  }
  iVar5 = ctx->offset + ctx->bytes_written;
  iVar1 = stream_flash_erase_page(ctx,(ctx->buf_bytes - 1) + iVar5);
  if (iVar1 < 0) {
    local_24 = "stream_flash_erase_page err %d offset=0x%08zx";
  }
  else {
    sVar2 = flash_get_write_block_size((device *)ctx->fdev);
    iVar1 = ctx->buf_bytes - sVar2 * (ctx->buf_bytes / sVar2);
    n = 0;
    if (iVar1 != 0) {
      n = sVar2 - iVar1;
      iVar1 = (**(code **)(*(int *)(ctx->fdev + 8) + 0xc))();
      memset(ctx->buf + ctx->buf_bytes,(uint)*(byte *)(iVar1 + 4),n);
    }
    iVar1 = (**(code **)(*(int *)(ctx->fdev + 8) + 4))(ctx->fdev,iVar5,ctx->buf,ctx->buf_bytes + n);
    if (iVar1 == 0) {
      uVar4 = 0;
      if (ctx->callback == (undefined *)0x0) {
LAB_000514de:
        ctx->bytes_written = ctx->bytes_written + ctx->buf_bytes;
        ctx->buf_bytes = 0;
        return 0;
      }
      for (; uVar4 < ctx->buf_bytes; uVar4 = uVar4 + 1) {
        ctx->buf[uVar4] = ~ctx->buf[uVar4];
      }
      iVar1 = (*(code *)**(undefined4 **)(ctx->fdev + 8))(ctx->fdev,iVar5);
      if (iVar1 == 0) {
        iVar1 = (*(code *)ctx->callback)(ctx->buf,ctx->buf_bytes,iVar5);
        if (iVar1 == 0) goto LAB_000514de;
        local_24 = "callback failed: %d";
      }
      else {
        local_24 = "flash read failed: %d";
      }
      local_28 = 3;
      uVar3 = 0x1840;
      goto LAB_00051484;
    }
    local_24 = "flash_write error %d offset=0x%08zx";
  }
  local_28 = 4;
  uVar3 = 0x2040;
  local_1c = iVar5;
LAB_00051484:
  desc.level = (dword)&local_28;
  desc.domain = uVar3;
  desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
  desc.data_len = in_stack_ffffffc8;
  iStack_20 = iVar1;
  z_impl_z_log_msg_static_create
            (&PTR_s_STREAM_FLASH_0008b888,desc,in_stack_ffffffcc,in_stack_ffffffd0);
  return iVar1;
}


