/*
 * Function: tc_cmac_final
 * Entry:    00083a4c
 * Prototype: int __stdcall tc_cmac_final(uint8_t * tag, TCCmacState_t s)
 */


/* exclude_from_export_ai */

int tc_cmac_final(uint8_t *tag,TCCmacState_t s)

{
  byte *pbVar1;
  TCCmacState_t puVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  
  iVar4 = 0;
  if (tag != (uint8_t *)0x0) {
    if (s == (TCCmacState_t)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(s + 0x44);
      if (iVar4 == 0x10) {
        puVar2 = s + 0x10;
      }
      else {
        memset(s + iVar4 + 0x30,0,0x10 - iVar4);
        puVar2 = s + 0x20;
        s[*(int *)(s + 0x44) + 0x30] = 0x80;
      }
      pbVar3 = puVar2 + -1;
      pbVar5 = s + -1;
      do {
        pbVar1 = pbVar5 + 1;
        pbVar3 = pbVar3 + 1;
        *pbVar1 = *pbVar1 ^ pbVar5[0x31] ^ *pbVar3;
        pbVar5 = pbVar1;
      } while (s + 0xf != pbVar1);
      tc_aes_encrypt(tag,s,*(TCAesKeySched_t *)(s + 0x48));
      tc_cmac_erase(s);
      iVar4 = 1;
    }
  }
  return iVar4;
}


