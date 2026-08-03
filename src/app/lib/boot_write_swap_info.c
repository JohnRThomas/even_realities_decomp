/*
 * Function: boot_write_swap_info
 * Entry:    00067390
 * Prototype: int __stdcall boot_write_swap_info(flash_area * fap, uint8_t swap_type, uint8_t image_num)
 */


/* exclude_from_export */

int boot_write_swap_info(flash_area *fap,uint8_t swap_type,uint8_t image_num)

{
  flash_area *extraout_r0;
  flash_area *fap_00;
  uint32_t off;
  int iVar1;
  uint uVar2;
  uint extraout_r1;
  uint uVar3;
  uint extraout_r2;
  char *failedexpr;
  undefined4 uStack_c;
  
  uVar3 = (uint)image_num;
  uVar2 = (uint)swap_type;
  fap_00 = fap;
  uStack_c = uVar2;
  if (uVar3 < 0xf) goto LAB_000673a6;
  failedexpr = "(image_num) < 0xF";
  while( true ) {
    __assert_func("WEST_TOPDIR/bootloader/mcuboot/boot/bootutil/src/bootutil_public.c",386,
                  "boot_write_swap_info",failedexpr);
    fap_00 = extraout_r0;
    uVar2 = extraout_r1;
    uVar3 = extraout_r2;
LAB_000673a6:
    if (uVar2 < 0xf) break;
    failedexpr = "(swap_type) < 0xF";
  }
  uStack_c = CONCAT13((byte)uVar2 | (byte)(uVar3 << 4),(undefined3)uStack_c);
  off = boot_swap_info_off(fap_00);
  iVar1 = boot_write_trailer(fap,off,(uint8_t *)((int)&uStack_c + 3),'\x01');
  return iVar1;
}


