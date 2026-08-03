/*
 * Function: id_create
 * Entry:    00057fc4
 * Prototype: int __stdcall id_create(uint8_t id, bt_addr_le_t * addr, uint8_t * irk)
 */


/* exclude_from_export */

int id_create(uint8_t id,bt_addr_le_t *addr,uint8_t *irk)

{
  bool bVar1;
  uint uVar2;
  bt_addr_le_t *dst;
  atomic_val_t aVar3;
  int iVar4;
  bt_addr_le_t *extraout_r0;
  undefined8 uStack_18;
  uint8_t *puStack_10;
  
  uVar2 = (uint)id;
  uStack_18._0_4_ = uVar2;
  uStack_18._4_4_ = addr;
  puStack_10 = irk;
  if ((addr == (bt_addr_le_t *)0x0) ||
     (bVar1 = bt_addr_le_eq(addr,(bt_addr_le_t *)&DAT_000f0b50), bVar1)) {
    do {
      iVar4 = bt_addr_le_create_static((bt_addr_le_t *)&uStack_18);
      if (iVar4 != 0) {
        return iVar4;
      }
      iVar4 = id_find((bt_addr_le_t *)&uStack_18);
    } while (-1 < iVar4);
    bt_addr_le_copy((bt_addr_le_t *)((int)&bt_dev + uVar2 * 7),(bt_addr_le_t *)&uStack_18);
    bVar1 = addr == (bt_addr_le_t *)0x0;
    dst = addr;
    addr = extraout_r0;
    if (bVar1) goto LAB_00057fe4;
  }
  else {
    dst = (bt_addr_le_t *)((int)&bt_dev + uVar2 * 7);
  }
  bt_addr_le_copy(dst,addr);
LAB_00057fe4:
  aVar3 = atomic_get(&DAT_200020d4);
  if (aVar3 << 0x1d < 0) {
    bt_settings_store_id();
    bt_settings_store_irk();
  }
  return 0;
}


