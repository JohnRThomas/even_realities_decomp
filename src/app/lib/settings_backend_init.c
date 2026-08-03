/*
 * Function: settings_backend_init
 * Entry:    00051adc
 * Prototype: int __stdcall settings_backend_init(void)
 */


/* exclude_from_export */

int settings_backend_init(void)

{
  flash_area *in_r0;
  int iVar1;
  uint uVar2;
  uint in_r3;
  uint uVar3;
  flash_area *local_20;
  uint32_t local_1c;
  flash_sector fStack_18;
  uint local_14;
  
  local_1c = 1;
  local_20 = in_r0;
  local_14 = in_r3;
  iVar1 = flash_area_open('\t',&local_20);
  if ((iVar1 == 0) &&
     ((iVar1 = flash_area_get_sectors(9,&local_1c,&fStack_18), iVar1 == 0 || (iVar1 == -0xc)))) {
    if (local_14 < 0x10000) {
      uVar3 = 0;
      uVar2 = 0;
      do {
        uVar2 = uVar2 + local_14;
        if (local_20->fa_size < uVar2) {
          uVar3 = uVar3 & 0xffff;
          break;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 != 8);
      DAT_2000ab08 = (undefined2)local_14;
      DAT_2000ab0a = (undefined2)uVar3;
      DAT_2000aafc = local_20->fa_off;
      DAT_2000ab30 = local_20->fa_dev;
      iVar1 = settings_nvs_backend_init((settings_nvs *)&DAT_2000aaf4);
      if (iVar1 == 0) {
        DAT_2000aaf8 = &DAT_2000281c;
        settings_nvs_src((settings_nvs *)&DAT_2000aaf4);
        DAT_2000aaf8 = &DAT_2000281c;
        settings_nvs_dst((settings_nvs *)&DAT_2000aaf4);
      }
    }
    else {
      iVar1 = -0x21;
    }
  }
  return iVar1;
}


