/*
 * Function: flash_area_align
 * Entry:    00082798
 * Prototype: uint32_t __stdcall flash_area_align(flash_area * param_1)
 */


/* exclude_from_export */

uint32_t flash_area_align(flash_area *param_1)

{
  uint32_t *puVar1;
  
  puVar1 = (uint32_t *)(**(code **)(*(int *)(param_1->fa_dev + 8) + 0xc))();
  return *puVar1;
}


