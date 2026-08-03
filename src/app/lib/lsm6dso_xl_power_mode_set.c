/*
 * Function: lsm6dso_xl_power_mode_set
 * Entry:    000831da
 * Prototype: int32_t __stdcall lsm6dso_xl_power_mode_set(stmdev_ctx_t * ctx, lsm6dso_xl_hm_mode_t val)
 */


/* exclude_from_export */

int32_t lsm6dso_xl_power_mode_set(stmdev_ctx_t *ctx,lsm6dso_xl_hm_mode_t val)

{
  int32_t iVar1;
  stmdev_ctx_t *local_18;
  lsm6dso_xl_hm_mode_t local_14 [2];
  
  local_18 = ctx;
  local_14[0] = val;
  iVar1 = lsm6dso_read_reg(ctx,'\x14',(uint8_t *)&local_18,1);
  if (iVar1 == 0) {
    local_18 = (stmdev_ctx_t *)
               CONCAT31(local_18._1_3_,(byte)local_18 & 0x7f | (byte)(((uint)val >> 1 & 1) << 7));
    iVar1 = lsm6dso_write_reg(ctx,'\x14',(uint8_t *)&local_18,1);
    if ((iVar1 == 0) && (iVar1 = lsm6dso_read_reg(ctx,'\x15',(uint8_t *)local_14,1), iVar1 == 0)) {
      local_14[0] = CONCAT31(local_14[0]._1_3_,(byte)local_14[0] & 0xef | (byte)((val & 1U) << 4));
      iVar1 = lsm6dso_write_reg(ctx,'\x15',(uint8_t *)local_14,1);
    }
  }
  return iVar1;
}


