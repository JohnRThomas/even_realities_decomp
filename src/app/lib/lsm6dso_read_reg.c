/*
 * Function: lsm6dso_read_reg
 * Entry:    00083134
 * Prototype: int32_t __stdcall lsm6dso_read_reg(stmdev_ctx_t * ctx, uint8_t reg, uint8_t * data, uint16_t len)
 */


/* exclude_from_export */

int32_t lsm6dso_read_reg(stmdev_ctx_t *ctx,uint8_t reg,uint8_t *data,uint16_t len)

{
  int32_t iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00083140. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*ctx->read_reg)(ctx->handle,reg,data,len);
  return iVar1;
}


