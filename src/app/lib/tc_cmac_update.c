/*
 * Function: tc_cmac_update
 * Entry:    00083978
 * Prototype: int __stdcall tc_cmac_update(TCCmacState_t s, uint8_t * data, size_t dlen)
 */


/* exclude_from_export_ai */

int tc_cmac_update(TCCmacState_t s,uint8_t *data,size_t dlen)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  uint to_len;
  int iVar4;
  
  if (s != (TCCmacState_t)0x0) {
    if (dlen == 0) {
      return 1;
    }
    if (data != (uint8_t *)0x0) {
      iVar2 = *(int *)(s + 0x50);
      if (iVar2 != 0 || *(int *)(s + 0x54) != 0) {
        iVar4 = *(int *)(s + 0x44);
        *(int *)(s + 0x50) = iVar2 + -1;
        *(uint *)(s + 0x54) = *(int *)(s + 0x54) + -1 + (uint)(iVar2 != 0);
        if (iVar4 != 0) {
          to_len = 0x10 - iVar4;
          if (dlen < to_len) {
            _copy(s + iVar4 + 0x30,dlen,data,dlen);
            *(size_t *)(s + 0x44) = *(int *)(s + 0x44) + dlen;
            return 1;
          }
          _copy(s + iVar4 + 0x30,to_len,data,to_len);
          *(undefined4 *)(s + 0x44) = 0;
          dlen = (dlen - 0x10) + iVar4;
          data = data + to_len;
          pbVar3 = s + -1;
          do {
            pbVar1 = pbVar3 + 1;
            *pbVar1 = *pbVar1 ^ pbVar3[0x31];
            pbVar3 = pbVar1;
          } while (pbVar1 != s + 0xf);
          tc_aes_encrypt(s,s,*(TCAesKeySched_t *)(s + 0x48));
        }
        for (; 0x10 < dlen; dlen = dlen - 0x10) {
          pbVar3 = s + -1;
          pbVar1 = data + -1;
          do {
            pbVar3 = pbVar3 + 1;
            pbVar1 = pbVar1 + 1;
            *pbVar3 = *pbVar3 ^ *pbVar1;
          } while (pbVar3 != s + 0xf);
          tc_aes_encrypt(s,s,*(TCAesKeySched_t *)(s + 0x48));
          data = data + 0x10;
        }
        if (dlen == 0) {
          return 1;
        }
        _copy(s + 0x30,dlen,data,dlen);
        *(size_t *)(s + 0x44) = dlen;
        return 1;
      }
    }
  }
  return 0;
}


