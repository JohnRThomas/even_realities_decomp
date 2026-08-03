/*
 * Function: boot_write_image_ok
 * Entry:    00088608
 * Prototype: int __stdcall boot_write_image_ok(flash_area * fap)
 */


/* exclude_from_export */

int boot_write_image_ok(flash_area *fap)

{
  int iVar1;
  uint off;
  uint8_t local_c;
  undefined3 uStack_b;
  undefined4 uStack_8;
  
  off = fap->fa_size - 0x18 & 0xfffffff8;
  uStack_8 = 1;
  _local_c = CONCAT31((int3)(off >> 8),1);
  iVar1 = boot_write_trailer(fap,off,&local_c,'\x01');
  return iVar1;
}


