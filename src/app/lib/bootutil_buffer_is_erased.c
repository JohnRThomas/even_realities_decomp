/*
 * Function: bootutil_buffer_is_erased
 * Entry:    0008853c
 * Prototype: bool __stdcall bootutil_buffer_is_erased(flash_area * area, void * buffer, size_t len)
 */


/* exclude_from_export */

bool bootutil_buffer_is_erased(flash_area *area,void *buffer,size_t len)

{
  uint8_t uVar1;
  bool bVar2;
  uint8_t *puVar3;
  uint8_t *puVar4;
  
  if ((buffer == (void *)0x0) || (len == 0)) {
LAB_0008855e:
    bVar2 = false;
  }
  else {
    uVar1 = flash_area_erased_val(area);
    puVar4 = buffer;
    do {
      puVar3 = puVar4 + 1;
      if (*puVar4 != uVar1) goto LAB_0008855e;
      puVar4 = puVar3;
    } while (puVar3 != (uint8_t *)(len + (int)buffer));
    bVar2 = true;
  }
  return bVar2;
}


