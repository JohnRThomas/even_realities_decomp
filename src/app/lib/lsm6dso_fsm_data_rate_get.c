/*
 * Function: lsm6dso_fsm_data_rate_get
 * Entry:    000833e4
 * Prototype: int32_t __stdcall lsm6dso_fsm_data_rate_get(stmdev_ctx_t * ctx, lsm6dso_fsm_odr_t * val)
 */


/* exclude_from_export */

int32_t lsm6dso_fsm_data_rate_get(stmdev_ctx_t *ctx,lsm6dso_fsm_odr_t *val)

{
  int32_t iVar1;
  int32_t iVar2;
  uint uVar3;
  lsm6dso_fsm_odr_t *local_14;
  
  local_14 = val;
  iVar1 = lsm6dso_mem_bank_set(ctx,2);
  if (iVar1 == 0) {
    iVar2 = lsm6dso_read_reg(ctx,0x5f,(uint8_t *)&local_14,1);
    if (iVar2 == 0) {
      uVar3 = ((uint)local_14 & 0x1f) >> 3;
      if (((uVar3 == 2) || (uVar3 == 3)) || (uVar3 == 1)) {
        *(byte *)val = (byte)((uint)((int)local_14 << 0x1b) >> 0x1e);
      }
      else {
        *(undefined1 *)val = 0;
      }
    }
    iVar1 = lsm6dso_mem_bank_set(ctx,0);
    iVar1 = iVar1 + iVar2;
  }
  return iVar1;
}


