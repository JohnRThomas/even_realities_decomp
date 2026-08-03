/*
 * Function: flash_nrf_read
 * Entry:    000871ae
 * Prototype: int __stdcall flash_nrf_read(device * dev, off_t addr, void * data, size_t len)
 */


/* exclude_from_export */

int flash_nrf_read(device *dev,off_t addr,void *data,size_t len)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = is_regular_addr_valid(addr,len);
  if (!bVar1) {
    iVar2 = flash_nrf_read_error_outline(addr,len);
    return iVar2;
  }
  if (len != 0) {
    memcpy(data,(void *)addr,len);
  }
  return 0;
}


