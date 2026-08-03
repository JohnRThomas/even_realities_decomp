/*
 * Function: lsm6dso_mem_bank_set
 * Entry:    000832d8
 * Prototype: int32_t __stdcall lsm6dso_mem_bank_set(stmdev_ctx_t * ctx, lsm6dso_reg_access_t val)
 */


/* exclude_from_export */

int32_t lsm6dso_mem_bank_set(stmdev_ctx_t *ctx,lsm6dso_reg_access_t val)

{
  int32_t iVar1;
  uint8_t local_c;
  undefined3 uStack_b;
  
  _local_c = CONCAT31((int3)((uint)val >> 8),(char)((val & 3U) << 6));
  iVar1 = lsm6dso_write_reg(ctx,'\x01',&local_c,1);
  return iVar1;
}


