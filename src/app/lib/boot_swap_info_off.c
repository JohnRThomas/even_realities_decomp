/*
 * Function: boot_swap_info_off
 * Entry:    00088514
 * Prototype: uint32_t __stdcall boot_swap_info_off(flash_area * fap)
 */


/* exclude_from_export */

uint32_t boot_swap_info_off(flash_area *fap)

{
  return (fap->fa_size - 0x18 & 0xfffffff8) - 0x10;
}


