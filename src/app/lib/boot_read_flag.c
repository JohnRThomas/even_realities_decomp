/*
 * Function: boot_read_flag
 * Entry:    00088562
 * Prototype: int __stdcall boot_read_flag(flash_area * fap, uint8_t * flag, uint32_t off)
 */


/* exclude_from_export */

int boot_read_flag(flash_area *fap,uint8_t *flag,uint32_t off)

{
  bool bVar1;
  int iVar2;
  uint8_t uVar3;
  
  iVar2 = flash_area_read(fap,off,flag,1);
  if (iVar2 < 0) {
    iVar2 = 1;
  }
  else {
    bVar1 = bootutil_buffer_is_erased(fap,flag,1);
    if (bVar1) {
      uVar3 = '\x03';
    }
    else if (*flag == '\x01') {
      uVar3 = '\x01';
    }
    else {
      uVar3 = '\x02';
    }
    iVar2 = 0;
    *flag = uVar3;
  }
  return iVar2;
}


