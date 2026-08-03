/*
 * Function: user_data_alloc
 * Entry:    00051b88
 * Prototype: void * __stdcall user_data_alloc(bt_gatt_dm * dm, size_t len)
 */


/* exclude_from_export */

void * user_data_alloc(bt_gatt_dm *dm,size_t len)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)((int)&dm->conn + 3) & 0xfffffffc;
  if (0x74 < uVar4) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
            "len <= (128 - sizeof(struct k_mem_block_id) - sizeof(struct data_chunk_item *))",
            "WEST_TOPDIR/nrf/subsys/bluetooth/gatt_dm.c",91);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if ((DAT_2000ac84 == (undefined4 *)0x0) || (0x74 < DAT_2000ac8c + uVar4)) {
    puVar2 = k_calloc(1,0x78);
    if (puVar2 == (undefined4 *)0x0) {
      return (void *)0x0;
    }
    *puVar2 = 0;
    puVar1 = puVar2;
    if (DAT_2000ac88 != (undefined4 *)0x0) {
      *DAT_2000ac88 = puVar2;
      puVar1 = DAT_2000ac84;
    }
    DAT_2000ac84 = puVar1;
    DAT_2000ac8c = 0;
    DAT_2000ac88 = puVar2;
  }
  iVar3 = DAT_2000ac8c + 4;
  DAT_2000ac8c = uVar4 + DAT_2000ac8c;
  return (void *)((int)DAT_2000ac88 + iVar3);
}


