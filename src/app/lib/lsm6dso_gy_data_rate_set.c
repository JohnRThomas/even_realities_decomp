/*
 * Function: lsm6dso_gy_data_rate_set
 * Entry:    00083506
 * Prototype: int32_t __stdcall lsm6dso_gy_data_rate_set(stmdev_ctx_t * ctx, lsm6dso_odr_g_t val)
 */


/* exclude_from_export */

int32_t lsm6dso_gy_data_rate_set(stmdev_ctx_t *ctx,lsm6dso_odr_g_t val)

{
  int32_t iVar1;
  int32_t iVar2;
  uint uVar3;
  undefined1 local_18 [4];
  lsm6dso_emb_fsm_enable_t local_14;
  
  local_18 = (undefined1  [4])ctx;
  local_14.opaque = (byte  [4])val;
  iVar1 = lsm6dso_fsm_enable_get(ctx,&local_14);
  if (iVar1 == 0) {
    uVar3 = (uint)local_14.opaque[1];
    if ((int)(((uint)((int)local_14.opaque << 0x1f | (int)local_14.opaque << 0x1e |
                      (int)local_14.opaque << 0x1d | (int)local_14.opaque << 0x1c |
                      (int)local_14.opaque << 0x1b | (int)local_14.opaque << 0x1a |
                     (int)local_14.opaque << 0x19) >> 0x1f | (uint)local_14.opaque >> 7 & 1 |
               uVar3 & 1 | (uVar3 & 3) >> 1 | (uVar3 & 7) >> 2 | (uVar3 & 0xf) >> 3 |
               (uVar3 & 0x1f) >> 4 | (uVar3 & 0x3f) >> 5 | (uVar3 & 0x7f) >> 6 |
              (uint)(local_14.opaque[1] >> 7)) << 0x1f) < 0) {
      iVar1 = lsm6dso_fsm_data_rate_get(ctx,(lsm6dso_fsm_odr_t *)(local_18 + 3));
      if (iVar1 != 0) {
        return iVar1;
      }
      switch((uint)local_18 >> 0x18) {
      case 0:
        if (val == 0) {
          val = 1;
        }
        break;
      case 1:
        if ((uint)val < 2) {
          val = 2;
        }
        break;
      case 2:
        if ((uint)val < 3) {
          val = 3;
        }
        break;
      case 3:
        if ((uint)val < 4) {
          val = 4;
        }
      }
    }
    iVar2 = lsm6dso_read_reg(ctx,'\x11',local_18,1);
    local_18[0] = local_18[0] & 0xf | (byte)((val & 0xfU) << 4);
    iVar1 = lsm6dso_write_reg(ctx,'\x11',local_18,1);
    iVar1 = iVar1 + iVar2;
  }
  return iVar1;
}


