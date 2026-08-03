/*
 * Function: tc_sha256_update
 * Entry:    00083ab8
 * Prototype: int __stdcall tc_sha256_update(TCSha256State_t s, uint8_t * data, size_t datalen)
 */


/* exclude_from_export_ai */

int tc_sha256_update(TCSha256State_t s,uint8_t *data,size_t datalen)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint8_t *puVar4;
  uint8_t *puVar5;
  TCSha256State_t puVar6;
  
  iVar1 = 0;
  if (s != (TCSha256State_t)0x0) {
    if (data == (uint8_t *)0x0) {
      iVar1 = 0;
    }
    else {
      if (datalen != 0) {
        puVar6 = s + 0x28;
        puVar4 = data;
        do {
          uVar3 = *(uint *)((int)s + 0x68);
          uVar2 = uVar3 + 1;
          *(uint *)((int)s + 0x68) = uVar2;
          puVar5 = puVar4 + 1;
          *(uint8_t *)((int)s + uVar3 + 0x28) = *puVar4;
          if (0x3f < uVar2) {
            s = (TCSha256State_t)sha256_compress((uint *)s,(int)puVar6);
            uVar2 = *(uint *)((int)s + 0x20);
            *(uint *)((int)s + 0x20) = uVar2 + 0x200;
            *(uint *)((int)s + 0x24) = *(uint *)((int)s + 0x24) + (uint)(0xfffffdff < uVar2);
            *(uint *)((int)s + 0x68) = 0;
          }
          puVar4 = puVar5;
        } while (data + datalen != puVar5);
      }
      iVar1 = 1;
    }
  }
  return iVar1;
}


