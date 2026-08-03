/*
 * Function: nvs_delete
 * Entry:    0008216c
 * Prototype: int __stdcall nvs_delete(nvs_fs * fs, uint16_t id)
 */


/* exclude_from_export_ai */

int nvs_delete(nvs_fs *fs,uint16_t id)

{
  ssize_t sVar1;
  
  sVar1 = nvs_write(fs,id,(void *)0x0,0);
  return sVar1;
}


