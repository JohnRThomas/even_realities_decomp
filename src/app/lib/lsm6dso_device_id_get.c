/*
 * Function: lsm6dso_device_id_get
 * Entry:    000832f6
 * Prototype: int32_t __stdcall lsm6dso_device_id_get(stmdev_ctx_t * ctx, uint8_t * buff)
 */


/* exclude_from_export */

int32_t lsm6dso_device_id_get(stmdev_ctx_t *ctx,uint8_t *buff)

{
  int32_t iVar1;
  
  iVar1 = lsm6dso_read_reg(ctx,'\x0f',buff,1);
  return iVar1;
}


