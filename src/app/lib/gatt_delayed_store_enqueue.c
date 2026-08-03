/*
 * Function: gatt_delayed_store_enqueue
 * Entry:    0005cfd0
 * Prototype: void __stdcall gatt_delayed_store_enqueue(uint8_t id, bt_addr_le_t * peer_addr, delayed_store_flags flag)
 */


/* exclude_from_export */

void gatt_delayed_store_enqueue(uint8_t id,bt_addr_le_t *peer_addr,delayed_store_flags flag)

{
  bool bVar1;
  ds_peer *pdVar2;
  int bit;
  int bit_00;
  int bit_01;
  undefined4 extraout_r1;
  char *test;
  ds_peer *extraout_r2;
  char *file;
  int iVar3;
  int line;
  int iVar4;
  k_timeout_t delay;
  
  bVar1 = bt_addr_le_is_bonded(id,peer_addr);
  pdVar2 = gatt_delayed_store_find(id,peer_addr);
  if (!bVar1) {
    return;
  }
  if (pdVar2 == (ds_peer *)0x0) {
    bVar1 = atomic_test_bit((atomic_t *)&gatt_delayed_store.peer_list0.flags,bit);
    if (bVar1) {
      bVar1 = atomic_test_bit((atomic_t *)&gatt_delayed_store.peer_list1.flags,bit_00);
      if (bVar1) {
        bVar1 = atomic_test_bit((atomic_t *)&gatt_delayed_store.peer_list2.flags,bit_01);
        if (bVar1) {
          _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","el != ((void *)0)",
                  "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",1399);
          _ASSERT("\tCan\'t save CF / CCC to flash\n",test,file,line);
                    /* WARNING: Subroutine does not return */
          k_panic();
        }
        iVar4 = 2;
        iVar3 = 0x18;
      }
      else {
        iVar4 = 1;
        iVar3 = 0xc;
      }
    }
    else {
      iVar3 = 0;
      iVar4 = 0;
    }
    bt_addr_le_copy((bt_addr_le_t *)(gatt_delayed_store.peer_list0.peer.a.val + iVar3 + -1),
                    peer_addr);
    (&gatt_delayed_store.peer_list0)[iVar4].id = id;
    pdVar2 = extraout_r2;
  }
  atomic_set_bit((atomic_t *)&pdVar2->flags,1 << (flag & 0xffU));
  delay.ticks._4_4_ = 0x8000;
  delay.ticks._0_4_ = extraout_r1;
  k_work_reschedule(&gatt_delayed_store.work,delay);
  return;
}


