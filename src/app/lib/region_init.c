/*
 * Function: region_init
 * Entry:    00053e9c
 * Prototype: void __stdcall region_init(uint32_t index, arm_mpu_region * region_conf)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export */

void region_init(uint32_t index,arm_mpu_region *region_conf)

{
  _DAT_e000ed98 = index;
  _DAT_e000ed9c = *(byte *)(region_conf + 2) & 0x1f | *region_conf & 0xffffffe0U;
  _DAT_e000eda0 = region_conf[3] & 0xffffffe0U | (uint)(*(byte *)(region_conf + 2) >> 5) << 1 | 1;
  return;
}


