/*
 * Function: bt_smp_update_keys
 * Entry:    00061728
 * Prototype: void __stdcall bt_smp_update_keys(bt_conn * conn)
 */


/* exclude_from_export_ai */

void bt_smp_update_keys(bt_conn *conn)

{
  bool bVar1;
  bt_smp *smp;
  bt_keys *pbVar2;
  char *str;
  size_t len;
  undefined *puVar3;
  uint uVar4;
  byte *pbVar5;
  byte bVar7;
  undefined4 *puVar8;
  dword *target;
  undefined1 *local_28;
  char *local_24;
  int iStack_20;
  undefined2 local_1c;
  byte *pbVar6;
  
  smp = smp_chan_get(conn);
  if (smp == (bt_smp *)0x0) {
    return;
  }
  target = &smp->SMP_NUM_FLAGS_;
  bVar1 = atomic_test_bit((atomic_t *)target,3);
  if (!bVar1) {
    return;
  }
  pbVar2 = (bt_keys *)(conn->le).keys;
  if (pbVar2 != (bt_keys *)0x0) {
    bt_keys_clear(pbVar2);
  }
  pbVar2 = bt_keys_get_addr(conn->id,&(conn->le).dst);
  (conn->le).keys = &pbVar2->id;
  if (pbVar2 == (bt_keys *)0x0) {
    iStack_20 = bt_addr_le_to_str(&(conn->le).dst,str,len);
    local_24 = "Unable to get keys for %s";
    local_1c = 0x200;
    local_28 = &DAT_01000003;
    LOG_ERR(&PTR_s_bt_smp_0008b930,0x1c40,(char *)&local_28);
    smp_error(smp,'\b');
    return;
  }
  bVar1 = atomic_test_bit((atomic_t *)target,0xe);
  if (bVar1) {
    puVar3 = (conn->le).keys;
    puVar3[0xd] = puVar3[0xd] | 2;
  }
  uVar4 = (uint)smp->method;
  puVar3 = (conn->le).keys;
  if (uVar4 < 4) {
    if (uVar4 != 0) {
LAB_000617be:
      puVar3 = (conn->le).keys;
      bVar7 = puVar3[0xd] | 1;
      goto LAB_000617c8;
    }
  }
  else if (uVar4 - 5 < 2) {
    puVar3[0xd] = puVar3[0xd] | 0x20;
    goto LAB_000617be;
  }
  puVar3[0xd] = puVar3[0xd] & 0xdf;
  puVar3 = (conn->le).keys;
  bVar7 = puVar3[0xd] & 0xfe;
LAB_000617c8:
  puVar3[0xd] = bVar7;
  bVar7 = smp->prsp[4];
  if (smp->preq[4] <= smp->prsp[4]) {
    bVar7 = smp->preq[4];
  }
  (conn->le).keys[0xc] = bVar7;
  bVar1 = atomic_test_bit((atomic_t *)target,5);
  puVar3 = (conn->le).keys;
  if (bVar1) {
    puVar3[0xd] = puVar3[0xd] | 0x10;
    bVar1 = atomic_test_bit((atomic_t *)target,0xd);
    if (bVar1) {
      bt_keys_find_addr((uint8_t)(conn->le).keys,(bt_addr_le_t *)&Reserved2);
      pbVar6 = smp->tk;
      puVar8 = (undefined4 *)((conn->le).keys + 0x1a);
      do {
        pbVar5 = pbVar6 + 4;
        *puVar8 = *(undefined4 *)pbVar6;
        pbVar6 = pbVar5;
        puVar8 = puVar8 + 1;
      } while (pbVar5 != &smp->pkey_BT_PUB_KEY_LEN_);
      puVar3 = (conn->le).keys;
      *(undefined4 *)(puVar3 + 0x10) = 0;
      *(undefined4 *)(puVar3 + 0x14) = 0;
      *(undefined2 *)((conn->le).keys + 0x18) = 0;
    }
  }
  else {
    puVar3[0xd] = puVar3[0xd] & 0xef;
  }
  return;
}


