/*
 * Function: aw9320x_read_chipid
 * Entry:    00031990
 * Prototype: int32_t __stdcall aw9320x_read_chipid(void)
 */


/* exclude_from_export */

int32_t aw9320x_read_chipid(void)

{
  int8_t iVar1;
  int iVar2;
  uint32_t local_c [2];
  
  local_c[0] = 0;
  iVar1 = aw9320x_i2c_read(0xff00,local_c);
  if ((iVar1 < '\0') || (4 < local_c[0] + 0xdfddcdfd)) {
    iVar2 = -1;
  }
  else {
    iVar2 = (0x15U >> (local_c[0] + 0xdfddcdfd & 0xff) & 1) - 1;
  }
  return iVar2;
}


