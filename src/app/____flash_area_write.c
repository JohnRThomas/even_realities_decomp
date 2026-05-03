/*
 * Function: $_?_flash_area_write
 * Entry:    00082742
 * Prototype: int __stdcall $_?_flash_area_write(flash_area * param_1, uint32_t off, void * src, uint32_t len)
 */


int ____flash_area_write(flash_area *param_1,uint32_t off,void *src,uint32_t len)

{
  int iVar1;
  
  if ((-1 < (int)off) && (len + off <= param_1->fa_size)) {
                    /* WARNING: Could not recover jumptable at 0x00082762. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)(param_1->fa_dev + 8) + 4))(param_1->fa_dev,off + param_1->fa_off);
    return iVar1;
  }
  return -0x16;
}


