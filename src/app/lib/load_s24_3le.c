/*
 * Function: load_s24_3le
 * Entry:    0006bfd4
 * Prototype: void __stdcall load_s24_3le(lc3_encoder * encoder, void * _pcm, int stride)
 */


/* exclude_from_export */

void load_s24_3le(lc3_encoder *encoder,void *_pcm,int stride)

{
  uint uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  float *pfVar5;
  uint in_fpscr;
  float fVar6;
  
  iVar3 = *(byte *)((int)encoder + 2) + 1;
  if (*(byte *)((int)encoder + 2) == 4) {
    iVar3 = 6;
  }
  puVar2 = (undefined2 *)(encoder[0x128] + -2);
  pfVar5 = (float *)encoder[0x129];
  puVar4 = puVar2 + ((byte)*encoder + 3) * iVar3 * 0x14;
  do {
    uVar1 = (uint)*(byte *)((int)_pcm + 1) << 0x10 | (uint)*(byte *)_pcm << 8 |
            (uint)*(byte *)((int)_pcm + 2) << 0x18;
    puVar2 = puVar2 + 1;
    *puVar2 = (short)(uVar1 >> 0x10);
    fVar6 = (float)VectorSignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
    fVar6 = scalbnf(fVar6,-0x10);
    *pfVar5 = fVar6;
    pfVar5 = pfVar5 + 1;
    _pcm = (void *)((int)_pcm + stride * 3);
  } while (puVar2 != puVar4);
  return;
}


