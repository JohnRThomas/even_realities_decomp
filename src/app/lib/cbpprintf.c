/*
 * Function: cbpprintf
 * Entry:    00081336
 * Prototype: int __stdcall cbpprintf(cbprintf_cb out, void * ctx, void * packaged)
 */


/* exclude_from_export */

int cbpprintf(cbprintf_cb out,void *ctx,void *packaged)

{
  byte bVar1;
  int iVar2;
  size_t sVar3;
  byte *in_r3;
  byte *pbVar4;
  byte *s;
  uint uVar5;
  
  if (in_r3 != (byte *)0x0) {
    bVar1 = in_r3[1];
    pbVar4 = in_r3 + (uint)*in_r3 * 4 + (uint)in_r3[3] * 2 + (uint)in_r3[2];
    for (uVar5 = 0; uVar5 < bVar1; uVar5 = uVar5 + 1) {
      s = pbVar4 + 1;
      *(byte **)(in_r3 + (uint)*pbVar4 * 4) = s;
      sVar3 = strlen((char *)s);
      pbVar4 = s + sVar3 + 1;
    }
                    /* WARNING: Could not recover jumptable at 0x00081376. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*ctx)(out,packaged,*(undefined4 *)(in_r3 + 4),in_r3 + 8);
    return iVar2;
  }
  return -0x16;
}


