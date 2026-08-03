/*
 * Function: lsm6dso_xl_data_rate_set
 * Entry:    0008342a
 * Prototype: int32_t __stdcall lsm6dso_xl_data_rate_set(stmdev_ctx_t * ctx, lsm6dso_odr_xl_t val)
 */


/* exclude_from_export */

int32_t lsm6dso_xl_data_rate_set(stmdev_ctx_t *ctx,lsm6dso_odr_xl_t val)

{
  int32_t iVar1;
  int32_t iVar2;
  byte abVar3 [4];
  uint uVar4;
  undefined1 local_18 [4];
  lsm6dso_emb_fsm_enable_t local_14;
  
  abVar3[1] = 0;
  abVar3[2] = 0;
  abVar3[3] = 0;
  abVar3[0] = val;
  local_18 = (undefined1  [4])ctx;
  local_14.opaque = abVar3;
  iVar1 = lsm6dso_fsm_enable_get(ctx,&local_14);
  if (iVar1 == 0) {
    uVar4 = (uint)local_14.opaque[1];
    if ((int)(((uint)((int)local_14.opaque << 0x1f | (int)local_14.opaque << 0x1e |
                      (int)local_14.opaque << 0x1d | (int)local_14.opaque << 0x1c |
                      (int)local_14.opaque << 0x1b | (int)local_14.opaque << 0x1a |
                     (int)local_14.opaque << 0x19) >> 0x1f | (uint)local_14.opaque >> 7 & 1 |
               uVar4 & 1 | (uVar4 & 3) >> 1 | (uVar4 & 7) >> 2 | (uVar4 & 0xf) >> 3 |
               (uVar4 & 0x1f) >> 4 | (uVar4 & 0x3f) >> 5 | (uVar4 & 0x7f) >> 6 |
              (uint)(local_14.opaque[1] >> 7)) << 0x1f) < 0) {
      iVar1 = lsm6dso_fsm_data_rate_get(ctx,(lsm6dso_fsm_odr_t *)(local_18 + 3));
      if (iVar1 != 0) {
        return iVar1;
      }
      switch((uint)local_18 >> 0x18) {
      case 0:
        if (abVar3 == (byte  [4])0x0) {
          abVar3[0] = 1;
          abVar3[1] = 0;
          abVar3[2] = 0;
          abVar3[3] = 0;
        }
        break;
      case 1:
        if ((uint)abVar3 < 2) {
          abVar3[0] = 2;
          abVar3[1] = 0;
          abVar3[2] = 0;
          abVar3[3] = 0;
        }
        break;
      case 2:
        if ((uint)abVar3 < 3) {
          abVar3[0] = 3;
          abVar3[1] = 0;
          abVar3[2] = 0;
          abVar3[3] = 0;
        }
        break;
      case 3:
        if ((uint)abVar3 < 4) {
          abVar3[0] = 4;
          abVar3[1] = 0;
          abVar3[2] = 0;
          abVar3[3] = 0;
        }
      }
    }
    iVar2 = lsm6dso_read_reg(ctx,'\x10',local_18,1);
    local_18[0] = local_18[0] & 0xf | (byte)(((uint)abVar3 & 0xf) << 4);
    iVar1 = lsm6dso_write_reg(ctx,'\x10',local_18,1);
    iVar1 = iVar1 + iVar2;
  }
  return iVar1;
}


