/*
 * Function: smp_encrypt_info
 * Entry:    0005ffe8
 * Prototype: uint8_t __stdcall smp_encrypt_info(bt_smp * smp, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t smp_encrypt_info(bt_smp *smp,net_buf *buf)

{
  bool bVar1;
  bt_keys *pbVar2;
  char *str;
  size_t len;
  undefined4 *puVar3;
  int extraout_r3;
  undefined4 *puVar5;
  undefined4 *puVar6;
  bt_addr_le_t *addr;
  undefined1 *puStack_28;
  char *pcStack_24;
  int iStack_20;
  undefined2 uStack_1c;
  undefined4 *puVar4;
  
  bVar1 = atomic_test_bit((atomic_t *)&smp->SMP_NUM_FLAGS_,0xd);
  if (bVar1) {
    puVar6 = *(undefined4 **)(extraout_r3 + 0xc);
    addr = (bt_addr_le_t *)(*(int *)&smp[1].dhkey_BT_DH_KEY_LEN_ + 0x90);
    pbVar2 = bt_keys_get_type(BT_KEYS_REMOTE_CSRK,
                              *(uint8_t *)(*(int *)&smp[1].dhkey_BT_DH_KEY_LEN_ + 8),addr);
    if (pbVar2 == (bt_keys *)0x0) {
      iStack_20 = bt_addr_le_to_str(addr,str,len);
      pcStack_24 = "Unable to get keys for %s";
      uStack_1c = 0x200;
      puStack_28 = &DAT_01000003;
      LOG_ERR(&PTR_s_bt_smp_0008b930,0x1c40,(char *)&puStack_28);
      return '\b';
    }
    puVar3 = puVar6;
    puVar5 = (undefined4 *)((int)&pbVar2->ltk_val0 + 2);
    do {
      puVar4 = puVar3 + 1;
      *puVar5 = *puVar3;
      puVar3 = puVar4;
      puVar5 = puVar5 + 1;
    } while (puVar4 != puVar6 + 4);
  }
  atomic_set_bit((atomic_t *)smp,7);
  return '\0';
}


