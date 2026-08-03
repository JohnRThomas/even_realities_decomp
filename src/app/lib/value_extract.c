/*
 * Function: value_extract
 * Entry:    000895ca
 * Prototype: bool __stdcall value_extract(size_t min_decode, size_t max_decode, size_t * num_decode, zcbor_decoder_t decoder, zcbor_state_t * state, void * result, size_t result_len)
 */


/* exclude_from_export */

bool value_extract(size_t min_decode,size_t max_decode,size_t *num_decode,zcbor_decoder_t decoder,
                  zcbor_state_t *state,void *result,size_t result_len)

{
  int iVar1;
  size_t *psVar2;
  byte *pbVar3;
  int iVar4;
  size_t *psVar5;
  undefined1 *puVar6;
  byte bVar7;
  
  if ((num_decode == (size_t *)0x0) || (max_decode == 0)) {
    iVar1 = 0xe;
LAB_000895d8:
    zcbor_error(min_decode,iVar1);
  }
  else {
    iVar1 = zcbor_assert_state((int *)min_decode,(int *)max_decode);
    if (iVar1 != 0) {
      if (*(int *)(min_decode + 8) == 0) {
        iVar1 = 3;
      }
      else {
        pbVar3 = *(byte **)min_decode;
        bVar7 = *pbVar3;
        *(byte **)(min_decode + 4) = pbVar3;
        bVar7 = bVar7 & 0x1f;
        *(byte **)min_decode = pbVar3 + 1;
        memset((void *)max_decode,0,(size_t)num_decode);
        if (bVar7 < 0x18) {
          *(byte *)max_decode = bVar7;
LAB_0008961a:
          *(int *)(min_decode + 8) = *(int *)(min_decode + 8) + -1;
          goto LAB_000895ee;
        }
        iVar4 = *(int *)min_decode;
        if ((byte)(bVar7 - 0x18) < 4) {
          psVar2 = (size_t *)(1 << (uint)(byte)(bVar7 - 0x18));
          if (num_decode < psVar2) {
            iVar1 = 5;
            *(int *)min_decode = iVar4 + -1;
          }
          else {
            if ((uint)(iVar4 + (int)psVar2) <= *(uint *)(min_decode + 0xc)) {
              puVar6 = (undefined1 *)(max_decode - 1);
              psVar5 = psVar2;
              do {
                psVar5 = (size_t *)((int)psVar5 - 1);
                puVar6 = puVar6 + 1;
                *puVar6 = *(undefined1 *)(*(int *)min_decode + (int)psVar5);
              } while (psVar5 != (size_t *)0x0);
              *(int *)min_decode = *(int *)min_decode + (int)psVar2;
              goto LAB_0008961a;
            }
            iVar1 = 8;
            *(int *)min_decode = iVar4 + -1;
          }
        }
        else {
          iVar1 = 7;
          *(int *)min_decode = iVar4 + -1;
        }
      }
      goto LAB_000895d8;
    }
  }
  iVar1 = 0;
LAB_000895ee:
  return SUB41(iVar1,0);
}


