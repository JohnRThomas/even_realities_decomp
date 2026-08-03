/*
 * Function: flash_img_init_id
 * Entry:    000828e8
 * Prototype: int __stdcall flash_img_init_id(flash_img_context * ctx, uint8_t area_id)
 */


/* exclude_from_export_ai */

int flash_img_init_id(flash_img_context *ctx,uint8_t area_id)

{
  int iVar1;
  device *fdev;
  
  iVar1 = flash_area_open(area_id,(flash_area **)((int)&ctx[0x38].stream + 3));
  if (iVar1 == 0) {
    fdev = flash_area_get_device(*(flash_area **)((int)&ctx[0x38].stream + 3));
    iVar1 = *(int *)((int)&ctx[0x38].stream + 3);
    iVar1 = stream_flash_init((stream_flash_ctx *)((int)&ctx[0x39].flash_area + 2),fdev,
                              &ctx->buf_CONFIG_IMG_BLOCK_BUF_SIZE_,0x200,*(size_t *)(iVar1 + 4),
                              *(size_t *)(iVar1 + 8),(stream_flash_callback_t)0x0);
  }
  return iVar1;
}


