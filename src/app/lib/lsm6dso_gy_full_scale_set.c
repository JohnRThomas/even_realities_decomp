/*
 * Function: lsm6dso_gy_full_scale_set
 * Entry:    0008317e
 * Prototype: int32_t __stdcall lsm6dso_gy_full_scale_set(stmdev_ctx_t * ctx, lsm6dso_fs_g_t val)
 */


/* exclude_from_export */

int32_t lsm6dso_gy_full_scale_set(stmdev_ctx_t *ctx,lsm6dso_fs_g_t val)

{
  int32_t iVar1;
  lsm6dso_fs_g_t local_14 [2];
  
  local_14[0] = val;
  iVar1 = lsm6dso_read_reg(ctx,0x11,(uint8_t *)local_14,1);
  if (iVar1 == 0) {
    local_14[0] = CONCAT31(local_14[0]._1_3_,(byte)local_14[0] & 0xf1 | (byte)((val & 7U) << 1));
    iVar1 = lsm6dso_write_reg(ctx,'\x11',(uint8_t *)local_14,1);
  }
  return iVar1;
}


