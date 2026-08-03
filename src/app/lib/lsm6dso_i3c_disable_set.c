/*
 * Function: lsm6dso_i3c_disable_set
 * Entry:    00083332
 * Prototype: int32_t __stdcall lsm6dso_i3c_disable_set(stmdev_ctx_t * ctx, lsm6dso_i3c_disable_t val)
 */


/* exclude_from_export */

int32_t lsm6dso_i3c_disable_set(stmdev_ctx_t *ctx,lsm6dso_i3c_disable_t val)

{
  int32_t iVar1;
  int32_t iVar2;
  int iVar3;
  stmdev_ctx_t *local_18;
  lsm6dso_i3c_disable_t local_14;
  
  local_18 = ctx;
  local_14 = val;
  iVar1 = lsm6dso_read_reg(ctx,'\x18',(uint8_t *)&local_14,1);
  local_14 = CONCAT31(local_14._1_3_,(byte)local_14 & 0xfd | (byte)(((uint)val >> 7 & 1) << 1));
  iVar2 = lsm6dso_write_reg(ctx,'\x18',(uint8_t *)&local_14,1);
  iVar3 = iVar1 + iVar2;
  if (iVar3 == 0) {
    iVar1 = lsm6dso_read_reg(ctx,'b',(uint8_t *)&local_18,1);
    local_18 = (stmdev_ctx_t *)
               CONCAT31(local_18._1_3_,(byte)local_18 & 0xe7 | (byte)((val & 3U) << 3));
    iVar2 = lsm6dso_write_reg(ctx,'b',(uint8_t *)&local_18,1);
    iVar3 = iVar2 + iVar1;
  }
  return iVar3;
}


