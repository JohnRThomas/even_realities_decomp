/*
 * Function: flash_area_open
 * Entry:    000512e8
 * Prototype: int __stdcall flash_area_open(uint8_t id, flash_area * * param_2)
 */


/* exclude_from_export_ai */

int flash_area_open(uint8_t id,flash_area **param_2)

{
  bool bVar1;
  int iVar2;
  flash_area *pfVar3;
  
  if (DAT_20002868 == (flash_area *)0x0) {
    iVar2 = -0xd;
  }
  else {
    pfVar3 = DAT_20002868;
    for (iVar2 = 0; iVar2 < 0x16; iVar2 = iVar2 + 1) {
      if (pfVar3->fa_id == id) {
        if (((device *)pfVar3->fa_dev != (device *)0x0) &&
           (bVar1 = z_device_is_ready((device *)pfVar3->fa_dev), bVar1)) {
          *param_2 = pfVar3;
          return 0;
        }
        return -0x13;
      }
      pfVar3 = (flash_area *)&pfVar3->fa_label;
    }
    iVar2 = -2;
  }
  return iVar2;
}


