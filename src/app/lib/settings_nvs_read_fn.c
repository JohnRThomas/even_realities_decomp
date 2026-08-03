/*
 * Function: settings_nvs_read_fn
 * Entry:    000829a8
 * Prototype: ssize_t __stdcall settings_nvs_read_fn(void * back_end, void * data, size_t len)
 */


/* exclude_from_export_ai */

ssize_t settings_nvs_read_fn(void *back_end,void *data,size_t len)

{
  size_t sVar1;
  
  sVar1 = nvs_read(*(nvs_fs **)back_end,*(uint16_t *)((int)back_end + 4),data,len);
  if ((int)len <= (int)sVar1) {
    sVar1 = len;
  }
  return sVar1;
}


