/*
 * Function: lsm6dso_sh_master_set
 * Entry:    000835e2
 * Prototype: int32_t __stdcall lsm6dso_sh_master_set(stmdev_ctx_t * ctx, uint8_t val)
 */


/* exclude_from_export */

int32_t lsm6dso_sh_master_set(stmdev_ctx_t *ctx,uint8_t val)

{
  int32_t iVar1;
  int32_t iVar2;
  int32_t iVar3;
  uint local_1c [2];
  
  local_1c[0] = (uint)val;
  iVar1 = lsm6dso_mem_bank_set(ctx,1);
  if (iVar1 == 0) {
    iVar2 = lsm6dso_read_reg(ctx,'\x14',(uint8_t *)local_1c,1);
    local_1c[0] = CONCAT31(local_1c[0]._1_3_,(byte)local_1c[0] & 0xfb | (byte)((val & 1) << 2));
    iVar3 = lsm6dso_write_reg(ctx,'\x14',(uint8_t *)local_1c,1);
    iVar1 = lsm6dso_mem_bank_set(ctx,0);
    iVar1 = iVar2 + iVar3 + iVar1;
  }
  return iVar1;
}


