/*
 * Function: flash_area_erased_val
 * Entry:    000827aa
 * Prototype: uint8_t __stdcall flash_area_erased_val(flash_area * param_1)
 */


/* exclude_from_export_ai */

uint8_t flash_area_erased_val(flash_area *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(param_1->fa_dev + 8) + 0xc))();
  return *(uint8_t *)(iVar1 + 4);
}


