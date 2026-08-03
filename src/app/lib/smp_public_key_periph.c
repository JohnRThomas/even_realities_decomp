/*
 * Function: smp_public_key_periph
 * Entry:    00060118
 * Prototype: uint8_t __stdcall smp_public_key_periph(bt_smp * smp)
 */


/* exclude_from_export_ai */

uint8_t smp_public_key_periph(bt_smp *smp)

{
  bool bVar1;
  uint8_t uVar2;
  bt_conn_auth_cb *pbVar3;
  int iVar4;
  net_buf *buf;
  undefined4 *puVar5;
  undefined4 *puVar6;
  bt_smp *smp_00;
  bt_smp *extraout_r0;
  atomic_t *target;
  undefined4 uVar7;
  bt_smp *pbVar8;
  undefined4 *puVar9;
  uint8_t *e;
  size_t extraout_r2;
  size_t extraout_r2_00;
  size_t len;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  dword *target_00;
  undefined4 uVar13;
  char local_40 [4];
  char *local_3c;
  uint uStack_38;
  char local_20 [4];
  char *local_1c;
  
  pbVar3 = latch_auth_cb(smp);
  target_00 = &smp->SMP_NUM_FLAGS_;
  bVar1 = atomic_test_bit((atomic_t *)target_00,0xe);
  len = extraout_r2;
  if ((!bVar1) &&
     (iVar4 = memcmp(&smp->pkey_BT_PUB_KEY_LEN_,DAT_2000b928,0x20), len = extraout_r2_00, iVar4 == 0
     )) {
    local_1c = "Remote public key rejected";
    local_20[0] = '\x02';
    local_20[1] = '\0';
    local_20[2] = '\0';
    local_20[3] = '\0';
    LOG_ERR(&PTR_s_bt_smp_0008b930,0x1080,local_20);
    return '\b';
  }
  buf = smp_create_pdu(smp,'\f',len);
  if (buf == (net_buf *)0x0) {
    return '\b';
  }
  puVar5 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,0x40);
  puVar6 = DAT_2000b928 + 8;
  puVar9 = puVar5;
  puVar11 = DAT_2000b928;
  do {
    puVar10 = puVar11;
    puVar11 = puVar10 + 1;
    *puVar9 = *puVar10;
    puVar9 = puVar9 + 1;
  } while (puVar11 != puVar6);
  puVar9 = puVar5 + 8;
  do {
    puVar5 = puVar11 + 1;
    *puVar9 = *puVar11;
    puVar9 = puVar9 + 1;
    puVar11 = puVar5;
  } while (puVar5 != puVar10 + 9);
  smp_send(smp,buf,(bt_conn_tx_cb_t)0x0,puVar5);
  uStack_38 = (uint)smp->method;
  switch(uStack_38) {
  case 0:
  case 3:
    atomic_set_bit((atomic_t *)smp,4);
    uVar2 = sc_smp_send_dhkey_check(smp_00,e);
    if (uVar2 != '\0') {
      return uVar2;
    }
    goto LAB_00060246;
  case 1:
    atomic_set_bit((atomic_t *)smp,3);
    atomic_set_bit(target,0xe);
    atomic_set_bit((atomic_t *)target_00,10);
    uVar7._0_1_ = smp[1].dhkey_BT_DH_KEY_LEN_;
    uVar7._1_1_ = smp[1].e[0];
    uVar7._2_1_ = smp[1].e[1];
    uVar7._3_1_ = smp[1].e[2];
    (*(code *)pbVar3->passkey_display)(uVar7);
    goto LAB_00060246;
  case 2:
    uVar13._0_1_ = smp[1].dhkey_BT_DH_KEY_LEN_;
    uVar13._1_1_ = smp[1].e[0];
    uVar13._2_1_ = smp[1].e[1];
    uVar13._3_1_ = smp[1].e[2];
    pbVar3 = latch_auth_cb(smp);
    iVar4 = bt_rand(smp[1].rrnd + 9,4);
    if (iVar4 != 0) {
      return '\b';
    }
    uVar12 = *(uint *)(smp[1].rrnd + 9);
    smp[1].rrnd[0xd] = 0;
    *(uint *)(smp[1].rrnd + 9) = uVar12 % 1000000;
    if ((pbVar3 != (bt_conn_auth_cb *)0x0) && (pbVar3->pairing_accept != (undefined *)0x0)) {
      atomic_set_bit((atomic_t *)target_00,0xb);
      (*(code *)pbVar3->pairing_accept)(uVar13,*(undefined4 *)(smp[1].rrnd + 9));
    }
    atomic_set_bit((atomic_t *)smp,3);
    iVar4 = 0xe;
    pbVar8 = extraout_r0;
    break;
  default:
    local_3c = "Unknown pairing method (%u)";
    local_40[0] = '\x03';
    local_40[1] = '\0';
    local_40[2] = '\0';
    local_40[3] = '\0';
    LOG_ERR(&PTR_s_bt_smp_0008b930,0x1840,local_40);
    return '\b';
  case 5:
    iVar4 = 4;
    pbVar8 = smp;
  }
  atomic_set_bit((atomic_t *)pbVar8,iVar4);
LAB_00060246:
  atomic_set_bit((atomic_t *)target_00,7);
  pbVar8 = smp_find(8);
  if (pbVar8 == (bt_smp *)0x0) {
    uVar2 = generate_dhkey(smp);
  }
  else {
    uVar2 = '\0';
  }
  return uVar2;
}


