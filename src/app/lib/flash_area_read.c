/*
 * Function: flash_area_read
 * Entry:    00082718
 * Prototype: int __stdcall flash_area_read(flash_area * param_1, uint32_t off, void * dst, uint32_t len)
 */


/* exclude_from_export_ai */

int flash_area_read(flash_area *param_1,uint32_t off,void *dst,uint32_t len)

{
  int iVar1;
  
  if ((-1 < (int)off) && (len + off <= param_1->fa_size)) {
                    /* WARNING: Could not recover jumptable at 0x00082738. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)**(undefined4 **)(param_1->fa_dev + 8))(param_1->fa_dev,off + param_1->fa_off)
    ;
    return iVar1;
  }
  return -0x16;
}


