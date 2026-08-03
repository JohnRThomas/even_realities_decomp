/*
 * Function: load_s24
 * Entry:    0006c038
 * Prototype: void __stdcall load_s24(lc3_encoder * encoder, void * _pcm, int stride)
 */


/* exclude_from_export */

void load_s24(lc3_encoder *encoder,void *_pcm,int stride)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  float *pfVar5;
  uint in_fpscr;
  float fVar6;
  
  iVar1 = 0;
  iVar3 = *(byte *)((int)encoder + 2) + 1;
  if (*(byte *)((int)encoder + 2) == 4) {
    iVar3 = 6;
  }
  puVar2 = (undefined2 *)(encoder[0x128] + -2);
  pfVar5 = (float *)encoder[0x129];
  puVar4 = puVar2 + ((byte)*encoder + 3) * iVar3 * 0x14;
  do {
    puVar2 = puVar2 + 1;
    *puVar2 = (short)((uint)*(undefined4 *)((int)_pcm + iVar1) >> 8);
    fVar6 = (float)VectorSignedToFloat(*(undefined4 *)((int)_pcm + iVar1),
                                       (byte)(in_fpscr >> 0x16) & 3);
    fVar6 = scalbnf(fVar6,-8);
    *pfVar5 = fVar6;
    pfVar5 = pfVar5 + 1;
    iVar1 = iVar1 + stride * 4;
  } while (puVar2 != puVar4);
  return;
}


