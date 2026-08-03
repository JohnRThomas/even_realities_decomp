/*
 * Function: lsm6dso_acceleration_raw_get
 * Entry:    0008329c
 * Prototype: int32_t __stdcall lsm6dso_acceleration_raw_get(stmdev_ctx_t * ctx, int16_t * val)
 */


/* exclude_from_export */

int32_t lsm6dso_acceleration_raw_get(stmdev_ctx_t *ctx,int16_t *val)

{
  int32_t iVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = ctx;
  local_c = val;
  iVar1 = lsm6dso_read_reg(ctx,0x28,(uint8_t *)&local_10,6);
  *val = (ushort)(byte)local_10 + (ushort)local_10._1_1_ * 0x100;
  val[1] = (ushort)local_10._2_1_ + (ushort)local_10._3_1_ * 0x100;
  val[2] = (ushort)(byte)local_c + (ushort)local_c._1_1_ * 0x100;
  return iVar1;
}


