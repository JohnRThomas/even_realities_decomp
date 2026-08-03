/*
 * Function: lsm6dso_block_data_update_set
 * Entry:    000831ac
 * Prototype: int32_t __stdcall lsm6dso_block_data_update_set(stmdev_ctx_t * ctx, uint8_t val)
 */


/* exclude_from_export */

int32_t lsm6dso_block_data_update_set(stmdev_ctx_t *ctx,uint8_t val)

{
  int32_t iVar1;
  uint local_14 [2];
  
  local_14[0] = (uint)val;
  iVar1 = lsm6dso_read_reg(ctx,0x12,(uint8_t *)local_14,1);
  if (iVar1 == 0) {
    local_14[0] = CONCAT31(local_14[0]._1_3_,(byte)local_14[0] & 0xbf | (byte)((val & 1) << 6));
    iVar1 = lsm6dso_write_reg(ctx,'\x12',(uint8_t *)local_14,1);
  }
  return iVar1;
}


