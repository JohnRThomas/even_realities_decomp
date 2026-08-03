/*
 * Function: boot_write_trailer
 * Entry:    0008859a
 * Prototype: int __stdcall boot_write_trailer(flash_area * fap, uint32_t off, uint8_t * inbuf, uint8_t inlen)
 */


/* exclude_from_export */

int boot_write_trailer(flash_area *fap,uint32_t off,uint8_t *inbuf,uint8_t inlen)

{
  byte bVar1;
  uint32_t uVar2;
  int iVar3;
  int iVar4;
  uint n;
  uint len;
  flash_area *pfStack_28;
  uint32_t uStack_24;
  uint8_t *puStack_20;
  
  n = (uint)inlen;
  pfStack_28 = fap;
  uStack_24 = off;
  puStack_20 = inbuf;
  uVar2 = flash_area_align(fap);
  len = (n - 1) + uVar2 & -uVar2;
  if (len < 9) {
    bVar1 = flash_area_erased_val(fap);
    memcpy(&pfStack_28,inbuf,n);
    memset((void *)((int)&pfStack_28 + n),(uint)bVar1,len - n);
    iVar3 = flash_area_write(fap,off,&pfStack_28,len);
    iVar4 = 0;
    if (iVar3 != 0) {
      iVar4 = 1;
    }
  }
  else {
    iVar4 = -1;
  }
  return iVar4;
}


