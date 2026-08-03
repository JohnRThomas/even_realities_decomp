/*
 * Function: load_float
 * Entry:    0006c090
 * Prototype: void __stdcall load_float(lc3_encoder * encoder, void * _pcm, int stride)
 */


/* exclude_from_export */

void load_float(lc3_encoder *encoder,void *_pcm,int stride)

{
  undefined4 uVar1;
  float *pfVar2;
  undefined2 *puVar3;
  int iVar4;
  float *pfVar5;
  float fVar6;
  
  iVar4 = *(byte *)((int)encoder + 2) + 1;
  if (*(byte *)((int)encoder + 2) == 4) {
    iVar4 = 6;
  }
  pfVar2 = (float *)encoder[0x129];
  puVar3 = (undefined2 *)(encoder[0x128] + -2);
  pfVar5 = pfVar2 + ((byte)*encoder + 3) * iVar4 * 0x14;
  do {
    fVar6 = scalbnf(*(float *)_pcm,0xf);
    *pfVar2 = fVar6;
    pfVar2 = pfVar2 + 1;
    uVar1 = SignedSaturate((int)fVar6,0xf);
    SignedDoesSaturate((int)fVar6,0xf);
    _pcm = (void *)((int)_pcm + stride * 4);
    puVar3 = puVar3 + 1;
    *puVar3 = (short)uVar1;
  } while (pfVar2 != pfVar5);
  return;
}


