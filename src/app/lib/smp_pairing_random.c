/*
 * Function: smp_pairing_random
 * Entry:    000605dc
 * Prototype: uint8_t __stdcall smp_pairing_random(bt_smp * smp, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t smp_pairing_random(bt_smp *smp,net_buf *buf)

{
  bool bVar1;
  uint8_t uVar2;
  bt_conn_auth_cb *pbVar3;
  int iVar4;
  undefined4 uVar5;
  bt_smp *smp_00;
  undefined4 uVar6;
  byte *pbVar7;
  byte bVar8;
  char cVar9;
  uint8_t *puVar10;
  uint8_t *puVar11;
  dword *target;
  byte *x;
  uint8_t *res;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  char local_20 [4];
  char *local_1c;
  uint8_t *puVar12;
  
  res = (uint8_t *)&local_40;
  pbVar3 = latch_auth_cb(smp);
  x = smp->rrnd;
  puVar10 = (buf->field6_0xc).field0.data;
  pbVar7 = x;
  puVar11 = puVar10;
  do {
    puVar12 = puVar11 + 4;
    *(undefined4 *)pbVar7 = *(undefined4 *)puVar11;
    pbVar7 = pbVar7 + 4;
    puVar11 = puVar12;
  } while (puVar12 != puVar10 + 0x10);
  target = &smp->SMP_NUM_FLAGS_;
  bVar1 = atomic_test_bit((atomic_t *)target,5);
  if (bVar1) {
    switch(smp->method) {
    case 1:
    case 2:
      iVar4 = bt_crypto_f4(&smp->pkey_BT_PUB_KEY_LEN_,DAT_2000b928,x,
                           (byte)(*(uint *)(smp[1].rrnd + 9) >> smp[1].rrnd[0xd]) & 1 | 0x80,res);
      if (iVar4 == 0) {
        iVar4 = memcmp(smp->pcnf,res,0x10);
        if (iVar4 != 0) {
          return '\x04';
        }
        atomic_set_bit((atomic_t *)smp,3);
        uVar2 = smp_send_pairing_random(smp_00);
        if (uVar2 == '\0') {
          bVar8 = smp[1].rrnd[0xd] + 1;
          smp[1].rrnd[0xd] = bVar8;
          if (bVar8 == 0x14) {
            atomic_set_bit((atomic_t *)smp,0xd);
            atomic_set_bit((atomic_t *)target,0x10);
            return '\0';
          }
          iVar4 = bt_rand(smp->prnd,0x10);
          return (iVar4 != 0) << 3;
        }
        return uVar2;
      }
      local_1c = "Calculate confirm failed";
      goto LAB_0006066e;
    case 3:
      iVar4 = bt_crypto_g2(&smp->pkey_BT_PUB_KEY_LEN_,DAT_2000b928,x,smp->prnd,&local_30);
      if (iVar4 != 0) {
        return '\b';
      }
      atomic_set_bit((atomic_t *)target,10);
      uVar6._0_1_ = smp[1].dhkey_BT_DH_KEY_LEN_;
      uVar6._1_1_ = smp[1].e[0];
      uVar6._2_1_ = smp[1].e[1];
      uVar6._3_1_ = smp[1].e[2];
      (*(code *)pbVar3->passkey_display_keypress)(uVar6,local_30);
    case 0:
      atomic_set_bit((atomic_t *)smp,0xd);
      iVar4 = 0x10;
LAB_000606a8:
      atomic_set_bit((atomic_t *)target,iVar4);
      uVar2 = smp_send_pairing_random(smp);
      return uVar2;
    default:
      LOG_ERR(&PTR_s_bt_smp_0008b930,0x1840,&stack0xffffffb0);
      break;
    case 5:
      iVar4 = bt_rand(smp->prnd,0x10);
      if (iVar4 == 0) {
        if ((pbVar3 != (bt_conn_auth_cb *)0x0) && (pbVar3->passkey_entry != (undefined *)0x0)) {
          if ((int)((uint)smp->preq[2] << 0x1f) < 0) {
            cVar9 = (smp->prsp[2] & 1) << 1;
          }
          else if ((smp->prsp[2] & 1) == 0) {
            cVar9 = '\x03';
          }
          else {
            cVar9 = '\x01';
          }
          local_30._0_2_ = CONCAT11(cVar9,1);
          smp[1].tk[1] = 0;
          smp[1].tk[2] = 0;
          smp[1].tk[3] = 0;
          smp[1].tk[4] = 0;
          smp[1].tk[5] = 0;
          smp[1].tk[6] = 0;
          smp[1].tk[7] = 0;
          smp[1].tk[8] = 0;
          atomic_set_bit((atomic_t *)target,0xc);
          uVar5._0_1_ = smp[1].dhkey_BT_DH_KEY_LEN_;
          uVar5._1_1_ = smp[1].e[0];
          uVar5._2_1_ = smp[1].e[1];
          uVar5._3_1_ = smp[1].e[2];
          (*(code *)pbVar3->passkey_entry)(uVar5,&local_30);
          return '\0';
        }
        return '\x02';
      }
    }
  }
  else {
    pbVar7 = smp->tk;
    iVar4 = smp_c1(pbVar7,x,smp->preq,smp->prsp,
                   (bt_addr_le_t *)(*(int *)&smp[1].dhkey_BT_DH_KEY_LEN_ + 0x97),
                   (bt_addr_le_t *)(*(int *)&smp[1].dhkey_BT_DH_KEY_LEN_ + 0x9e),res);
    if (iVar4 != 0) {
      return '\b';
    }
    iVar4 = memcmp(smp->pcnf,res,0x10);
    if (iVar4 != 0) {
      return '\x04';
    }
    local_40 = *(undefined4 *)smp->rrnd;
    uStack_3c = *(undefined4 *)(smp->rrnd + 4);
    local_38 = *(undefined4 *)smp->prnd;
    uStack_34 = *(undefined4 *)(smp->prnd + 4);
    iVar4 = internal_encrypt_le(pbVar7,res,res);
    if (iVar4 == 0) {
      do {
        uVar5 = *(undefined4 *)res;
        uVar6 = *(undefined4 *)(res + 4);
        res = res + 8;
        *(undefined4 *)pbVar7 = uVar5;
        *(undefined4 *)(pbVar7 + 4) = uVar6;
        pbVar7 = pbVar7 + 8;
      } while (res != (uint8_t *)&local_30);
      iVar4 = 1;
      goto LAB_000606a8;
    }
    local_1c = "Calculate STK failed";
LAB_0006066e:
    local_20[0] = '\x02';
    local_20[1] = '\0';
    local_20[2] = '\0';
    local_20[3] = '\0';
    LOG_ERR(&PTR_s_bt_smp_0008b930,0x1040,local_20);
  }
  return '\b';
}


