/*
 * Function: smp_pairing_req
 * Entry:    0006086c
 * Prototype: uint8_t __stdcall smp_pairing_req(bt_smp * smp, net_buf * buf)
 */


/* exclude_from_export */

uint8_t smp_pairing_req(bt_smp *smp,net_buf *buf)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  uint8_t uVar4;
  bt_conn_auth_cb *pbVar5;
  int iVar6;
  atomic_t *target;
  bt_conn_auth_cb *pbVar7;
  bt_keys *pbVar8;
  undefined4 uVar9;
  bt_smp *extraout_r0;
  bt_smp *smp_00;
  byte extraout_r1;
  byte *pbVar10;
  code *pcVar11;
  dword *target_00;
  int iVar12;
  byte *pbVar13;
  uint uVar14;
  char local_48 [4];
  char *local_44;
  uint uStack_40;
  uint local_38 [4];
  char local_28 [4];
  char *local_24;
  
  iVar12 = *(int *)&smp[1].dhkey_BT_DH_KEY_LEN_;
  pbVar5 = latch_auth_cb(smp);
  pbVar13 = (buf->field6_0xc).field0.data;
  if (9 < pbVar13[3] - 7) {
    return '\x06';
  }
  if (*(int *)(iVar12 + 0xc0) == 0) {
    pbVar8 = bt_keys_get_addr(*(uint8_t *)(iVar12 + 8),(bt_addr_le_t *)(iVar12 + 0x90));
    *(bt_keys **)(iVar12 + 0xc0) = pbVar8;
    if (pbVar8 == (bt_keys *)0x0) {
      return '\b';
    }
  }
  target_00 = &smp->SMP_NUM_FLAGS_;
  bVar2 = atomic_test_bit((atomic_t *)target_00,0xf);
  if ((!bVar2) && (iVar6 = smp_init(smp), iVar6 != 0)) {
    return (uint8_t)iVar6;
  }
  smp->preq[0] = 1;
  *(undefined4 *)(smp->preq + 1) = *(undefined4 *)pbVar13;
  *(undefined2 *)(smp->preq + 5) = *(undefined2 *)(pbVar13 + 4);
  smp->prsp[0] = 2;
  bVar3 = get_auth(smp,pbVar13[2]);
  smp->prsp[3] = bVar3;
  bVar3 = get_io_capa();
  smp->prsp[1] = bVar3;
  smp->prsp[4] = 0x10;
  smp->prsp[5] = pbVar13[4] & 3;
  smp->prsp[6] = pbVar13[5] & 1;
  if (((int)((uint)smp->prsp[3] << 0x1c) < 0) && ((int)((uint)pbVar13[2] << 0x1c) < 0)) {
    atomic_set_bit((atomic_t *)target_00,5);
    smp->prsp[5] = smp->prsp[5] & 2;
    smp->prsp[6] = 0;
  }
  bVar2 = atomic_test_bit((atomic_t *)target_00,5);
  if (bVar2) {
    pbVar10 = &DAT_2001e2a8;
  }
  else {
    pbVar10 = &DAT_2001e2a7;
  }
  smp->prsp[2] = *pbVar10;
  if (((int)((uint)smp->prsp[3] << 0x1a) < 0) && ((int)((uint)pbVar13[2] << 0x1a) < 0)) {
    atomic_set_bit((atomic_t *)target_00,0x14);
  }
  if (((int)((uint)smp->prsp[3] << 0x1f) < 0) && ((int)((uint)pbVar13[2] << 0x1f) < 0)) {
    atomic_set_bit((atomic_t *)target_00,0xd);
  }
  else {
    smp->prsp[5] = 0;
    smp->prsp[6] = 0;
  }
  smp[1].tk[9] = smp->prsp[6];
  smp[1].tk[10] = smp->prsp[5];
  atomic_set_bit((atomic_t *)target_00,3);
  uVar14 = (uint)*pbVar13;
  bVar2 = atomic_test_bit(target,5);
  if (bVar2) {
    if ((-1 < (int)((uint)(smp->preq[3] & smp->prsp[3]) << 0x1c)) ||
       (bVar3 = extraout_r1, -1 < (int)((uint)(smp->preq[2] | smp->prsp[2]) << 0x1f))) {
      if (4 < uVar14) goto LAB_00060a2e;
      bVar1 = smp->preq[3] | smp->prsp[3];
      bVar3 = bVar1 & 4;
      if ((bVar1 & 4) != 0) {
        bVar3 = get_io_capa();
        bVar3 = (&UNK_000f3240)[(uint)bVar3 + uVar14 * 5];
      }
    }
  }
  else if (uVar14 < 5) {
    if ((int)((uint)(smp->preq[2] & smp->prsp[2]) << 0x1f) < 0) {
      bVar3 = 6;
    }
    else {
      bVar1 = smp->preq[3] | smp->prsp[3];
      bVar3 = bVar1 & 4;
      if ((bVar1 & 4) != 0) {
        bVar3 = get_io_capa();
        bVar3 = (&DAT_000f3259)[(uint)bVar3 + uVar14 * 5];
        if (bVar3 == 4) {
          if (*(char *)(*(int *)&smp[1].dhkey_BT_DH_KEY_LEN_ + 3) == '\0') {
            bVar3 = 2;
          }
          else {
            bVar3 = 1;
          }
        }
      }
    }
  }
  else {
LAB_00060a2e:
    bVar3 = 0;
  }
  smp->method = bVar3;
  bVar2 = update_keys_check(smp,*(bt_keys **)(iVar12 + 0xc0));
  if (!bVar2) {
    return '\x03';
  }
  uVar14 = (uint)*(byte *)(*(int *)&smp[1].dhkey_BT_DH_KEY_LEN_ + 10);
  if (uVar14 == 3) {
LAB_00060aba:
    if (smp->method == 0) {
      return '\x03';
    }
  }
  else {
    if (3 < uVar14) {
      if (uVar14 != 4) {
        return '\b';
      }
      bVar3 = smp->prsp[4];
      if (smp->preq[4] <= smp->prsp[4]) {
        bVar3 = smp->preq[4];
      }
      if (bVar3 != 0x10) {
        return '\x06';
      }
      bVar2 = atomic_test_bit((atomic_t *)target_00,5);
      if (!bVar2) {
        return '\x03';
      }
      goto LAB_00060aba;
    }
    if (1 < uVar14 - 1) {
      return '\b';
    }
  }
  bVar2 = atomic_test_bit((atomic_t *)target_00,5);
  if (bVar2) {
    if ((((smp->method == 0) && (bVar2 = atomic_test_bit((atomic_t *)target_00,0xf), !bVar2)) &&
        (pbVar5 != (bt_conn_auth_cb *)0x0)) && (pbVar5->oob_data_request != (undefined *)0x0)) {
      atomic_set_bit((atomic_t *)target_00,10);
      pcVar11 = (code *)pbVar5->oob_data_request;
      goto LAB_00060b22;
    }
    iVar12 = 0xc;
    goto LAB_00060bb4;
  }
  pbVar5 = latch_auth_cb(smp);
  iVar12 = *(int *)&smp[1].dhkey_BT_DH_KEY_LEN_;
  pbVar7 = latch_auth_cb(smp);
  pbVar8 = bt_keys_find_addr(*(uint8_t *)(iVar12 + 8),(bt_addr_le_t *)(iVar12 + 0x90));
  uStack_40 = (uint)smp->method;
  if (((pbVar8 != (bt_keys *)0x0) && ((int)((uint)*(byte *)((int)&pbVar8->keys + 1) << 0x1f) < 0))
     && (uStack_40 == 0)) {
    local_24 = "JustWorks failed, authenticated keys present";
    local_28[0] = '\x02';
    local_28[1] = '\0';
    local_28[2] = '\0';
    local_28[3] = '\0';
    LOG_ERR(&PTR_s_bt_smp_0008b930,0x1040,local_28);
    return '\b';
  }
  switch(uStack_40) {
  case 0:
    goto switchD_00060ac6_caseD_0;
  case 1:
    atomic_set_bit((atomic_t *)target_00,10);
    (*(code *)pbVar7->passkey_display)(iVar12);
    break;
  case 2:
    iVar6 = bt_rand(local_38,4);
    if (iVar6 != 0) {
      return '\b';
    }
    local_38[0] = local_38[0] % 1000000;
    if ((pbVar7 != (bt_conn_auth_cb *)0x0) && (pbVar7->pairing_accept != (undefined *)0x0)) {
      atomic_set_bit((atomic_t *)target_00,0xb);
      (*(code *)pbVar7->pairing_accept)(iVar12,local_38[0]);
    }
    smp->tk[0] = (byte)local_38[0];
    smp->tk[2] = (byte)(local_38[0] >> 0x10);
    smp->tk[1] = (byte)(local_38[0] >> 8);
    smp->tk[3] = (byte)(local_38[0] >> 0x18);
    break;
  default:
    local_44 = "Unknown pairing method (%u)";
    local_48[0] = '\x03';
    local_48[1] = '\0';
    local_48[2] = '\0';
    local_48[3] = '\0';
    LOG_ERR(&PTR_s_bt_smp_0008b930,0x1840,local_48);
    return '\b';
  case 6:
    if ((pbVar7 == (bt_conn_auth_cb *)0x0) || (pbVar7->passkey_entry == (undefined *)0x0)) {
      return '\x02';
    }
    local_38[0] = local_38[0] & 0xffff0000;
    atomic_set_bit((atomic_t *)target_00,10);
    uVar9._0_1_ = smp[1].dhkey_BT_DH_KEY_LEN_;
    uVar9._1_1_ = smp[1].e[0];
    uVar9._2_1_ = smp[1].e[1];
    uVar9._3_1_ = smp[1].e[2];
    (*(code *)pbVar7->passkey_entry)(uVar9,local_38);
  }
  if (smp->method == 0) {
switchD_00060ac6_caseD_0:
    bVar2 = atomic_test_bit((atomic_t *)target_00,0xf);
    if (((!bVar2) && (pbVar5 != (bt_conn_auth_cb *)0x0)) &&
       (pbVar5->oob_data_request != (undefined *)0x0)) {
      atomic_set_bit((atomic_t *)target_00,10);
      pcVar11 = (code *)pbVar5->oob_data_request;
      iVar12._0_1_ = smp[1].dhkey_BT_DH_KEY_LEN_;
      iVar12._1_1_ = smp[1].e[0];
      iVar12._2_1_ = smp[1].e[1];
      iVar12._3_1_ = smp[1].e[2];
LAB_00060b22:
      (*pcVar11)(iVar12);
      return '\0';
    }
  }
  atomic_set_bit((atomic_t *)smp,3);
  iVar12 = 0xe;
  smp = extraout_r0;
LAB_00060bb4:
  atomic_set_bit((atomic_t *)smp,iVar12);
  uVar4 = send_pairing_rsp(smp_00);
  return uVar4;
}


