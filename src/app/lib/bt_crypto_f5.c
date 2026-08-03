/*
 * Function: bt_crypto_f5
 * Entry:    00061f88
 * Prototype: int __stdcall bt_crypto_f5(uint8_t * w, uint8_t * n1, uint8_t * n2, bt_addr_le_t * a1, bt_addr_le_t * a2, uint8_t * mackey, uint8_t * ltk)
 */


/* exclude_from_export_ai */

int bt_crypto_f5(uint8_t *w,uint8_t *n1,uint8_t *n2,bt_addr_le_t *a1,bt_addr_le_t *a2,
                uint8_t *mackey,uint8_t *ltk)

{
  uint8_t uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  size_t length;
  size_t length_00;
  uint8_t *puVar5;
  undefined4 *puVar6;
  uint8_t *puVar7;
  uint8_t auStack_88 [16];
  uint8_t auStack_78 [32];
  uint8_t local_58 [4];
  undefined4 uStack_54;
  undefined4 local_50;
  uint8_t local_4c [9];
  undefined1 auStack_43 [16];
  uint8_t local_33;
  undefined1 auStack_32 [6];
  uint8_t local_2c;
  undefined1 auStack_2b [11];
  
  puVar7 = local_58;
  puVar2 = &DAT_0008bfad;
  do {
    puVar6 = puVar2;
    puVar5 = puVar7;
    uVar4 = puVar6[1];
    *(undefined4 *)puVar5 = *puVar6;
    *(undefined4 *)(puVar5 + 4) = uVar4;
    puVar7 = puVar5 + 8;
    puVar2 = puVar6 + 2;
  } while (puVar6 + 2 != (undefined4 *)&UNK_0008bfdd);
  uVar1 = *(uint8_t *)(puVar6 + 3);
  puVar7[0] = '\0';
  puVar7[1] = '\0';
  puVar7[2] = '\0';
  puVar7[3] = '\x01';
  puVar5[0xc] = uVar1;
  sys_memcpy_swap(auStack_78,w,0x20);
  iVar3 = bt_crypto_aes_cmac(&DAT_000f3391,auStack_78,0x20,auStack_88);
  if (iVar3 == 0) {
    sys_memcpy_swap((void *)((int)&uStack_54 + 1),n1,0x10);
    sys_memcpy_swap(auStack_43,n2,0x10);
    local_33 = a1->type;
    sys_memcpy_swap(auStack_32,&a1->a,6);
    local_2c = a2->type;
    sys_memcpy_swap(auStack_2b,&a2->a,6);
    iVar3 = bt_crypto_aes_cmac(auStack_88,local_58,0x35,mackey);
    if (iVar3 == 0) {
      sys_mem_swap(mackey,length);
      local_58[0] = '\x01';
      iVar3 = bt_crypto_aes_cmac(auStack_88,local_58,0x35,ltk);
      if (iVar3 == 0) {
        sys_mem_swap(ltk,length_00);
      }
    }
  }
  return iVar3;
}


