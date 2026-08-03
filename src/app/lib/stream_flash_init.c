/*
 * Function: stream_flash_init
 * Entry:    00051554
 * Prototype: int __stdcall stream_flash_init(stream_flash_ctx * ctx, device * fdev, uint8_t * buf, size_t buf_len, size_t offset, size_t size, stream_flash_callback_t cb)
 */


/* exclude_from_export */

int stream_flash_init(stream_flash_ctx *ctx,device *fdev,uint8_t *buf,size_t buf_len,size_t offset,
                     size_t size,stream_flash_callback_t cb)

{
  log_msg_desc desc;
  size_t sVar1;
  size_t sVar2;
  uint8_t *package;
  void *in_stack_ffffffc8;
  undefined4 local_28;
  char *local_24;
  
  if (((ctx != (stream_flash_ctx *)0x0) && (fdev != (device *)0x0)) && (buf != (uint8_t *)0x0)) {
    package = (uint8_t *)0x0;
    sVar2 = buf_len;
    sVar1 = flash_get_write_block_size(fdev);
    if (buf_len == (buf_len / sVar1) * sVar1) {
      flash_page_foreach(fdev,(flash_page_cb)0x82809,&stack0xffffffc0);
      if (package == (uint8_t *)0x0) {
        return -0xe;
      }
      if (((uint8_t *)(offset + size) <= package) &&
         (sVar1 = flash_get_write_block_size(fdev), offset == (offset / sVar1) * sVar1)) {
        ctx->buf = buf;
        ctx->buf_len = buf_len;
        ctx->fdev = (undefined *)fdev;
        ctx->bytes_written = 0;
        ctx->buf_bytes = 0;
        ctx->offset = offset;
        if (size == 0) {
          size = (int)package - offset;
        }
        ctx->callback = cb;
        ctx->available = size;
        ctx->last_erased_page_start_offset = -1;
        return 0;
      }
      local_24 = "Incorrect parameter";
    }
    else {
      local_24 = "Buffer size is not aligned to minimal write-block-size";
    }
    local_28 = 2;
    desc.level = (dword)&local_28;
    desc.domain = 0x1040;
    desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
    desc.data_len = sVar2;
    z_impl_z_log_msg_static_create(&PTR_s_STREAM_FLASH_0008b888,desc,package,in_stack_ffffffc8);
  }
  return -0xe;
}


