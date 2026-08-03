/*
 * Function: boot_set_next
 * Entry:    0006748c
 * Prototype: int __stdcall boot_set_next(flash_area * fa, bool active, bool confirm)
 */


/* exclude_from_export */

int boot_set_next(flash_area *fa,bool active,bool confirm)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint8_t swap_type;
  uint uVar4;
  uint uVar5;
  bool image_num;
  undefined4 local_20;
  uint uStack_1c;
  uint uStack_18;
  
  uStack_18 = (uint)confirm;
  uVar3 = (uint)active;
  uVar5 = uStack_18;
  if (uVar3 != 0) {
    uVar5 = uVar3;
  }
  local_20 = fa;
  uStack_1c = uVar3;
  iVar2 = boot_read_swap_state(fa,&local_20);
  if (iVar2 != 0) {
    return iVar2;
  }
  swap_type = (uint8_t)local_20;
  uVar4 = (uint)local_20 & 0xff;
  if (uVar4 == 2) {
    if (uVar3 == 0) {
      flash_area_erase(fa,0,fa->fa_size);
      return 3;
    }
  }
  else {
    if (uVar4 == 3) {
      if (uVar3 != 0) {
        return 0;
      }
      iVar2 = boot_write_magic(fa);
      if (iVar2 != 0) {
        return iVar2;
      }
      if (uVar5 == 0) {
        swap_type = '\x02';
      }
      else {
        iVar2 = boot_write_image_ok(fa);
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      bVar1 = fa->fa_id;
      image_num = false;
      if ((bVar1 != 4) && (bVar1 != 2)) {
        if (bVar1 == 1) {
          image_num = true;
        }
        else {
          image_num = bVar1 == 8;
        }
      }
      iVar2 = boot_write_swap_info(fa,swap_type,image_num);
      return iVar2;
    }
    if (uVar4 == 1) {
      if (uVar3 == 0) {
        return 0;
      }
      if (local_20._3_1_ != '\x03') {
        return 0;
      }
      iVar2 = boot_write_image_ok(fa);
      return iVar2;
    }
    __assert_func("WEST_TOPDIR/bootloader/mcuboot/boot/bootutil/src/bootutil_public.c",558,
                  "boot_set_next","0");
  }
  return 4;
}


