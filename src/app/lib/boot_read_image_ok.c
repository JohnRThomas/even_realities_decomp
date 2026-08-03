/*
 * Function: boot_read_image_ok
 * Entry:    00088616
 * Prototype: int __stdcall boot_read_image_ok(flash_area * fap, uint8_t * image_ok)
 */


/* exclude_from_export */

int boot_read_image_ok(flash_area *fap,uint8_t *image_ok)

{
  int iVar1;
  
  iVar1 = boot_read_flag(fap,image_ok,fap->fa_size - 0x18 & 0xfffffff8);
  return iVar1;
}


