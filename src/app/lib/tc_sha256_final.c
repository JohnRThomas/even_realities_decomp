/*
 * Function: tc_sha256_final
 * Entry:    00083b04
 * Prototype: int __stdcall tc_sha256_final(uint8_t * digest, TCSha256State_t s)
 */


/* exclude_from_export_ai */

int tc_sha256_final(uint8_t *digest,TCSha256State_t s)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint8_t *puVar5;
  uint8_t *puVar6;
  TCSha256State_t puVar7;
  
  iVar3 = 0;
  if (digest != (uint8_t *)0x0) {
    if (s == (TCSha256State_t)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(s + 0x68);
      uVar2 = *(uint *)(s + 0x20);
      *(uint *)(s + 0x20) = uVar2 + iVar3 * 8;
      *(uint *)(s + 0x24) = *(int *)(s + 0x24) + (uint)CARRY4(uVar2,iVar3 * 8);
      uVar2 = iVar3 + 1;
      *(uint *)(s + 0x68) = uVar2;
      s[iVar3 + 0x28] = 0x80;
      puVar7 = s + 0x28;
      if (0x38 < uVar2) {
        memset(puVar7 + uVar2,0,0x40 - uVar2);
        sha256_compress((uint *)s,(int)puVar7);
        *(undefined4 *)(s + 0x68) = 0;
      }
      memset(puVar7 + *(int *)(s + 0x68),0,0x38 - *(int *)(s + 0x68));
      uVar2 = *(uint *)(s + 0x20);
      uVar4 = *(undefined4 *)(s + 0x24);
      *(uint *)(s + 100) =
           uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18
      ;
      s[99] = (char)uVar4;
      s[0x62] = (char)((uint)uVar4 >> 8);
      s[0x60] = (char)((uint)uVar4 >> 0x18);
      s[0x61] = (char)((uint)uVar4 >> 0x10);
      sha256_compress((uint *)s,(int)puVar7);
      puVar1 = (undefined4 *)(s + -4);
      puVar5 = digest + 4;
      do {
        puVar1 = puVar1 + 1;
        uVar4 = *puVar1;
        puVar6 = puVar5 + 4;
        puVar5[-4] = (uint8_t)((uint)uVar4 >> 0x18);
        puVar5[-3] = (uint8_t)((uint)uVar4 >> 0x10);
        puVar5[-2] = (uint8_t)((uint)uVar4 >> 8);
        puVar5[-1] = (uint8_t)uVar4;
        puVar5 = puVar6;
      } while (puVar6 != digest + 0x24);
      memset(s,0,0x70);
      iVar3 = 1;
    }
  }
  return iVar3;
}


