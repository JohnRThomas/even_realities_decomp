/*
 * Function: lc3_setup_bits
 * Entry:    0006b750
 * Prototype: void __stdcall lc3_setup_bits(lc3_bits_t * bits, lc3_bits_mode mode, void * buffer, int len)
 */


/* exclude_from_export_ai */

void lc3_setup_bits(lc3_bits_t *bits,lc3_bits_mode mode,void *buffer,int len)

{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  lc3_bits_t lVar5;
  
  memset(bits,0,0x38);
  pvVar2 = (void *)((int)buffer + len);
  bits[2] = 0xffffff;
  bits[3] = 0xffffffff;
  *(char *)bits = (char)mode;
  bits[8] = (uint)(mode == 0) * 0x20;
  bits[10] = (lc3_bits_t)buffer;
  bits[0xc] = (lc3_bits_t)buffer;
  bits[0xb] = (lc3_bits_t)pvVar2;
  bits[0xd] = (lc3_bits_t)pvVar2;
  if (mode == 0) {
    lVar5 = 0;
    if (buffer < pvVar2) {
      bits[0xc] = (lc3_bits_t)((int)buffer + 1);
      lVar5 = (uint)*(byte *)buffer << 0x10;
      bits[1] = lVar5;
      if ((void *)((int)buffer + 1) < pvVar2) {
        bits[0xc] = (lc3_bits_t)((int)buffer + 2);
        lVar5 = lVar5 | (uint)*(byte *)((int)buffer + 1) << 8;
        bits[1] = lVar5;
        if ((void *)((int)buffer + 2) < pvVar2) {
          bits[0xc] = (int)buffer + 3;
          lVar5 = lVar5 | *(byte *)((int)buffer + 2);
        }
      }
    }
    iVar4 = 4;
    if (len < 5) {
      iVar4 = len;
    }
    uVar1 = iVar4 * -8 + 0x20;
    bits[1] = lVar5;
    bits[8] = uVar1;
    if (iVar4 != 0) {
      bits[0xd] = (int)pvVar2 - 1;
      lVar5 = (uint)*(byte *)((int)pvVar2 - 1) << 0x18;
      if (iVar4 != 1) {
        uVar3 = (uint)*(byte *)((int)pvVar2 - 1) << 0x10;
        bits[7] = uVar3;
        bits[0xd] = (int)pvVar2 - 2;
        lVar5 = uVar3 | (uint)*(byte *)((int)pvVar2 - 2) << 0x18;
        if (iVar4 != 2) {
          bits[7] = lVar5 >> 8;
          bits[0xd] = (int)pvVar2 - 3;
          lVar5 = lVar5 >> 8 | (uint)*(byte *)((int)pvVar2 - 3) << 0x18;
          if (iVar4 != 3) {
            bits[7] = lVar5 >> 8;
            bits[0xd] = (int)pvVar2 - 4;
            lVar5 = lVar5 >> 8 | (uint)*(byte *)((int)pvVar2 - 4) << 0x18;
          }
        }
      }
      bits[7] = lVar5;
    }
    if (7 < (int)uVar1) {
      uVar3 = uVar1;
      if (0x1f < (int)uVar1) {
        uVar3 = 0x20;
      }
      bits[8] = 0;
      bits[9] = uVar3;
      bits[7] = bits[7] >> (uVar1 & 0xff);
    }
  }
  return;
}


