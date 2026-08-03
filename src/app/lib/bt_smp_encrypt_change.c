/*
 * Function: bt_smp_encrypt_change
 * Entry:    00061454
 * Prototype: void __stdcall bt_smp_encrypt_change(bt_l2cap_chan * chan, uint8_t hci_status)
 */


/* exclude_from_export */

void bt_smp_encrypt_change(bt_l2cap_chan *chan,uint8_t hci_status)

{
  bool bVar1;
  bt_security_err bVar2;
  uint uVar3;
  atomic_t *target;
  net_buf *pnVar4;
  void *d;
  undefined2 *user_data;
  undefined4 uVar5;
  int iVar6;
  char *str;
  undefined4 uVar7;
  size_t len;
  size_t len_00;
  void *extraout_r3;
  void *extraout_r3_00;
  void *user_data_00;
  undefined4 *puVar8;
  uint8_t status;
  bt_smp *smp;
  undefined **target_00;
  undefined *puVar9;
  bt_conn *pbVar10;
  undefined4 *puVar11;
  undefined1 *local_70;
  char *local_6c;
  int iStack_68;
  undefined2 local_64;
  char local_50 [4];
  char *local_4c;
  undefined4 local_44 [4];
  undefined4 local_34;
  undefined4 uStack_30;
  undefined2 local_2c;
  
  target_00 = &chan[-0xc].ops;
  smp = (bt_smp *)(chan + -0xc);
  pbVar10 = chan->conn;
  bVar1 = atomic_test_and_clear_bit((atomic_t *)target_00,1);
  if (!bVar1) {
    return;
  }
  if (hci_status != '\0') {
    bVar1 = atomic_test_bit((atomic_t *)target_00,3);
    if (!bVar1) {
      return;
    }
    bVar2 = bt_security_err_get(hci_status);
    uVar3 = bVar2 - 1 & 0xff;
    if (uVar3 < 9) {
      status = (&DAT_000f3228)[uVar3];
    }
    else {
      status = '\0';
    }
    atomic_set_bit((atomic_t *)target_00,2);
    goto LAB_000614a6;
  }
  if (pbVar10->encrypt == '\0') {
    return;
  }
  bVar1 = atomic_test_bit((atomic_t *)target_00,3);
  if (!bVar1) {
    smp_reset(smp);
    return;
  }
  bVar1 = atomic_test_bit((atomic_t *)target_00,5);
  if (bVar1) {
    if (((int)((uint)*(byte *)&chan[-1].destroy << 0x1c) < 0) &&
       ((int)((uint)*(byte *)((int)&chan[-1].destroy + 1) << 0x1c) < 0)) {
      atomic_set_bit((atomic_t *)target_00,0x11);
    }
    *(byte *)&chan[-1].destroy = *(byte *)&chan[-1].destroy & 0xf7;
    *(byte *)((int)&chan[-1].destroy + 1) = *(byte *)((int)&chan[-1].destroy + 1) & 0xf7;
  }
  uVar3 = (uint)*(byte *)((int)&chan[-1].destroy + 1);
  if ((int)(uVar3 << 0x1f) < 0) {
    iVar6 = 6;
LAB_00061510:
    atomic_set_bit((atomic_t *)smp,iVar6);
  }
  else {
    if ((int)(uVar3 << 0x1e) < 0) {
      iVar6 = 8;
      goto LAB_00061510;
    }
    if ((int)(uVar3 << 0x1d) < 0) {
      iVar6 = 10;
      goto LAB_00061510;
    }
  }
  atomic_set_bit((atomic_t *)target_00,2);
  if ((chan->conn->le).keys == (undefined *)0x0) {
    iStack_68 = bt_addr_le_to_str(&(chan->conn->le).dst,str,0);
    local_6c = "No keys space for %s";
    local_64 = 0x200;
    local_70 = &DAT_01000003;
    LOG_ERR(&PTR_s_bt_smp_0008b930,0x1c40,(char *)&local_70);
    return;
  }
  bVar1 = atomic_test_bit(target,5);
  if ((!bVar1) && ((int)((uint)*(byte *)&chan[-1].destroy << 0x1f) < 0)) {
    puVar9 = (chan->conn->le).keys;
    iVar6 = bt_rand(local_44,0x1a);
    if (iVar6 == 0) {
      pnVar4 = smp_create_pdu(smp,'\x06',len);
      if (pnVar4 == (net_buf *)0x0) {
        local_4c = "Unable to allocate Encrypt Info buffer";
      }
      else {
        d = net_buf_add((net_buf *)&(pnVar4->field6_0xc).field0,0x10);
        memcpy(d,local_44,(uint)(byte)puVar9[0xc]);
        uVar3 = (uint)(byte)puVar9[0xc];
        user_data_00 = extraout_r3;
        if (uVar3 < 0x10) {
          memset((void *)(uVar3 + (int)d),0,0x10 - uVar3);
          user_data_00 = extraout_r3_00;
        }
        smp_send(smp,pnVar4,(bt_conn_tx_cb_t)0x0,user_data_00);
        pnVar4 = smp_create_pdu(smp,'\a',len_00);
        if (pnVar4 != (net_buf *)0x0) {
          user_data = net_buf_add((net_buf *)&(pnVar4->field6_0xc).field0,10);
          *(undefined4 *)(user_data + 1) = local_34;
          *(undefined4 *)(user_data + 3) = uStack_30;
          *user_data = local_2c;
          smp_send(smp,pnVar4,(bt_conn_tx_cb_t)0x616c9,user_data);
          bVar1 = atomic_test_bit((atomic_t *)target_00,0xd);
          if (bVar1) {
            bt_keys_find_addr((uint8_t)puVar9,(bt_addr_le_t *)&DAT_00000001);
            puVar8 = local_44;
            puVar11 = (undefined4 *)(puVar9 + 0x4a);
            do {
              uVar5 = *puVar8;
              uVar7 = puVar8[1];
              puVar8 = puVar8 + 2;
              *puVar11 = uVar5;
              puVar11[1] = uVar7;
              puVar11 = puVar11 + 2;
            } while (puVar8 != &local_34);
            *(undefined4 *)(puVar9 + 0x40) = local_34;
            *(undefined4 *)(puVar9 + 0x44) = uStack_30;
            *(undefined2 *)(puVar9 + 0x48) = local_2c;
          }
          goto LAB_0006159e;
        }
        local_4c = "Unable to allocate Central Ident buffer";
      }
    }
    else {
      local_4c = "Unable to get random bytes";
    }
    local_50[0] = '\x02';
    local_50[1] = '\0';
    local_50[2] = '\0';
    local_50[3] = '\0';
    LOG_ERR(&PTR_s_bt_smp_0008b930,0x1040,local_50);
  }
LAB_0006159e:
  if (*(short *)&chan[-1].destroy != 0) {
    return;
  }
  status = '\0';
LAB_000614a6:
  smp_pairing_complete(smp,status);
  return;
}


