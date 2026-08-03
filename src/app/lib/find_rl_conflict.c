/*
 * Function: find_rl_conflict
 * Entry:    00058084
 * Prototype: void __stdcall find_rl_conflict(bt_keys * resident, void * user_data)
 */


/* exclude_from_export */

void find_rl_conflict(bt_keys *resident,void *user_data)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_30 [24];
  
  if (user_data == (void *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","conflict != ((void *)0)",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/id.c",876);
  }
  else {
    iVar3 = *(int *)user_data;
    if (iVar3 == 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","conflict->candidate != ((void *)0)",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/id.c",877);
    }
    else if (resident == (bt_keys *)0x0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","resident != ((void *)0)",
              "WEST_TOPDIR/zephyr/subsys/bluetooth/host/id.c",878);
    }
    else {
      if (-1 < (int)((uint)*(byte *)(iVar3 + 8) << 0x1d)) {
        if ((*(int *)((int)user_data + 4) == 0) && ((int)((uint)resident->state << 0x1d) < 0)) {
          bVar1 = bt_addr_le_eq((bt_addr_le_t *)(iVar3 + 1),&resident->addr);
          memset(auStack_30,0,0x16);
          iVar2 = memcmp((void *)(iVar3 + 0x2a),auStack_30,0x10);
          if (((iVar2 != 0) &&
              (iVar3 = memcmp((void *)(iVar3 + 0x2a),(void *)((int)&resident->irk_val0 + 2),0x10),
              iVar3 == 0)) || (bVar1)) {
            *(bt_keys **)((int)user_data + 4) = resident;
          }
        }
        return;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","(conflict->candidate->state & BT_KEYS_ID_ADDED) == 0"
              ,"WEST_TOPDIR/zephyr/subsys/bluetooth/host/id.c",880);
    }
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


