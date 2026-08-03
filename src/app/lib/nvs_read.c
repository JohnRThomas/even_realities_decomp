/*
 * Function: nvs_read
 * Entry:    00082174
 * Prototype: ssize_t __stdcall nvs_read(nvs_fs * fs, uint16_t id, void * data, size_t len)
 */


/* exclude_from_export */

ssize_t nvs_read(nvs_fs *fs,uint16_t id,void *data,size_t len)

{
  ssize_t sVar1;
  
  sVar1 = nvs_read_hist(fs,id,data,len,0);
  return sVar1;
}


