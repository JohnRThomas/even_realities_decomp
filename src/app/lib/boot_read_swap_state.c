/*
 * Function: boot_read_swap_state
 * Entry:    000672e4
 * Prototype: int __stdcall boot_read_swap_state(flash_area * fap, boot_swap_state * state)
 */


/* exclude_from_export */

int boot_read_swap_state(flash_area *fap,boot_swap_state *state)

{
  bool bVar1;
  int iVar2;
  uint32_t off;
  undefined1 uVar3;
  byte local_21;
  undefined1 auStack_20 [20];
  
  iVar2 = flash_area_read(fap,fap->fa_size - 0x10,auStack_20,0x10);
  if (-1 < iVar2) {
    bVar1 = bootutil_buffer_is_erased(fap,auStack_20,0x10);
    if (bVar1) {
      uVar3 = 3;
    }
    else {
      iVar2 = memcmp(auStack_20,&DAT_0009ce24,0x10);
      if (iVar2 == 0) {
        uVar3 = 1;
      }
      else {
        uVar3 = 2;
      }
    }
    *(undefined1 *)state = uVar3;
    off = boot_swap_info_off(fap);
    iVar2 = flash_area_read(fap,off,&local_21,1);
    if (-1 < iVar2) {
      *(byte *)((int)state + 1) = local_21 & 0xf;
      *(byte *)(state + 1) = local_21 >> 4;
      bVar1 = bootutil_buffer_is_erased(fap,&local_21,1);
      if ((bVar1) || (4 < *(byte *)((int)state + 1))) {
        *(undefined1 *)((int)state + 1) = 1;
        *(undefined1 *)(state + 1) = 0;
      }
      iVar2 = boot_read_flag(fap,(uint8_t *)((int)state + 2),(fap->fa_size - 0x18 & 0xfffffff8) - 8)
      ;
      if (iVar2 == 0) {
        iVar2 = boot_read_image_ok(fap,(uint8_t *)((int)state + 3));
        return iVar2;
      }
    }
  }
  return 1;
}


