/*
 * Function: settings_nvs_backend_init
 * Entry:    00082adc
 * Prototype: int __stdcall settings_nvs_backend_init(settings_nvs * cf)
 */


/* exclude_from_export */

int settings_nvs_backend_init(settings_nvs *cf)

{
  ssize_t sVar1;
  undefined4 in_r1;
  int iVar2;
  undefined2 local_12;
  
  local_12 = (undefined2)((uint)in_r1 >> 0x10);
  iVar2 = *(int *)&cf[2].last_name_id;
  *(int *)((int)&cf[1].cache_CONFIG_SETTINGS_NVS_NAME_CACHE_SIZE_ + 2) = iVar2;
  if (iVar2 == 0) {
    iVar2 = -0x13;
  }
  else {
    iVar2 = nvs_mount((nvs_fs *)&cf->last_name_id);
    if (iVar2 == 0) {
      sVar1 = nvs_read((nvs_fs *)&cf->last_name_id,0x8000,&local_12,2);
      if (sVar1 < 0) {
        local_12 = 0x8000;
      }
      *(undefined2 *)&cf[2].cf_nvs = local_12;
    }
  }
  return iVar2;
}


