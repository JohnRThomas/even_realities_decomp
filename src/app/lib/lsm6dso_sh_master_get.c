/*
 * Function: lsm6dso_sh_master_get
 * Entry:    0008362a
 * Prototype: int32_t __stdcall lsm6dso_sh_master_get(stmdev_ctx_t * ctx, uint8_t * val)
 */


/* exclude_from_export */

int32_t lsm6dso_sh_master_get(stmdev_ctx_t *ctx,uint8_t *val)

{
  int32_t iVar1;
  int32_t iVar2;
  uint8_t *local_1c [2];
  
  local_1c[0] = val;
  iVar1 = lsm6dso_mem_bank_set(ctx,1);
  if (iVar1 == 0) {
    iVar1 = lsm6dso_read_reg(ctx,'\x14',(uint8_t *)local_1c,1);
    *val = (byte)((uint)((int)local_1c[0] << 0x1d) >> 0x1f);
    iVar2 = lsm6dso_mem_bank_set(ctx,0);
    iVar1 = iVar1 + iVar2;
  }
  return iVar1;
}


