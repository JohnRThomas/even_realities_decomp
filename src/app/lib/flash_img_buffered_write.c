/*
 * Function: flash_img_buffered_write
 * Entry:    000828a8
 * Prototype: int __stdcall flash_img_buffered_write(flash_img_context * ctx, uint8_t * data, size_t len, bool flush)
 */


/* exclude_from_export_ai */

int flash_img_buffered_write(flash_img_context *ctx,uint8_t *data,size_t len,bool flush)

{
  int iVar1;
  ssize_t sVar2;
  stream_flash_ctx *ctx_00;
  
  ctx_00 = (stream_flash_ctx *)((int)&ctx[0x39].flash_area + 2);
  iVar1 = stream_flash_buffered_write(ctx_00,data,len,flush);
  if (flush) {
    sVar2 = boot_get_trailer_status_offset(*(size_t *)(*(int *)((int)&ctx[0x38].stream + 3) + 8));
    iVar1 = stream_flash_erase_page
                      (ctx_00,*(int *)(*(int *)((int)&ctx[0x38].stream + 3) + 4) + sVar2);
    if (iVar1 == 0) {
      flash_area_close(*(flash_area **)((int)&ctx[0x38].stream + 3));
      *(undefined4 *)((int)&ctx[0x38].stream + 3) = 0;
    }
  }
  return iVar1;
}


