/*
 * Function: lsm6dso_fsm_enable_get
 * Entry:    000833bc
 * Prototype: int32_t __stdcall lsm6dso_fsm_enable_get(stmdev_ctx_t * ctx, lsm6dso_emb_fsm_enable_t * val)
 */


/* exclude_from_export */

int32_t lsm6dso_fsm_enable_get(stmdev_ctx_t *ctx,lsm6dso_emb_fsm_enable_t *val)

{
  int32_t iVar1;
  int32_t iVar2;
  int32_t iVar3;
  
  iVar1 = lsm6dso_mem_bank_set(ctx,2);
  iVar2 = lsm6dso_read_reg(ctx,0x46,val->opaque,2);
  iVar3 = lsm6dso_mem_bank_set(ctx,0);
  return iVar3 + iVar1 + iVar2;
}


