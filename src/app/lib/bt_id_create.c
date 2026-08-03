/*
 * Function: bt_id_create
 * Entry:    000584b0
 * Prototype: int __stdcall bt_id_create(bt_addr_le_t * addr, uint8_t * irk)
 */


/* WARNING: Type propagation algorithm not settling */
/* exclude_from_export_ai */

int bt_id_create(bt_addr_le_t *addr,uint8_t *irk)

{
  byte id;
  bool bVar1;
  int iVar2;
  atomic_val_t aVar3;
  uint8_t *extraout_r2;
  uint8_t *extraout_r2_00;
  uint8_t *irk_00;
  uint uVar4;
  dword in_stack_ffffffd8;
  uint8_t *in_stack_ffffffdc;
  void *in_stack_ffffffe0;
  undefined4 local_18;
  char *local_14;
  
  if ((addr != (bt_addr_le_t *)0x0) &&
     (bVar1 = bt_addr_le_eq(addr,(bt_addr_le_t *)&DAT_000f0b50), !bVar1)) {
    if ((addr->type != '\x01') || (((addr->a).val[5] & 0xc0) != 0xc0)) {
      local_14 = "Only static random identity address supported";
      local_18 = 2;
      LOG_WRN(&PTR_s_bt_id_0008b900,0x1040,&local_18,2,in_stack_ffffffd8,in_stack_ffffffdc,
              in_stack_ffffffe0);
      return -0x16;
    }
    iVar2 = id_find(addr);
    if (-1 < iVar2) {
      return -0x78;
    }
  }
  if (irk == (uint8_t *)0x0) {
    if (DAT_20002007 == 1) {
      return -0xc;
    }
    aVar3 = atomic_get(&DAT_200020d4);
    irk_00 = extraout_r2;
    if ((aVar3 << 0x1f < 0) ||
       ((addr != (bt_addr_le_t *)0x0 &&
        (bVar1 = bt_addr_le_eq(addr,(bt_addr_le_t *)&DAT_000f0b50), irk_00 = extraout_r2_00, !bVar1)
        ))) {
      id = DAT_20002007;
      uVar4 = (uint)DAT_20002007;
      DAT_20002007 = DAT_20002007 + 1;
      iVar2 = id_create(id,addr,irk_00);
      if (iVar2 != 0) {
        DAT_20002007 = DAT_20002007 + -1;
        return iVar2;
      }
      return uVar4;
    }
  }
  return -0x16;
}


