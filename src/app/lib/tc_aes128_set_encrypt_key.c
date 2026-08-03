/*
 * Function: tc_aes128_set_encrypt_key
 * Entry:    00052ce0
 * Prototype: int __stdcall tc_aes128_set_encrypt_key(TCAesKeySched_t s, uint8_t * k)
 */


/* exclude_from_export_ai */

int tc_aes128_set_encrypt_key(TCAesKeySched_t s,uint8_t *k)

{
  uint *puVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint local_44 [10];
  undefined *puStack_1c;
  
  local_44[0] = 0;
  local_44[1] = 0x1000000;
  local_44[2] = 0x2000000;
  local_44[3] = 0x4000000;
  local_44[4] = 0x8000000;
  local_44[5] = 0x10000000;
  local_44[6] = 0x20000000;
  local_44[7] = 0x40000000;
  local_44[8] = 0x80000000;
  local_44[9] = 0x1b000000;
  puStack_1c = &DAT_36000000;
  iVar2 = 0;
  if (s != (TCAesKeySched_t)0x0) {
    if (k == (uint8_t *)0x0) {
      iVar2 = 0;
    }
    else {
      pbVar3 = k;
      puVar1 = (uint *)(s + -4);
      do {
        pbVar4 = pbVar3 + 4;
        puVar1 = puVar1 + 1;
        *puVar1 = (uint)pbVar3[1] << 0x10 | (uint)*pbVar3 << 0x18 | (uint)pbVar3[3] |
                  (uint)pbVar3[2] << 8;
        pbVar3 = pbVar4;
      } while (k + 0x10 != pbVar4);
      uVar5 = 4;
      puVar1 = (uint *)(s + -4);
      do {
        uVar6 = puVar1[4];
        if ((uVar5 & 3) == 0) {
          uVar6 = *(uint *)((int)local_44 + (uVar5 & 0xfffffffc)) ^
                  ((uint)(byte)(&DAT_000ef97e)[uVar6 >> 0x18] |
                   (uint)(byte)(&DAT_000ef97e)[(uVar6 & 0xffffff) >> 0x10] << 0x18 |
                   (uint)(byte)(&DAT_000ef97e)[(uVar6 & 0xffff) >> 8] << 0x10 |
                  (uint)(byte)(&DAT_000ef97e)[uVar6 & 0xff] << 8);
        }
        uVar5 = uVar5 + 1;
        puVar1[5] = uVar6 ^ puVar1[1];
        puVar1 = puVar1 + 1;
      } while (uVar5 != 0x2c);
      iVar2 = 1;
    }
  }
  return iVar2;
}


