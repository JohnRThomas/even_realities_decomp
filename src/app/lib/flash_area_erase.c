/*
 * Function: flash_area_erase
 * Entry:    0008276c
 * Prototype: int __stdcall flash_area_erase(flash_area * fa, off_t off, size_t len)
 */


/* exclude_from_export_ai */

int flash_area_erase(flash_area *fa,off_t off,size_t len)

{
  int iVar1;
  
  if ((-1 < off) && (len + off <= fa->fa_size)) {
                    /* WARNING: Could not recover jumptable at 0x0008278c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)(fa->fa_dev + 8) + 8))(fa->fa_dev,off + fa->fa_off);
    return iVar1;
  }
  return -0x16;
}


