/*
 * Function: smp_ident_addr_info
 * Entry:    0006111c
 * Prototype: uint8_t __stdcall smp_ident_addr_info(bt_smp * smp, net_buf * buf)
 */


/* exclude_from_export_ai */

uint8_t smp_ident_addr_info(bt_smp *smp,net_buf *buf)

{
  uint8_t uVar1;
  bool bVar2;
  int iVar3;
  bt_keys *pbVar4;
  bt_keys *pbVar5;
  char *str;
  char *str_00;
  size_t in_r2;
  size_t len;
  size_t len_00;
  bt_addr_le_t *pbVar6;
  bt_conn *conn;
  bt_addr_le_t *addr;
  bt_conn_le *addr_00;
  undefined1 *local_48;
  char *local_44;
  int iStack_40;
  undefined2 local_3c;
  bt_addr_le_t *local_38;
  bt_addr_le_t *pbStack_34;
  char local_28 [4];
  char *local_24;
  
  addr = (bt_addr_le_t *)(buf->field6_0xc).field0.data;
  smp[1].tk[10] = smp[1].tk[10] & 0xfd;
  conn = *(bt_conn **)&smp[1].dhkey_BT_DH_KEY_LEN_;
  addr_00 = &conn->le;
  if ((addr->type != '\0') && (((addr->a).val[5] & 0xc0) != 0xc0)) {
    iStack_40 = bt_addr_le_to_str(addr,(char *)buf,in_r2);
    local_44 = "Invalid identity %s";
    local_3c = 0x200;
    local_48 = &DAT_01000003;
    LOG_ERR(&PTR_s_bt_smp_0008b930,0x1c40,(char *)&local_48);
    iStack_40 = bt_addr_le_to_str(&addr_00->dst,str,len);
    local_44 = " for %s";
    local_3c = 0x200;
    local_48 = &DAT_01000003;
    LOG_ERR(&PTR_s_bt_smp_0008b930,0x1c40,(char *)&local_48);
    return '\n';
  }
  iVar3 = memcmp(addr_00,addr,7);
  if ((iVar3 == 0) || (pbVar4 = bt_keys_find_addr(conn->id,addr), pbVar4 == (bt_keys *)0x0)) {
LAB_000611d8:
    bVar2 = atomic_test_bit((atomic_t *)&smp->SMP_NUM_FLAGS_,0xd);
    if (bVar2) {
      pbVar4 = bt_keys_get_type(BT_KEYS_LTK,conn->id,&addr_00->dst);
      if (pbVar4 == (bt_keys *)0x0) {
        iStack_40 = bt_addr_le_to_str(&addr_00->dst,str_00,len_00);
        local_44 = "Unable to get keys for %s";
        local_3c = 0x200;
        local_48 = &DAT_01000003;
        LOG_ERR(&PTR_s_bt_smp_0008b930,0x1c40,(char *)&local_48);
        goto LAB_0006121c;
      }
      if (conn->role == '\0') {
        pbVar6 = &(conn->le).resp_addr;
      }
      else {
        pbVar6 = &(conn->le).init_addr;
      }
      if ((pbVar6->type == '\x01') && (((pbVar6->a).val[5] & 0xc0) == 0x40)) {
        *(undefined4 *)((pbVar4->irk_rpa).val + 2) = *(undefined4 *)(pbVar6->a).val;
        pbVar4->_irk_pad = *(ushort *)((pbVar6->a).val + 4);
        if (((conn->le).dst.type != '\0') && (((conn->le).dst.a.val[5] & 0xc0) != 0xc0)) {
          local_38 = &addr_00->dst;
          pbStack_34 = addr;
          bt_conn_foreach(BT_CONN_TYPE_LE,(void *)0x8699b,&local_38);
          bt_addr_le_copy(&pbVar4->addr,addr);
          bt_conn_identity_resolved(conn);
        }
      }
      if ((int)((uint)smp[1].tk[10] << 0x1e) < 0) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!(smp->remote_dist & 0x02)",
                "WEST_TOPDIR/zephyr/subsys/bluetooth/host/smp.c",3785);
LAB_0006128c:
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      pbVar5 = bt_id_find_conflict(pbVar4);
      if (pbVar5 != (bt_keys *)0x0) {
        local_24 = "Refusing new pairing. The old bond must be unpaired first.";
        local_28[0] = '\x02';
        local_28[1] = '\0';
        local_28[2] = '\0';
        local_28[3] = '\0';
        LOG_ERR(&PTR_s_bt_smp_0008b930,0x1080,local_28);
        return '\x03';
      }
      pbVar5 = bt_id_find_conflict(pbVar4);
      if (pbVar5 != (bt_keys *)0x0) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!bt_id_find_conflict(new_bond)",
                "WEST_TOPDIR/zephyr/subsys/bluetooth/host/smp.c",3813);
        goto LAB_0006128c;
      }
      bt_id_add(pbVar4);
    }
    if ((int)((uint)smp[1].tk[10] << 0x1d) < 0) {
      atomic_set_bit((atomic_t *)smp,10);
    }
    if (*(short *)(smp[1].tk + 9) == 0) {
      smp_pairing_complete(smp,'\0');
    }
    uVar1 = '\0';
  }
  else {
    bVar2 = update_keys_check(smp,pbVar4);
    if (bVar2) {
      bt_keys_clear(pbVar4);
      goto LAB_000611d8;
    }
LAB_0006121c:
    uVar1 = '\b';
  }
  return uVar1;
}


