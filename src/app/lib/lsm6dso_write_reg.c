/*
 * Function: $_?_lsm6dso_write_reg
 * Entry:    00087c90
 * Prototype: int __stdcall $_?_lsm6dso_write_reg(stmdev_ctx_t * ctx, uint8_t reg, uint8_t * data, uint16_t len)
 */


/* exclude_from_export */

int ____lsm6dso_write_reg(stmdev_ctx_t *ctx,uint8_t reg,uint8_t *data,uint16_t len)

{
  int iVar1;
  uint8_t local_29;
  uint8_t *local_28;
  undefined4 local_24;
  undefined1 local_20;
  uint8_t *local_1c;
  uint uStack_18;
  undefined1 local_14;
  
  uStack_18 = (uint)len;
  local_28 = &local_29;
  local_24 = 1;
  local_20 = 0;
  local_14 = 2;
  local_29 = reg;
  local_1c = data;
  iVar1 = (**(code **)(*(int *)(ctx->write_reg + 8) + 8))
                    (ctx->write_reg,&local_28,2,*(undefined2 *)&ctx->read_reg);
  return iVar1;
}


