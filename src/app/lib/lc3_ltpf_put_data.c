/*
 * Function: lc3_ltpf_put_data
 * Entry:    0006e620
 * Prototype: void __stdcall lc3_ltpf_put_data(lc3_bits_t * bits, lc3_ltpf_data_t * data)
 */


/* exclude_from_export_ai */

void lc3_ltpf_put_data(lc3_bits_t *bits,lc3_ltpf_data_t *data)

{
  byte bVar1;
  lc3_bits_t lVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = bits[8];
  uVar4 = uVar3 + 1;
  bVar1 = data->opaque[0];
  if ((int)uVar4 < 0x21) {
    bits[8] = uVar4;
    bits[7] = bits[7] | (uint)bVar1 << (uVar3 & 0xff);
    lVar2 = uVar3 + 10;
    uVar3 = *(uint *)data[1].opaque;
  }
  else {
    lc3_put_bits_generic(bits,(uint)bVar1,1);
    uVar4 = bits[8];
    uVar3 = *(uint *)data[1].opaque;
    lVar2 = uVar4 + 9;
  }
  if ((int)lVar2 < 0x21) {
    bits[7] = bits[7] | uVar3 << (uVar4 & 0xff);
    bits[8] = lVar2;
    return;
  }
  lc3_put_bits_generic(bits,uVar3,9);
  return;
}


