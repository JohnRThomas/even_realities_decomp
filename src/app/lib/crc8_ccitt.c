/*
 * Function: crc8_ccitt
 * Entry:    0004de34
 * Prototype: uint8_t __stdcall crc8_ccitt(uint8_t initial_value, void * buf, size_t len)
 */


/* exclude_from_export_ai */

uint8_t crc8_ccitt(uint8_t initial_value,void *buf,size_t len)

{
  byte *pbVar1;
  uint uVar2;
  
  uVar2 = (uint)initial_value;
  pbVar1 = (byte *)(len + (int)buf);
  for (; buf != pbVar1; buf = (void *)((int)buf + 1)) {
    uVar2 = (uint)(byte)(&DAT_000ee4f5)[(uVar2 ^ *(byte *)buf) >> 4] ^
            ((uVar2 ^ *(byte *)buf) & 0xf) << 4;
    uVar2 = (uint)(byte)(&DAT_000ee4f5)[uVar2 >> 4] ^ (uVar2 & 0xf) << 4;
  }
  return (uint8_t)uVar2;
}


