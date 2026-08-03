/*
 * Function: bt_keys_find_irk
 * Entry:    00061ae8
 * Prototype: bt_keys * __stdcall bt_keys_find_irk(uint8_t id, bt_addr_le_t * addr)
 */


/* exclude_from_export */

bt_keys * bt_keys_find_irk(uint8_t id,bt_addr_le_t *addr)

{
  bool bVar1;
  bt_keys *pbVar2;
  int iVar3;
  int iVar4;
  
  if (addr == (bt_addr_le_t *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","addr != ((void *)0)",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/keys.c",233);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if ((addr->type == '\x01') && (((addr->a).val[5] & 0xc0) == 0x40)) {
    if ((int)((uint)(ushort)key_pool.ltk_rand0 << 0x1e) < 0) {
      if (key_pool.id != id) {
        if ((int)((uint)DAT_2000b996 << 0x1e) < 0) {
LAB_00061b96:
          if ((DAT_2000b988 == id) && (iVar3 = memcmp(&addr->a,&DAT_2000b9c2,6), iVar3 == 0))
          goto LAB_00061baa;
          goto LAB_00061bb0;
        }
LAB_00061b4e:
        if (-1 < (int)((uint)DAT_2000b996 << 0x1e)) goto LAB_00061b0a;
        goto LAB_00061b56;
      }
      iVar4 = memcmp(&addr->a,key_pool.irk_rpa.val + 2,6);
      iVar3 = 0;
      if (iVar4 == 0) goto LAB_00061bac;
      if ((int)((uint)DAT_2000b996 << 0x1e) < 0) goto LAB_00061b96;
LAB_00061bb0:
      if ((key_pool.id != id) ||
         (bVar1 = bt_rpa_irk_matches((uint8_t *)((int)&key_pool.irk_val0 + 2),&addr->a), !bVar1))
      goto LAB_00061b4e;
      iVar3 = 0;
    }
    else {
      if (-1 < (int)((uint)DAT_2000b996 << 0x1e)) goto LAB_00061b0a;
      if (DAT_2000b988 == id) {
        iVar3 = memcmp(&addr->a,&DAT_2000b9c2,6);
        if (iVar3 != 0) goto LAB_00061b4e;
LAB_00061baa:
        iVar3 = 0x5c;
LAB_00061bac:
        return (bt_keys *)(key_pool.addr.a.val + iVar3 + -2);
      }
LAB_00061b56:
      if ((DAT_2000b988 != id) || (bVar1 = bt_rpa_irk_matches(&DAT_2000b9b2,&addr->a), !bVar1))
      goto LAB_00061b0a;
      iVar3 = 0x5c;
    }
    *(undefined4 *)(key_pool.irk_rpa.val + iVar3 + 2) = *(undefined4 *)(addr->a).val;
    pbVar2 = (bt_keys *)(key_pool.addr.a.val + iVar3 + -2);
    *(undefined2 *)((int)(&key_pool.irk_rpa + 1) + iVar3) = *(undefined2 *)((addr->a).val + 4);
  }
  else {
LAB_00061b0a:
    pbVar2 = (bt_keys *)0x0;
  }
  return pbVar2;
}


