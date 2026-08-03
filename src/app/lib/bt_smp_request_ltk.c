/*
 * Function: bt_smp_request_ltk
 * Entry:    00086b28
 * Prototype: bool __stdcall bt_smp_request_ltk(bt_conn * conn, uint64_t rand, uint16_t ediv, uint8_t * ltk)
 */


/* exclude_from_export */

bool bt_smp_request_ltk(bt_conn *conn,uint64_t rand,uint16_t ediv,uint8_t *ltk)

{
  uint16_t uVar1;
  uint8_t *d;
  bool bVar2;
  bt_smp *smp;
  bt_keys *pbVar3;
  int iVar4;
  undefined *puVar5;
  byte *s;
  uint n;
  dword *target;
  undefined8 local_28;
  undefined4 uStack_20;
  
  d = ltk;
  uStack_20 = (undefined4)rand;
  local_28 = rand;
  smp = smp_chan_get(conn);
  uVar1 = ediv;
  if (smp == (bt_smp *)0x0) {
LAB_00086c4a:
    bVar2 = false;
  }
  else {
    target = &smp->SMP_NUM_FLAGS_;
    if (ediv == 0) {
      if ((int)local_28 != 0 || local_28._4_4_ != 0) goto LAB_00086ba2;
      bVar2 = atomic_test_bit((atomic_t *)target,3);
      if ((bVar2) && (bVar2 = atomic_test_bit((atomic_t *)target,1), bVar2)) {
        s = smp->tk;
        n = (uint)smp->prsp[4];
        if ((uint)smp->preq[4] <= (uint)smp->prsp[4]) {
          n = (uint)smp->preq[4];
        }
      }
      else {
        if ((conn->le).keys == (undefined *)0x0) goto LAB_00086ba8;
LAB_00086c1a:
        puVar5 = (conn->le).keys;
        if ((puVar5 == (undefined *)0x0) || (-1 < (int)((uint)*(ushort *)(puVar5 + 0xe) << 0x1a)))
        goto LAB_00086bd8;
        s = puVar5 + 0x1a;
        n = (uint)(byte)puVar5[0xc];
      }
    }
    else {
LAB_00086ba2:
      if ((conn->le).keys == (undefined *)0x0) {
LAB_00086ba8:
        pbVar3 = bt_keys_find(0x20,conn->id,&(conn->le).dst);
        (conn->le).keys = &pbVar3->id;
        if (pbVar3 == (bt_keys *)0x0) {
          pbVar3 = bt_keys_find(BT_KEYS_IRK,conn->id,&(conn->le).dst);
          (conn->le).keys = &pbVar3->id;
        }
        if (uVar1 == 0) {
          if ((int)local_28 == 0 && local_28._4_4_ == 0) goto LAB_00086c1a;
        }
      }
LAB_00086bd8:
      puVar5 = (conn->le).keys;
      if ((puVar5 == (undefined *)0x0) ||
         (((-1 < (int)((uint)*(ushort *)(puVar5 + 0xe) << 0x1f) ||
           (iVar4 = memcmp(puVar5 + 0x40,&local_28,8), iVar4 != 0)) ||
          (iVar4 = memcmp(puVar5 + 0x48,&ediv,2), iVar4 != 0)))) {
        bVar2 = atomic_test_bit((atomic_t *)target,0xf);
        if (bVar2) {
          bt_conn_security_changed(conn,'\x06',BT_SECURITY_ERR_PIN_OR_KEY_MISSING);
        }
        smp_reset(smp);
        goto LAB_00086c4a;
      }
      s = puVar5 + 0x4a;
      n = (uint)(byte)puVar5[0xc];
    }
    memcpy(d,s,n);
    if (n < 0x10) {
      memset(d + n,0,0x10 - n);
    }
    atomic_set_bit((atomic_t *)target,1);
    bVar2 = true;
  }
  return bVar2;
}


