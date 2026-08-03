/*
 * Function: region_allocate_and_init
 * Entry:    00083f50
 * Prototype: int __stdcall region_allocate_and_init(uint8_t index, arm_mpu_region * region_conf)
 */


/* exclude_from_export */

int region_allocate_and_init(uint8_t index,arm_mpu_region *region_conf)

{
  uint index_00;
  int iVar1;
  int extraout_r0;
  uint local_20 [2];
  byte local_18;
  uint local_14;
  
  index_00 = (uint)index;
  local_20[0] = *region_conf;
  local_18 = (byte)(short)region_conf[2] & 0x1f | (byte)(*(short *)((int)region_conf + 10) << 5);
  local_14 = (local_20[0] & 0xffffffe0) + region_conf[1] + -1 & 0xffffffe0;
  if (7 < index_00) {
    iVar1 = region_allocate_and_init_error(index_00);
    return iVar1;
  }
  region_init(index_00,(arm_mpu_region *)local_20);
  return extraout_r0;
}


