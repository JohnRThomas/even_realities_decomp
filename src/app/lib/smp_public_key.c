/*
 * Function: smp_public_key
 * Entry:    0006029c
 * Prototype: uint8_t __stdcall smp_public_key(bt_smp * smp, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t smp_public_key(bt_smp *smp,net_buf *buf)

{
  bool bVar1;
  uint8_t uVar2;
  bt_keys *pbVar3;
  byte *pbVar4;
  uint8_t *puVar5;
  uint8_t *puVar6;
  uint8_t *puVar7;
  int iVar8;
  char local_18 [4];
  char *local_14;
  
  latch_auth_cb(smp);
  puVar5 = (buf->field6_0xc).field0.data;
  pbVar4 = &smp->pkey_BT_PUB_KEY_LEN_;
  puVar7 = puVar5;
  do {
    puVar6 = puVar7;
    puVar7 = puVar6 + 4;
    *(undefined4 *)pbVar4 = *(undefined4 *)puVar6;
    pbVar4 = pbVar4 + 4;
  } while (puVar7 != puVar5 + 0x20);
  pbVar4 = smp->mackey + 0xe;
  do {
    puVar5 = puVar7 + 4;
    *(undefined4 *)pbVar4 = *(undefined4 *)puVar7;
    pbVar4 = pbVar4 + 4;
    puVar7 = puVar5;
  } while (puVar5 != puVar6 + 0x24);
  bVar1 = bt_pub_key_is_debug(&smp->pkey_BT_PUB_KEY_LEN_);
  if (bVar1) {
    local_14 = "Remote is using Debug Public key";
    local_18[0] = '\x02';
    local_18[1] = '\0';
    local_18[2] = '\0';
    local_18[3] = '\0';
    LOG_ERR(&PTR_s_bt_smp_0008b930,0x10c0,local_18);
    atomic_set_bit((atomic_t *)&smp->SMP_NUM_FLAGS_,0xe);
    iVar8 = *(int *)&smp[1].dhkey_BT_DH_KEY_LEN_;
    if (*(int *)(iVar8 + 0xc0) == 0) {
      pbVar3 = bt_keys_get_addr(*(uint8_t *)(iVar8 + 8),(bt_addr_le_t *)(iVar8 + 0x90));
      *(bt_keys **)(iVar8 + 0xc0) = pbVar3;
    }
    iVar8 = *(int *)(iVar8 + 0xc0);
    if (((iVar8 != 0) && ((*(ushort *)(iVar8 + 0xe) & 0x24) != 0)) &&
       (-1 < (int)((uint)*(byte *)(iVar8 + 0xd) << 0x1e))) {
      return '\x03';
    }
  }
  if (DAT_2000b928 == 0) {
    atomic_set_bit((atomic_t *)&smp->SMP_NUM_FLAGS_,6);
    return '\0';
  }
  uVar2 = smp_public_key_periph(smp);
  return uVar2;
}


