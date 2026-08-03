/*
 * Function: smp_g2_test
 * Entry:    00060358
 * Prototype: int __stdcall smp_g2_test(void)
 */


/* exclude_from_export_ai */

int smp_g2_test(void)

{
  bt_smp *in_r0;
  int iVar1;
  undefined4 uVar2;
  net_buf *buf;
  undefined4 uVar3;
  size_t len;
  undefined4 *puVar4;
  byte *mackey;
  byte *n1;
  byte *n2;
  undefined4 *puVar5;
  uint8_t *puVar6;
  uint8_t *puVar7;
  uint8_t auStack_68 [16];
  uint8_t local_58 [16];
  undefined4 local_48 [8];
  char local_28 [4];
  char *local_24;
  
  memset(local_48,0,0x10);
  switch(in_r0->method) {
  case 0:
  case 3:
    break;
  case 1:
  case 2:
    local_48[0] = *(undefined4 *)(in_r0[1].rrnd + 9);
    break;
  default:
    LOG_ERR(&PTR_s_bt_smp_0008b930,0x1840,&stack0xffffff88);
    return 8;
  case 5:
    puVar4 = *(undefined4 **)(in_r0[1].tk + 5);
    if (puVar4 != (undefined4 *)0x0) {
      puVar5 = puVar4 + 4;
      puVar6 = (uint8_t *)local_48;
      do {
        uVar2 = *puVar4;
        uVar3 = puVar4[1];
        puVar4 = puVar4 + 2;
        *(undefined4 *)puVar6 = uVar2;
        *(undefined4 *)(puVar6 + 4) = uVar3;
        puVar6 = puVar6 + 8;
      } while (puVar4 != puVar5);
    }
  }
  mackey = in_r0[1].prnd + 8;
  n1 = in_r0->rrnd;
  n2 = in_r0->prnd;
  iVar1 = bt_crypto_f5((uint8_t *)((int)&in_r0->bondable + 3),n1,n2,
                       (bt_addr_le_t *)(*(int *)&in_r0[1].dhkey_BT_DH_KEY_LEN_ + 0x97),
                       (bt_addr_le_t *)(*(int *)&in_r0[1].dhkey_BT_DH_KEY_LEN_ + 0x9e),mackey,
                       in_r0->tk);
  if (iVar1 == 0) {
    puVar6 = local_58;
    iVar1 = bt_crypto_f6(mackey,n2,n1,(uint8_t *)local_48,in_r0->prsp + 1,
                         (bt_addr_le_t *)(*(int *)&in_r0[1].dhkey_BT_DH_KEY_LEN_ + 0x9e),
                         (bt_addr_le_t *)(*(int *)&in_r0[1].dhkey_BT_DH_KEY_LEN_ + 0x97),puVar6);
    if (iVar1 == 0) {
      if (in_r0->method == 5) {
        puVar4 = *(undefined4 **)(in_r0[1].tk + 1);
        if (puVar4 == (undefined4 *)0x0) {
          memset(local_48,0,0x10);
        }
        else {
          puVar5 = puVar4 + 4;
          puVar7 = (uint8_t *)local_48;
          do {
            uVar2 = *puVar4;
            uVar3 = puVar4[1];
            puVar4 = puVar4 + 2;
            *(undefined4 *)puVar7 = uVar2;
            *(undefined4 *)(puVar7 + 4) = uVar3;
            puVar7 = puVar7 + 8;
          } while (puVar4 != puVar5);
        }
      }
      iVar1 = bt_crypto_f6(mackey,n1,n2,(uint8_t *)local_48,in_r0->preq + 1,
                           (bt_addr_le_t *)(*(int *)&in_r0[1].dhkey_BT_DH_KEY_LEN_ + 0x97),
                           (bt_addr_le_t *)(*(int *)&in_r0[1].dhkey_BT_DH_KEY_LEN_ + 0x9e),
                           auStack_68);
      if (iVar1 == 0) {
        iVar1 = memcmp(in_r0[1].pcnf + 8,auStack_68,0x10);
        if (iVar1 != 0) {
          return 0xb;
        }
        buf = smp_create_pdu(in_r0,'\r',len);
        if (buf == (net_buf *)0x0) {
          return 8;
        }
        puVar4 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,0x10);
        do {
          uVar2 = *(undefined4 *)puVar6;
          uVar3 = *(undefined4 *)(puVar6 + 4);
          puVar6 = puVar6 + 8;
          *puVar4 = uVar2;
          puVar4[1] = uVar3;
          puVar4 = puVar4 + 2;
        } while (puVar6 != (uint8_t *)local_48);
        smp_send(in_r0,buf,(bt_conn_tx_cb_t)0x0,puVar4);
        atomic_set_bit((atomic_t *)&in_r0->SMP_NUM_FLAGS_,1);
        return 0;
      }
      local_24 = "Calculate remote DHKey check failed";
    }
    else {
      local_24 = "Calculate local DHKey check failed";
    }
  }
  else {
    local_24 = "Calculate LTK failed";
  }
  local_28[0] = '\x02';
  local_28[1] = '\0';
  local_28[2] = '\0';
  local_28[3] = '\0';
  LOG_ERR(&PTR_s_bt_smp_0008b930,0x1040,local_28);
  return 8;
}


